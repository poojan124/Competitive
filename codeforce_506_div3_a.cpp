#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&m,&m);
    string s;
    cin>>s;
    int len = s.length();
    int fac=0;
    for(int i=0;i<=int((len)/2)-1;i++){
        if(s[i] == s[int((len)/2)+i])
            fac++;
        else
            break;
    }
    string app = s.substr(fac);
    string ans = s;
    for(int i=1;i<m;i++)
        ans += app;
    cout<<ans;
    return 0;
}
