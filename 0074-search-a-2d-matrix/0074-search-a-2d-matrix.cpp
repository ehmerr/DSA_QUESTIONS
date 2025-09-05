class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            // Implement the solution here
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        int end = rows*cols-1;

        while(start<=end){
            int mid = start+(end-start)/2;
            int rowmid = mid/cols;
            int colmid = mid%cols;

            if(matrix[rowmid][colmid]==target){
                return true;
            }      
            else if(matrix[rowmid][colmid]>target){
                end = mid - 1;
            }
            else{
                      start = mid + 1;
            }
        }
        return false;
    }
};