class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        //we are creating a matrix which will have rows equal to the columns of original matrix and columns equal to the rows of original matrix

        //rows in the original matrix
        int rowsOriginal = matrix.size();
        int colsOriginal = matrix[0].size();

        int rowsTranspose = colsOriginal;
        int colsTranspose = rowsOriginal;

        //initialising the transpose matrix
        vector<vector<int>> transpose(rowsTranspose,vector<int>(colsTranspose,0));

        for(int i=0;i<rowsTranspose;i++){
            for(int j=0;j<colsTranspose;j++){
                transpose[i][j]=matrix[j][i];
            }
        }
        return transpose;
        
    }
};