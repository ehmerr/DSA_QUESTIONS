class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
int rowsOrig = matrix.size();
int colsOrig = matrix[0].size();

int rowsTrans = colsOrig;
int colsTrans = rowsOrig;

   vector<vector<int>> transpose(rowsTrans, vector<int>(colsTrans,0));

for(int i=0;i<rowsTrans;i++){
    for(int j=0;j<colsTrans;j++){
        transpose[i][j] = matrix[j][i];
        }
    }
    return transpose;
}

};