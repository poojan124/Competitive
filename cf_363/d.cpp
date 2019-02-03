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

vector<vector<int> > v(100005);
int n,m;

int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_index; 
    for(int v = 1; v <= n; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
  
    return min_index; 
} 
void primMST() 
{ 
    bool visi[n+1];  
    memset(visi,0,sizeof(visi));
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(1);
    while(!q.empty()) { 
        int u = q.top();
        q.pop();
        if(visi[u])
            continue;
        visi[u] = 1; 
        ans.push_back(u);
        trav(x,v[u]){
            if (!visi[x]){
                q.push(x);   
            }         
        }
    } 
    pv(ans);
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y;
    F0R(i,m){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    primMST();
    return 0;
}