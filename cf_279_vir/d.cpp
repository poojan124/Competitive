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
bool getfrac(ll a,ll b, vector<pl> &m,ll x){
    pl p1,p2;
    int cnt2 = 0,cnt3 = 0;
    while(a%2==0){
        cnt2++;
        a/=2;
    }
    while(a%3==0){
        cnt3++;
        a/=3;
    }
    p1 = mp(cnt2,cnt3);
    cnt2 = cnt3 = 0;
    while(b%2==0){
        cnt2++;
        b/=2;
    }
    while(b%3==0){
        cnt3++;
        b/=3;
    }
    p2 = mp(cnt2,cnt3);
    m.pb(p1);
    m.pb(p2);
    if(a==b)
        return 1;
    else
        return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    vector<pl> v;
    bool ok = getfrac(a*b,c*d,v,max(max(a,b),max(c,d)));
    pair<ll,ll> p1 = v[0];
    pair<ll,ll> p2 = v[1];
    if(!ok){
        cout<<"-1"<<endl;
    }
    else{
        ll diff3,diff2;
        if(p1.S >p2.S)
            p1.F += p1.S - p2.S;
        else
            p2.F += p2.S - p1.S;
        diff3 = abs(p1.S - p2.S);
        diff2 = abs(p1.F - p2.F);
        cout<<diff3+diff2<<"\n";
        while(diff3>0){
            if(p1.S > p2.S){
                if(a%3==0){
                    a/=3;
                    a*=2;
                }
                else{
                    b/=3;
                    b*=2;
                }
            }
            else{
                if(c%3==0){
                    c/=3;
                    c*=2;
                }
                else{
                    d/=3;
                    d*=2;
                }
            }
            diff3--;
        }
        while(diff2>0){
            if(p1.F > p2.F){
                if(a%2==0)
                    a/=2;
                else
                    b/=2;
            }
            else{
                if(c%2==0)
                    c/=2;
                else
                    d/=2;
            }
            diff2--;
        }
        cout<<a<<" "<<b<<"\n"<<c<<" "<<d<<"\n";
    }
    return 0;
}