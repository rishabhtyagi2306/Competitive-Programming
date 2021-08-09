class Solution {
public:
    double power(double x, long long n)
    {
        double ans = 1;
        while(n > 0)
        {
            if(n % 2 == 0)
            {
                x *= x;
                n /= 2;
            }
            else
            {
                ans *= x;
                n -= 1;
            }
        }
        return ans;
    }
    double myPow(double x, int n) {
        double ans = power(x, abs(n));
        if(n < 0)
        {
            ans = 1.00/ans;
        }
        
        return ans;
    }
};