/*
Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.
*/

int findZeroes(int arr[], int n, int m) {
    // sliding window technique
    int len = 0, start = 0, end = 0, ctr = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            end++;
        }
        else{
            if(ctr < m){
                ctr++;
                end++;
            }
            else{
                while(arr[start] != 0){
                    start++;
                }
                start++;
                end++;
            }
        }
        len = max(len,(end-start));
    }
    return len;
}
