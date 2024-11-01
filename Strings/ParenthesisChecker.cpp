#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    /*
    Function to check if parentheses/brackets/braces are balanced
    Returns: true if balanced, false otherwise
    
    Dry Run Example with s = "{[()]}"
    -----------------------------
    i=0: char='{'  → stack: {
    i=1: char='['  → stack: { [
    i=2: char='('  → stack: { [ (
    i=3: char=')'  → stack: { [    (matches with '(', so pop)
    i=4: char=']'  → stack: {      (matches with '[', so pop)
    i=5: char='}'  → stack: empty  (matches with '{', so pop)
    Stack is empty → Return true
    */
    bool isParenthesisBalanced(string& s) {
        // Stack to store opening brackets
        stack<char> st;
        
        // Iterate through each character in string
        for(int i = 0; i < s.size(); i++) {
            // If current character is an opening bracket
            // push it to stack
            if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
            }
            // If current character is a closing bracket
            else if(s[i] == ']' || s[i] == '}' || s[i] == ')') {
                // If stack is empty, means we found closing bracket
                // without matching opening bracket
                if(st.empty()) return false;
                
                // Check if current closing bracket matches with
                // the last opening bracket in stack
                if((s[i] == ']' && st.top() != '[') ||
                   (s[i] == '}' && st.top() != '{') ||
                   (s[i] == ')' && st.top() != '(')) {
                    return false;
                }
                
                // If brackets match, remove the opening bracket from stack
                st.pop();
            }
        }
        
        // Stack should be empty if all brackets are matched
        // If not empty, we have extra opening brackets
        return st.empty();
    }
};

/*
More Test Cases:
---------------
1. "()"      → true
   i=0: char='('  → stack: (
   i=1: char=')'  → stack: empty  → true

2. "([)]"    → false
   i=0: char='('  → stack: (
   i=1: char='['  → stack: ( [
   i=2: char=')'  → stack: ( [    → false (')' doesn't match with '[')

3. "{{"      → false
   i=0: char='{'  → stack: {
   i=1: char='{'  → stack: { {
   End: stack not empty → false (extra opening brackets)

4. "}{"      → false
   i=0: char='}'  → stack: empty  → false (no opening bracket)
*/