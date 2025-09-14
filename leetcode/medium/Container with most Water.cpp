class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int i=0;
        int j=n-1;
        while(true){
            if(i>=j){
                break;
            }
           int temp=(j-i)*min(height[i],height[j]);
           if(temp>ans){
            ans=temp;
           }
           if(height[i]<height[j]){
                i++;
           }
           else{
            j=j-1;
           } 
        }
        return ans;
    }
};