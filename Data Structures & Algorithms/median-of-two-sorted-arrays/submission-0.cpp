class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int half = (n1 + n2 + 1) / 2;

        int low = 0;
        int high = n1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int inverse = half - mid;

            int l1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int l2 = (inverse == 0) ? INT_MIN : nums2[inverse - 1];
            int r1 = (mid == n1) ? INT_MAX : nums1[mid];
            int r2 = (inverse == n2) ? INT_MAX : nums2[inverse];

            if(l1 <= r2 && l2 <= r1) {
                if((n1 + n2) % 2 == 1) {
                    return max(l1, l2);
                }
                else {
                    return ((double)(max(l1, l2)) + 
                            min(r1, r2)) / 2.0;
                }
                }
            else if(l1 > r2) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return 0;
    }
};
