#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c5 = 0, c10 = 0, c15 = 0;
        int a[n];
        for(int i = 0 ; i  < n ; i++){
            cin >> a[i];
        }
        bool ok = true;
        for(int x : a){
            if(x == 5){
                c5++;
            }
            if(x == 10){
                c10++;
                if(c5 == 0){
                    ok = false;
                    break;
                }
                else{
                    c5--;
                }
            }
            if(x == 15){
                if((c10 == 0) && (c5 < 2)){
                    ok = false;
                }
                else if(c10 > 0 ){
                    c10--;
                }
                else{
                    c5 -= 2;
                }
            }
        }
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}