// Hash Map -> Space: O(N), Time: O(N)
// Sorting -> Space: O(1), Time: O(N logN)
// Moore's Voting -> Space: O(1), Time: O(N)

#include <bits/stdc++.h>
using namespace std;

int findCandidate(int a[], int size)
{
	int maj_index = 0, count = 1;
	for (int i = 1; i < size; i++) {
		if (a[maj_index] == a[i])
			count++;
		else
			count--;
		if (count == 0) {
			maj_index = i;
			count = 1;
		}
	}
	return a[maj_index];
}

bool isMajority(int a[], int size, int cand)
{
	int count = 0;
	for (int i = 0; i < size; i++)

		if (a[i] == cand)
			count++;

	if (count > size / 2)
		return 1;

	else
		return 0;
}

void printMajority(int a[], int size)
{
	int cand = findCandidate(a, size);

	if (isMajority(a, size, cand))
		cout << " " << cand << " ";

	else
		cout << "No Majority Element";
}

int main()
{
	int a[] = { 1, 3, 3, 1, 2 };
	int size = (sizeof(a)) / sizeof(a[0]);

	printMajority(a, size);

	return 0;
}

/*
Loop through each element and maintains a count of majority element, and a majority index
If the next element is same then increment the count, if the next element is not same then decrement the count.
If the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
Now check if the candidate is actually the majority element.
*/
