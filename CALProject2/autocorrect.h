#ifndef SRC_AUTOCORRECT_H_
#define SRC_AUTOCORRECT_H_
#include "file.h"
#include <algorithm>
#include<list>
class autoCorrect{
private:
	list<File> dic;
	File text;
	list<File>::iterator currDicPos;
	set<word*>::iterator currFilePos;
public:
	autoCorrect(){
	}
	autoCorrect(list<File> dic, File text){
		this->dic = dic;
		this->text = text;
		currDicPos = this->dic.begin();
		currFilePos = this->text.getWords().begin();
	}
	void addDic(File dic)
	{
		this->dic.push_back(dic);
	}
	void setText(File t)
	{
		text = t;
	}
	File getText()
	{
		return text;
	}
	void setCurrDicPos(list<File>::iterator currDicPos)
	{
		this->currDicPos = currDicPos;
	}
	void setcurrFilePos(set<word*>::iterator currFilePos)
	{
		this->currFilePos = currFilePos;
	}
};

#endif