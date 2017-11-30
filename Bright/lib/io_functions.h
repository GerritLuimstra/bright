/*
	Gets the contents of a file
	@param fileName The reference to the file
	@return string The textual representation of the contents of the file
*/
string getFileContents(string fileName) {
	string contents;
	std::ifstream in(fileName);
	if (in.is_open())
	{
		std::string line;
		while (std::getline(in, line)) contents = contents + line + "\n";
	}

	return contents;
}