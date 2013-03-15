#include<iostream>
#include<cstdio>

using namespace std;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    cout << a[i] << " ";

    cout << endl;
}

void swap(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

void maxHeapify(int a[], int i, int n)
{
    int l = left(i);

    int r = right(i);

    int largest = i;

    if (l < n && a[l] > a[largest])
    	largest = l;

    if (r < n && a[r] > a[largest])
    	largest = r;

    if (largest != i)
	{
    	swap(a[largest], a[i]);
    	maxHeapify(a, largest, n);
    }
}

void buildHeap(int a[], int n)
{
    for (int i = n / 2; i >= 0; i--)
	{
    	maxHeapify(a, i, n);
    }
}

void heapSort(int a[], int n)
{
    buildHeap(a, n);

    while (n > 1)
	{
    	swap(a[0], a[n - 1]);
    	n--;
    	maxHeapify(a, 0, n);
    }
}

int main()
{
    int a[] = { 1, 4, 2, 7, 5, 10, 9, 16, 15, 14 };

    int n = sizeof(a) / sizeof(int);

    heapSort(a, n);

    display(a, n);

    system("pause");

    return 0;
}
