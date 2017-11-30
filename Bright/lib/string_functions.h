using namespace std;

/*
	Determines whether a string (haystack) contains a substring (needle)
	@param string haystack The string that should contain the other string
	@param string needle The string that should be contained in the other string
	@return bool
*/
bool str_contains(string haystack, string needle) {
	return haystack.find(needle) != string::npos;
}

/*
	Determines whether a string (haystack) starts with a substring (needle)
	@param string haystack The string that should contain the needle
	@param string needle The string that should be at the beginning of the haystack
	@return bool
*/
bool str_starts(string haystack, string needle) {
	return haystack.find(needle) == 0;
}

/*
	Determines whether a string (haystack) ends with a substring (needle)
	@param string haystack The string that should contain the needle
	@param string needle The string that should be at the end of the haystack
	@return bool
*/
bool str_ends(string haystack, string needle) {
	return haystack.find(needle) == (haystack.length() - needle.length());
}

/*
	Counts the occurences of a charachter in a string
	@param string haystack The string that should contain the other string
	@param string needle The charachter that should be contained in the other string
	@return bool
*/
int str_occ_count(string haystack, char needle) {
	int count = 0;
	for (int i = 0; i < haystack.length(); i++) {
		if (haystack[i] == needle) count++;
	}
	return count;
}

/*
	Trims the whitespace from the beginning of a string and modifies the string 'in place'
	@param string s The string to be trimmed
	@return void
*/
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

/*
	Trims the whitespace from the end of a string and modifies the string 'in place'
	@param string s The string to be trimmed
	@return void
*/
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

/*
	Trims the whitespace from the beginning and end of a string and modifies the string 'in place'
	@param string s The string to be trimmed
	@return void
*/
static inline void trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}

/*
	Trims the whitespace from the beginning of a string and returns the modified string (copy)
	@param string s The string to be trimmed
	@return void
*/
static inline std::string ltrim_copy(std::string s) {
	ltrim(s);
	return s;
}

/*
	Trims the whitespace from the end of a string and returns the modified string (copy)
	@param string s The string to be trimmed
	@return void
*/
static inline std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}

/*
	Trims the whitespace from the beginning and end of a string and returns the modified string (copy)
	@param string s The string to be trimmed
	@return void
*/
static inline std::string trim_copy(std::string s) {
	trim(s);
	return s;
}

/*
	Returns the string after a given substring
	@param string s The string to return the substring from
	@param string after Returns the text after this charachter or substring
*/
string str_after(string s, string after) {
	return s.substr(s.find(after) + 1);
}