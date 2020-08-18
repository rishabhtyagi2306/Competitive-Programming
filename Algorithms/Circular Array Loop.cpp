//You are given an array of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.
//
//Determine if there is a loop (or a cycle) in array. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements. Print 1 if cycle present else print 0.

//Sample Input
//5
//2 -1 1 2 2
//Sample Output
//1

// this problem can be solved using slow and fast pointers.



#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int next(vector<int>& nums, int i){
      int n = nums.size();
      return (n+nums[i]+i)%n;
   }
   bool circularArrayLoop(vector<int>& nums) {
      int n = nums.size();
      if(n < 2) return false;
      for(int i = 0; i < n; i++)nums[i] %= n;
      for(int i = 0; i < n; i++){
         if(nums[i] == 0) continue;
         int slow = i;
         int fast = i;
         while(nums[slow] * nums[fast] > 0 && nums[next(nums, fast)] * nums[slow] > 0){
            slow = next(nums, slow);
            fast = next(nums, next(nums, fast));
            if(slow == fast){
               if(slow == next(nums, slow))
               break;
               return true;
            }
         }
         int x = nums[i];
         slow = i;
         while(nums[slow] * x > 0){
            int temp = next(nums, slow);
            nums[slow] = 0;
            slow = temp;
         }
      }
      return false;
   }
};
main(){
   vector<int> v = {2,-1,1,2,2};
   Solution ob;
   cout << (ob.circularArrayLoop(v));
}



