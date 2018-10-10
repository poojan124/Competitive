#include<bits/stdc++.h>
using namespace std;
int v[100005]={0},cnt=0;
vector<int> g[100005];
void dfs(int i){
    if(v[i]!=1){
        cnt++;
        v[i]=1;
        for_each(g[i].begin(),g[i].end(),dfs);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    long long int ans=0;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back( y );
        g[y].push_back( x );
    }
    vector< int> an;
    long long int s=0,c_1=0;
    for(int i=0;i<n;i++){
        if(v[i]!=1){
            cnt=0;
            dfs(i);
            if(cnt>1){
                s+=cnt;
                an.push_back(cnt);
            }
            else
                c_1++;
            //cout<<cnt<<endl;
        }
    }
    for(int i=0;i<an.size()-1;i++){
        s-=an[i];
        ans+=(an[i]*(s+c_1));
    }
    s-=an[an.size()-1];
    ans+=(an[an.size()-1]*(s+c_1));
    ans+= ((c_1*(c_1 - 1))/2);
    cout<<ans;
    return 0;
}
