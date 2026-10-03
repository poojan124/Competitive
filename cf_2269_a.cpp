#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i<t ; i++){
        int n,k;
        cin >> n >> k;
        int sum = 0;
        sum += 2*(k-1);
        if(n-k >= 0){
            sum += pow(2,n-k+1);
        }
        cout << sum << endl;
    }
    return 0;
}
