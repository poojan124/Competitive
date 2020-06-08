#include<bits/stdc++.h>

using namespace std;

int next(vector<int> arr, int target, int end) { 
    int start = 0; 
    int ans = -1; 
    while (start <= end) { 
        int mid = (start + end) / 2; 
        if (arr[mid] <= target) 
            start = mid + 1; 
        else{ 
            ans = mid; 
            end = mid - 1; 
        } 
    } 
    return ans; 
} 

int main(){

    int n;
    cin >> n;
    long long a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    map<int, vector<int> > m;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        m[sum].push_back(i);
    }
    sum = 0;
    long long ans = 0;
    for(int i = 0; i < n ; i ++){
        if(m.find(sum) == m.end()) continue;
        int tp = m[sum].size();
        int x = next(m[sum], i-1, tp);
        cout << sum << " " << tp << " " << x << " add " << (n - i - tp + x) << endl; 
        tp -= x;
        ans += (n - i - tp);
        sum += a[i];
    }
    cout << ans << endl;
    return 0;
}