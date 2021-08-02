class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int mid = 0, left = 0, right = n-1;
        
        // This is less than equal to right beacause of this case [2,0,1]
        while(mid <= right) 
        {
            if(a[mid] == 0)
            {
                swap(a[mid], a[left]);
                mid++;
                left++;
            }
            else if(a[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(a[mid], a[right]);
                right--;
            }
        }
    }
};