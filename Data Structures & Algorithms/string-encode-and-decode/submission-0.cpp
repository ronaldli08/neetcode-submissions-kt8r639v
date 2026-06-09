class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for(const auto& str:strs) {
            output += to_string(str.size());
            output += '|';
            output += str;
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        int i = 0;
        while (i < s.size()) {
            string num = "";
            while(s[i] != '|') {
                num += s[i];
                ++i;
            }
            ++i;
            string str = "";
            for(int j = 0; j < stoi(num); ++j) {
                str += s[i + j];
            }
            i += stoi(num);
            output.push_back(str);
        }
        return output;
    }
};
