#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int ans[n];
        int k=n-1;
        for(int i=0;i<n/2;i++){
            ans[k-1] = a[i];
            ans[k] = a[n-i-1];
            k-=2;
        }
        if(n%2){
            ans[0] = a[(int)n/2];
        }
        for(int i=0;i<n;i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}