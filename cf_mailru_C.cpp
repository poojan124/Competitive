#include<bits/stdc++.h>
using namespace std;
#define ll long long
void xgcd(ll *result, ll a, ll b){
    long aa[2]={1,0}, bb[2]={0,1}, q, r;
    while(1) {
        q = a / b; a = a % b;
        aa[0] = aa[0] - q*aa[1];  bb[0] = bb[0] - q*bb[1];
        if (a == 0) {
            result[0] = b; result[1] = aa[1]; result[2] = bb[1];
            return;
        };
        q = b / a; b = b % a;
        aa[1] = aa[1] - q*aa[0];  bb[1] = bb[1] - q*bb[0];
        if (b == 0) {
            result[0] = a; result[1] = aa[0]; result[2] = bb[0];
            return;
        };
    };
}
int main(){
    // cout<<gcd(-14,21)<<endl;
    ll x1,x2,x3,y1,y2,y3;
    cin>>x1>>x2>>x3>>y1>>y2>>y3;
    ll c[3];
    ll ans = 0;
    xgcd(c,x3,y3);
    if(abs(x1-y1)%c[0] == 0){
        cout<<min(abs(y1-y2),abs(x1-x2))+1<<endl;
        return 0;
    }
    else{
        if(abs(x1-x2)>abs(y1-y2)){
            swap(x1,y1);
            swap(x2,y2);
            swap(x3,y3);
        }
        cout<<"1--> "<<x1<<" "<<x2<<" "<<x3<<" "<<y1<<" "<<y2<<" "<<y3<<endl; 
        if(y2<x2){
            ll d = (ll)((x2-y2)/y3); 
            d++;
            y1 = y1 + d*y3;
            y2 = y2 + d*y3;
        }
        ll d = (ll)((y2-x2)/x3);
        cout<<"2--> "<<x1<<" "<<x2<<" "<<x3<<" "<<y1<<" "<<y2<<" "<<y3<<" "<<d<<endl; 
        x1 = x1 + d*x3;
        x2 = x2 + d*x3;
        ll left = max(x1,y1);
        ll right = min(x2,y2);
        if(right>left && (x2>=y1 && x2<=y2) )
            ans = max(ans, right-left+1);
        cout<<"3--> "<<x1<<" "<<x2<<" "<<x3<<" "<<y1<<" "<<y2<<" "<<y3<<" "<<d<<endl;         
        x1 = x1 + x3;
        x2 = x2 + x3;
        left = max(x1,y1);
        right = min(x2,y2);
        if(right>left && (x1>=y1 && x1<=y2) )
            ans = max(ans, right-left+1);
        cout<<"4--> "<<x1<<" "<<x2<<" "<<x3<<" "<<y1<<" "<<y2<<" "<<y3<<" "<<d<<endl; 
    }
    cout<<ans<<endl;
}