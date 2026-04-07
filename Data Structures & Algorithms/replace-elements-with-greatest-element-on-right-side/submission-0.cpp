class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        if(size == 1) {
            arr = {-1};
            return arr;
        }
        else {
            int cur = -1;
            for(int i = size - 2; i >= 0; --i) {
                int temp = arr[i];
                arr[i] = max(arr[i+1], cur);
                cur = temp;
            }
        }
        arr[size - 1] = -1;
        return arr;
    }
};