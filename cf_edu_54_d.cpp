#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MAX = 1e18;
vector<vector<pair<ll,pair<ll,ll > > > > v(300005);
vector<vector<pair<ll,ll> > > veg(300005);
vector<ll> dis(300005);
vector<pair<ll,ll> > par(300005);
void dijsktra(ll n,ll s){
    priority_queue< pair<ll,ll> ,vector<pair<ll,ll> > ,greater< pair<ll,ll > > > q;
    for(int i=2;i<=n+1;i++){
        dis[i] = MAX;
        par[i] = make_pair(1,MAX);
    }
    q.push(make_pair(0,1));
    par[1] = make_pair(-1,-1);
    while(!q.empty()){
        ll u = q.top().second;
        ll ww = q.top().first;
        q.pop();
        // skip duplicate entry
        // LOL try removing next two line :D
        if(dis[u]<ww)
            continue;
        for(auto i : v[u]){
            ll vert = i.first;
            ll w = i.second.first;
            if(dis[vert]>dis[u]+w){
                dis[vert] = dis[u]+w;
                q.push(make_pair(dis[vert],vert));
                par[vert] = make_pair(u,i.second.second);
            }
        }
    }
    for(int i=2;i<=n;i++){
        ll x = i;
        ll y = par[i].first;
        ll num = par[i].second;
        veg[x].push_back(make_pair(y,num));
        veg[y].push_back(make_pair(x,num));
    }
}
bool visited[300005];
vector<ll> ans;
void dfs(ll s){
    visited[s] = 1;
    for(auto i:veg[s]){
        ll u = i.first;
        ll num = i.second;
        if(!visited[u]){
            ans.push_back(num);
            dfs(u);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,make_pair(z,i+1)));
        v[y].push_back(make_pair(x,make_pair(z,i+1)));
    }
    dijsktra(n,1);
    ll eg = min(k,n-1);
    cout<<eg<<endl;
    dfs(1);
    assert(ans.size()==n-1);
    for(int i=0;i<eg;i++)
        cout<<ans[i]<<" ";
    return 0;
}
