class Solution {
public:
    
    struct tri{
        int s, e, p;
    };
    
    static bool comp(tri a, tri b)
    {
        return a.e <= b.e;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(), i, j;
        tri a[n];
        
        for(i = 0; i < n; i++)
        {
            a[i].s = startTime[i];
            a[i].e = endTime[i];
            a[i].p = profit[i];
        }
        
        sort(a, a+n, comp);
        
        int dp[n];
        memset(dp, 0, sizeof(dp));
        
        for(i = 0; i < n; i++)
        {
            cout<<a[i].s<<" "<<a[i].e<<" "<<a[i].p<<endl;
        }
        
        dp[0] = a[0].p;
        i = 1;
        while(i < n)
        {
            int start = 0, end = i-1;
            int ind = -1;
            while(start <= end)
            {
                int mid = (start + end) / 2;
                if(a[mid].e <= a[i].s)
                {
                    ind = mid;
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            if(ind != -1)
                dp[i] = max(dp[i-1], dp[ind] + a[i].p);
            else
                dp[i] = max(dp[i-1], a[i].p);
            i++;
        }
        
        int ans = *max_element(dp, dp+n);
        
        return ans;
        
    }
};