#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> v;
    v.push('@');
    for(auto i :s){
        if(i == ')' && v.top() == '(')
            v.pop();
        else
            v.push(i);
    }
    bool f1=false,f2=false;
    while(!v.empty()){
        if(v.top()==')')
            f2 = 1;
        if(v.top()=='(')
            f1 = 1;
        v.pop();
    }
    //for(auto i:v)
      //  cout<<" "<<i<<endl;
    if(!f1 && !f2)
        cout<<"0"<<endl;
    if(f1 && f2)
        cout<<"2"<<endl;
    else if(f1 || f2)
        cout<<"1"<<endl;
    return 0;
}