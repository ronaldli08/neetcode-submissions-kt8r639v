class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> expression;
        int result;

        for(string token:tokens) {
            if(token == "+" || 
                token == "-" || 
                token == "*" || 
                token == "/") {
                    string a = expression.top();
                    expression.pop();
                    string b = expression.top();
                    expression.pop();
                    if(token == "+") {
                        result = stoi(a) + stoi(b);
                    }
                    else if(token == "-") {
                        result = -stoi(a) + stoi(b);
                    }
                    else if(token == "*") {
                        result = stoi(a) * stoi(b);
                    }
                    else if(token == "/") {
                        result = stoi(b) / stoi(a);
                    }
                    expression.push(to_string(result));
                }
            else expression.push(token);
        }
        return stoi(expression.top());
    }
};
