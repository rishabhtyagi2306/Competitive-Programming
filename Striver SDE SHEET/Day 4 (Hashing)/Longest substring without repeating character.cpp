class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cnt;
        int n = s.size(), i, j;
        i = j = 0;
        int ans = 0;
        while(i < n)
        {
            cnt[s[i]]++;
            if(cnt.size() == (i-j+1))
            {
                ans = max(ans, i-j+1);
            }
            else
            {
                while(cnt.size() < (i - j + 1))
                {
                    cnt[s[j]]--;
                    if(cnt[s[j]] == 0)
                        cnt.erase(s[j]);
                    j++;
                }
            }
            i++;
        }
        
        return ans;
    }
};