// more than n/3
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), i, j;
        int cntf = 0, cnts = 0, f = INT_MAX, s = INT_MAX;
        for(i = 0; i < n; i++)
        {
            if(nums[i] == f)
                cntf++;
            else if(nums[i] == s)
                cnts++;
            else if(cntf == 0)
            {
                f = nums[i];
                cntf = 1;
            }
            else if(cnts == 0)
            {
                s = nums[i];
                cnts = 1;
            }
            else
            {
                cntf--;
                cnts--;
            }
        }
        
        cntf = cnts = 0;
        for(i = 0; i < n; i++)
        {
            if(nums[i] == f)
                cntf++;
            if(nums[i] == s)
                cnts++;
        }
        vector<int> ans;
        if(cntf > n/3)
            ans.push_back(f);
        if(cnts > n/3)
            ans.push_back(s);
        
        return ans;
    }
};


// more than n/2 
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size(), i, j;
        int cnt = 1, ind = 0;
        for(i = 1; i < n; i++)
        {
            if(nums[ind] == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if(cnt == 0)
            {
                ind = i;
                cnt = 1;
            }
        }
        
        cnt = 0;
        for(i = 0; i < n; i++)
        {
            if(nums[ind] == nums[i])
                cnt++;
        }
        
        if(cnt > n/2)
            return nums[ind];
        return 0;
    }
}; 