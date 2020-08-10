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
const ll N=5005;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
ll n,m;
int a[3];
vector<ll>g[N];


int tot0,tot1;
int clr[N];
vector<vector<int> >vts[2];
bool ok;

void dfs(int v)
{
    tot0+=clr[v]==0;
    tot1+=clr[v]==1;
    vts[clr[v]].back().pb(v);
    for(auto u : g[v])
    {
        if(clr[u]==-1){
        clr[u]=clr[v]^1;
        dfs(u);}
        else if(clr[u]==clr[v])
        ok=false;               // this component is not bipartite
    }
}
int dp[N][N];
int res[N];

void solve()
{
    // err()
    vector<pair<int,int> >siz;
    memset(clr,-1,sizeof(clr));
    vts[0].clear();
    vts[1].clear();
    rep(i,0,n)
    {
        if(clr[i]==-1)
        {
            tot0=tot1=0;
            clr[i]=0;
            ok=true;
            vts[0].pb(vector<int>());
            vts[1].pb(vector<int>());
            dfs(i);
            if(!ok)
            {
                // err()
                cout<<"NO";
                return ;
            }
            // cout<<tot0<<" "<<tot1<<endl;
            // err2(tot0,tot1)<<endl;
            siz.pb(make_pair(tot0,tot1));
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    rep(i,0,siz.size())
    {
        rep(j,0,N)
        {
            if(dp[i][j]!=-1)
            {
                // err2(i,j)<<endl;
                dp[i+1][j+siz[i].first]=0;
                dp[i+1][j+siz[i].second]=1;
            }
        }
    }

    if(dp[siz.size()][a[1]]==-1){
        // err()
        cout<<"NO";
        return ;
    }
    cout<<"YES"<<endl;
    memset(res,-1,sizeof(res));
    ll cur=a[1];
    repb(i,siz.size(),1)
    {
        for(auto it: vts[dp[i][cur]][i-1])
        res[it]=2;
        cur-=(vts[dp[i][cur]][i-1].size());
    }
    rep(i,0,n)
    if(res[i]==-1)
    {
    if(a[0]>0){
        res[i]=1;
        a[0]--;
    }
    else
    {
        a[2]--;
        res[i]=3;
    }
    }

    rep(i,0,n)
    cout<<res[i];
    return;
    
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        cin>>n>>m;
        rep(i,0,3)
        cin>>a[i];
        rep(i,0,n)
        g[i].clear();
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            --v;--u;
            g[v].pb(u);
            g[u].pb(v);
        }
        solve();
    }

}