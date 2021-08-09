class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), i, j;
        int m = matrix[0].size();
        i = 0; j = m-1;
        while(i < n && j >= 0)
        {
            if(matrix[i][j] < target)
            {
                i++;
            }
            else if(matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        while(i < n)
        {
            if(matrix[i][0] == target)
                return true;
            i++;
        }
        while(j >= 0)
        {
            if(matrix[n-1][j] == target)
                return true;
            j--;
        }
        return false;
    }
};