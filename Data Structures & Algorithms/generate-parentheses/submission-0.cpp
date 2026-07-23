class Solution {
public:
    vector<string> output;
    vector<string> generateParenthesis(int n) {
        string s = "";
        parenth(0, 0, n, s);
        return output;
    }

    void parenth(int open, int close, int n, string& cur) {
        if((int)cur.size() == n * 2) {
            output.push_back(cur);
            return;
        }

        if(open < n) {
            open++;
            cur += '(';
            parenth(open, close, n, cur);
            cur.pop_back();
            open--;
        }

        if(close < open) {
            close++;
            cur += ')';
            parenth(open, close, n, cur);
            cur.pop_back();
            close--;
        }
    }
};
