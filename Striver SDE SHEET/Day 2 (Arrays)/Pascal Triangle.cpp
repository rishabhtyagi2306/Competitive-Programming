class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++)
        {
            vector<int> tmp;
            if(i == 1)
            {
                tmp.push_back(1);
            }
            else if(i == 2)
            {
                tmp.push_back(1);
                tmp.push_back(1);
            }
            else
            {
                tmp.push_back(1);
                for(int j = 1; j < ans[i-2].size(); j++)
                {
                    tmp.push_back(ans[i-2][j] + ans[i-2][j-1]);
                }
                tmp.push_back(1);
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
//     Space optimized code O(1) space.
//     void printPascal(int n)
//     {
//         for (int line = 1; line <= n; line++)
//         {
//             int C = 1; // used to represent C(line, i)
//             for (int i = 1; i <= line; i++)
//             {

//                 // The first value in a line is always 1
//                 cout<< C<<" ";
//                 C = C * (line - i) / i;
//             }
//             cout<<"\n";
//         }
//     }
};