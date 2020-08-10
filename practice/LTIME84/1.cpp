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

vector<V>adj(200005);
vector<ll>prv(200005);
vector<ll>dpth(200005);
vector<ll>a(200005);

void dfs(ll s, ll  p, ll d)
{
    // pth[s]=v;
    // pth[s].pb(s);
    prv[s]=p;
    dpth[s]=d;
    for(auto it:adj[s])
    {
        if(it!=p)
        {
            dfs(it,s,d+1);
        }
    }
}

int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n,q;
        cin>>n>>q;
        a=vector<ll>(n+1);
        // adj=pth=vector<vector<ll>>(n+1);
        rep(i,1,n+1)
        cin>>a[i];

        rep(i,1,n)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        vector<ll>v;

        dfs(1,0,0);


        while(q--)
        {
            ll u,v;
            cin>>u>>v;
            vector<ll>pth;
            if(u==v)
            {
                cout<<"0"<<endl;
                continue;
            }
            pth.pb(a[u]);
            pth.pb(a[v]);
            while(u!=v)
            {
                if(dpth[u]>dpth[v])
                {
                    if(prv[u]!=v)
                    pth.pb(a[prv[u]]);
                    u=prv[u];
                }
                else 
                {
                    if(prv[v]!=u)
                    {
                        pth.pb(a[prv[v]]);
                    }
                    v=prv[v];
                }
                if(pth.size()>100)break;
            }
            // cout<<u<<" "<<v<<" "<<pth.size()<<endl;
            if(pth.size()>100)
            {
                cout<<"0"<<endl;
                continue;
            }
            else 
            {
                vector<ll>freq(101,0),sorted;
                for(auto it:pth)
                freq[it]++;
                for(ll i=1;i<=100;i++)
                {
                    while(freq[i]!=0)
                    {
                        sorted.pb(i);freq[i]--;
                    }
                }
                ll ans=LLONG_MAX;
                for(ll i=1;i<sorted.size();i++)
                {
                    ans=min(ans,sorted[i]-sorted[i-1]);
                }
                cout<<ans<<endl;
            }
        }
    }

}