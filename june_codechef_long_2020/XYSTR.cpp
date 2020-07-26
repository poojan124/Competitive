#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 0;
        bool prev = false;
        for(int i=1;i<s.length();i++){
            if((s[i] == 'y' && s[i-1] == 'x' && !prev) || (s[i] == 'x' && s[i-1] == 'y' && !prev)){
                ans++;
                prev = true;
            }
            else{
                prev = false;
            }
        }
        cout << ans << endl;
    }
    return 0;
}