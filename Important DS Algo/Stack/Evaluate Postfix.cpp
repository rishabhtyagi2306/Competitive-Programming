
// C++ program to evaluate value of 
// a postfix expression 

#include <iostream> 
#include <string.h> 
#include<stack>

using namespace std;


// Function that returns the value of a 
// given postfix expression 
int evaluatePostfix(char* exp) 
{ 
    // Create a stack 
    stack<int> st;
    
    int i; 

    // Scan all characters one by one 
    for (i = 0; exp[i]; ++i) 
    { 
        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        if (isdigit(exp[i])) 
            st.push(exp[i] - '0'); 

        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = st.top();
            st.pop();
            
            int val2 = st.top();
            st.pop();
            
            switch (exp[i]) 
            { 
                case '+': st.push(val2 + val1); break; 
                case '-': st.push(val2 - val1); break; 
                case '*': st.push(val2 * val1); break; 
                case '/': st.push(val2/val1); break; 
            } 
        } 
    } 
    
    return st.top(); 
} 

// Driver Code 
int main() 
{ 
    char exp[] = "231*+9-"; 
    cout<<"postfix evaluation: "<< evaluatePostfix(exp); 
    return 0; 
} 
