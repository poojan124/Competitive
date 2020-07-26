#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k,x,ans=0;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> x;
            ans += max(0, x-k);
        }
        cout << ans << endl;
    }
    return 0;
}