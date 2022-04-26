// Given a positive integer N, the task is to find the Nth natural number after removing all the natural numbers containing digit 9.

#include <bits/stdc++.h>
using namespace std;

long long findNthNumber(long long N)
{
	long long result = 0, p = 1;

	while (N > 0) 
    {
		result += (p * (N % 9));
		N = N / 9;
		p = p * 10;
	}

	return result;
}

int main()
{
	int N = 9;
	cout << findNthNumber(N);
	return 0;
}

// convert the number from base 10 to base 9
