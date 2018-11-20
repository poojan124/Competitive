#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll foo(ll a,ll b){
    while(b>0 && a>1){
        a=ceil(a/3.0);
        b--;
    }
    return a;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a==1)
            cout<<"1.000000"<<endl;
        if(a==2)
            cout<<"0.5000000"<<endl;
        if(a<=2)
            continue;
        if(b==0){
            printf("%0.20lf\n",1/(double)a);
            continue;
        }
        if(b==1){
            ll answer = a;
            if(answer%4!=0){
                if(answer%2==1)
                    answer = (ll)((answer+1)/2);
                else
                    answer = (ll)(answer/2)+1;
            }
            else
                answer = (ll)answer/2;
            printf("%0.20lf\n",1/(double)answer);
            continue;
        }
        ll ans = ceil(log(2*a+1)/log(3));
        if(ans <= b)
            cout<<"1.000000"<<endl;      
        else{
            ll answer=0;
            b--;
            if(a%3==1)
                a=a-1;
            if(a%3==2)
                a=a+1;
            a=2*a/3;
            answer = foo(a,b);
            // cout<<answer<<endl;
            printf("%0.20lf\n",1/(double)answer);
        }
    }
}