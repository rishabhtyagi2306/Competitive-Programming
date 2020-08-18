//The heights of certain Buildings which lie adjacent to each other are given. Light starts falling from left side of the buildings. If there is a building of certain Height, all the buildings to the right side of it having lesser heights cannot see the sun . The task is to find the total number of such buildings that receive light.



//Time Complexity: Time complexity of this solution is O(1).
//
//Algorithm: we can solve the problem by checking if the height of a particular building is greater than the height of all buildings on its left then it will receive sunlight. The steps to solve the problem are:
//
//Step 1:Initialize a variable t (int t denoting number of test cases) and for t cases initialize variables int n,curmax=INTMIN,res=0.
//
//Step 2: Using loop from i=0 till i<n take ‘n’ number of buildings and on getting each building compare it with the curmax if curmax<=num then increment res by 1 and update cur_max equal to num.
//
//Step 3: When i=n print the res.
//
// 
//  
#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,cur_max=INT_MIN,res=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            if(num>=cur_max){
                res++;
                cur_max=num;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
 
