/*
Har Har Mahadev!
*/

#include<bits/stdc++.h>
using namespace std;
int n, s1, s2;
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, vector<int> &wt, vector<int> &val, int n){ 
    int i, w; 
    int K[2][W+1]; 
    int ans = 0;
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0) 
                K[i%2][w] = 0; 
            else if (wt[i-1] <= w) 
                K[i%2][w] = max(val[i-1] + K[(i-1) % 2][w-wt[i-1]],  K[(i-1) % 2][w]);
            else
                K[i%2][w] = K[(i-1) % 2][w]; 
        } 
    } 
    return K[n%2][W]; 
} 

bool ok(vector<int> &a, int last){
    int s = 0;
    for(int i=0;i<=last;i++){
        s += a[i];
    }
    int ans;
    if(s1 > s2)
        swap(s1, s2);
    ans = knapSack(s1, a, a, last);
    // cout << "Ans 1 " << ans << endl;
    if ( s - ans <= s2) return true;
    return false;
}

int main(){
    
    cin >> n >> s1 >> s2;
    vector<int> a(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(ok(a, mid)){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans + 1;
    return 0;
}