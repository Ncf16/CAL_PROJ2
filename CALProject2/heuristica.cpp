
#include "heuristica.h"
using namespace std;

//only words that have the same length start and end letter
bool level1(System::String^ search, int size, wchar_t first, wchar_t last, int tol)
{
	if (search->Length != size)
		return false;

	if ((search[0] != first) || (search[size - 1] != last))
		return false;

	return true;

}
//only words that have the length within a certain tol start and end letter
bool level2(System::String^ search, int size, wchar_t first, wchar_t last, int tol)
{

	if (abs(search->Length - size) > tol)
		return false;

	if ((search[0] != first) || (search[size - 1] != last))
		return false;

	return true;

}

//only words that have the same start and end letter
bool level3(System::String^ search, int size, wchar_t first, wchar_t last, int tol)
{
	if ((search[0] != first) || (search[size - 1] != last))
		return false;

	return true;

}

//only the same letter
bool level4(System::String^ search, int size, wchar_t first, wchar_t last, int tol)
{
	return (search[0] == first);
}
//only works with the same size
bool level5(System::String^ search, int size, wchar_t first, wchar_t last, int tol)
{
	return search->Length == size;
}//only works within the  same [size-tol,size+tol}
bool level6(System::String^ search, int size, wchar_t first, wchar_t last, int tol)
{
	return abs(search->Length - size) <= tol;
}

//Full mayhem, "back hole"
bool level7(System::String^ search, int size, wchar_t first, wchar_t last, int tol)
{
	return true;
}