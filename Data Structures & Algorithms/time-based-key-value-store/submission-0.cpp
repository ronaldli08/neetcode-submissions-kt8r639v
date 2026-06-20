class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tm;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }

    static bool customSort(const pair<int, string> &a, const pair<int, string> &b) {
        return a.first < b.first;
    }
    
    string get(string key, int timestamp) {
        int n = tm[key].size();
        int low = 0;
        int high = n - 1;
        auto itr = upper_bound(tm[key].begin(), tm[key].end(), pair<int, string>{timestamp, ""}, customSort);

        if (itr == tm[key].begin()) {
            return "";
        }
        else {
            itr--;
            return itr->second;
        }






    }
};
