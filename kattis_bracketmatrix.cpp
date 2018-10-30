#include<bits/stdc++.h>
using namespace std;
string ans = "No";
void check(vector<pair<int,int>> v){
    int s1 = 0;
    int s2 = 0;
    for(auto i:v){
        s1 += i.first;
        s2 += i.second;        
    }
    if(s1==0 && s2==0){
        ans = "Yes";
        return;
    }
    // if((s1!=0 && s2==0) || (s1==0 && s2!=0))
    //     return;
    return;
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(auto i:v)
        i.first = i.second = 0;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        for(int j=0;j<n;j++){
            if(a[j]=='(')
                v[j].first += 1;
            if(a[j]==')')
                v[j].second += 1;
            // v[j].first += (a[i][j]=='('?1:0);
            // v[j].second += (a[i][j]==')'?0:1);
        }
    }
    // cout<<"size >?" <<v.size()<<endl;
    // for(auto i:v)
        // cout<<i.first<<" "<<i.second<<endl;
    if(v[0].first!=n || v[0].second!=0 || v[n-1].first!=0 || v[n-1].second!=n){
        cout<<"No"<<endl;
        return 0;
    }
    int ss = n*n;
    while(ss){
        ss--;
        for(int i=0;i<n-1;){
            int pre = i+1;
            while((pre+1)<n && v[pre].first==0 && v[pre].second==0)
                pre++;
            // cout<<"INEX I FOUNR " << pre<<endl;
            if(v[i].first>0 && v[pre].second>0 && pre!=n){
                // cout<<"I+9ts fkisdjnf ia"<<endl;
                int min_ = min(v[i].first,v[pre].second);
                v[i].first -= min_;
                v[pre].second -= min_;
            }
            i = pre;
        }
    }
    check(v);
    // for(auto i:v)
        // cout<<i.first<<" "<<i.second<<endl;
    // cout<<ss<<endl;
    cout<<ans<<endl;
    return 0;
}