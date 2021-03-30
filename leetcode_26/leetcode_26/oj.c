#define _CRT_SECURE_NO_WARNINGS


//����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

int removeDuplicates(int* nums, int numsSize){
	int prev = 0;
	int next = 1;
	int count = numsSize;
	while (next < count)
	{
		if (nums[prev] == nums[next])
		{
			while ((next < count) && (nums[prev] == nums[next]))
			{
				numsSize--;
				next++;
			}
			if (next < count)
			{
				prev++;
				nums[prev] = nums[next];
				next++;
			}
			else
			{
				break;
			}
		}
		else
		{
			prev++;
			nums[prev] = nums[next];
			next++;
		}
	}
	return numsSize;
}