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
const ll N=100005;
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

// struct segtree{
//     ll x,y;
//     ll tree[4*N];

//     void build_tree(vector<ll>&v , ll ind,ll l, ll r)
//     {
//         if(l==r)
//         {
//             tree[ind]=v[l];
//             return;
//         }
//         ll mid=(l+r)/2;
//         build_tree(v,2*ind,l,mid);
//         build_tree(v,2*ind+1,mid+1,r);
//         tree[ind]=max(tree[2*ind],tree[2*ind+1]);
//     }

//     ll query(ll ind, ll l, ll r)
//     {
//         // cout<<l<<" "<<r<<" "<<endl;
//         if(x>r || y<l)return -LLONG_MAX;
//         if(l>=x && r<=y)return tree[ind];
//         ll mid=(l+r)/2;
//         return max(query(2*ind,l,mid),query(2*ind+1,mid+1,r));
//     }
// }obj;

vector<ll>cost,b,c,mn;
vector<V>adj;
ll ans=0;

pll dfs(ll s, ll prv)
{
    ll type[2];
    type[0]=0;
    type[1]=0;
    if(b[s]!=c[s])
    type[b[s]]++;
    mn[s]=cost[s];
    if(prv!=-1)
    mn[s]=min(mn[s],mn[prv]);
    for(auto it:adj[s])
    {
        if(it!=prv)
        {
            pll rem=dfs(it,s);
            type[rem.first]+=rem.second;
        }
    }

    // cout<<s<<" "<<type[0]<<" "<<type[1]<<endl;

    ll x=min(type[0],type[1]);
    ans+=(2ll*x*mn[s]);

    type[0]-=x;
    type[1]-=x;

    if(type[0]==0 && type[1]==0)
    {
        return make_pair(0,0);
    }
    if(s==0)
    {
        ans=-1;
        return make_pair(0,0);
    }
    if(type[0]>0)
    {
        return make_pair(0,type[0]);
    }
    if(type[1]>0)
    {
        return make_pair(1,type[1]);
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
        for(ll i=0;i<n;i++)
        {
            ll cst,ini,fin;
            cin>>cst>>ini>>fin;
            cost.pb(cst);
            b.pb(ini);
            c.pb(fin);
        }

        adj=vector<V>(n);
        mn=vector<ll>(n);
        rep(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(0,-1);

        cout<<ans<<endl;
        

    }

}