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

#include "menu.h"
#include"trie.h"
#include <time.h>
#include <sys/timeb.h>
#include <time.h>
#include <locale>
#include <codecvt>
#include <string>

#include <cstdlib>
#include "extra.h"
int loadParse(std::string file, Trie &d);
int loadParseVec(std::string file, std::vector<std::string> &d);
std::string toString(System::String^ str);
System::String^ toString(std::string str);


#endif /* SRC_PARSING_H_ */
