class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1000000000;
        int mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            if(time(mid, piles) <= h) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }

    long long time(int k, const vector<int>& piles) {
        long long tot = 0;
        for(int pile:piles) {
            tot += pile / k;
            tot += pile % k != 0 ? 1 : 0;
        }
        return tot;
    }
};
