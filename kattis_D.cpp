#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int cnt[k+1];
    memset(cnt,0,sizeof(cnt));
    int simi1 =0,simi2 = 0;
    string s1 = "01";
    string s2  = "00";
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        simi1 += abs((x[0]-'0')-(s1[0]-'0'))==0?1:0;
        simi2 += abs((x[0]-'0')-(s2[0]-'0'))==0?1:0;
        simi1 += abs((x[1]-'0')-(s1[1]-'0'))==0?1:0;
        simi2 += abs((x[1]-'0')-(s2[1]-'0'))==0?1:0;
        for(int j=0;j<k;j++)
            cnt[j]+= (x[j]-48);
    }
    cout<<cnt[0]<<" "<<cnt[1]<<endl;
    // cout<<n-cnt[0]<<" ----------- "<<n-cnt[1]<<endl;
    // for(auto i :cnt)
    //     cout<<"--> "<<i<<endl;
    // for(int i=0;i<k;i++){
    //     if(cnt[i]<n-cnt[i])
    //         cout<<'1';
    //     else
    //         cout<<'0';
    // }

    cout<<simi1<<" "<<simi2<<endl;
    
}