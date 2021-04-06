#define _CRT_SECURE_NO_WARNINGS

//ÄæÖÃÊı×é
void reverse(int* array, int start, int end)
{
	while (start < end)
	{
		int tmp = array[start];
		array[start] = array[end];
		array[end] = tmp;
		start++;
		end--;
	}
}

void rotate(int* nums, int numsSize, int k){
	k %= numsSize;
	int head = 0;
	int tail = numsSize - 1;
	if (k % numsSize == 0)  return nums;
	int l_mid = numsSize - k - 1;
	int r_mid = numsSize - k;
	reverse(nums, head, l_mid);
	reverse(nums, r_mid, tail);
	reverse(nums, head, tail);
	return nums;
}