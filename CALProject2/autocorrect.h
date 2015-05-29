#ifndef SRC_AUTOCORRECT_H_
#define SRC_AUTOCORRECT_H_
#include "dictionary.h"
#include <algorithm>
#include "trie.h"
#include "vectorWords.h"
#include <iostream>
#include<string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include"extra.h"

class autoCorrect{
private:
	Trie dic;
	vector<string> file;
	VectorWords text;
	vector<string>::iterator currFilePos;
public:
	autoCorrect(){
	}
	autoCorrect(Trie dic, VectorWords text){
		this->dic = dic;
		this->text = text;
		currFilePos = this->text.getWords().begin();
	}

	void setText(VectorWords t)
	{
		text = t;
	}
	void newRoot()
	{
		this->dic.setRoot(new Node());
	}
	Trie getDic()
	{
		return this->dic;
	}
	VectorWords getText()
	{
		return text;
	}
 
	void setcurrFilePos(vector<string>::iterator currFilePos)
	{
		this->currFilePos = currFilePos;
	}
};

int approximateString(System::String^ pattern, System::String^ word);

#endif