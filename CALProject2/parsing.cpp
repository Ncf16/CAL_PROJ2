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
#define TAB "\t"
#include <time.h>

//algoritmo de exact matching, vale a pena por 1 char?

int loadParse(string diciName, Trie &d)
{
	
	ifstream dic;
	time_t t, t1;
	time(&t);
	cout << diciName << endl;

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
				d.addWord(toString(Final));
				Final.clear();
			}
			else {
				d.addWord(toString(read));
			}

			read.clear();

		} while (!dic.eof());

	}
	else
		return 0;
	time(&t1);
	cout<<"TEMPO: "  << t1 - t << endl;
	return 1;
}
void loadParse(string diciName, vector<string> &d)
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
		cout << "FAILED \n" << endl;
	cout << "OUT" << endl;
}
string toString(System::String^ str) {
	string tmp;

	for (int i = 0; i < str->Length; i++)
		tmp += (char)str[i];

	return tmp;
}

System::String^ toString(std::string str) {
	return  gcnew System::String(str.c_str());
}