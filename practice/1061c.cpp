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
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        rep(i,0,n)
        cin>>v[i];
        vector<vector<ll> >vec(n);
        rep(i,0,n)
        {
            ll num=v[i];
            ll tmp=sqrt(num);
            for(ll j=1;j<=tmp;j++)
            {
                if(num%j==0)
                {
                    if(j*j==num)
                    {
                        if(j<=n)
                        vec[i].pb(j);
                    }
                    else 
                    {
                        if(j<=n)
                        vec[i].pb(j);
                        if((num/j)<=n)
                        vec[i].pb(num/j);
                    }
                }
            }
            sort(all(vec[i]),greater<ll>());
        }
        ll dp[n+1];
        dp[0]=1;
        rep(i,1,n+1)
        dp[i]=0;
        rep(i,0,n)
        {
            rep(j,0,(ll)vec[i].size())
            {
                dp[vec[i][j]]=(dp[vec[i][j]]+dp[vec[i][j]-1])%M;
            }
        }
        ll ans=0;
        rep(i,1,n+1)
        {
            ans=(ans+dp[i])%M;
        }
        cout<<ans;
    }

}