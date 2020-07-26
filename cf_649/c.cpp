#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << " asdf";
    int n;
    cin >> n;
    int a[n], b[n];
    bool ok = true;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int v[1000001];
    memset(v, 0, sizeof(v));
    int cur = 0;
    for(int i=0;i<n;i++){
        if(a[i] - (i+1) > 0){
            cout << -1 << endl;
            return 0;
        }
        int j = cur;
        if(cur == a[i]){
            j = cur + 1;
        }
        while(j <= 1000000 && v[j] == 1){
            j++;
        }
        v[j] = 1;
        b[i] = j;
    }
    for(auto x : b){
        cout << x << " ";
    }
    return 0;
}