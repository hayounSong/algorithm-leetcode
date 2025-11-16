class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=nums.size();
        int left=0;
        int ans=999999999;
        int sum=0;
        for(int right=0;right<len;right++){
            sum=sum+nums[right];
            while(sum>=target){
                ans=min(ans,right-left+1);
                sum=sum-nums[left];
                left++;
            }
        }
        if(ans==999999999){
            return 0;
        }
        return ans;
    }
};