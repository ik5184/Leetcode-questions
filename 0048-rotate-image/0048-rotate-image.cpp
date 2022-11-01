class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size=matrix.size();
        
        
        // this code is for transpose the matrix
        for(int i=0;i<size;i++){
            for(int j=i;j<size;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
        //this code fro swap the column
        for(int i=0;i<size;i++){
            for(int j=0;j<size/2;j++){
               int temp=matrix[i][j];
                matrix[i][j]=matrix[i][size-1-j];
                matrix[i][size-1-j]=temp;
            }
        }
    }
};