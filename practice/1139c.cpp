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
    return (res)%M;
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

vector<V>adj;

vector<ll>vis;


ll dfs(ll s, ll  prv)
{
    vis[s]=1;
    ll cnt2=1;
    for(auto it:adj[s])
    {
        if(it!=prv)
        {
            if(vis[it]!=1)
            {
                cnt2+=dfs(it,s);
            }
        }
    }
    return cnt2;
}


int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,k;
        cin>>n>>k;
        adj=vector<vector<ll> >(n+1);
        vis=vector<ll>(n+1,0);
        vector<pll>v1;
        rep(i,1,n)
        {
            ll u,v,clr;
            cin>>u>>v>>clr;
            if(clr==0){
            adj[u].pb(v);
            adj[v].pb(u);}
            if(clr==1)
            v1.pb(make_pair(u,v));
        }

        if(v1.size()==0)
        {
            cout<<"0"<<endl;
            return 0;
        }   


        V cnt;
        rep(i,1,n+1)
        {
            if(vis[i]==0)
            {
                ll cnt1=dfs(i,0);
                // cout<<i<<" "<<cnt1<<endl;
                cnt.pb(cnt1);
            }
        }
        
        ll tot=pow1(n,k);

        for(auto it:cnt)
        {
            // cout<<it<<endl;
            tot=(tot-pow1(it,k)+M)%M;
        }
        cout<<tot<<endl;


    }

}