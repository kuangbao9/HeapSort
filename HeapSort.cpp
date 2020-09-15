#include<stdio.h>

void Swap(int *a, int i, int j)
{
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
void AdjustHeap(int *a, int i, int n)
{
	int tmp  =a[i];
	int j;
	for(j=i*2+1; j<n; j=j*2+1)
	{
		if(j+1<n && a[j+1]>a[j]) //比较左右孩子 ,指针指向较大孩子 
		{
			j++;
		}
		if(a[j] > tmp) //若孩子节点大于双亲节点，则交换 
		{
			a[i] = a[j];//交换值 
			i=j;//交换下标 
		}
		else
			break; //否则直接退出 
	}
	a[i] = tmp; //将tmp值归位 
}
void HeapSort(int *a, int n)
{
	int i, j;
	for(i=n/2-1; i>=0; i--) //寻找第一个非叶子节点 
	{
		AdjustHeap(a, i, n); //构建大顶堆 
	}
	for(i=n-1; i>=0; i--)
	{
		Swap(a, 0, i); //交换首尾元素 
		AdjustHeap(a, 0, i); //将剩下的元素继续构建大顶堆 
	}
}

int main()
{
	int i=0;
	int a[10] = {5,2,16,6,3,56,4 ,82, 36, 12};
	HeapSort(a, 10);
	for(i=0; i<10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
