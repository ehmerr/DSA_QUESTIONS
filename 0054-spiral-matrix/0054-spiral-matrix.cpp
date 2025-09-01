class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int startRow = 0;
        int endCol = m-1;
        int endRow = n-1;
        int startCol = 0;

         vector<int> ans;


//logic to solve the question

         //->loop to check if there are any pending element to print
         //if yes->4 steps-> startingRow print, endingCol print, endingRow print, startingCol print.

//1. Pushing all the starting row inside the ans



while(startRow<=endRow && startCol<=endCol){

if(startRow<=endRow){
for(int col = startCol;col<=endCol;col++){
    ans.push_back(matrix[startRow][col]);
}
startRow++;
}

if(startCol<=endCol){
for(int row= startRow;row<=endRow;row++){
    ans.push_back(matrix[row][endCol]);
}
endCol--;
}

if(startRow<=endRow){
for(int col = endCol;col>=startCol;col--){
    ans.push_back(matrix[endRow][col]);
}
endRow--;
}

if(startCol<=endCol){
for(int row= endRow;row>=startRow;row--){
    ans.push_back(matrix[row][startCol]);
}
startCol++;
}


}
return ans;
    }
};