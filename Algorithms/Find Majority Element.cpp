/*
You have to given an array A of size N.
Find all the elements which appear more than floor(N/3) times in the given array.
Wait Wait!
There is a condition that you have to do your job in O(N) time complexity and O(1) space complexity.

Find Majority Elements
To solve this question in O(n) time complexity and O(1) space complexity, we use Moore’s Voting Algorithm.
This is a two-step process.
-> The first step gives the element that maybe the majority element in the array. If there is a majority element in an array, then this step will definitely return majority element, otherwise, it will return candidate for majority element.
-> Check if the element obtained from the above step is majority element. This step is necessary as there might be no majority element.
Algorithm:

Loop through each element and maintains a count of majority element, and a majority index, maj_index
If the next element is same then increment the count if the next element is not same then decrement the count.
If the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
Now again traverse through the array and find the count of majority element found.
If the count is greater than floor(N/3) then this element will be one of the majority elements.
Else print nothing.
Code: */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<=n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define AS 200001

vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    if(nums.size() == 0) return ans;
    int n = nums.size();

    int candidate1 = nums[0],count1=1;
    int candidate2 = 0,count2=0;
    for(int i=1;i<n;i++){
        if(candidate1 == nums[i]) count1++;
        else if(candidate2 == nums[i]) count2++;
        else if(count1 == 0){
            candidate1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0){
            candidate2 = nums[i];
            count2 = 1;
        }
        else{
            count2--;
            count1--;
        }
    }
    count1 = 0,count2 = 0;

    for(int i=0;i<n;i++){
        if(nums[i] == candidate1) count1++;
        else if(nums[i] == candidate2) count2++;
    }
    if(count1>n/3) ans.push_back(candidate1);
    if(count2>n/3) ans.push_back(candidate2);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;

    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    vector<int> ans = majorityElement(v);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }

    if(ans.size()==0)
    {
        cout<<"No Majority Elements";
    }
    cout<<endl;

    return 0;
}
