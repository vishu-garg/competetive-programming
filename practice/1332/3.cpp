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
   cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll vis[n];
        rep(i,0,n)vis[i]=0;
        vector<vector<ll> >v;
        rep(i,0,n)
        {
            if(vis[i])
            continue;
            vector<ll> tmp;
            vis[i]=1;
            tmp.pb(i);
            if(vis[n-1-i]==0)
            {
                vis[n-1-i]=1;
                tmp.pb(n-1-i);
            }
            ll j=i+k;
            while(j<n && vis[j]==0)
            {
                tmp.pb(j);
                vis[j]=1;
                if(n-1-j>=0 && vis[n-1-j]==0){
                tmp.pb(n-1-j);vis[n-1-j]=1;}
                j+=k;
            }
            v.pb(tmp);
        }
    ll cnt=0;
    for(auto it : v)
    {
        // cout<<it.size()<<" ###"<<endl;
        map<char,ll> mp;
        rep(i,0,it.size())
        {
            // cout<<it[i]<<" ";
            mp[s[it[i]]]++;
        }
        cout<<endl;
        auto p=*(mp.begin());
        char tmp=p.first;
        ll mx=p.second;
        for(auto t1 : mp)
        {
            if(t1.second>mx)
            {
                tmp=t1.first;
                mx=t1.second;
            }
        }
        // cout<<mx<<" "<<tmp<<"###"<<endl;
        rep(i,0,it.size())
        {
            if(s[it[i]]!=tmp)
            cnt++;
        }
    }
    cout<<cnt<<endl;

    }
}