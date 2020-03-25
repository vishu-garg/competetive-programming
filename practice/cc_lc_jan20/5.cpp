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

ll fact[100005];

ll power(ll a , ll n)
{
    ll reslt=1;
    while(n)
    {
        if(n & 1)
        reslt=(reslt*a)%M;

        a=(a*a)%M;
        n>>=1;
    }
    return reslt;
}

int main()
{
    fact[0]=1;
    rep(i,1,100005){
        fact[i]=(i*fact[i-1])%M;
    }
    ll t;
    cin>>t;
   while(t--)
    {
        map<ll,ll> mp;
        ll n;
        cin>>n;
        ll a[2*n];
        ll sum=0;
        rep(i,0,2*n){cin>>a[i];
        sum+=a[i];
        mp[a[i]]++;}
        ll m=sum/(n+1);
        if((sum%(n+1)) || mp.find(m)==mp.end() || mp[m]<2){
        cout<<"0"<<endl;
        continue;}
        mp[m]-=2;
        ll ans=fact[n-1];
        for(pll p :mp)
        {
            ll a=p.ft;
            ll b=p.sd;
            if(b==0)continue;
            if(mp.find(m-a)==mp.end() || ((m!=2*a) && (b!=mp[m-a])) || ((m==2*a) && (b%2)))
            {
                ans=0;
                break;
            }
            // cout<<ans;
            if(2*a == m){
                ll tot=b/2;
                ans=(ans*power(fact[tot],M-2))%M;
                mp[a]=0;
            }
            else 
            {
                ll tot=b;
                // err()
                ans=(ans*power(fact[tot],M-2))%M;
                // err()
                ans=(ans*power(2,tot))%M;
                mp[m-a]=0;
            }
        }
        cout<<ans<<endl;
    }
}