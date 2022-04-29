// Given a sorted array of positive integers, the count number of occurrences for each element in the array. 
// Assume all elements in the array are less than some constant M.
// Do this without traversing the complete array. i.e. expected time complexity is less than O(n). 

// C++ program to count number of occurrences of
// each element in the array in less than O(n) time
#include <iostream>
#include <vector>
using namespace std;

// A recursive function to count number of occurrences
// for each element in the array without traversing
// the whole array
void findFrequencyUtil(int arr[], int low, int high,
					vector<int>& freq)
{
	// If element at index low is equal to element
	// at index high in the array
	if (arr[low] == arr[high]) {
		// increment the frequency of the element
		// by count of elements between high and low
		freq[arr[low]] += high - low + 1;
	}
	else {
		// Find mid and recurse for left and right
		// subarray
		int mid = (low + high) / 2;
		findFrequencyUtil(arr, low, mid, freq);
		findFrequencyUtil(arr, mid + 1, high, freq);
	}
}

// A wrapper over recursive function
// findFrequencyUtil(). It print number of
// occurrences of each element in the array.
void findFrequency(int arr[], int n)
{
	// create a empty vector to store frequencies
	// and initialize it by 0. Size of vector is
	// maximum value (which is last value in sorted
	// array) plus 1.
	vector<int> freq(arr[n - 1] + 1, 0);

	// Fill the vector with frequency
	findFrequencyUtil(arr, 0, n - 1, freq);

	// Print the frequencies
	for (int i = 0; i <= arr[n - 1]; i++)
		if (freq[i] != 0)
			cout << "Element " << i << " occurs "
				<< freq[i] << " times" << endl;
}

int main()
{
	int arr[] = { 1, 1, 1, 2, 3, 3, 5, 5,
				8, 8, 8, 9, 9, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findFrequency(arr, n);
	return 0;
}


/*
The problem can be solved in less than O(n) time if all its elements are sorted, i.e. 
if similar elements exist in the array then the elements are in a contiguous subarray or it can be said that if ends of a subarray 
are same then all the elements inside the subarray are equal. 
So the count of that element is the size of the subarray and all the elements of that subarray need not be counted. 
 
Algorithm: 
Create a HashMap (hm) to store the frequency of elements.
Create a recursive function that accepts an array and size.
Check if the first element of the array is equal to the last element. If equal then all the elements are the same and update the frequency by hm[array[0]+=size
Else divide the array into two equal halves and call the function recursively for both the halves.
Traverse the hashmap and print the element frequency pair.
*/
