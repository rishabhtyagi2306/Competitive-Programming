class Solution {
public:
    void merge(vector<int> &a, int l, int mid, int r, int &ans)
    {
        int n = mid-l+1;
        int m = r-mid;
        int left[n], right[m];
        int i, j, k;
        
        for(i = 0; i < n; i++)
        {
            left[i] = a[i+l];
        }
        for(i = 0; i < m; i++)
        {
            right[i] = a[i+mid+1];
        }
        
        i = j = 0;
        k = l;
        while(i < n && j < m)
        {
            if((long long)left[i] > 2ll * right[j])
            {
                ans += (n - i);
                j++;
            }
            else
            {
                i++;
            }
        }
        i = j = 0;
        while(i < n && j < m)
        {
            if(left[i] <= right[j])
            {
                a[k++] = left[i++];
            }
            else
            {
                a[k++] = right[j++];
            }
        }
        while(i < n)
        {
            a[k++] = left[i++];
        }
        while(j < m)
        {
            a[k++] = right[j++];
        }
    }
    
    void mergeSort(vector<int> &a, int l, int r, int &ans)
    {
        if(l >= r)
            return ;
            
        int mid = (l + r)/2;
        mergeSort(a, l, mid, ans);
        mergeSort(a, mid+1, r, ans);
        merge(a, l, mid, r, ans);
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        mergeSort(nums, 0, n-1, ans);
        
        return ans;
    }
};