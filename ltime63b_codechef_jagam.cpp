// NOT WORKIGN :S:SS:S"SLKFWEK:OLJ:OW FO:L W

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,z1,z2;
        cin>>n>>z1>>z2;
        vector<int> v;
        int flag1=0,flag2=0,flag3=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            if(abs(v[i])==abs(z1) || abs(v[i])==abs(z2))
                flag1=1;
        }
        //cout<<boom<<a.size()<<endl;
        if(flag1)
            cout<<"1"<<endl;
        else if(z1 == 0 || z2 == 0)
            cout<<"2"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
