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
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,pair<ll,ll> > >v(n);
        rep(i,0,n)
        {
            ll vs,l,h;
            cin>>vs>>l>>h;
            v[i]={vs,{l,h}};
        }
        sort(v.begin(),v.end());
        ll t2=0,f=0;
        pair<ll,ll> p=make_pair(m,m);
        rep(i,0,n)
        {
            ll vs=v[i].first;
            ll lt=v[i].second.first;
            ll ht=v[i].second.second;
            p.first-=(vs-t2);
            p.second+=(vs-t2);
            if(p.second<lt || p.first>ht)
            {
                cout<<"NO"<<endl;
                f=1;
                break;
            }
            p.first=max(p.first,lt);
            p.second=min(p.second,ht);
            t2=vs;
        }
        if(f==0)
        cout<<"YES"<<endl;
    }
}
