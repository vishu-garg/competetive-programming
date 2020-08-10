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
ll pow1(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
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

VV adj;
V depth,vis,parent;

void dfs(ll src, ll par, ll dpth)
{
    // err2(src,dpth);
    vis[src]=1;
    depth[src]=dpth;
    parent[src]=par;
    for(auto it:adj[src])
    {
        if(vis[it]==0)
        {
            dfs(it,src,dpth+1);
        }
    }
}

int main()
{
    fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        adj=VV(n+1);
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        parent=depth=vis=V(n+1,0);

        dfs(1,0,1);

        ll node=-1;
        for(int i=1;i<n+1;i++)
        {
            if(depth[i]>(n+1)/2)
            {
                node=i;
            }
        }
        if(node!=-1)
        {
            vector<ll>tmp;
            while(node!=0)
            {
                tmp.pb(node);
                node=parent[node];
            }
            cout<<"PATH"<<endl;
            cout<<tmp.size()<<endl;
            errA(tmp);
        }
        else 
        {
            // sort(all(depth));
            vector<pll>tmp1;
            for(int i=1;i<=n;i++)
            tmp1.pb({depth[i],i});
            sort(all(tmp1));
            vector<pll>tmp;
            for(ll i=0;i<tmp1.size()-1;i++)
            {
                if(tmp1[i].first==tmp1[i+1].first)
                {
                    // cout<<tmp1[i].first<<" "<<tmp1[i+1].first<<endl;
                    // cout<<tmp1[i].second<<" "<<tmp1[i+1].second<<endl;
                    tmp.pb({tmp1[i].second,tmp1[i+1].second});
                    i++;
                }
            }
            cout<<"PAIRING"<<endl;
            cout<<tmp.size()<<endl;
            for(auto it:tmp)
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}