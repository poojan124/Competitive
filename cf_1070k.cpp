#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int s[n+1];
    int sum = 0;
    memset(s,0,sizeof(s));
    for(int i=0;i<n;i++){
        cin>>s[i];
        sum+=s[i];
    }
    if(sum%k!=0)
        cout<<"No";
    else{
        int sz = sum/k;
        int tsum = 0;
        int cntr = 0;
        vector<int> v;
        for(int i=0;i<n;i++){
            tsum += s[i];
            cntr++;
            if(tsum>sz){
                cout<<"No";
                return 0;
            }
            else if(tsum == sz){
                v.push_back(cntr);
                cntr = 0;
                tsum = 0;
            }
        }
        assert(v.size()==k);
        cout<<"Yes"<<endl;
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }
    return 0;
}