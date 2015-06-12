#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectSort(int* nums, int numsSize)
{
	if (!nums || numsSize < 0)
		return;
	int i, j, min;
	for (i = 0; i < numsSize-1; ++i)
	{
		min = i;
		for (j = i + 1; j < numsSize; ++j)
		{
			if (nums[j] < nums[i])
				min = j;
		}
		if (min != i)
		{
			swap(&nums[i], &nums[min]);
		}
	}
}

int main()
{
	int nums[] = { 5, 3, 2, 6, 8, 5 };
	int size = (sizeof(nums) / sizeof(int));
	SelectSort(nums, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}