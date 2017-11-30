#include <stdio.h>
#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Custom headers
#include "lib/string_functions.h"
#include "lib/io_functions.h"
#include "lib/stack.h"
#include "lib/core.h"

using namespace std;

int main() {

	string credits = "--------------------------------\n";
	credits +=       "|   Bright Interpreter v00.01   |\n";
	credits +=       "|          written by           |\n";
	credits +=       "|       Gerrit Luimstra         |\n";
	credits +=       "--------------------------------\n";

	// Print the credits
	cout << credits;

	// Variables

	// Visuals
	string extension = "b";
	string clineWaiter = ">> ";
	cout << "Type 'help' for some quick help.\n";

	// Language
	vector<string> stack;
	vector<string> static_environment;
	vector<string> dynamic_environment;

	while (true) {

		// Print the cLineWaiter
		cout << clineWaiter;
		
		// Read input from the user
		string input;
		getline(std::cin, input);
		trim(input);

		// Display the help for the interpreter
		if (input == "help") {
			cout << "  help                 - Display the available command for the interpreter\n";
			cout << "  brighten <filename>  - Interpret a Bright source file\n";
			cout << "  exit                 - Exit the interpreter\n";
			continue;
		}
		// Try to interpret the source file
		else if (str_starts(input, "brighten ")) {

			// Extract the filename of the file to be interpreted
			string fileName = trim_copy(str_after(input, "brighten "));
			
			// NOTE: This validation should be improved
			// Check if it is a bright source file
			if (!str_ends(fileName, ".b")) {
				cout << "This file does not seem to be a Bright source file.\n";
				cout << "A Bright source file should end with the ." + extension + " extension.\n";
				continue;
			}

			// Strip the "brighten " from the fileName to get the reference to the actual file
			fileName = trim_copy(fileName.substr(8));

			// Grab the contents of the source file
			string contents = trim_copy(getFileContents(fileName));
			if (contents == "") {
				cout << "The file you provided does not exist or is empty.\n";
				continue;
			}

			// Interpret and evaluate the code
			interpretSource(contents);
		}
		// Exit the interpreter
		else if (input == "exit") {
			cout << "Thank you for using this interpreter!\n";
			cout << "Press any key to exit\n";
			getchar();
			break;
		} 
		// Unknown command
		else {
			cout << "Unknown command. \nType 'help' for a list of available commands.\n";
			continue;
		}

	}

	return 0;
}