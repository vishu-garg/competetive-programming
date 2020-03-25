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

int main()
{
    ll n,k,d;
    cin>>n>>k>>d;
    ll dp[n+1][2];
    dp[0][0]=1;
    dp[0][1]=0;
    rep(i,1,n+1)
    {
        dp[i][0]=dp[i][1]=0;
        rep(j,1,k+1)
        {
            if(i-j<0)break;
            if(j<d)
            {
                dp[i][0]=(dp[i][0]+dp[i-j][0])%M;
                dp[i][1]=(dp[i][1]+dp[i-j][1])%M;
            }
            else 
            {
                dp[i][1]=(dp[i][1]+dp[i-j][0])%M;
                dp[i][1]=(dp[i][1]+dp[i-j][1])%M;
            }
        }
    }
    cout<<dp[n][1];
    return 0;
}