#include <iostream>
#include <queue>
using namespace std;

int field[17][17]={0};
int visited[17][17]={0};
int direcx[3]={0,1,1};
int direcy[3]={1,1,0};
int main(){
    ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>field[i][j];
        }
    }

    queue<pair<int,pair<int,pair<int,int>>>> q;
    q.push({0,{0,{0,1}}});
    int ans=0;
    while(!q.empty()){

        int cdirec=q.front().first;
        int ccount=q.front().second.first;
        int cx=q.front().second.second.first;
        int cy=q.front().second.second.second;
        if(cx==N-1&&cy==N-1){
            ans++;
        }
        q.pop();

        for(int i=0;i<3;i++){
            if(cdirec==0&&i==2){
                continue;
            }
            else if(cdirec==2&&i==0){
                continue;
            }

        if(i!=1){
        if(cx+direcx[i]>=N||cy+direcy[i]>=N){
            continue;
        }
        if(field[cx+direcx[i]][cy+direcy[i]]!=0){
            continue;
        }
        }
        else if(i==1){
         if(cx+direcx[0]>=N||cy+direcy[0]>=N){
            continue;
        }
         if(cx+direcx[1]>=N||cy+direcy[1]>=N){
            continue;
        }
         if(cx+direcx[2]>=N||cy+direcy[2]>=N){
            continue;
        }
          if(field[cx+direcx[0]][cy+direcy[0]]!=0){
            continue;
        }
        if(field[cx+direcx[1]][cy+direcy[1]]!=0){
            continue;
        }
        if(field[cx+direcx[2]][cy+direcy[2]]!=0){
            continue;
        }
        }

            int dx=cx+direcx[i];
            int dy=cy+direcy[i];
            if(dx>=N||dy>=N||field[dx][dy]!=0){
                continue;
            }
            else{
                visited[dx][dy]=ccount+1;
                q.push({i,{ccount+1,{dx,dy}}});
            }
        }
    }
    cout<<ans;
}