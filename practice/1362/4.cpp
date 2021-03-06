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
vector<ll>adj[500005];
vector<ll>vis(500005,-1);
vector<ll>tpc(500005);
bool ok=true;
vector<ll>ans(500005);
void dfs(ll s)
{
    vis[s]=1;
    map<ll,ll>mp;
    for(auto it:adj[s])
    {
        if(vis[it]==1)
        mp[ans[it]]=1;
    }
    for(ll i=1;;i++)
    {
        if(mp[i]==0){ans[s]=i;break;}
    }
    if(ans[s]!=tpc[s])
    {ok=false;}
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }


        rep(i,1,n+1)cin>>tpc[i];
        ll flg=0;
        // vector<ll>ans2;
        // ll cur=0;
        vector<pair<ll,ll>>t2;
        for(ll i=1;i<n+1;i++)
        {
            t2.pb({tpc[i],i});
        }
        sort(all(t2));
        vector<ll>tmp;
        rep(i,0,t2.size())
        {tmp.pb(t2[i].second);}
        vector<ll>ans2;
        rep(i,0,n)
        {
            // if(vis[i]!=-1 || tpc[i]!=1)continue;
            // cur++;
            // vector<ll>vec;
            // ans[i]=1;
            // cout<<tmp[i]<<endl;
            dfs(tmp[i]);
            if(!ok)
            {
                flg=1;
                cout<<"-1";
                break;
            }
            ans2.pb(tmp[i]);
            // cur=1;
        }
        

        if(flg==0)
        {
            for(auto it:ans2)
            cout<<it<<" ";
            cout<<endl;
        }


    }

}