#pragma once
class MySort
{
public:
	MySort(void);
	~MySort(void);

	void ShellSort(int*,int);
	void Shuffle(int*,int);
	void MergeSort(int*,int);
	void BottomUpMSort(int*,int);
	void QuickSort(int*,int);
	void InsertionSort(int*,int);
private:
	int partition(int*,int,int);
	void sortquick(int*,int,int);

	void merge(int*,int*,int,int,int);
	void sortmerge(int*,int*,int,int);

	bool less(int,int);
	void exch(int*,int,int);
};

