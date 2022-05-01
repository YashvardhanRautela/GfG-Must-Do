using namespace std;

// Maximum number of digits in output
#define MAX 500

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
	int res[MAX];

	// Initialize result
	res[0] = 1;
	int res_size = 1;

	// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
	for (int x=2; x<=n; x++)
		res_size = multiply(x, res, res_size);

	cout << "Factorial of given number is \n";
	for (int i=res_size-1; i>=0; i--)
		cout << res[i];
}

// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function may value of res_size and returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
	int carry = 0; // Initialize carry

	// One by one multiply n with individual digits of res[]
	for (int i=0; i<res_size; i++)
	{
		int prod = res[i] * x + carry;

		// Store last digit of 'prod' in res[]
		res[i] = prod % 10;

		// Put rest in carry
		carry = prod/10;
	}

	// Put carry in res and increase result size
	while (carry)
	{
		res[res_size] = carry%10;
		carry = carry/10;
		res_size++;
	}
	return res_size;
}

// Driver program
int main()
{
	factorial(100);
	return 0;
}


// Another method

vector<long long> factorial(vector<long long> a, int n) 
{
       long long maxi=INT_MIN;
       for(int i=0;i<n;i++)
           if(maxi<a[i])
               maxi=a[i];
       vector<long long> dp(maxi+1,-1);
       vector<long long> ans;
       dp[0]=1;
       dp[1]=1;
       for(int i=2;i<maxi+1;i++)
           dp[i]=i*dp[i-1]%1000000007;
       for(int i=0;i<n;i++)
           ans.push_back(dp[a[i]]);
       return ans;
}
