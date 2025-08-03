class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            int checkin=0;
            for(int i=0;i<wordList.size();i++){
                if(endWord==wordList[i]){
                    checkin=1;
                    break;
                }
            }
            if(checkin==0){
                return 0;
            }
            int visited[5001]={0};
            queue<pair<string,int>> q;
            q.push({beginWord,0});
            while(!q.empty()){
                string cword=q.front().first;
                int ccount=q.front().second;
                q.pop();
                if(cword==endWord){
                    return ccount+1;
                    break;
                }
                vector<int> rem;
                cout<<cword<<"\n";
                for(int i=0;i<wordList.size();i++){
                    string dword=wordList[i];
                    if(wordList[i]==cword){
                        continue;
                    }
                    // if(visited[i]!=0&&visited[i]<ccount+1){
                    //     continue;
                    // }
                    int diffcount=0;
                    
                    for(int j=0;j<dword.length();j++){
                        if(dword[j]!=cword[j]){
                            diffcount++;
                        }
                        if(diffcount>=2){
                            break;
                        }
                    }
                    if(diffcount>=2){
                        continue;
                    }
                    visited[i]=ccount+1;
                    q.push({wordList[i],ccount+1});
                    rem.push_back(i);
                }
                sort(rem.begin(),rem.end(),greater<int>());
                for(int i=0;i<rem.size();i++){
                    // cout<<wordList[rem[i]+"\n";
                    wordList.erase(wordList.begin()+rem[i]);
                }
            }
            return 0;
    }
};