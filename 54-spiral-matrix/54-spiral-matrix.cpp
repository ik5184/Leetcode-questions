class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int count=0;
        int startrow=0;
        int startcol=0;
        int endingrow=row-1;
        int endingcol=col-1;
        
        while(count < total){
            
            for(int index=startcol;count < total && index<=endingcol;index++){
                ans.push_back(matrix[startrow][index]);
                count++;
            }
            startrow++;
            
            
            for(int index=startrow;count < total && index<=endingrow;index++){
                ans.push_back(matrix[index][endingcol]);
                count++;

                
            }
            endingcol--;
            
            for(int index=endingcol;count < total && index>=startcol;index--){
                ans.push_back(matrix[endingrow][index]);
                count++;

             }
            endingrow--;
            for(int index=endingrow;count < total && index>=startrow;index--){
                ans.push_back(matrix[index][startcol]);
                count++;
            
             }
            startcol++;
            
         }
        return ans;
    }
};