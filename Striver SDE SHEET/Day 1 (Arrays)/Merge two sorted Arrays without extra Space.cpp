class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j;
        for(j = 0, i = m; j < n && i < n+m; j++, i++)
        {
            nums1[i] = nums2[j];
        }
        int gap = (n+m+1)/2;
        while(gap > 0)
        {
            i = 0;
            j = gap;
            while(j < n+m)
            {
                if(nums1[i] > nums1[j])
                    swap(nums1[i], nums1[j]);
                j++;
                i++;
            }
            if(gap == 1)
                break;
            gap = (gap + 1)/2;
        }
    }
};