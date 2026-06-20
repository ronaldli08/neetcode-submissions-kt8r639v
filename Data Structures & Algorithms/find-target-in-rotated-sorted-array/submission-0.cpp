class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }
        int pivot = low;
        int left = binSearch(0, low - 1, nums, target);
        int right = binSearch(low, n - 1, nums, target);
        if(left != -1) {
            return left;
        }
        else return right;
    }
    int binSearch(int low, int high, vector<int>& nums, int target) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
