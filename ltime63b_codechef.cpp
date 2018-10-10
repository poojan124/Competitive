#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int invalid = 0;
        int weak = 0;
        while(n--){
            string s1,s2;
            cin>>s1>>s2;
            if(s1=="correct"){
                int sum = s2.length();
                for(int i=0;i<s2.length();i++)
                    sum -= (s2[i]-'0');
                if(sum)
                    invalid = 1;
            }
            else{
                int sum = s2.length();
                for(int i=0;i<s2.length();i++)
                    sum -= (s2[i]-'0');
                if(!sum)
                    weak = 1;
            }
        }
        if(invalid)
            cout<<"INVALID"<<endl;
        else if(weak && !invalid)
            cout<<"WEAK"<<endl;
        else
            cout<<"FINE"<<endl;

    }
    return 0;
}
