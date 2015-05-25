#ifndef SRC_VECTORWORDS_H_
#define SRC_VECTORWORDS_H_

#include <vector>
#include <string>

//a usar no wordForm 
class VectorWords
{
private:
	std::vector<std::string> words;
	std::string wordToBeChanged;
public:


	void setWordToBeChanged(std::string w)
	{
		if (w != "")
			wordToBeChanged = w;
	}
	void changeWords(std::vector<std::string> w)
	{
		words = w;
	}
	void addWords(std::string word)
	{
		words.push_back(word);
	}
	std::vector<std::string> getWords()
	{
		return words;
	}
	std::string getWordToBeChanged()
	{
		return wordToBeChanged;
	}
};

#endif