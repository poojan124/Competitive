// #include<bits/stdc++.h>


// using namespace std;
// vector<int> sqr;
// int main(){
//     for(int i=0;i<=3164;i++){
//         sqr.push_back(i*i);
//     }
//     int T;
//     cin >> T;
//     for(int t = 1 ; t <= T; t++){
//         int n;
//         cin >> n;
//         unordered_map<int, int> m;
//         int a[n];
//         int sum = 0;
//         int ans = 0;
//         int max_ = 0;
//         for(int i=0;i<n;i++){
//             cin >> a[i];
//             sum += a[i];
//             // m[sum]++;
//             // if(((int)sqrt(sum)*(int)sqrt(sum)) == sum) ans++;
//             max_ = max(max_, sum);
//         }
//         int left = 0;
//         for(int i = 0; i < n ; i++){
//             left += a[i];
            
//             // int l = lower_bound(sqr.begin(), sqr.end(), -left) - sqr.begin();
//             int r = lower_bound(sqr.begin(), sqr.end(), max_ - left) - sqr.begin();

//             cout << sqr[r] << " " << max_ << " " << left << " " << ans << endl;
            
//             for(int j = 0 ; j <= r ; j++){
//                 // int to_find = left + sqr[j];
//                 // cout << "find : " << to_find << endl;

//                 // if(m.find(to_find) != m.end()){
//                 //     cout << "Found : " << m[to_find] << endl;
//                 //     ans += m[to_find];
//                 // }
//                 m[]
//             }
//             // max_ -= a[i];
//         }
//         cout << "Case #" << t << ": " << ans << endl; 
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
vector<int> sqr;
int  main(){
    for(int i=0;i<=3164;i++){
        sqr.push_back(i*i);
    }
    int T;
    cin >> T;
    for(int t = 1 ; t <= T; t++){
        int n;
        cin >> n;
        unordered_map<int, int> m;
        m[0] =1;
        int a[n];
        int sum = 0;
        long long ans = 0;
        int max_ = 0;
        int min_ = INT_MIN;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
            // if(((int)sqrt(sum)*(int)sqrt(sum)) == sum) ans++;
            max_ = max(max_, sum);
            min_ = min(min_, sum);
            for(int j=0; j<=3164; j++){
                if((sum - sqr[j] > max_) && (sum - sqr[j] < min_)){
                    break;
                }
                if(m.find(sum-sqr[j]) != m.end())
                    ans += m[sum-sqr[j]];
            	
            }
            m[sum]++;
        }
        // int left = 0;
        // for(int i = 0;i < n ;i++){
        //     left += a[i];
        //     int l = lower_bound(sqr.begin(), sqr.end(), -left) - sqr.begin();
        //     int r = lower_bound(sqr.begin(), sqr.end(), max_) - sqr.begin();
        //     for(int j = l ; j <= r ; j++){
        //         int to_find = left + sqr[j];
        //         if(find(m.begin(), m.end(), to_find) != m.end()){
        //             ans += m[to_find];
        //         }
        //     }
        //     max_ -= a[i];
        // }
        cout << "Case #" << t << ": " << ans << endl; 
    }
    return 0;
}