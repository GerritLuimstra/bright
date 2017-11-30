using namespace std;

extern int stack;

bool interpretSource(string source) {

	// Loop over the file, row by row
	string line = "";
	for (size_t i = 0; i < source.length(); i++) {
		line += source[i];
		if (source[i] == '\n') {
			string code = line;
			// Reset the line
			line = "";

			// If it is a comment, skip it.
			if (str_starts(code, "#")) {
				cout << "Comment, processing.. \n";
				continue;
			}

			cout << "The code to execute is: " + code + "\n";

			// TODO: Also process the last line
		}
	}

	return 0;	
}

int determineScopeLevel() {
	return str_occ_count('\t');
}