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
    ll n,m,k;
    cin>>n>>m>>k;
    ll mx=(4*m*n)-(2*m)-(2*n);
    if(mx<k)
    {
        cout<<"NO";
        return 0;
    }
    vector<pair<int,string> > v;
    ll all=0;
    rep(i,1,n+1)
    {
        v.pb(make_pair(m-1,"R"));
        all+=(v.back().first*(int)(v.back().second.size()));
        if(i==1)
        v.pb(make_pair(m-1,"L"));
        else 
        v.pb(make_pair(m-1,"UDL"));
        all+=(v.back().first*(int)(v.back().second.size()));
        if(i==n)
        v.pb(make_pair(n-1,"U"));
        else 
        v.pb(make_pair(1,"D"));
        all+=(v.back().first*(int)(v.back().second.size()));
    }
    while(all>k){
        string tmp=v.back().second;
        ll cur=(v.back().first*(int)(v.back().second.size()));
        v.pop_back();
        all-=cur;
//        cout<<all<<" "<<k<<endl;
        if(all>=k)
        continue;
        cur=k-all;
        if(cur/(int)tmp.size()>0)v.pb(make_pair(cur/(int)tmp.size(),tmp));
        tmp.resize(cur%tmp.size());
        if(tmp.size()>0)
        v.pb(make_pair(1,tmp));
        all=k;
    }
    cout<<"YES"<<endl;
    vector<pair<int,string> > v2;
    v2=v;
    v.clear();
    rep(i,0,v2.size())
    {
    	if(v2[i].first!=0)
    	v.pb(v2[i]);
	}
    cout<<v.size()<<endl;
    rep(i,0,v.size())
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}