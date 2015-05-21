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

//typedef struct {
//	bool operator()(word * W, word* W1) {
//		return W->wSize() > W1->wSize();
//	}
//
//} comparteToSize;
class file {

private:
	set<word*> words;
public:
	file() {
	}
	file(set<word*> w) {
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
