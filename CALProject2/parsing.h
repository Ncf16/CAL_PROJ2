/*
 * parsing.h
 *
 *  Created on: 22/04/2015
 *      Author: Filipe
 */

#ifndef SRC_PARSING_H_
#define SRC_PARSING_H_

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include "menu.h"
#include"trie.h"
#include <time.h>
#include <sys/timeb.h>

int loadParse(std::string file, Trie &d);
std::string toString(System::String^ str);
System::String^ toString(std::string str);
int GetMilliCount();
int GetMilliSpan(int nTimeStart);

#endif /* SRC_PARSING_H_ */
