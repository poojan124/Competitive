#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define fill(m, z) memset(m, z, sizeof(m))
#define sqr(x) ((x) * (x))
#define forl(i, b, e) for (i = b; i < e; ++i)
#define forle(i, b, e) for (i = b; i <= e; ++i)
#define forne(i, b, e) for (i = b; i != e; ++i)
#define forg(i, e, b) for (i = e; i > b; --i)
#define forge(i, e, b) for (i = e; i >= b; --i)

//CHAR_MAX 127
//INT_MAX 2147483647
//UINT_MAX 4294967295
//_I64_MAX 9223372036854775807
//_UI64_MAX 18446744073709551615

//CHAR_MIN -128
//INT_MIN �2147483648
//_I64_MIN -9223372036854775808

const long long mod = 998244353;
const double eps = 1e-9;

bool us[2000][2000];

int main() {
    int n, m, r, c, x, y, i;
    cin >> n >> m >> r >> c >> x >> y;
    vector<string> pl(n);
    forl(i, 0, n)
        cin >> pl[i];
    deque<pair<pii, pii>> mv;
    int ans = 0;
    us[r - 1][c - 1] = 1;
    mv.push_front(mp(mp(r - 1, c - 1), mp(x, y)));
    while (!mv.empty()) {
        ++ans;
        pii tm = mv.front().first;
        pii st = mv.front().second;
        mv.pop_front();
        int tx = tm.first, ty = tm.second;
        int st_l = st.first, st_r = st.second;
        cout<<"FOR "<<tx<<" "<<ty<<" "<<st_l<<" "<<st_r<<endl;
        if (tx && !us[tx - 1][ty] && pl[tx - 1][ty] == '.') {
            mv.push_front(mp(mp(tx - 1, ty), st));
            us[tx - 1][ty] = 1;
        }
        if (tx + 1 < n && !us[tx + 1][ty] && pl[tx + 1][ty] == '.') {
            mv.push_front(mp(mp(tx + 1, ty), st));
            us[tx + 1][ty] = 1;
        }
        if (ty && !us[tx][ty - 1] && st_l && pl[tx][ty - 1] == '.') {
            mv.push_back(mp(mp(tx, ty - 1), mp(st_l - 1, st_r)));
            us[tx][ty - 1] = 1;
        }
        if (ty + 1 < m && !us[tx][ty + 1] && st_r && pl[tx][ty + 1] == '.') {
            mv.push_back(mp(mp(tx, ty + 1), mp(st_l, st_r - 1)));
            us[tx][ty + 1] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}