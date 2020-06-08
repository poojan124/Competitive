/*
why be a king when you can be a god.
*/

#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+2], b[n+2];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int pos=n, neg=n;
        int diff[n];
        for(int i=0 ; i<n; i++){
            if((pos == n) && (a[i] == 1)) 
                pos = i;
            if((neg == n) && (a[i] == -1))
                neg = i;
            diff[i] = b[i] - a[i];
        }
        string ans = "YES";
        for(int i = 0; i < n ; i++){
            if(diff[i] > 0 && pos >= i) ans = "NO";
            if(diff[i] < 0 && neg >= i) ans = "NO";
        }
        cout << ans << endl;
    }
    return 0;
}