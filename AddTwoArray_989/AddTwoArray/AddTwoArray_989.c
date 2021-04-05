#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverseArray(int* array, int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
		left++;
		right--;
	}
}

int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
	int flag = 0;
	int size;
	int len = (numSize > 5 ? numSize : 5);
	int* newArray = (int*)malloc(sizeof(int)* (len + 1));
	memset(newArray, 0, sizeof(int)*(len + 1));
	int index = 0;
	while (k)
	{
		newArray[index++] = (k % 10);
		k /= 10;
		flag++;
	}
	reverseArray(num, numSize);
	index = 0;
	size = numSize;
	while (numSize)
	{
		newArray[index] += num[index];
		if (newArray[index] / 10 > 0)
		{
			newArray[index] %= 10;
			index++;
			newArray[index] += 1;
			numSize--;
		}
		else
		{
			index++;
			numSize--;
		}
	}
	while (flag - size)
	{
		if (newArray[index] / 10 > 0)
		{
			newArray[index] %= 10;
			index++;
			newArray[index] += 1;
			flag--;
		}
		else
		{
			index++;
			flag--;
		}
	}
	if (newArray[index] != 0)
	{
		index++;
		*returnSize = index;
	}
	else
	{
		*returnSize = index;
	}
	reverseArray(newArray, *returnSize);
	return newArray;
}

int main()
{
	int array[4] = { 1, 2, 0, 0 };
	int k = 34;
	int returnSize = 0;
	int* ret_array = addToArrayForm(array, 4, k, &returnSize);
	int index = 0;
	while (returnSize--)
	{
		printf("%d " , ret_array[index++]);
	}
	return 0;
}