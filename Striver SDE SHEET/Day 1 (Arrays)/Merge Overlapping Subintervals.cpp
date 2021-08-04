class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i, j, n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;
        
        for(i = 1; i < n; i++)
        {
            if(end >= intervals[i][0])
            {
                end = max(intervals[i][1], end);
            }
            else
            {
                ans.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({st, end});
        
        return ans;
    }
};