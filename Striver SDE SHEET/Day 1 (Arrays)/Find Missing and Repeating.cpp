class Solution{
public:
    int *findTwoElement(int *a, int n) {
        
        int tmp = 0, i, j;
        for(i = 1; i <= n; i++)
        {
            tmp ^= a[i-1];
            tmp ^= i;
        }
        
        int *ans = new int(2);
        
        int bit = tmp & ~(tmp - 1);
        ans[0] = ans[1] = 0;
        for(i = 0; i < n; i++)
        {
            if(a[i] & bit)
                ans[0] ^= a[i];
            else
                ans[1] ^= a[i];
        }
        
        for(i = 1; i <= n; i++)
        {
            if(i & bit)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }
        for(i = 0; i < n; i++)
        {
            if(a[i] == ans[1])
            {
                swap(ans[1], ans[0]);
                break;
            }
        }
        
        return ans;
    }
};