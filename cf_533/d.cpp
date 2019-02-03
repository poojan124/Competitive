// just ignore this

#include<bits/stdc++.h>
using namespace std;    
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
#define PI 3.1415926535897932384626433832795
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define trav(x,v) for (auto &x : v)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;
bool flag = false;
char grid[1001][1001];
int covered[11];
int n,m,p;
int visi[1001][1001];
vector<vector<pi> > ending(11);
int capa[11];
void dfs(int x,int y,int cnt,int who){
    cout<<"inf";
    if(x<0 || x>=n || y>=m || y<=0 )
        return;
    if(visi[x][y]!=0 || visi[x][y] != '.')
        return;
    if(visi[x][y]!=who)
        return;
    visi[x][y] = who;
    if(cnt==0){
        ending[who].pb(mp(x,y));
        return;
    }
    dfs(x+1,y,cnt-1,who);
    dfs(x,y+1,cnt-1,who);
    dfs(x-1,y,cnt-1,who);
    dfs(x,y-1,cnt-1,who);
}
bool check(){
    F0R(i,11){
        if(ending[i].size()!=0)
            return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cin>>n>>m>>p;
    vector<pi> ow(p);
    F0R(i,n){
        F0R(j,m){
            cin>>grid[i][j];
            if(grid[i][j]!='.' || grid[i][j]!='#'){
                ow[grid[i][j]-'0'] = mp(i,j);
                visi[i][j] = grid[i][j]-'0';
            }
            else{
                visi[i][j] = 0;
            }
        }
    }
    F0R(i,p){
        cin>>capa[i+1];
    }
    F0R(i,p){
        dfs(ow[i+1].F,ow[i+1].F,capa[i+1],i+1);
    }
    while(check()){
        FOR(i,1,p+1){
            trav(xx,ending[i]){
                dfs(xx.F,xx.S,capa[i],i);
            }
        }
        F0R(i,11){
            ending[i].clear();
        }
    }  
    int cntr[p+1];
    memset(cntr,0,sizeof(cntr));
    F0R(i,n){
        F0R(j,m)
            cntr[visi[i][j]]++;
    }
    FOR(i,1,p+1) cout<<cntr[i]<<" ";
    return 0;
}