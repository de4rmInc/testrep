#include "MySort.h"
#include <time.h>
#include <iostream>

MySort::MySort(void)
{
}


MySort::~MySort(void)
{
}

void MySort::ShellSort(int* a,int N)
{
	int h=1;
	while(h<N/3)
	{
		h=h*3+1;
	}
	while(h>=1)
	{
		for(int i=h;i<N;i++)
		{
			for (int j = i; j >= h && less(a[j],a[j-h]); j-=h)
			{
				exch(a,j,j-h);
			}
		}
		h=h/3;
	}
//	return a;
}

void MySort::Shuffle(int* a, int N)
{
	int r=0;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		r=rand()%(i+1);
		exch(a,i,r);
	}	
}

void MySort::MergeSort(int* a,int length)
{
	int* aux = new int[length];
	sortmerge(a,aux,0,length-1);
}

void MySort::BottomUpMSort(int* a, int length)
{
	int* aux = new int[length];
	for (int sz = 1; sz < length; sz=sz+sz)
	{
		for (int lo = 0; lo < length-sz; lo+=sz+sz)
		{
			merge(a,aux,lo,lo+sz-1,__min(lo+sz+sz-1,length-1));
		}
	}
}

void MySort::merge(int* a,int* aux,int lo,int mid,int hi)
{
	for (int k = lo; k <= hi; k++)
	{
		aux[k] = a[k];
	}
	for(int i=lo, j=mid+1, k=lo; k<=hi ; k++)
	{
	    if(i>mid) a[k]=aux[j++];
		else if(j>hi) a[k]=aux[i++];
		else if(less(aux[j],aux[i])) a[k]=aux[j++];
		else a[k]=aux[i++];
	}
}

void MySort::sortmerge(int* a,int* aux,int lo,int hi)
{
	if(hi<=lo) return;
	int mid=lo+(hi-lo)/2;
	sortmerge(a,aux,lo,mid);
	sortmerge(a,aux,mid+1,hi);
	if(!less(a[mid+1],a[mid])) return;
	merge(a,aux,lo,mid,hi);
}

void MySort::QuickSort(int* a,int length)
{
	Shuffle(a,length);
	sortquick(a,0,length-1);
}

void MySort::sortquick(int*a, int lo, int hi)
{
	if(lo>=hi) return;
	int j=partition(a, lo, hi);
	sortquick(a,lo,j-1);
	sortquick(a,j+1,hi);
}

int MySort::partition(int* a, int lo,int hi)
{
	int i=lo, j=hi+1;

	while (true)
	{
		while (less(a[++i], a[lo]))
		{
			if(i==hi) break;
		}
		while (less(a[lo], a[--j]))
		{
			if(j==lo) break;
		}
		if (i>=j) break;
		exch(a,i,j);
	}

	exch(a,lo,j);
	return j;
}

void MySort::InsertionSort(int* a, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = length-1; j >= i; j--)
		{
			if (less(a[j],a[i]))
			{
				exch(a,j,i);
			}
		}
	}
}

bool MySort::less(int a,int b) { return a<b; }

void MySort::exch(int* a,int i, int j)
{
	int temp=a[i];
	a[i]=a[j], a[j]=temp;
}