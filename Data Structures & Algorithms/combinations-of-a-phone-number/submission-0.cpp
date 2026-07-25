class Solution {
public:
    vector<string> output;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string cur;
        dfs(digits, 0, cur);
        return output;
    }

    void dfs(string& digits, int i, string& cur) {
        if(i == digits.size()) {
            output.push_back(cur);
            return;
        }
        switch(digits[i] - '0'){
            case 2:
                cur += 'a';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'b';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'c';
                dfs(digits, i+1, cur);
                cur.pop_back();
                break;
            case 3:
                cur += 'd';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'e';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'f';
                dfs(digits, i+1, cur);
                cur.pop_back();
                break;
            case 4:
                cur += 'g';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'h';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'i';
                dfs(digits, i+1, cur);
                cur.pop_back();
                break;
            case 5:
                cur += 'j';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'k';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'l';
                dfs(digits, i+1, cur);
                cur.pop_back();
                break;
            case 6:
                cur += 'm';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'n';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'o';
                dfs(digits, i+1, cur);
                cur.pop_back();
                break;
            case 7:
                cur += 'p';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'q';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'r';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 's';
                dfs(digits, i+1, cur);
                cur.pop_back();
                break;
            case 8:
                cur += 't';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'u';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'v';
                dfs(digits, i+1, cur);
                cur.pop_back();
                break;
            case 9:
                cur += 'w';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'x';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'y';
                dfs(digits, i+1, cur);
                cur.pop_back();
                cur += 'z';
                dfs(digits, i+1, cur);
                cur.pop_back();
                break;
        }
    }
};
