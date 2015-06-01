#include <stdio.h>

void InserSort(int A[],int N)
{
	if(A==NULL || N<1)
		return;
	
	int i,P;
	int Temp;
	for (P=1;P<N;P++)
	{
		Temp = A[P];
		for(i=P;i>0 && A[i-1]>Temp;i--)
		{
			A[i] = A[i-1];
		}
		A[i] = Temp;
	}
}
int main()
{
	int i;
	int A[] = {4,1,77,2,11,32,8,6};
	int len = sizeof(A)/sizeof(int);
	InserSort(A,len);
	for (i = 0;i<len;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}