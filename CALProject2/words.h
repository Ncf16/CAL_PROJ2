/*
 * words.h
 *
 *  Created on: 15/05/2015
 *      Author: Filipe
 */

#ifndef SRC_WORDS_H_

#include <string>
using namespace std;
class  word {
private:
	string Word;
	//bool visited;
public:
	word() {
		Word = "";
		//visited = false;
	}
	word(string w, bool v) {
		Word = w;
		//visited = v;
	}
	void operator=(word W)
	{
		this->Word = W.getWord();
		//this->visited = w.isVisited();    
	}
	bool operator==(word w)
	{
		return (w.getWord().compare(this->Word) == 0);
	}
	bool operator>(word w)
	{
		return (w.getWord().compare(this->Word) > 0);
	}
	bool operator<(word w)
	{
		return (w.getWord().compare(this->Word) < 0);
	}
	bool operator!=(word w)
	{
		return (w.getWord().compare(this->Word) != 0);
	}
	/*	bool isVisited() const {
			return visited;
			}

			void setVisited(bool visited) {
			this->visited = visited;
			}*/

	const string getWord() const {
		return Word;
	}

	void setWord(const string &Word) {
		this->Word = Word;
	}
	int wSize()
	{
		return Word.size();
	}
};

#define SRC_WORDS_H_

#endif /* SRC_WORDS_H_ */
