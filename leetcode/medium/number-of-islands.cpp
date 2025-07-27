class Solution {
int visited[301][301]={0};
int direcx[4]={0,0,1,-1};
int direcy[4]={1,-1,0,0};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(visited[i][j]==0&&grid[i][j]-'0'==1){
                    ans++;
                    int sx=i;
                    int sy=j;
                    visited[sx][sy]=1;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int cx=q.front().first;
                        int cy=q.front().second;
                        q.pop();
                        for(int z=0;z<4;z++){
                            int dx=cx+direcx[z];
                            int dy=cy+direcy[z];

                            if(dx<0||dx>=grid.size()){
                                continue;
                            }
                             if(dy<0||dy>=grid[dx].size()){
                                continue;
                            }
                            if(grid[dx][dy]-'0'==0||visited[dx][dy]!=0){
                                continue;
                            }
                            q.push({dx,dy});
                            visited[dx][dy]=1;
                            
                        }

                    }

                }
                else{
                    continue;
                }
            }
        }
                return ans;
    };
};