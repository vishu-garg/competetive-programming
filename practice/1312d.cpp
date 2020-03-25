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
const ll M = 998244353;
const ll INF = 1e12;
#define PI 3.14159265

ll fact[200005];

ll pow1(ll a,ll b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
}

int main()
{
    fact[0]=1;
    rep(i,1,200005)
    {
        fact[i]=(fact[i-1]*i)%M;
    }
    ll n,m;
    cin>>n>>m;

    ll ans=1;
    ll ans1=fact[m];
    ll ans2=fact[n-1];
    ll ans3=fact[m-n+1];
    ans*=(ans1);
    // cout<<ans<<" "<<ans2<<" "<<ans3<<" "<<endl;
    // cout<<pow1(ans2,M-2)<<endl;
    ans*=((ll)pow1(ans2,M-2));
    // cout<<ans<<endl;
    ans%=M;
    ans*=((ll)pow1(ans3,M-2));
    ans%=M;
    // cout<<ans<<endl;
    // cout<<ans<<endl;
    ans*=(n-2);
    ans%=M;
    // cout<<ans<<endl;
    if(n==2)
    {
        ans*=((ll)pow1(2,M-2));
        ans%=M;
    }
    else 
    {
        ll tmp=((ll)pow1(2,n-3))%M;
        ans*=tmp;
        ans%=M;
    }

    cout<<ans;



}