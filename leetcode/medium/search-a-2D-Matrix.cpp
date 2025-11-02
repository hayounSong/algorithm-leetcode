class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool ans=false;
        for(int i=0;i<m;i++){
            if(i==0){
                if(target<=matrix[i][n-1]){
                    for(int j=0;j<n;j++){
                        if(target==matrix[i][j]){
                            ans=true;
                            return ans;
                        }
                    }
                    return ans;
                }
            }
                else{
                    if(target>matrix[i-1][n-1]&target<=matrix[i][n-1]){
                        for(int j=0;j<n;j++){
                            if(target==matrix[i][j]){
                                ans=true;
                                return ans;
                        }
                    }
                    return ans;
                    }
                }
            }
        return ans;
    }
};