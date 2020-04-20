//here I've written only the function which is required for the algo you can implement the full code



int maxSubarraySum(int a[], int n){
    int sum = 0;
    int maxSum = INT_MIN;
    int i, j;
    for(i = 0; i < n; i++)
    {
        sum += a[i];
        if(maxSum < sum)
           maxSum = sum;
        if(sum < 0)
           sum = 0;
    }
    return maxSum;
    // Your code here
    
}