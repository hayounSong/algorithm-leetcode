#include<iostream>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    int n,k;
     void backtrack(int cnum,int ccount,vector<int> v){
        if(cnum>n&&v.size()<k){
            return;
        }
        cout<<cnum;
        if(v.size()==k){
            cout<<cnum;            
            ans.push_back(v); 
            return;
        }
        for(int i=cnum;i<=n;i++){
            v.push_back(i);
            backtrack(i+1,ccount,v);
            v.pop_back();

        }
    }
public:
    vector<vector<int>> combine(int N, int K) {
    n=N;
    k=K;
    vector<int> v;
    backtrack(1,0,v);
    return ans;
    }
};