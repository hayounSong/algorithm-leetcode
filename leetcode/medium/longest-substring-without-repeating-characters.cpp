class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int size=s.size();
        int right=0;
        int ans=0;
        int scount[10001]={0};
        for(int right=0;right<size;right++){
            if(scount[s[right]]==0){
                scount[s[right]]++;
                ans=max(right-left+1,ans);
            }
            else{
                while(scount[s[right]]!=0){
                scount[s[left]]=scount[s[left]]-1;
                left++;
                }
                scount[s[right]]++;
            }
        }
        return ans;
    }
};