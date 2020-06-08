#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T; 
    for(int t=1;t<=T;t++){
        int r, s;
        cin >> r >> s;
        cout << "Case #" << t << ": " << (r-1)  * (s-1) << endl;
        for(int i=r;i>=2;i--){
            for(int j=1;j<=s-1;j++){
                cout << i * j << " " << i-1 << endl; 
            }
        }
    }
    return 0;
}