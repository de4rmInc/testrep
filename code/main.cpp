#include <iostream>
#include <time.h>
#include <ctime>
#include <stdarg.h>
#include <thread>
#include <mutex>
#include "MySort.h"

using namespace std;

void met(int a, ...)
{
	va_list list;
	va_start(list,a);
	
}

void printarr(int* a,int length)
{
	cout<<"array\n";
	for (int i = length-10; i < length; i++)
	{
		cout<<*(a+i)<<" ";
	}
	cout<<endl;
}

void genarr(int* a,int length,int seed)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		a[i]=(rand()%2)?rand()%seed:rand()%seed*-1;
	}
}

void elapsed_print(long begin,long end)
{
	double elapsedMs = double(end-begin) * 1000.0/CLOCKS_PER_SEC;
	cout<<"Elpsed time: "<<elapsedMs<<" ms"<<endl;
}

int F(const void* l, const void* r)
{
	return (*(int*)l - *(int*)r);
}

int main(int argc,char** argv)
{
	int n=10000, seed=n%32000;
	int* a=new int[n];
	int* b=new int[n];
	auto begint = clock();
	genarr(a,n,seed);
	for (int i = 0; i < n; i++)
	{
		b[i]=a[i];
	}
	auto endt = clock();
	elapsed_print(begint,endt);
	printarr(a,n);
	//*******************************
	//***********SHELLSORT********************
	//*******************************
	cout<<"Insertion\n";
	begint = clock();
	MySort().InsertionSort(a,n);//.QuickSort(a,n);//.MergeSort(a,n);	
	endt = clock();
	printarr(a,n);
	elapsed_print(begint,endt);
	
	//*******************************
	//***********MERGESORT********************
	//*******************************
	cout<<"done\nMergeSort Bottromup\n";
	//MySort().Shuffle(a,n);
	//genarr(a,n,seed);
	
	printarr(b,n);
	begint = clock();
	MySort().BottomUpMSort(b,n);//.MergeSort(b,n);//
	//qsort(b,n,sizeof(int),F);
	endt = clock();
	elapsed_print(begint,endt);
	cout<<"\ndone\nexit";
	printarr(b,n);
	cin>>ws;
	return 0;
}

