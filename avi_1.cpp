#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int do_thing(int num){
    string s = to_string(num);
    int t = 4 - s.length();
    while(t--){
        s += '0';
    }
    sort(s.begin(), s.end());
    string s1 =  s;
    reverse(s.begin(), s.end());
    string s2 = s;
    return abs(stoi(s1) - stoi(s2));
}

int foo(int num){
    int ans = 0;
    while(num != 6174){
        num = do_thing(num);
        ans ++;
    }
    return ans;
}

int main(){
    cout << foo(2111) << endl;
    cout << foo(9831) << endl;
    cout << foo(6174) << endl;
    cout << foo(1234) << endl;
    return 0;
}
