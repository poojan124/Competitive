#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
using namespace std;
int gcd(int a,int b){
    if(b==0)
        return 1;
    else
        return gcd(b,a%b);
}
int modulo(int a,int b,int n){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1)
            x=(x*y)%n;
        y = (y*y)%n;
        b /= 2;
    }
    return x%n;
}
int main()
{

    return 0;
}
