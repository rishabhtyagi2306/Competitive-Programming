class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size(), i, j;
        int ans = 0;
        int lf = 0, rg = 0;
        i = 0, j = n-1;
        while(i <= j)
        {
            if(a[i] <= a[j])
            {
                if(lf <= a[i])
                    lf = a[i];
                else
                    ans += lf - a[i];
                i++;
            }
            else
            {
                if(rg <= a[j])
                    rg = a[j];
                else
                    ans += rg - a[j];
                j--;
            }
        }
        
        return ans;
    }
};