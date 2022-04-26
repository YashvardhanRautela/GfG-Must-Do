// Given an array of positive numbers, find the smallest positive integer value that cannot be represented as the sum of elements of any subset of a given set. 
// The expected time complexity is O(nlogn).

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long smallestpositive(vector<long long> arr, int n) 
{
    long long int res = 1; // Initialize result

    sort(arr.begin(), arr.end());
    
    // Traverse the array and increment 'res' if arr[i] is
    // smaller than or equal to 'res'.
    for (int i = 0; i < n && arr[i] <= res; i++)
        res = res + arr[i];

    return res;
}

int main() 
{
    vector<long long> arr1 = {1, 3, 4, 5};
    cout << smallestpositive(arr1, arr1.size()) << endl;
    return 0;
}
