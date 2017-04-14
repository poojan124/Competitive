#include<bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int v[200005];
int max1,min1,all_max,cntr;
void dfs(int s,int a[],int cnt[]){
    if(!v[s]){
        cnt[a[s]]++;
        cntr++;
        all_max=max(all_max,cnt[a[s]]);
        v[s]=1;
        for(vector<int> :: iterator it=g[s].begin();it!=g[s].end();it++){
            dfs(*it,a,cnt);
        }
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int cnt[k+2];
    int a[n+2];
    int ans=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int sos=0;
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++){
            if(sos==n)
                break;
            all_max=0,cntr=0;
            memset(cnt,0,sizeof(cnt));
            if(!v[i]){
                dfs(i,a,cnt);
                ans+=cntr-all_max;
            }
            sos+=cntr;
    }
    cout<<ans<<endl;
}
