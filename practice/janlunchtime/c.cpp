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
ll n;
ll dfs(vector<vector<ll> > v)
{   
    ll vis[n]={0};
    queue<ll> q;
    q.push(0);
    // ll fnd=0;
    ll ans[n];
    ans[0]=0;vis[0]=1;
    while(!q.empty())
    {
        ll t=q.front();
        q.pop();
        // vis[t]=1;
        rep(i,0,v[t].size())
        {
         if(vis[v[t][i]]!=1)
            {q.push(v[t][i]);
            ans[v[t][i]]=ans[t]+1;
            vis[v[t][i]]=1;
            // cout<<v[t][i]<<" ";
            }

        }
        // cout<<endl;
    }
    if(vis[n-1]==1)
    return ans[n-1];
    
    return -1;


}



int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    ll k;
    cin>>n>>k;
    vector<string> s(n);
    rep(i,0,n)
    cin>>s[i];
    vector<vector<ll> >v(n);
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            ll tmp=abs(i-j);
            // cout<<"char = "<<s[i][j]<<" i= "<<i<<" j= "<<j<<" tmp= "<<tmp<<endl;
            if(s[i][j]=='1' && i!=j && tmp<=k)
            v[i].pb(j);
        }
    }
    // cout<<"***";
    // rep(i,0,n)
    // {
    //     rep(j,0,v[i].size())
    //     // cout<<v[i][j]<<" ";
    //     // cout<<endl;
    // }
    cout<<dfs(v)<<endl;
    }
}