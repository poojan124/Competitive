#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int ans = n;
        int sum = 0;
        for(auto x : a) sum += x;
        int i = 0, j = n-1;
        while((sum % x == 0) && i <= j){
            if((sum - a[j])%x !=0 ){
                sum -= a[j];
                j--;
            }
            else{
                sum -= a[i];
                i++;
            }
            ans--;
        }
        cout << (ans?ans:-1) << endl;
    }

}