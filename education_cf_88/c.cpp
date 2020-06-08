#include<bits/stdc++.h>
#define ll long long

using namespace std;

double eq(ll h, ll c, ll q1, ll q2){
    return (h*q1 + c*q2)/(double)(q1 + q2);
}

ll bs(ll h, ll c, ll t){
    ll low = 1;
    ll high = h;
    while(low < high){
        ll mid = (low+high)/2;
        
        double val1 = abs(eq(h, c, mid-1, mid-2)-t);
        double val2 = abs(eq(h, c, mid, mid-1)-t);
        double val3 = abs(eq(h, c, mid+1, mid)-t);
        // cout << low << " " << high << " " << mid << " " << val1 << " " << val2 << " " << val3 << endl;
        if(mid==1){
            return val2<val3?mid:mid+1;
        }
        if(val1<val2 && val2<val3){
            high = mid-1;
        }     
        else if(val1>val2 && val2>val3){
            low = mid+1;
        }
        else if(val2<val1 && val2<val3){
            return mid;
        }
        else{
            return -1;
        }
    }
    return low;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        ll h,c,t;
        cin >> h >> c >> t;
        if(t==h){
            cout << 1 << endl;
        }
        else if(t <= (h+c)/2.0 ){
            cout << 2 << endl;
        }
        else{
            int val = bs(h, c, t);
            if(val!=-1)
                cout << 2*bs(h, c, t)-1 << endl;
            else{
                cout << ((abs(t-h)<abs(t-((h+c)/2.0)))?1:2) << endl;
            }
        }
    }
    return 0;
}
