//You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. 
//One of the integers is missing in the list. Write an efficient code to find the missing integer.

#include <bits/stdc++.h>
using namespace std;
 
// Function to get the missing number
int getMissingNo(int array[], int n)
{
    int i;
        
    //XOR of array
    int x_arr = array[0];
    for (i = 1; i < n-1; i++)
        x_arr = x_arr ^ array[i];
            
    //XOR of nos
    int x_nos = 1;
    for (i = 2; i < n+1; i++)
        x_nos = x_nos ^ i;
        
    return x_arr ^ x_nos;
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = getMissingNo(arr, n);
    cout << miss;
}
