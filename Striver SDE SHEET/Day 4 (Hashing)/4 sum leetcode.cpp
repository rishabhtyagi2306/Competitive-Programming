class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(), i, j, k, l;
        vector<vector<int>> ans;
        vector<int> tmp(4);
        sort(nums.begin(), nums.end());
        for(auto j : nums)
            cout<<j<<" ";
        cout<<endl;
        for(i = 0; i < n; )
        {
            for(j = i+1; j < n; )
            {
                long long sum = nums[i] + nums[j];
                k = j+1;
                l = n-1;
                while(k < l)
                {
                    long long sol = sum + nums[k] + nums[l];
                    if(sol < target)
                    {
                        k++;
                    }
                    else if(sol > target)
                    {
                        l--;
                    }
                    else
                    {
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[k];
                        tmp[3] = nums[l];
                        ans.push_back(tmp);
                        int prev = nums[k];
                        while(k < l && nums[k] == prev)
                        {
                            k++;
                        }
                        prev = nums[l];
                        while(l > k && nums[l] == prev)
                        {
                            l--;
                        }
                    }
                }
                int prev = nums[j];
                while(j < n && nums[j] == prev)
                {
                    j++;
                }
            }
            int prev = nums[i];
            while(i < n && prev == nums[i])
            {
                i++;
            }
        }
        
        return ans;
    }
};