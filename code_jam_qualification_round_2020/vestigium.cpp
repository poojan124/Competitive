#include<bits/stdc++.h>

using namespace std;
bool check(map<int,int> m){
    for(auto x : m)
        if(x.second > 1)
            return true;
    return false;
}

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int n;
        cin >> n;
        int a[n][n];
        int diag = 0, ans1 = 0, ans2 = 0;
        map<int,int> m;
        for(int i = 0 ; i < n ; i++){
            m.clear();
            for(int j = 0 ; j < n ; j++){
                cin >> a[i][j];
                if(i==j) diag += a[i][j];
                m[a[i][j]]++;
            }           
            ans1 += check(m);
        }
        for(int i = 0; i < n; i++){
            m.clear();
            for(int j = 0; j < n ; j++)
                m[a[j][i]]++;
            ans2 += check(m);
        }
        cout << "Case #" << t + 1 << ": " << diag << " " << ans1 << " " << ans2 << endl;
    }
    

    return 0;
}