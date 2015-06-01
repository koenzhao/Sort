#include <stdio.h>
#include <string.h>
void mergeSort(int data[], int first, int last, int result[]);
void merge(int data[], int first, int mid, int last, int result[]);
int main()
{
	int data[]={2,5,1,6,3,8,4,7};
	int first = 0, last = 7;
	int result[10];
	int i=0;
	mergeSort(data,first,last,result);
	while (i<last+1)
	{
		printf("%d ",result[i]);
		i++;
	}
	return 0;
}
void mergeSort(int data[], int first, int last, int result[])
{
	if(first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(data,first,mid,result);
		mergeSort(data,mid+1,last,result);
		merge(data,first,mid,last,result);
	}
}
void merge(int data[], int first, int mid, int last, int result[])
{
	int i = first, j = mid + 1;
	int m = mid,n = last;
	int k = 0;
	while (i<=m && j<=n)
	{
		if (data[i] <=data [j])
			result[k++] = data[i++];
		else
			result[k++] = data[j++];
	}
	while(i<=m)
		result[k++] = data[i++];
	while(j<=n)
		result[k++] = data[j++];
	for (i=0; i<k; i++)
	{
		data[first+i] = result[i];
	}
}