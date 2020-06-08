#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n], b[n];
        bool ok1 = false, ok2 = false;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++){
            cin >> b[i];
            (b[i]?ok1:ok2) = true;
        }
        if(ok1 && ok2){
            cout<<"Yes"<<endl;
        }
        else{
            bool ans = true;
            for(int i=0;i<n-1;i++){
                if(a[i] > a[i+1]){
                    cout<<"No"<<endl;
                    ans = false;
                    break;
                }
            }
            if(ans){
                cout<<"Yes"<<endl;
            }
        }
    }
  	return 0;
}