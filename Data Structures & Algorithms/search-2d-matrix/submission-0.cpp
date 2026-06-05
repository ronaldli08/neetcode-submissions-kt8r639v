class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m - 1;
        int mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            if(matrix[mid][n-1] < target) {
                low = mid + 1;
            }
            else if(matrix[mid][0] > target){
                high = mid - 1;
            }
            else{
                break;
            }
        }
        int mI = low + (high - low) / 2;
        low = 0;
        high = n - 1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(matrix[mI][mid] == target) {
                return true;
            }
            else if(matrix[mI][mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
}; 