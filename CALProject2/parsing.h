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


int loadParse(std::string file, dictionary &d);
std::string toString(System::String^ str);
System::String^ toString(std::string str);
#endif /* SRC_PARSING_H_ */
