#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#define Cutoff (3)

void Swap(int* num1,int* num2);
int Median3(int A[], int Left, int Right);
void Qsort(int A[],int Left,int Right);
int Partition(int A[],int Left,int Right);

#endif