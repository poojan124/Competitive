#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1)
            cout << "-1" << endl;
        else{
            string s = "";
            s += '2';
            n--;
            while(n--){
                s += '3';
            }
            cout << s << endl;
        }
    }
    return 0;
}