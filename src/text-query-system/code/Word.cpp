// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

#include <algorithm>
#include <string>

Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters

	auto punc = string{"~`!@#$%^&*()-_+={}[]\\|:;'<>?,./\""};
	auto wordTemp = false;
	for(int i=0; i<word_.length(); i++){
		if(punc.find(word_[i])>=0 && punc.find(word_[i])<punc.length()){
			continue;
		}else{
			if(word_[i]==' '){
				throw WordContainsSpace();
			}
			wordTemp=true;
		}
	}
	if(!wordTemp){
		throw WordContainsNoLetters{};
	}
	if (word_.empty()) throw WordContainsNoLetters{};


	

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	auto word1 = string{""};
	auto rhsWord = string{""};
	auto punc = string{"~`!@#$%^&*()-_+={}[]\\|:;'<>?,./\""};
	for(int i =0;i<std::max(word_.length(),rhs.word_.length());i++){
		if(i<word_.length()){
			if(punc.find(word_[i])<0 || punc.find(word_[i])>punc.length()){
				word1+=word_[i];
			}
		}
		if(i<rhs.word_.length()){
			if(punc.find(rhs.word_[i])<0 || punc.find(rhs.word_[i])>punc.length()){
				rhsWord+=rhs.word_[i];
			}
		}

	}
	if (word1.length() == rhsWord.length()) {
		for (int i = 0; i < word1.length(); i++) {
			if (std::tolower(word1[i]) != std::tolower(rhsWord[i])) return false;
		}
	} else return false;
	return true;
}

bool Word::isQueryable() const
{
	if(word_.length()>=3){
		return true;
	}
	return false;
}
