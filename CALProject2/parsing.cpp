/*
 * parsing.cpp
 *
 *  Created on: 22/04/2015
 *      Author: Filipe
 */
#include "parsing.h"
#include<iomanip>
#include "Trie.h"
using namespace std;
/**
 * loads from the parser
 */

#define BARRA '/'
#define TAB '\t'

using namespace std;
//algoritmo de exact matching, vale a pena por 1 char?
string toString(System::String^ str) {
	string tmp;

	for (int i = 0; i < str->Length; i++)
		tmp += (char)str[i];

	return tmp;
}

System::String^ toString(string str) {
	return  gcnew System::String(str.c_str());
}


int loadParse(string diciName, Trie &d)
{


	wofstream teste;
	teste.open("treta.txt");
	int t;
	cout << diciName << endl;
	t = GetMilliCount();
	wstring read;
	wstring Final;

	size_t n, n1;
	const locale empty_locale = locale::empty();
	typedef codecvt_utf8<wchar_t> converter_type;
	const converter_type* converter = new converter_type;
	const locale utf8_locale = locale(empty_locale, converter);
	wifstream stream(diciName.c_str());
	stream.imbue(utf8_locale);
	//stream.open(diciName.c_str(), ifstream::in);

	if (!stream.fail()) {
		do {
			getline(stream, read);
			n = read.find(TAB);
			n1 = read.find(BARRA);

			if (n != string::npos || n1 != string::npos) {
				int lim = min(n, n1);
				Final.assign(read, 0, lim);
				System::String^temp = gcnew System::String(Final.c_str());
				d.addWord(temp);
				teste << Final.c_str() << endl;
				Final.clear();
			}
			else {
				teste << read.c_str() << endl;
				System::String^temp = gcnew System::String(read.c_str());
				d.addWord(temp);
			}
			read.clear();
		} while (!stream.eof());
	}
	else
		return 0;


	teste.close();
	stream.close();
	cout << "TEMPO: " << GetMilliSpan(t) << endl;
	return 1;
}
int loadParseVec(std::string diciName, std::vector<std::string> &d)
{
	ifstream dic;
	string read;
	size_t n, n1;
	string Final;

	cout << "here" << endl;

	dic.open(diciName.c_str());
	if (!dic.fail()) {
		cout << "working" << endl;
		do {
			getline(dic, read);

			n = read.find(TAB);
			n1 = read.find(BARRA);
			if (n != string::npos || n1 != string::npos) {
				int lim = min(n, n1);
				Final.assign(read, 0, lim);
				d.push_back(Final);
				Final.clear();
			}
			else {
				d.push_back(read);
			}

			read.clear();

		} while (!dic.eof());

	}
	else
		return 0;

	return 1;
}
