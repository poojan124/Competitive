#include<bits/stdc++.h>
using namespace std;
int n,m;
bool visited[105][105];
char a[105][105];
void solve(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return;
    if(a[i][j] == '.' || visited[i][j])
        return;
    visited[i][j]  = true;
    solve(i-1,j);
    solve(i,j-1);
    solve(i+1,j);
    solve(i,j+1);
    // solve(i-1,j-1);
    // solve(i+1,j+1);
    // solve(i-1,j+1);
    // solve(i+1,j-1);
}
int main(){
    scanf("%d%d",&n,&m);
    memset(visited, false, sizeof(visited));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && a[i][j] == '#'){
                solve(i,j);
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}