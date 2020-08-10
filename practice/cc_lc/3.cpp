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
vector<bool>vis;
map<pll,vector<ll>>mp1,mp2;
pair<ll,ll>pr;
bool is_cycle=false;

void dfs(ll s, ll prnt, vector<ll>&v)
{
    // cout<<s<<" <---"<<endl;
    vis[s]=true;
    v.pb(s);
    for(auto it:adj[s])
    {
        if(it!=prnt)
        {
            // cout<<" -->"<<it<<endl;
            if(vis[it] && is_cycle==false)
            {
                // cout<<s<<" "<<
                is_cycle=true;
                pr.first=s;
                pr.second=it;
            }
            else if(is_cycle==false)
            pr=make_pair(s,it);
            if(vis[it]==false)
            {
                dfs(it,s,v);
            }
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
        ll n,m;
        cin>>n>>m;
        adj=vector<vector<ll>>(n+1);
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        vis=vector<bool>(n+1,false);

        for(ll i=1;i<n+1;i++)
        {
            if(vis[i]==false)
            {
                vector<ll>v;
                pr.first=i;pr.second=i;

                dfs(i,0,v);

                // cout<<i<<" "<<"==="<<endl;
                // for(auto it:v)
                // cout<<it<<" ";
                // cout<<pr.first<<" "<<pr.second<<endl;
                // cout<<endl;
                // cout<<is_cycle<<endl;
                if(is_cycle==true)
                {
                    mp1[pr]=v;
                }
                else 
                {
                    mp2[pr]=v;
                }
                is_cycle=false;
            }
        }

        // for(auto it:mp1)
        // {
            // cout<<it.first.first<<" "<<it.first.second<<endl;
            // for(auto it2:it.second)
            // cout<<it2<<" ";
            // cout<<endl;
        // }

        // for(auto it:mp2)
        // {
            // cout<<it.first.first<<" "<<it.first.second<<endl;
            // for(auto it2:it.second)
            // cout<<it2<<" ";
            // cout<<endl;
        // }

        ll cst=0;
        if(mp2.size()>1)
        cst+=(mp2.size()-1)*2;
        
        ll flght=m;
        if(mp2.size()>1)
        flght+=(mp2.size()-1);
        
        if(mp2.size()==1 && mp1.size()!=0)
        {
            auto it=*mp2.begin();
            pair<ll,ll> p=it.first;
            if(p.first==p.second)
            {
                cst+=2;
                flght+=1;
            }
        }

        cout<<cst<<" "<<0<<endl;

        mp1.clear();
        mp2.clear();
        vis.clear();
        adj.clear();


    }

}