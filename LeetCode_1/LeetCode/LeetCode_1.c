#define _CRT_SECURE_NO_WARNINGS

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i, j;
	int* ret = (int*)malloc(2 * 4);
	for (i = 0; i< numsSize; i++)
	{
		for (j = i + 1; j<numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				ret[0] = i;
				ret[1] = j;
				break;
			}
		}
	}
	*returnSize = 2;
	return ret;
}