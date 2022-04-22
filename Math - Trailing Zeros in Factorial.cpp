//Find count of trailing zeroes in n!

#include <iostream>
using namespace std;

// Function to return trailing 0s in factorial of n
int findTrailingZeros(int n)
{
	if (n < 0) // Negative Number Edge Case
		return -1;

	int count = 0;

	// Keep dividing n by powers of 5 and update count
	for (int i = 5; n / i >= 1; i *= 5)
		count += n / i;

	return count;
}

// Driver Code
int main()
{
	int n = 100;
	cout << "Count of trailing 0s in " << 100 << "! is "
		<< findTrailingZeros(n);
	return 0;
}

/*
We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. 
So if we count 5s in prime factors, we are done. How to count the total number of 5s in prime factors of n!? A simple way is to calculate floor(n/5). 
For example, 7! has one 5, 10! has two 5s. It is not done yet, there is one more thing to consider. Numbers like 25, 125, etc have more than one 5. 
For example, if we consider 28! we get one extra 5 and the number of 0s becomes 6. Handling this is simple, first, divide n by 5 and remove all single 5s, 
then divide by 25 to remove extra 5s, and so on. Following is the summarized formula for counting trailing 0s.

Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
*/
