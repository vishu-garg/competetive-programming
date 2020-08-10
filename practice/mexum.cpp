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

ll pow1(ll a,ll b){
    ll res=1;
    a%=M;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    map<ll,ll>mp;
    rep(i,0,n)
    {cin>>a[i];mp[a[i]]++;}
    sort(all(a));
    V mes(n-1);
    rep(i,1,n)
    {
        mes[i-1]=(a[i]-a[i-1]);
    }
    ll ind=lower_bound(all(mes),2)-mes.size();
    ll ans=a[ind]+1;
    vector<ll> vec,vec2;
    for(auto it : mp)
    {
        vec2.pb(it.first);
        vec.pb(it.second);
    }
    ll sz=vec.size();
    ll a1[sz],a2[sz];
    rep(i,0,sz)
    {
        a1[i]=pow1(vec[i],x);
        a2[i]=(a1[i]-1)%M;
        if(a2[i]<0)
        a2[i]+=M;
    }

    rep(i,1,sz)
    {
        a2[i]=(a2[i]*a2[i-1])%M;
    }
    repb(i,sz-2,0)
    {
        a1[i]=(a1[i]*a1[i+1])%M;
    }

    ll sum=0;
    while(ans>0)
    {
        ll tmp=1;
        ll i2=lower_bound(all(vec2),ans)-vec2.size();
        tmp=(tmp*a2[i2])%M;
        if(i2!=sz-1)
        {
            tmp=(tmp*a1[i2+1])%M;
        }
        sum=(sum+(ans*tmp)%M)%M;
    }
    cout<<sum<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }

}