class Solution {
public:
    void solve(vector<int>& a, int n, int i, vector<int>& v,                                        vector<vector<int>>& ans)
    {
        ans.push_back(v);
        
        for(int j = i; j < n; j++)
        {
            if(j != i && a[j] == a[j-1])
            {
                continue;
            }
            v.push_back(a[j]);
            solve(a, n, j+1, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size(), i, j;
        vector<vector<int>> ans;
        vector<int> v;
        
        sort(nums.begin(), nums.end());
        solve(nums, n, 0, v, ans);
        
        return ans;
    }
};