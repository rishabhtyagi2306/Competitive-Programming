class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), i, j;
        
        if(n == 0)
        {
            return 0;
        }
        unordered_set<int> st;
        for(i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        int ans = 1;
        int cnt = 1;
        for(i = 0; i < n; i++)
        {
            if(st.find(nums[i]-1) == st.end())
            {
                int x = nums[i] + 1;
                while(st.find(x) != st.end())
                {
                    x++;
                    cnt++;
                }
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        
        return ans;
    }
};