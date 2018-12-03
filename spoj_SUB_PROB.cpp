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
#define SZ(vec) int((vec).size())
#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll prm1 = 107;
const ll prm2 = 109;
template<typename T>
T modPos(T a,T mo){
    if(a>0)
        return a%mo;
    else
        return (a%mo+mo)%mo;
}/**
void cal_hash(string s,int mo1,int mo2,int pr1,int pr2,vector<pi> &h){
    h.pb(mp(s[0] - 'A' + 1,s[0] - 'A' + 1));
    FOR(i,1,s.length())
        h.pb(mp( (h[i-1].F*pr1)%mo1 + (s[i] - 'A' + 1)%mo1, (h[i-1].S*pr2)%mo2 + (s[i] - 'A' + 1)%mo2 ));
}**/
void cal_pow(ll mo1,ll mo2,ll prm1,ll prm2,ll n,vector<pl> &p_pow){
    p_pow.pb(mp(1,1));
    FOR(i,1,n+1)
        p_pow.pb( mp( (p_pow[i-1].F*prm1)%mo1, (p_pow[i-1].S*prm2)%mo2 ) );
}/**
pi get_hash(int l,int r,vector<pi> h,vector<pi> p_pow){
    if(l==0)
        return h[r];
    else
        return mp( modPos( h[r].F - (h[l-1].F*p_pow[r-l+1].F)%MOD1, MOD1 ) , modPos( h[r].S - (h[l-1].S*p_pow[r-l+1].S)%MOD2, MOD2 ));
}**/
bool is_eq(pl a,pl b){
    return a.F==b.F && a.S==b.S;
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    string s;
    cin>>s;
    //vector<pi> h;
    vector<pl> p_pow;
    cal_pow(MOD1,MOD2,prm1,prm2,SZ(s),p_pow);
    //cal_hash(s,MOD1,MOD2,prm1,prm2,h);
    int n;
    cin>>n;
    auto simple_h = [&](string q)->pl {
        pl cur_h = mp(0,0);
        int len = q.size();
        F0R(i,len)
            cur_h = mp((cur_h.F + ((q[i]-'A'+1)*p_pow[len-i-1].F)%MOD1)%MOD1 , (cur_h.S + ((q[i]-'A'+1)*p_pow[len-i-1].S)%MOD2) %MOD2 );
        return cur_h;
    };
    map<ll,bool> m1;
    map<ll,bool> m2;
    FOR(gap,1,min(2000,SZ(s))+1){
        pl tp = simple_h(s.substr(0,gap));
        m1[tp.F] = true;
        m2[tp.S] = true;
        FOR(i,1,SZ(s)-gap+1){
            tp = mp( ((modPos(tp.F - ((s[i-1]-'A'+1 )*p_pow[gap-1].F)%MOD1,MOD1)*prm1)%MOD1 + (s[i+gap-1] - 'A' +1))%MOD1 , ((modPos(tp.S - ((s[i-1]-'A'+1 )*p_pow[gap-1].S)%MOD2,MOD2)*prm2)%MOD2 + (s[i+gap-1] - 'A' +1))%MOD2 );
            m1[tp.F] = true;
            m2[tp.S] = true;
        }
    }
    //pm(m1);
    //pm(m2);
    while(n--){
        string q;
        cin>>q;
        pl h1 = simple_h(q);
        //cout<<h1.F<<" ----- "<<h1.S<<endl;
        if(m1[h1.F] && m2[h1.S])
            cout<<"Y"<<"\n";
        else
            cout<<"N"<<"\n";
    }
    return 0;

}
