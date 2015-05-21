/*
 * dic.h
 *
 *  Created on: 16/05/2015
 *      Author: Filipe
 */

#ifndef SRC_DIC_H_
#define SRC_DIC_H_
#include "words.h"
#include <set>


class File {

private:
	set<word*> words;
public:
	File() {
	}
	File(set<word*> w) {
		words = w;

	}
	void addWord(word* W) {
		words.insert(W);
	}
	set<word*> getWords() const {
		return words;
	}

	void setWords(const set<word*>& words) {
		this->words = words;
	}
	int size() {
		return words.size();
	}
};

#endif /* SRC_DIC_H_ */
