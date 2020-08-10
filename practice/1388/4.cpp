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

VV adj,adj2;
V a;
ll n,sum=0;
V vis;
deque<ll>dq;

void dfs(ll s)
{
    vis[s]=1;
    ll tmp=0;
    for(auto it:adj[s])
    {
        if(vis[it]==-1)
        {
            dfs(it);
        }
        if(a[it]>=0)
        tmp+=a[it];
    }
    // err2(s,tmp);
    a[s]=tmp+a[s];
    sum+=a[s];
    return;
}

ll find_root(ll s)
{
    vis[s]=1;
    ll root=s;
    for(auto it:adj2[s])
    {
        if(vis[it]==-1)
        root=find_root(it);
    }
    vis[s]=-1;
    return root;
}

void dfs2(ll s)
{
    vis[s]=1;
    for(auto it:adj[s])
    {
        if(a[it]<0)
        {
            dq.push_back(it);
            dfs2(it);
        }
        else 
        {
            dq.push_front(it);
            dfs2(it);
        }
    }
}

int main()
{
    // fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
    // cin>>T;
    while(T--)
    {
        cin>>n;
        adj=VV(n+1);
        adj2=VV(n+1);
        vis=V(n+1,-1);
        a=V(n+1);
        V b(n);
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        rep(i,0,n)
        cin>>b[i];

        rep(i,0,n)
        {
            if(b[i]==-1)
            continue;
            else 
            {
                adj[b[i]-1].push_back(i);
                adj2[i].push_back(b[i]-1);
            }
        }

        for(ll i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                dfs(i);
            }
        }
        // err();
        cout<<sum<<endl;

        vis=V(n+1,-1);

        deque<ll>ans;

        for(ll i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                ll root=find_root(i);
                dq.push_back(root);
                dfs2(root);
                while(!dq.empty())
                {
                    ans.push_back(dq.front());
                    dq.pop_front();
                }
            }
        }

        while(!ans.empty())
        {
            cout<<ans.front()+1<<" ";
            ans.pop_front();
        }
        

    }

}