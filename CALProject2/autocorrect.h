#ifndef SRC_AUTOCORRECT_H_
#define SRC_AUTOCORRECT_H_
#include "dictionary.h"
#include <algorithm>

#include "vectorWords.h"
class autoCorrect{
private:
	dictionary dic;
	vector<string> file;
	VectorWords text;
	vector<string>::iterator currFilePos;
public:
	autoCorrect(){
	}
	autoCorrect(dictionary dic, VectorWords text){
		this->dic = dic;
		this->text = text;
		currFilePos = this->text.getWords().begin();
	}

	void setText(VectorWords t)
	{
		text = t;
	}
	dictionary getDic()
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

#endif