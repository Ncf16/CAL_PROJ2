#include <vector>
#include <string>


class VectorWords
{
public:
	std::vector<std::string> words;
	std::string wordToBeChanged;

	void setWordToBeChanged(std::string w)
	{
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