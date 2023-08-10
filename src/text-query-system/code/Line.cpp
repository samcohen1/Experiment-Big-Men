// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include <iostream>
#include <sstream>

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
	line_=line;
}

bool Line::contains(const Word& search_word) const
{
	//Empty line
	if(line_==""){
		return false;
	}
	//Single word
	if (!(line_.find(" ") >= 0 && line_.find(" ") < line_.length())) {
		Word line_word(line_);
		if (line_word == search_word) return true;
	}
	//First and last word
	auto first_word = Word{line_.substr(0, line_.find(" "))};
	auto last_word = Word{line_.substr(line_.rfind(" ")+1)};
	if (search_word == first_word || search_word == last_word) return true;
	//Any Word irrespecitve of case
	stringstream line_stream(line_);
	auto word = string{""};
	while (line_stream >> word) {
		auto check_word = Word{word};
		if (check_word == search_word && check_word.isQueryable()) return true;
	} 
	//Not Queriable

	return false;
}
