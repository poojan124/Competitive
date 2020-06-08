#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans = max(ans, a[i]|a[j]|a[k]);
            }
        }    
    }
    cout << ans;
    return 0;
}