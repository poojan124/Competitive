#include<bits/stdc++.h>
using namespace std;
long long goal;

bool solve(long long  mid, int w, vector<int> &c){
    long long sum = 0;
    int l = 0;
    int r = (int)c.size() -1 ;
    while(l <= r){
        if(c[l] > mid)
            return false;
        if(sum + c[l] > mid){
            w--;
            sum = 0;
        }
        if(w == 0) break;
        sum += c[l];
        l++;
    }
    if((sum > mid) || (l <= r))
        return false;
    return true;
}

int paint(int A, int B, vector<int> &C) {
    for(auto x: C) goal+= (long long)x;
    long long l = 0, r = goal;
    while(l<r){
        long long mid = l + (long long) ((r - l)/2);
        bool ok = solve(mid, A, C);
        if(ok) 
            r = mid;
        else
            l = mid+1;
    }
    if(l==r)
        return l * B % 10000003;
    // else is for when l>r. In this case we need to check for smaller answer first
    else{ 
        if(solve(l, A, C))
            return r * B % 10000003;
        else
            return l * B % 10000003;
    }
}


int main(){
    vector<int> v{ 185, 186, 938, 558, 655, 461, 441, 234, 902, 681 };
    cout << paint(3,10,v);
    return 0;
}