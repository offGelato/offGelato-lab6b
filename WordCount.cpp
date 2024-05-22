// WordCount.cpp

#include "WordCount.h"


using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0;

	for(size_t i = 0; i < CAPACITY;i++){
		for(auto j = table[i].begin(); j != table[i].end(); j++){
			total += j->second;
		}
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
	int total = 0;

	for(size_t i = 0; i < CAPACITY; i++){
		total += table[i].size();
	}

	return total;
}

int WordCount::getWordCount(std::string word) const {
	string newWord = makeValidWord(word);
	if(newWord.empty()){
		return 0;
	}
	size_t index = hash(newWord);
	for(auto i = table[index].begin(); i != table[index].end(); i++){
		if(i->first == newWord){
			return i->second;
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	string newWord = makeValidWord(word);
	if(newWord.empty()){
		return 0;
	}

	size_t index = hash(newWord);
	for(auto i = table[index].begin(); i < table[index].end(); i++){
		if(i->first == newWord){
			i->second += 1;
			return i->second;
		}
	}

	table[index].emplace_back(newWord, 1);

	return 1;
}

int WordCount::decrWordCount(std::string word) {
	string newWord = makeValidWord(word);
	if(newWord.empty()){
		return -1;
	}
	size_t index = hash(newWord);
	for(auto i = table[index].begin(); i != table[index].end(); i++){
		if(i->first == newWord){
			if(i->second > 1){
				i->second -= 1;
				return i->second;
			}
			if(i->second == 1){
				table[index].erase(i);
				return 0;
			}
		}
	}

	return -1;
}

bool WordCount::isWordChar(char c) {
	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	string newWord = "";
	for(size_t i = 0; i < word.length(); i++){
		if(isWordChar(word[i])){
			newWord += tolower(word[i]);
		}
		else if((word[i] == '-' || word[i] == '\'') && i != 0 && i != word.size()-1){
			if(isWordChar(word[i-1]) && isWordChar(word[i+1])){
			newWord += word[i];
			}
		}
	}
	return newWord;
}
