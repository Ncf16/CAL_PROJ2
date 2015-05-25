/*
 * dic.h
 *
 *  Created on: 16/05/2015
 *      Author: Filipe
 */

#ifndef SRC_dictionary_H_
#define SRC_dictionary_H_
#include <set>
#include<string>

class dictionary {

private:
	std::set<std::string> words;
public:
	dictionary() {
	}
	dictionary(std::set<std::string> w) {
		words = w;

	}
	void addWord(std::string W) {
		words.insert(W);
	}
	std::set<std::string> getWords() const {
		return words;
	}

	void setWords(std::set<std::string>& words) {
		this->words = words;
	}
	int size() {
		return words.size();
	}
};

#endif /* SRC_DIC_H_ */
