#include<bits/stdc++.h>
using namespace std;
int bitcount(int n) { 
    int cnt = 0; 
    while (n) { 
        cnt += 1; 
        n >>= 1; 
    } 
    return cnt; 
} 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        int max_ = INT_MIN;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(max_ > a[i])
                ans = max(ans, max_ - a[i]);
            max_ = max(max_, a[i]);
        }
        cout << bitcount(ans) << endl;
    }
    return 0;
}