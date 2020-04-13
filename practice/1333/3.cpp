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
//    cin>>t;
    while(t--)
    {
    	ll n;
        cin>>n;
        ll a[n+1];
        ll sum[n+1];
        map<ll,ll> mp,next;
        sum[0]=0;
        mp[0]=0;
        rep(i,1,n+1)
        {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        if(mp.find(sum[i])!=mp.end())
        next[mp[sum[i]]+1]=i;
        mp[sum[i]]=i;
        }

        ll min_i=n+1;
        ll next_index[n+1];
        repb(i,n,1)
        {
            next_index[i]=min_i;
            if(next.find(i)!=next.end())
            next_index[i]=min(next_index[i],next[i]);
            min_i=next_index[i];
        }
        ll ans=0;
        rep(i,1,n+1)
        {
            ll r=next_index[i];
            ll l=i;
            ans+=(r-l);
        }
        cout<<ans;
        
    }

}