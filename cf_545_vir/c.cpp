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
vector<vector<int > > v(100005);
vector<ll > op;
int visi[100005][52];
bool SEEN[100005];
int cnt = 0;
int n,m,d,x,y;
int ans = 0;
int ansarr[100005];
void dfs(int s,int p,int day){
    if(day>d)
        day = 1;
    //cout << ansarr[p] << " asdfasdfhaskdjfhkjahsdjk " << ansarr[s] << " asdfasdf " << visi[s][day]<< endl;
    if(visi[s][day] == p && ansarr[p] > ansarr[s]){
        //ansarr[s] = ansarr[p];
    }
    else if(visi[s][day] == p)
        return;
    cnt = max(ansarr[p],ansarr[s]);
    //cout << "day " << day << " s " << s << " open "<<op[s] << " can i " << (op[s] & (1ll<<(day-1))) << endl; 
    //cout << "source " << s <<  " parent " <<  p << " cnt " << cnt << " ans " << ans << endl;
    if(!SEEN[s] && (op[s] & (1ll<<(day-1))) ){
        //cout<< "---------------" << s << endl;
        cnt++;
        SEEN[s] = true;
    }
    ansarr[s] = max(cnt,ansarr[s]);
    visi[s][day] = p;
    ans = max(ans,cnt);
    //F0R(i,n+1)
        //cout << ansarr[i] << " ";
    //cout << endl;
    trav(ch, v[s]){
        dfs(ch,s,day+1);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    F0R(i,m){
        cin >> x >> y;
        v[x].pb(y);
    }
    string s;
    op.pb(0ll);
    F0R(i,n){
        cin >> s;
        reverse(all(s));
        op.pb(stoll(s, nullptr, 2));
    }
    memset(visi,0,sizeof(visi));
    memset(SEEN,0,sizeof(SEEN));
    memset(ansarr,0,sizeof(ansarr));
    dfs(1,-1,1);
    cout << ans ;
    return 0;
}
