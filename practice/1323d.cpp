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
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)
    cin>>a[i];
    ll ans=0;
    rep(i,0,31)
    {
        // ll cur_bit=0;
        vector<ll> v(n);
        ll x=(ll)pow(2,i);
        rep(j,0,n)
        v[j]=a[j]%(2*x);
        sort(v.begin(),v.end());
        ll p=n-1,q=n-1,r=n-1;
        ll tmp=0;
        rep(j,0,n-1)
        {
            p=max(j+1,p);
            q=max(j+1,q);
            r=max(j+1,r);
            while(v[j]+v[p]>=x && p>j)
            p--;
            while(v[j]+v[q]>=(2*x) && q>j)
            q--;
            while(v[j]+v[r]>=(3*x) && r>j)
            r--;
        tmp+=(max((ll)0,(q-p)))+(max((ll)0,(n-1-r)));
        }
        ans+=(tmp%2)*x;
    }
    cout<<ans;
}