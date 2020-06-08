#include<bits/stdc++.h>

using namespace std;
int intr(char c){
    return c-'0';
}
string add(string &s, char c, int times){
    while(times--){
        s += c;
    }
    return s;
}
int main(){
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; t++){
        string s;
        cin >> s;
        int op_cnt = 0;
        string ans = "";
        for(auto x : s){
            int cur = intr(x);
            if(op_cnt > cur)
                ans = add(ans, ')', op_cnt - cur);
            else if(op_cnt < cur)
                ans = add(ans, '(', cur - op_cnt);
            op_cnt = cur;
            ans += x;
        }
        ans = add(ans, ')', op_cnt);
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}