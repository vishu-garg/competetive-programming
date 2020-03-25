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
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}

// ll fact[1000005];
ll comb[1001][1001];
void ncr()
{
    comb[0][0]=1;
    rep(i,1,1001)
    {
        comb[i][0]=1;
        rep(j,1,i+1)
        comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%M;
    }
    return ;
}

int main()
{
    // fact[0]=1;
    // rep(i,0,1000005)
    // fact[i]=(fact[i-1]*i)%M;
    ll n;
    cin>>n;
    ll q[n+1],sum[n+1];
    sum[0]=0;
    rep(i,1,n+1)
    {
    cin>>q[i];
    sum[i]=sum[i-1]+q[i];
    }
    // ll f[n+1];
    ll ans=1;
    ncr();
    rep(i,2,n+1)
    {
        ans*=comb[sum[i]-1][q[i]-1];
        ans%=M;
    }
    cout<<ans;
}