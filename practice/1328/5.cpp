#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 

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

vector<vector<ll> > t;
V v,tin,tout;
ll tme=1;
V depth;
void dfs(ll src,ll par,ll dpth)
{
    v[src]=par;
    tin[src]=tme++;
    depth[src]=dpth;
    rep(i,0,t[src].size())
    {
        if(t[src][i]!=par)
        dfs(t[src][i],src,dpth+1);       
    }
    tout[src]=tme++;
}

bool isAnc(ll v, ll u)
{
    if(tin[v]<=tin[u] && tout[v]>=tout[u])
    return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    v=tin=tout=depth=vector<ll> (n+1);
    t=vector<vector<ll> >(n+1);
    rep(i,1,n)
    {
        ll a,b;
        cin>>a>>b;
        t[a].pb(b);
        t[b].pb(a);
    }
    // for(ll i=1;i<=n;i++)
    // // cout<<v[i]<<" ###";
    // cout<<endl;
    dfs(1,0,0);
    rep(i,0,m)
    {
        ll k;
        cin>>k;
        V s(k);
        rep(i,0,k)
        {
            cin>>s[i];
        }
        ll u=s[0];
        for(auto it : s)
        {
            // cout<<depth[it]<<" ";
            if(depth[it]>depth[u])u=it;
        }
        // cout<<endl<<u<<endl;
        for(ll i=0;i<s.size();i++)
        {
            if(u==s[i])continue;
            else if(s[i]==1)continue;
            else {/*cout<<s[i]<<" "<<v[s[i]]<<" <---"<<endl;*/s[i]=v[s[i]];}
        }
        // for(auto it:s)
        // cout<<it<<" ";
        // cout<<endl;
        bool ok=true;
        for(auto it : s)
        {
            // cout<<tin[it]<<" "<<tout[it]<<endl;
            // cout<<tin[u]<<" "<<tout[u]<<" <---"<<endl;
            if(!isAnc(it,u))
            {
                ok=false;
                break;
            }
        }
        if(ok)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
}