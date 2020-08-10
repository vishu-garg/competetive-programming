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
 
const ll N=100005;
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
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

vector<ll> adj[N];
vector<ll>val(N),fin_val(N);
vector<ll> ans;

void dfs(ll dis, ll src, ll prv ,ll o, ll e)
{
    ll x=(dis%2==0?e:o);
    val[src]^=x;
    ll flg=0;
    if(val[src]!=fin_val[src])
    {
        ans.pb(src);
        flg=1;
    }
    for(auto it: adj[src])
    {
        if(it==prv)continue;
        if(flg==0)
        dfs(dis+1,it,src,o,e);
        else 
        {
            if(dis%2==0)
            dfs(dis+1,it,src,o,e^1);
            else 
            dfs(dis+1,it,src,o^1,e);
        }
    }
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        rep(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        rep(i,0,n)
        cin>>val[i];

        rep(i,0,n)
        cin>>fin_val[i];

        dfs(0,0,-1,0,0);
      
        cout<<ans.size()<<endl;
        for(auto it : ans)
        cout<<it+1<<endl;

    }

}