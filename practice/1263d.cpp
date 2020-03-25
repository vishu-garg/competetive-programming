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
 
const int N = (int)2e5+100;
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

vector<ll> g[N];
ll used[N]={0};

void dfs(ll src)
{
    used[src]=1;
    rep(i,0,g[src].size())
    {
        if(used[g[src][i]]==0)
        dfs(g[src][i]);
    }
}

int main()
{
    ll n;
    cin>>n;
    string s[n];
    rep(i,0,n)
    {cin>>s[i];
        for(char c: s[i])
        {
            g[i].pb(n+c-'a');
            g[n+c-'a'].pb(i);
        }
    }

    ll ans=0;

    rep(i,n,n+26)
    {
        if(g[i].size()!=0 && used[i]==0)
        {
            dfs(i);
            ans++;
        }
    }
    
    cout<<ans;

}