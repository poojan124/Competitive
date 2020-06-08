#include<bits/stdc++.h>

using namespace std;
 
int main(){
    int t;
    cin >> t;
    for(int T=1;T<=t;T++){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int cnt = 0;
        int prev = -1;
        for(int i=0;i<n;i++){
            if(a[i] == k){
                prev = a[i];
                continue;
            }
            if(a[i] == (prev - 1)){
                if(a[i] == 1){
                    cnt++;
                    prev = -1;
                }
                else{
                    prev = a[i];
                }
            }
            else{
                prev = -1;
            }
        }

        cout << "Case #" << T << ": " << cnt << endl;
    }

    return 0;
}