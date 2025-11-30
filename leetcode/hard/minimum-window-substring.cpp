class Solution {
public:
    string minWindow(string s, string t) {
        int tsize=t.size();
        int scount[300]={0};
        int anscount[300]={0};
        for(int i=0;i<tsize;i++){
            anscount[t[i]]++;
        }
        int anssize=9999999;
        string ans="";
        int left=0;
        int right=0;
        for(int right=0;right<s.size();right++){
            if(anscount[s[right]]!=0){
                scount[s[right]]++;
                while(left<=right&&right+2-left>=tsize){
                    int isans=1;
                    for(int i=65;i<123;i++){
                        if(scount[i]<anscount[i]&&anscount[i]!=0){
                            isans=0;
                            break;
                        }
                    }
                    if(isans==1){
                        if(anssize>right+2-left){
                            string tans="";
                            for(int i=left;i<=right;i++){
                                tans+=s[i];
                            }
                            ans=tans;
                            anssize=right+2-left;
                        }
                        scount[s[left]]--;
                        left++;
                        while(left<right){
                            if(scount[s[left]]-1<anscount[s[left]]&&anscount[s[left]]!=0){
                                break;
                            }
                            else{                       
                                scount[s[left]]--;
                                left++;
                            }
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};