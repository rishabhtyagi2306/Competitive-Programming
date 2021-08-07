class Solution {
public:
    void Reverse(vector<int> &nums, int l, int r)
    {
        while(l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j, ind1 = -1, ind2 = -1;
        for(i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind1 = i;
                break;
            }
        }
        
        if(ind1 == -1)
        {
            reverse(nums.begin(), nums.end());
            // cout<<"retur \n";
            return ;
        }
        
        for(i = n-1; i >= ind1; i--)
        {
            if(nums[i] > nums[ind1])
            {
                ind2 = i;
                break;
            }
        }
        // cout<<ind1<<" "<<ind2<<endl;
        if(ind2 != -1)
            swap(nums[ind1], nums[ind2]);
        Reverse(nums, ind1+1, n-1);
    }
};