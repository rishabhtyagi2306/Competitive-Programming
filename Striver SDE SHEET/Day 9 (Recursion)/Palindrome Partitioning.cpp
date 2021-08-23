class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(string& s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        
        return true;
    }
    
    void solve(string& s, int ind, int n, vector<string>& v)
    {
        if(ind == n)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i = ind; i < n; i++)
        {
            if(isPalindrome(s, ind, i))
            {
                v.push_back(s.substr(ind, i - ind + 1));
                solve(s, i+1, n, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size(), i, j;
        vector<string> v;
        solve(s, 0, n, v);
        
        return ans;
    }
};