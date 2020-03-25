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
        ll a[2*n];
        rep(i,0,2*n)
        cin>>a[i];
        map<ll,ll> difr;
        difr[0]=0;
        ll cur=0;
        rep(i,n,2*n)
        {
            if(a[i]==1)
            cur++;
            else 
            cur--;
            if(!difr.count(cur))
            difr[cur]=i-(n-1);
        }
        ll dif=count(a,a+(2*n),1)-count(a,a+(2*n),2);
        ll ans=2*n;
        cur=0;
        repb(i,n-1,0)
        {
            if(a[i]==1)
            cur++;
            else 
            cur--;
            if(difr.count(dif-cur))
            ans=min(ans,n-i+difr[dif-cur]);
        }
        if(difr.count(dif))
        ans=min(ans,difr[dif]);

        cout<<ans<<endl;
    }
}