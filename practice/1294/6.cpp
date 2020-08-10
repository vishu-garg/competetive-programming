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
V p;

pair<ll,ll> dfs(ll v , ll par , ll dist)
{
    p[v]=par;
    pair<ll,ll>p1=make_pair(dist,v);
    for(auto it:adj[v])
    {
        if(it==par)
        continue;
        pll p2=dfs(it,v,dist+1);
        if(p2.first>p1.first)
        p1=p2;
    }
    return p1;
}

int main()
{
    fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        adj=VV(n+1);
        p=V(n+1);

        rep(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        pair<ll,ll>p1=dfs(1,0,0);   // find first deepest node
        pll p2=dfs(p1.second,0,0);               // find deepest from deepest node 

        vector<ll>v;

        ll node=p2.second;
        

        while(node!=p1.second)
        {
            v.pb(node);
            node=p[node];
        }
        
        v.pb(p1.second);

        if(v.size()==n)
        {
            cout<<n-1<<endl;
            cout<<v[0]<<" "<<v[1]<<" "<<v.back()<<endl;
            return 0;
        }

        queue<ll>q;
        V  tmp(n+1,-1);

        for(auto it:v)
        {
            q.push(it);
            tmp[it]=0;
        }

        while(!q.empty())
        {
            ll frnt=q.front();q.pop();

            for(auto it:adj[frnt])
            if(tmp[it]==-1)
            {
                q.push(it);
                tmp[it]=tmp[frnt]+1;
            }
        }

        pll p3=make_pair(tmp[1],1);

        for(ll i=2;i<=n;i++)
        {
            if(p3.first<tmp[i])
            {
                p3=make_pair(tmp[i],i);
            }
        }

        cout<<v.size()-1+p3.first<<endl;
        cout<<p1.second<<" "<<p2.second<<" "<<p3.second<<endl;


    }

}