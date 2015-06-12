#include <stdio.h>

/*交换函数*/
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*小根堆调整函数*/
void HeapAdjust_MinRoot(int* ptr,int node,int heap_size)
{
	if (!ptr || node >= heap_size)
		return ;
	int Left_Kid = 2*node+1;
	int Right_Kid = 2*node+2;
	int Min = node;
	if (Left_Kid < heap_size && ptr[Left_Kid]<ptr[node])
	{
		Min = Left_Kid;
	}
	if (Right_Kid < heap_size && ptr[Right_Kid] < ptr[Min])
	{
		Min = Right_Kid;
	}
	if (Min != node)
	{
		swap(&ptr[node], &ptr[Min]);
		HeapAdjust_MinRoot(ptr, Min, heap_size);
	}
}

/*大根堆调整函数*/
void HeapAdjust_MaxRoot(int* ptr, int node, int heap_size)
{
	if (!ptr || node >= heap_size)
		return;
	int Left_Kid = 2 * node + 1;
	int Right_Kid = 2 * node + 2;
	int Max= node;
	if (Left_Kid < heap_size && ptr[Left_Kid] > ptr[node])
	{
		Max = Left_Kid;
	}
	if (Right_Kid < heap_size && ptr[Right_Kid] > ptr[Max])
	{
		Max = Right_Kid;
	}
	if (Max != node)
	{
		swap(&ptr[node], &ptr[Max]);
		HeapAdjust_MaxRoot(ptr, Max, heap_size);
	}
}

/*堆建立函数*/
void BuildHeap(int* ptr, int heap_size)
{
	if (!ptr || heap_size <= 0)
		return;
	for (int i = heap_size / 2; i >= 0; --i)
	{
		//HeapAdjust_MinRoot(ptr, i, heap_size);
		HeapAdjust_MaxRoot(ptr, i, heap_size);
	}
		
}
 
/*打印堆*/
void Print_Heap(int* ptr,int heap_size)
{
	for (int i = 0; i < heap_size; ++i)
		printf("%d ", ptr[i]);
	printf("\n");
}

/*堆排序*/
void Heap_Sort(int* ptr, int heap_size)
{
	BuildHeap(ptr, heap_size);
	for (int i = heap_size - 1; i >= 0; --i)
	{
		swap(&ptr[0], &ptr[i]);
		HeapAdjust_MaxRoot(ptr, 0, i);
	}
}

int main()
{
	int A[] = {8,2,1,7,5,3,11,9,76,43,12,53,13,56,93,19,84,22,52,74,122};
	int size = (sizeof(A) / sizeof(int));
	//BuildHeap(A, size);
	Heap_Sort(A, size);
	Print_Heap(A, size);
	return 0;
}