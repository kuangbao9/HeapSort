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
		if(j+1<n && a[j+1]>a[j]) //�Ƚ����Һ��� ,ָ��ָ��ϴ��� 
		{
			j++;
		}
		if(a[j] > tmp) //�����ӽڵ����˫�׽ڵ㣬�򽻻� 
		{
			a[i] = a[j];//����ֵ 
			i=j;//�����±� 
		}
		else
			break; //����ֱ���˳� 
	}
	a[i] = tmp; //��tmpֵ��λ 
}
void HeapSort(int *a, int n)
{
	int i, j;
	for(i=n/2-1; i>=0; i--) //Ѱ�ҵ�һ����Ҷ�ӽڵ� 
	{
		AdjustHeap(a, i, n); //�����󶥶� 
	}
	for(i=n-1; i>=0; i--)
	{
		Swap(a, 0, i); //������βԪ�� 
		AdjustHeap(a, 0, i); //��ʣ�µ�Ԫ�ؼ��������󶥶� 
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
