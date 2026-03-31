class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        int x;int n; int i;  int j;
        n=matrix.size()*matrix[0].size();
        x=0;

        while(vec.size()<n){
        
        i=x;
        for(j=x;j<matrix[0].size()-x;j++){ vec.push_back(matrix[i][j]); } j--;
        
        for(i=x+1;i<matrix.size()-x;i++){vec.push_back(matrix[i][j]);}  i--;j--;
        if(vec.size()==n){return vec;}
        for(j=(matrix[0].size()-1)-x-1;j>=x;j--){vec.push_back(matrix[i][j]);}j++;
        
        for(i=(matrix.size()-1)-1-x;i>=x+1;i--){vec.push_back(matrix[i][j]);} 
        
        x++;
        }
        return vec;
    }

};
