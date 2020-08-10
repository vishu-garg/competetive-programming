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




map<pll,ll>mp;
vector<vector<pair<ll,ll>>> adj;
ll n,s;


int dfs(ll s, ll prv)
{
    if(adj[s].size()==1 && s!=1)
    {
        return 1;
    }
    // err2(s,prv);
    ll tot=0;
    for(auto it:adj[s])
    {
        if(it.first!=prv)
        {
            ll cnt=0;
            cnt=dfs(it.first,s);
            tot+=cnt;
            // err3(s,it.first,cnt);
            mp[{s,it.first}]+=cnt;
        }
    }
    return tot;
}

int main()
{
    // fast;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll T=1;
    // cin>>T;
    while(T--)
    {
        cin>>n;


        // err();
        map<pll,ll>mp2;

        adj=vector<Vpll>(n+2);

        rep(i,0,n-1)
        {
            ll u,v,w;
            cin>>u>>v>>w;

            // err3(u,v,w);

            // cout<<adj.size();

            adj[u].pb({v,w});
            adj[v].pb({u,w});

            mp2[{u,v}]=w;
            mp2[{v,u}]=w;


        }

        // err();

        ll c;
        cin>>c;
        

        dfs(1,0);

        // err();

        ll cnt=0;
        ll sum=0;
        vector<ll>tmp;
        for(auto it:mp)
        {
            // err();
            ll u=it.first.first,v=it.first.second;
            ll w=mp2[{u,v}];
            ll w2=w*it.second;
            // if(w==7)
            // {
            //     cout<<it.second<<endl;
            // }
            tmp.pb(w2);
            // err4(u,v,w,w2);
            // err2(sum,it.second);
        }

        // cout<<sum;
        // ll sum=0;
        sort(all(tmp));
        reverse(all(tmp));
        ll i=0;
        errA(tmp);
        while(i<tmp.size())
        {
            if(c>0){
            sum+=0;
            c--;
            i++;}
            else 
            {
                err1(tmp[i]);
                sum+=tmp[i];
                i++;
            }
        }

        cout<<sum<<endl;

        
        // err();
        
        mp.clear();

        // err();

        




        
        
        



    }

}