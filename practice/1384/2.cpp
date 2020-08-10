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

VV vis,v;
ll n,k,l;

void dfs(ll i, ll j)
{
    // err2(i,j);
    if(j>=n+2)return;
    if(vis[i][j]==1)return;
    vis[i][j]=1;
    // cout<<v[i][j]<<endl;
    if(v[i][j]>l)return;
    ll nxt1_i=(i+1)%(2*k),nxt1_j=(j+1);
    ll nxt2_i=(i+1)%(2*k),nxt2_j=(j);
    // err2(nxt1_i,nxt1_j);
    dfs(nxt1_i,nxt1_j);
    dfs(nxt2_i,nxt2_j);
    return;
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
        cin>>n>>k>>l;
        V a(n);
        rep(i,0,n)
        cin>>a[i];
        // err1(n);
        // errA(a);

        V d(2*k);
        rep(i,0,2*k)
        {
            if(i<=k)d[i]=i;
            else d[i]=(2*k)-i;
        }

        v=VV(2*k);
        rep(i,0,2*k)
        {
            v[i].pb(0);
            for(auto it:a)
            v[i].pb(it);
            rep(j,1,n+1)
            {
                v[i][j]+=d[i];
            }
            // errA(v[i]);
            v[i].pb(0);
            // errA(v[i]);
        }

        vis=VV(2*k,V(n+2,-1));

        dfs(0,0);

        ll flg=0;
        for(ll i=0;i<2*k;i++)
        {
            if(vis[i][n+1]==1)
            {
                flg=1;
                break;
            }
        }

        if(flg==1)
        {
            cout<<"Yes"<<endl;
        }
        else 
        {
            cout<<"No"<<endl;
        }


        
    }

}