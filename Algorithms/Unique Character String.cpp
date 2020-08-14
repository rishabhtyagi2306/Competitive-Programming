//Ramu has an array of strings. He want to find a string s such that it is a concatenation of sub-sequence of given array and have unique characters.Since,he has just started coding so he needs your help.
//A sub-sequence of an array is a set of elements that can be obtained by deleting some elements(posssibly none) from the array and keeping the order same.
//Print the maximum possible length of s.


//Algorithm:
//1.We will solve this problem through recursion.
//
//2.So, iterate from left to right and try every string as a starting string.
//
//3.Keep a set of character that stores characters that have occurred till now.
//
//4.Once,you have selected a string as a starting string,now for every other string you have 2 options:
//
//a.To add that string(only if all its characters have not occurred before) and add its character to set of current characters.
//
//b.To leave that string
//
//5.Try the same for all string and finally return maximum of them.
//Code:



#include <bits/stdc++.h> 
using namespace std; 
#define li long long int 

bool check(string s){ 

   //checks if all character are unique or not. 

  set<char> a; 

  for(auto i : s){ 

    if(a.count(i)) 

        return false; 

    a.insert(i); 

      } 

  return true; 

  } 



vector<string> helper(vector<string>& arr, int ind){ 

      //base case when we reach end of array 

  if(ind == arr.size()) 

    return {""}; 



  //To try every string as a starting string and store its result. 

  vector<string> tmp = helper(arr, ind+1); 



  vector<string> ret(tmp.begin(), tmp.end()); 

  //add current string to result of other string and 

  //check if characters are unique after adding 

  for(auto i : tmp){ 

    string test = i+arr[ind]; 

      if(check(test)) 

          ret.push_back(test); 

        } 

      return ret; 

    } 


int maxLength(vector<string>& arr) { 

  vector<string> tmp = helper(arr, 0); 

  int len = 0; 

  //return max length possible. 

  for(auto i : tmp){ 

    len = len > i.size() ? len : i.size(); 

        } 

  return len; 

  } 





int main(){ 

//driver code 

  int n; 

  cin>>n; 

  vector<string>v; 

  for(int i=0;i<n;i++){ 

    string s; 

    cin>>s; 

    v.push_back(s); 

    } 



  cout << maxLength(v) << endl; 

 } 

Time Complexity: 2^n where n is the number of elements in the array.
