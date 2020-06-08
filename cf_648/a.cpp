#include<bits/stdc++.h>
 
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++){
            bool ok = true;
            for(int j=0;j<m;j++){
                ok &= (a[i][j] == 0);
            }
            cnt1 += ok;
        }
        for(int i=0;i<m;i++){
            bool ok = true;
            for(int j=0;j<n;j++){
                ok &= (a[j][i] == 0);
            }
            cnt2 += ok;
        }
        cout << ((min(cnt1,cnt2) % 2 == 0)?"Vivek":"Ashish") << endl;
    }
    return 0;
}