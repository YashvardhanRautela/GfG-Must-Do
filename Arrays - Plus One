// Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ). 
// The digits are stored such that the most significant digit is the first element of the array.

#include <iostream>
#include <vector>

using namespace std;

void AddOne(vector<int>& digits)
{
	// initialize an index (digit of units)
	int index = digits.size() - 1;

	// while the index is valid and the value at [index] == 9, set it as 0
	while (index >= 0 && digits[index] == 9)
		digits[index--] = 0;

	// if index < 0 (if all digits were 9)
	if (index < 0)
    
		// insert an one at the beginning of the vector
		digits.insert(digits.begin(), 1);

	// else increment the value at [index]
	else
		digits[index]++;
}

int main()
{
	vector<int> digits{ 1, 7, 8, 9 };
	AddOne(digits);
	for (int digit : digits)
		cout << digit << ' ';
	return 0;
}

/*
Start from the end of the vector and if the last element is 9 set it to 0, else exit the loop.
If the loop setted all digits to 0 (if all digits were 9) insert 1 at the beginning.
Else increment the element at the position where the loop stopped.
*/
