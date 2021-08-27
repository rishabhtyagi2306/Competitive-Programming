class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int n = nums1.size(), m = nums2.size(), i, j;
        int st = 0, end = n;
        while(st <= end)
        {
            int cut1 = (st + end)/2;
            int cut2 = (n + m + 1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == n ? INT_MAX : nums1[cut1];
            int right2 = cut2 == m ? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 && left2 <= right1)
            {
                if((n + m) % 2 == 0)
                {
                    return (double)(max(left1, left2) + 
                                    min(right1, right2))/2.0;
                }
                else
                {
                    return (double)max(left1, left2);
                }
            }
            else if(left1 > right2)
            {
                end = cut1-1;
            }
            else
            {
                st = cut1+1;
            }
        }
        
        return 0.0;
    }
};