#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        if(m == 0){
            cout << 0 << endl;
        }
        else{
            int ans = min(n/k, m);
            m = max(0, m-(n/k));
            if(m == 0){
                
            }
        }
        
    }

    return 0;
}