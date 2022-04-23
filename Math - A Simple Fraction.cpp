//Given two integers representing the Numerator and Denominator of a fraction, return the fraction in string format. 
//If the fractional part is repeating, enclose the repeating part in parentheses.

#include <bits/stdc++.h>
using namespace std;

string calculateFraction(int num, int den)
{
	// If the numerator is zero, answer is 0
	if (num == 0)
		return "0";

	// If any one (out of numerator and denominator)
	// is -ve, sign of resultant answer -ve.
	int sign = (num < 0) ^ (den < 0) ? -1 : 1;

	num = abs(num);
	den = abs(den);

	// Calculate the absolute part
	// (before decimal point).
	int initial = num / den;

	// Output string to store the answer
	string res;

	// Append sign
	if (sign == -1)
		res += "-";

	// Append the initial part
	res += to_string(initial);

	// If completely divisible, return answer.
	if (num % den == 0)
		return res;

	res += ".";

	// Initialize Remainder
	int rem = num % den;
	map<int, int> mp;

	// Position at which fraction starts repeating if it exists
	int index;
	bool repeating = false;
	while (rem > 0 && !repeating) {

		// If this remainder is already seen,
		// then there exists a repeating fraction.
		if (mp.find(rem) != mp.end()) {

			// Index to insert parentheses
			index = mp[rem];
			repeating = true;
			break;
		}
		else
			mp[rem] = res.size();

		rem = rem * 10;

		// Calculate quotient, append it to result and calculate next remainder
        // visualise using long division
		int temp = rem / den;
		res += to_string(temp);
		rem = rem % den;
	}

	// If repeating fraction exists, insert parentheses.
	if (repeating) {
		res += ")";
		res.insert(index, "(");
	}

	return res;
}

int main()
{
	int num = 50, den = 22;
	cout << calculateFraction(num, den) << endl;

	num = -1, den = 2;
	cout << calculateFraction(num, den) << endl;
	return 0;
}

/*
The idea is to first calculate the integral quotient (absolute part before decimal point) and then calculate the fractional part. 
To check if the fractional part is repeating, insert the remainder (numerator % denominator) in a map with key as remainder and value as the index position 
at which this remainder occurs. If at any point of time, the remainder becomes zero, 
then there doesn’t exist a repeating fraction otherwise if the remainder is already found in the map, then there exists a repeating fraction.
*/
