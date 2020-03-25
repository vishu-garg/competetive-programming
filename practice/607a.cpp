#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}

int main()
{
    ll dp[1000005]={0};
    // ll mini=0;
    vector<ll> x(1000005,0);
    ll n;cin>>n;
    rep(i,0,n){
        ll a,b;cin>>a>>b;
        x[a]=b;
        // mini=max(mini,a+1);
    }
    if(x[0]!=0)
    dp[0]=1;
    else 
    dp[0]=0;
    // ll cnt=n-1;
    rep(i,1,1000005)
    {
        if(x[i]==0)dp[i]=dp[i-1];
        else 
        {
            if(i-x[i]-1>=0)
            dp[i]=(dp[i-x[i]-1]+1);
            else 
            dp[i]=1;
        }
    }
    // ll mn=n,mii=0;
    ll mn=0;
    rep(i,0,1000005)
    {
        if(x[i]!=0)
        {
            // cout<<dp[i]<<" ";
            if(dp[i]>mn)
            {
                mn=dp[i];
            }
        }
    }
    cout<<n-mn;
}