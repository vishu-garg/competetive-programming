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
V adj[N];
V  vis(N,false);
V v[N];
V cyc,tmp;
// set<ll>st;
V pos(N,-INF);

bool dfs(ll s,ll cnt)
{
    // cout<<s<<"<=="<<endl;
    tmp.pb(s);
    pos[s]=cnt;
    vis[s]=true;
    if(cnt%2)
    {v[1].pb(s);}
    else 
    {v[0].pb(s);}
    ll length=-1; // length of pur cycle
    for(auto it:adj[s])
    {
        // cout<<it<<"<---"<<endl;
        // cout<<pos[it]<<" "<<pos[s]<<endl;
        if(vis[it]==true && pos[s]-pos[it]>1)
        {
            // cout<<it<<"---"<<endl;
            length=max(length,pos[it]); // finding deepest node that give a cycle
        }
    }
    if(length!=-1) //there is a cycle
    {
        // cout<<length<<endl;
        for(ll i=length;i<=pos[s];i++)
        {
            cyc.pb(tmp[i]);
        }
        return true;
    }
    for(auto it:adj[s])
    {
        if(!vis[it])
        {
            if(dfs(it,cnt+1))
            return true;
        }
    }
    tmp.pop_back();
    return false;
}



int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(1,0);
        // cout<<cyc.size()<<endl;
        if(cyc.size()==0)
        {
            cout<<"1"<<endl;
            ll mx=max(v[0].size(),v[1].size());
            // cout<<v[0].size()<<" "<<v[1].size()<<endl;
            if(mx==v[0].size())
            {
                for(ll i=0;i<(k+1)/2;i++)
                cout<<v[0][i]<<" ";
                cout<<endl;
                return 0;
            }
            else 
            {
                for(ll i=0;i<(k+1)/2;i++)
                cout<<v[1][i]<<" ";
                cout<<endl;
                return 0;   
            }
        }
        else 
        {
            if(cyc.size()<=k)
            {
                cout<<"2"<<endl;
                cout<<cyc.size()<<endl;
                for(auto it:cyc)
                cout<<it<<" ";
                cout<<endl;
            }
            else 
            {
                cout<<"1"<<endl;
                ll cnt1=0;
                ll i=0;
                while(cnt1!=(k+1)/2)
                {
                    cout<<cyc[i]<<" ";
                    i+=2;
                    cnt1++;
                }
                cout<<endl;
            }
        }

    }

}