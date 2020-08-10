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

vector<vector<ll>>adj;
V A,B;
vector<bool> vis2;

// void dfs1(ll s, vector<ll>&cmp)
// {
//     vis[s]=true;
//     cmp.pb(s);
//     for(auto it:adj[s])
//     {
//         if(!vis[it])
//         dfs1(it,cmp);
//     }
// }

void dfs2(ll s, ld val, V& vec)
{
    vis2[s]=true;
    vec.pb(s);
    for(auto it:adj[s])
    {
        if(vis2[it])continue;
        ld val1=(ld)A[it]/(ld)B[it];
        if(val1==val)
        dfs2(it,val,vec);
    }
}

int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        A=vector<ll>(n+1);
        B=vector<ll>(n+1);
        rep(i,1,n+1)cin>>A[i];
        rep(i,1,n+1)cin>>B[i];
        adj=vector<vector<ll>>(n+1);
        vis2=vector<bool>(n+1,false);
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        // rep(i,1,n+1)
        // {  
        //     if(vis[i])continue;
        //     vector<ll>cmp;
        //     dfs1(i,cmp);
        //     conn.pb(cmp);
        // }
        // vector<ld> tmp2;
        // for(auto v:conn)
        // {
        //     ld mx=0;
        //     rep(i,0,v.size())
        //     {
        //         mx=max(mx,(ld)(A[v[i]])/(ld)(B[v[i]]));
        //     }
        //     tmp2.pb(mx);
        // }

        // sort(all(tmp2));
        // vector<ll>tmp3;
        // ld ans=tmp2.back();
        // repb(i,tmp2.size()-1,0)
        // {
        //     if(tmp2[i]==ans)
        //     tmp3.pb(i);
        // }
        vector<pair<ld,ll>>vec;
        rep(i,1,n+1)
        {
            ld val_tmp=(ld)(A[i])/(ld)(B[i]);
            vec.pb(make_pair(val_tmp,i));
        }
        sort(all(vec));
        ld ans=vec.back().first;
        V main_vec;

        for(auto it:vec)
        {
            if(vis2[it.second])continue;

            if(it.first!=ans)continue;
            vector<ll>tmp;
            dfs2(it.second,it.first,tmp);
            if(tmp.size()>main_vec.size())
            main_vec=tmp;
        }

        cout<<main_vec.size()<<endl;
        for(auto it:main_vec)
        cout<<it<<" ";
        cout<<endl;


    }

}