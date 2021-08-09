class Solution {
public:
    int uniquePaths(int m, int n) {
        int r = min(n-1, m-1);
        int N = n + m - 2;
        double res = 1.0;
        int i;
        for(i = 1; i <= r; i++)
        {
            res = res * (N - r + i)/i;
        }
        
        return (int)res;
    }
};