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
        ll   n;
        cin>>n;
        vector<pair<ll,ll> > v;
        rep(i,0,n){
            ll x,y;
            cin>>x>>y;
            v.pb({x,y});
        }
        sort(v.begin(),v.end());
        ll x=0,y=0,got_ans=0;
        sring s="";
        ll k=0;
        while(v.size()>0)
        {
            ll r2,u2;
            ll r=v[k].first;
            ll u=v[k].second;
            if(r<0 || u<0)
            {
                cout<<"NO";
                got_ans=1;
                continue;
            }
            else 
            {
                x=r;
                y=u;
                rep(i,0,r)
                s+="R";
                rep(i,0,u)
                s+="U";
                k++;
            }
        }
        if(got_ans)
        break;
        else 
        coout<<"YES"<<endl<<s;
    }
}