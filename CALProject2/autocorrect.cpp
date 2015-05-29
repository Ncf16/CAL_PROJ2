#include "autocorrect.h"
using namespace std;

void printArray(int **distance, const size_t &sizePattern, const  size_t &sizeWord)
{
	for (size_t i = 0; i < sizePattern; i++)
	{
		for (size_t j = 0; j < sizeWord; j++)
		{
			cout << distance[i][j] << "  ";
		}
		cout << endl;
	}
}
void initArray(int **distance, const size_t &sizePattern, const  size_t &sizeWord, const int &SIZE_OF_INT)
{
	for (size_t i = 0; i < sizePattern; i++)
	{
		distance[i] = (int *)malloc(SIZE_OF_INT*sizeWord);
		distance[i][0] = i;
	}
	for (size_t j = 0; j < sizeWord; j++)
	{
		if (sizePattern <= 0)
			break;
		distance[0][j] = j;
	}

}
void destroyArray(int **distance, const size_t &sizePattern, const  size_t &sizeWord)
{
	for (size_t i = 0; i < sizePattern; i++)
	{
		free(distance[i]);
	}
	free(distance);
}
//P					//T
int approximateString(System::String^ pattern, System::String^ word)
{

	const size_t sizePattern = pattern->Length;
	const size_t sizeWord = word->Length;
	const int SIZE_OF_INT = sizeof(int);

	if (sizePattern <= 0 || sizeWord <= 0)
		return -1;
	int **distance = (int **)malloc(SIZE_OF_INT*sizePattern);

	initArray(distance, sizePattern, sizeWord, SIZE_OF_INT);

	for (size_t i = 1; i < sizePattern; i++)
	{
		for (size_t j = 1; j < sizeWord; j++)
		{
			if (pattern[i] == word[j])
			{
				distance[i][j] = distance[i - 1][j - 1];
			}
			else
			{
				distance[i][j] = 1 + min({ distance[i - 1][j - 1], distance[i][j - 1], distance[i - 1][j] });

			}

		}
	}

	int res = distance[sizePattern - 1][sizeWord - 1];
	destroyArray(distance, sizePattern, sizeWord);
	return res;
}
