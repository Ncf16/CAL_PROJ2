#ifndef SRC_HEURISTICA_H_
#define SRC_HEURISTICA_H_
#include <iostream>
#include<math.h>

bool level1(System::String^ search, int size, wchar_t first, wchar_t last, int tol);
bool level2(System::String^ search, int size, wchar_t first, wchar_t last, int tol);
bool level3(System::String^ search, int size, wchar_t first, wchar_t last, int tol);
bool level4(System::String^ search, int size, wchar_t first, wchar_t last, int tol);
bool level5(System::String^ search, int size, wchar_t first, wchar_t last, int tol);
bool level6(System::String^ search, int size, wchar_t first, wchar_t last, int tol);
bool level7(System::String^ search, int size, wchar_t first, wchar_t last, int tol);
#endif