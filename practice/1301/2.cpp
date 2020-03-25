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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        rep(i,0,n)
        cin>>v[i];
        // v[n]=-1;
        vector<ll> ks;
        rep(i,1,n)
        {
            if(v[i]==-1 && v[i-1]!=-1)
            ks.pb(v[i-1]);
            else if(v[i]!=-1 && v[i-1]==-1)
            ks.pb(v[i]);
        }
        
//        rep
		ll k;
		if(ks.size()!=0)
        {
        sort(ks.begin(),ks.end());
		k=(ks[0]+ks[ks.size()-1])/2;
		}
        else if(ks.size()==0 && v[0]==-1)
        {cout<<"0 1"<<endl;continue;}
        ll ans=-1;;
        rep(i,0,n)
        {
            if(v[i]==-1)
            v[i]=k;
        }
        rep(i,0,n-1)
        {
            ans=max(ans,abs(v[i]-v[i+1]));
        }
        cout<<ans<<" "<<k<<endl;
    }
}