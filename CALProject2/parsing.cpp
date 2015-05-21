/*
 * parsing.cpp
 *
 *  Created on: 22/04/2015
 *      Author: Filipe
 */
#include "parsing.h"
#include<iomanip>
using namespace std;
/**
 * loads from the parser
 */

#define BARRA '/'
#define TAB "\t"
#include <time.h>

//algoritmo de exact matching, vale a pena por 1 char?

void loadParse(string diciName, dictionary &d) {
	ifstream dic;
	 
	cout << diciName << endl;
	 
	string read;
	size_t n, n1;
	 
	string final;
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
				final.assign(read, 0, lim);
				d.addWord(new word(final, false));
				final.clear();
			}
			else {
				d.addWord(new word(read, false));
			}
		 
			read.clear();

		} while (!dic.eof());

	}
	else
		cout << "FAILED \n" << endl;
	cout << "OUT" << endl;
}
 