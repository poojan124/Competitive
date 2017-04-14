#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int dis[200005];
vector<int> v[200005];
map<int,int> ch;
int find(int a){
    if(dis[a]==a)
        return a;
    return dis[a]=find(dis[a]);
}
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[n+2];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dis[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        int x=find(a);
        int y=find(b);
        if(x!=y){
            dis[x]=y;
        }
    }
    for(int i=1;i<=n;i++){
        v[find(i)].push_back(a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v[i].size()<=1)
            continue;
        int max_cur=0,cntr=0;
        ch.clear();
        for(int c=0;c<v[i].size();c++){
            ch[v[i][c]]++;
            max_cur=max_cur>ch[v[i][c]]?max_cur:ch[v[i][c]];
            cntr++;
        }
        ans+=cntr-max_cur;
    }
    cout<<ans<<endl;
    return 0;
}
