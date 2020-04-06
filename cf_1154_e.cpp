/*
utter failure
*/

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
#define SZ(a) (int)a.size()
#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    list<int> l;
    vector<list<int>::iterator> v(n+1);
    list<int>::iterator beg;
    vector<int> check(n+1, 0);
    F0R(i, n){
        cin >> x;
        l.pb(x);
        if(i==0) beg = --l.end();
        v[x] = --l.end();
    }
    int cur = n;
    x = n;
    int flag = 1;
    cout << *beg << endl;
    while(x>0){
        cout << "1" << endl;
        int d = 1;
        int K = k;
        auto cur_it = v[cur];
        cur_it++;
        list<int>::iterator last;
        while(cur_it != l .end() && K>0){
            K--;d++;
            check[*cur_it] = flag;
            last = cur_it;
            l.erase(cur_it);
            cur_it++;
        }
        if(last!=l.end()) last++;
        cout << "2" << endl;
        cur_it = v[cur];
        K = k;
        if(cur_it == beg){
            check[*cur_it] = flag;
            if(last == l.end())
                break;
            else
                beg = last;
        }
        cur_it--;
        while(K>0){
            cout << "going in loop " << K << endl;
            K--;d++;
            check[*cur_it] = flag;
            l.erase(cur_it);
            if(cur_it == beg){
                cout << "suspicious not at all \n" ;
                break;
            }
            cur_it--;
        }
        cout << "3 asdfasdfasdf asdf asdf asdf" << endl;
        if(K!=0){
            if(last == l.end())
                break;
            else
                beg = last;
        }
        l.erase(v[cur]);
        cur--;
        x-=d;
        flag = 3 - flag;
        cout << x << " " << d << " " << flag << endl;
    }
    cout << SZ(check) << " a?? " << endl;
    return 0;
}
