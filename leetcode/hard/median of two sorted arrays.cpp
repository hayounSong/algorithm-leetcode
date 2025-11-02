class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int asize=nums1.size();
        int bsize=nums2.size();
        double total=asize+bsize;
        int a=0;
        int b=0;

        int prev=0;
        int cur=0;
        for(int i=0;i<=total/2;i++){
            prev=cur;
            if(a>=asize){
                cur=nums2[b];
                b=b+1;
            }
            else if(b>=bsize){
                cur=nums1[a];
                a=a+1;
            }
            else{
                if(nums1[a]<nums2[b]){
                cur=nums1[a];
                a=a+1;
                }
                else{
                cur=nums2[b];
                b=b+1;
                }
            }
        }
        if((asize+bsize)%2==1){
            return cur;
        }
        else{
            return (cur+prev)/2.0;
        }
    }
};