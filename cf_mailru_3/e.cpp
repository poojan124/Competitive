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

const ll MOD = 1000000007;
const int MOD1 = 1000010101;
const ll prm = 109;
ll h[1000005];
ll modpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1)
            res = (a*res)%MOD;
        a = (a*a)%MOD;
        b=b>>1;
    }
    return res;
}
ll modPos(ll a, ll mod=MOD){
    if (a >= 0) return a%mod;
    return (a%mod+mod)%mod;
}
bool is_equal(pi p1,pi p2){
    ll mul = modpow(prm,abs(p1.F-p2.F));
    if(p1.F>=p2.F)
        return modPos(h[p1.S]-h[p1.F]) == modPos(modPos(h[p2.S]-h[p2.F])*mul);
    else
        return modPos((mul*modPos(h[p1.S]-h[p1.F]))) == modPos(h[p2.S]-h[p2.F]);
}
ll p_pow[1000005];
ll get_hash(int l, int r) {
    if(l==0)
        return h[r];
    return modPos(h[r] - ((h[l-1]*p_pow[r-l+1])%MOD));
}
int main(){
    string s,t;
    cin>>s>>t;
    int n = t.length();
    h[0] = t[0]-'a'+1;
    p_pow[0] = 1;
    FOR(i,1,n+1)
        p_pow[i] = (p_pow[i-1]*prm)%MOD;
    FOR(i,1,n)
        h[i] = ((h[i-1]*prm)%MOD + (t[i]-'a'+1))%MOD ;
    //F0R(i,n)cout<<h[i]<<" ";
    //cout<<endl;
    int cnt[] ={0,0};
    F0R(i,s.length())
        cnt[s[i]-'0']++;
    //flip if count of 0 is less. Always keep 0 bigger
    if(cnt[0]<cnt[1]){
        swap(cnt[0],cnt[1]);
        F0R(i,s.length())
            s[i] = '1' - s[i] + '0';
    }
    int ans = 0;
    for(int i=1;i*cnt[0]<n;i++){
        if((n - i*cnt[0])%cnt[1]==0){
            int j = (n - i*cnt[0])/cnt[1];
            int cur_pos = 0;
            ll h0 = -1;
            ll h1 = -1;
            bool match = true;
            trav(ch,s){
                if(ch=='0'){
                    ll h = get_hash(cur_pos,cur_pos+i-1);
                    cur_pos+=i;
                    if(h0==-1)
                        h0 = h;
                    else if(h0!=h){
                        match = false;
                        break;
                    }
                }
                if(ch=='1'){
                    ll h = get_hash(cur_pos,cur_pos+j-1);
                    cur_pos+=j;
                    if(h1==-1)
                        h1=h;
                    else if(h1!=h){
                        match = false;
                        break;
                    }
                }
            }
            if(match && h0!=h1)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
