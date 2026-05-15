class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char c:s) {
            if(c == '(' || c == '{' || c == '['){
                brackets.push(c);
            }
            else if(c == ')') {
                if(!brackets.empty() && brackets.top() == '(') {
                    brackets.pop();
                }
                else {
                    return false;
                }
            }
            else if(c == '}') {
                if(!brackets.empty() && brackets.top() == '{') {
                    brackets.pop();
                }
                else {
                    brackets.pop();
                    return false;
                }
            }
            else if(c == ']') {
                if(!brackets.empty() && brackets.top() == '[') {
                    brackets.pop();
                }
                else {
                    return false;
                }
            }
        }
        if(!brackets.empty()) {
            return false;
        }
        return true;
    }
};
