#include<bits/stdc++.h>
using namespace std;
long gcd(long a,long b){
    if( b == 0)
        return a;
    else
        return gcd(b,a%b); 
}
pair<long,long> frac_add(pair<long,long> x,pair<long,long> y){
    long u = x.first*y.second+x.second*y.first;
    long b = x.second*y.second*2;
    long g = gcd(u,b);
    return make_pair( u/g,b/g );
}
int main(){
    pair<int,int> l = make_pair(1,4),r = make_pair(1,2);
    vector<pair<int,int> > ans;
    ans.push_back(make_pair(1,2));
    ans.push_back(make_pair(1,4));
    int i = 3;
    while(i<=25){
        if(i%2){
            r = frac_add(l,r);
            ans.push_back(r);
        }
        else{
            l = frac_add(l,r);
            ans.push_back(l);
        }
        i++;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n-1].first<<" "<<ans[n-1].second<<" "; 
    }
    return 0;
}