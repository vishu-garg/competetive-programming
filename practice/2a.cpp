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
    map<string,ll> mp;
    vector<pair<string,ll> > v;
    set<string> st;
    rep(i,0,n)
    {
        string s;ll pnt;
        cin>>s>>pnt;
        v.pb({s,pnt});
        mp[s]+=pnt;
        st.insert(s);
    }
    ll m=mp[*st.begin()];
    for(auto it:st)
    {
        if(mp[it]>m)
        m=mp[it];
    }
    
    // cout<<m;
    map<string,ll> mp2;
    for(auto it:v)
    {
        mp2[it.first]+=it.second;
        if(mp2[it.first]==m)
        return cout<<it.first,0;
    }
    

}