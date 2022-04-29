// Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that 
// prod[i] is equal to the product of all the elements of arr[] except arr[i]. 
// Solve it without division operator in O(n) time.

#include <bits/stdc++.h>
using namespace std;

void productArray(int arr[], int n)
{

	// Base case
	if (n == 1) {
		cout << 0;
		return;
	}

	int i, temp = 1;

	/* Allocate memory for the product array */
	int* prod = new int[(sizeof(int) * n)];

	/* Initialize the product array as 1 */
	memset(prod, 1, n);

	/* In this loop, temp variable contains product of
	elements on left side excluding arr[i] */
	for (i = 0; i < n; i++) {
		prod[i] = temp;
		temp *= arr[i];
	}

	/* Initialize temp to 1
	for product on right side */
	temp = 1;

	/* In this loop, temp variable contains product of
	elements on right side excluding arr[i] */
	for (i = n - 1; i >= 0; i--) {
		prod[i] *= temp;
		temp *= arr[i];
	}

	/* print the constructed prod array */
	for (i = 0; i < n; i++)
		cout << prod[i] << " ";

	return;
}

int main()
{
	int arr[] = { 10, 3, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The product array is: \n";
	productArray(arr, n);
}

/*
In the previous solution, two extra arrays were created to store the prefix and suffix, 
in this solution store the prefix and suffix product in the output array (or product array) itself. Thus reducing the space required.

Algorithm: 

Create an array product and initialize its value to 1 and a variable temp = 1.
Traverse the array from start to end.
For every index i update product[i] as product[i] = temp and temp = temp * array[i], i.e store the product upto i-1 index from the start of array.
initialize temp = 1 and traverse the array from last index to start.
For every index i update product[i] as product[i] = product[i] * temp and temp = temp * array[i], i.e multiply with the product upto i+1 index from the end of array.
Print the product array.
*/
