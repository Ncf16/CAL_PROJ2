#include "autocorrect.h"
using namespace std;

void initArray(int **matrix, const size_t &sizePattern, const  size_t &sizeWord, const int &SIZE_OF_INT)
{
	for (size_t i = 0; i < sizePattern; i++)
	{
		matrix[i] = (int *)malloc(SIZE_OF_INT*sizeWord);// +1 * SIZE_OF_INT);
		matrix[i][0] = i;
	}
	for (size_t j = 0; j < sizeWord; j++)
	{

		matrix[0][j] = j;
	}

}

//P					//T
int approximateString(System::String^ pattern, System::String^ word)
{
	int time = GetMilliCount();
	const size_t sizePattern = pattern->Length;
	const size_t sizeWord = word->Length;
	const int SIZE_OF_INT = sizeof(int);

	int **distance = (int **)malloc(SIZE_OF_INT*sizePattern);//+SIZE_OF_INT);
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
	for (size_t i = 0; i < sizePattern; i++)
	{
		for (size_t j = 0; j < sizeWord; j++)
		{
			cout << distance[i][j] << "  ";
		}
		cout << endl;
	}

	for (size_t i = 0; i < sizePattern; i++)
	{
		free(distance[i]);
	}
	free(distance);

	cout << "Demora: " << GetMilliSpan(time) << endl;
	return res;
}
