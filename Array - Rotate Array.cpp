// rotate array anti-clockwise

#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int d, int n)
{
	int i, j, temp;
        
    // incase d > n
    d = d % n;

    // swap 0 to d-1
    i = 0;
    j = d-1;
    while(i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    // swap d to n-1
    i = d;
    j = n - 1;
    while(i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    // swap 0 to n-1
    i = 0;
    j = n - 1;
    while(i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	leftRotate(arr, 2, n);
	printArray(arr, n);

	return 0;
}


// https://www.youtube.com/watch?v=ENcnXXiRT6E
