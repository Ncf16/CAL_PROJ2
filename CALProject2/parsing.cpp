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
	//	ofstream teste;
	//teste.open("treta.txt");
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
				//teste << toString(toString(Final)) << endl;
				Final.clear();
			}
			else {
				//	teste << toString(toString(read)) << endl;
				d.addWord(toString(read));
			}

			read.clear();

		} while (!dic.eof());

	}
	else
		return 0;
	time(&t1);
	cout << "TEMPO: " << t1 - t << endl;
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

int GetMilliCount()
{
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}
//---------------------------------------------------------------------------

int GetMilliSpan(int nTimeStart)
{
	int nSpan = GetMilliCount() - nTimeStart;
	if (nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}
//-