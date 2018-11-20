#include<bits/stdc++.h>
using namespace std;
#define maxn (int)1e5
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int> z;
    partial_sum(v.begin(),v.end(),back_inserter(z));
    for(auto i:z)
        cout<<i<<endl;
}
