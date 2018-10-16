#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
int n,m;
int ans = 0;
char c[2000+5][2000+5];
bool visited[2000+5][2000+5];
void bfs(int x1,int y1,int l1,int r1){
    deque<pair<pii,pii>> q;
    q.push_back(mp(mp(x1,y1),mp(l1,r1)));
    visited[x1][y1] = 1;   
    ans++;
    while(!q.empty()){
        pair<pii,pii> p;
        p = q.front();
        q.pop_front();
        int x=p.first.first,y=p.first.second,l=p.second.first,r=p.second.second;
        // cout<<"FOR "<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
        if(x && c[x-1][y] == '.' && !visited[x-1][y]){
            visited[x-1][y]=1;ans++;
            q.push_front(mp(mp(x-1,y),mp(l,r)));
        }
        if(x+1 < n && c[x+1][y] == '.' && !visited[x+1][y]){
            visited[x+1][y]=1;ans++;
            q.push_front(mp(mp(x+1,y),mp(l,r)));
        }
        if(y && l && c[x][y-1] == '.' && !visited[x][y-1]){
            visited[x][y-1]=1;ans++;
            q.push_back(mp(mp(x,y-1),mp(l-1,r)));
        }
        if(y+1 < m && r && c[x][y+1] == '.' && !visited[x][y+1]){
            visited[x][y+1]=1;ans++;
            q.push_back(mp(mp(x,y+1),mp(l,r-1)));
        }
    }
}
int main(){
    memset(visited,0,sizeof(visited));
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    int l,r;
    cin>>l>>r;
    for(int i=0;i<n;i++)
        cin>>c[i];
    bfs(x-1,y-1,l,r);
    cout<<ans<<endl;
    return 0;
}