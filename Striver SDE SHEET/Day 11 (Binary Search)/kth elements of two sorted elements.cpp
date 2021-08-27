int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m)
            return kthElement(arr2, arr1, m, n, k);
        
        int st = max(0,k-m), end = min(k,n);
        while(st <= end)
        {
            int m1 = (st + end)/2;
            int m2 = k - m1;
            
            int left1 = m1 <= 0 ? INT_MIN : arr1[m1-1];
            int left2 = m2 <= 0 ? INT_MIN : arr2[m2-1];
            
            int right1 = m1 >= n ? INT_MAX : arr1[m1];
            int right2 = m2 >= m ? INT_MAX : arr2[m2];
            
            if(left1 <= right2 && left2 <= right1)
            {
                return max(left1, left2);
            }
            else if(left1 > right2)
            {
                end = m1-1;
            }
            else
            {
                st = m1+1;
            }
        }
        
        return -1;
    }