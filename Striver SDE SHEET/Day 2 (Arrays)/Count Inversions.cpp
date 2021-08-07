class Solution {
public:
    
    void merge(vector<pair<int, int>> &p, int l, int mid, int r, 
                        vector<int> &ans)
    {
        int n = mid-l+1, i, j;
        int m = r-mid;
        pair<int, int> left[n], right[m];
        for(i = 0; i < n; i++)
        {
            left[i] = p[i+l];
        }
        for(i = 0; i < m; i++)
        {
            right[i] = p[i+mid+1];
        }
        i = n-1, j = m-1;
        int k = l;
        while(i >= 0 && j >= 0)
        {
            if(left[i].first > right[j].first)
            {
                int dis = j+1;
                ans[left[i].second] += dis;
                i--;
            }
            else
            {
                j--;
            }
        }
        i = j = 0;
        while(i < n && j < m)
        {
            if(left[i].first <= right[j].first)
            {
                p[k++] = left[i++];
            }
            else
            {
                p[k++] = right[j++];
            }
        }
        while(i < n)
        {
            p[k++] = left[i++];
        }
        while(j < m)
        {
            p[k++] = right[j++];
        }
    }
    
    void mergeSort(vector<pair<int, int>> &nums, int l, int r, 
                        vector<int> &ans)
    {
        if(l >= r)
            return ;
        
        int mid = (l + r)/2;
        mergeSort(nums, l, mid, ans);
        mergeSort(nums, mid+1, r, ans);
        merge(nums, l, mid, r, ans);
    }
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size(), i, j;
        vector<pair<int, int>> p;
        for(i = 0; i < n; i++)
        {
            p.push_back({nums[i], i});
        }
        vector<int> ans(n);
        mergeSort(p, 0, n-1, ans);
        return ans;
    }
};