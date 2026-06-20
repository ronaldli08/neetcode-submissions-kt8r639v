class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n2 < n1) return false;
        vector<int> comp1(26, 0);
        vector<int> comp2(26, 0);
        for(char c:s1) {
            comp1[c - 'a']++;
        }
        for(int i = 0; i < n1; i++) {
            comp2[s2[i] - 'a']++;
        }
        if (comp1 == comp2) return true;
        int p = n1;
        while(p < n2) {
            comp2[s2[p] - 'a']++;
            comp2[s2[p - n1] - 'a']--;
            if (comp1 == comp2) return true;
            p++;
        }
        return false;
    }
};
