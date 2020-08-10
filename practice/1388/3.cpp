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
V c,h,c2;

bool ok=true;

pair<ll,ll> dfs(ll s,ll prv)
{
    // cout<<s<<endl;
    ll min_gd=0;
    ll tot_bd=0;
    ll tot=c[s];
    // err2(s,tot);
    for(auto it:adj[s])
    {
        if(it==prv)continue;
        pll p=dfs(it,s);
        min_gd+=p.first;
        tot_bd+=p.second;
        // err2(it,c[it]);
        tot+=c2[it];
    }

    c2[s]=tot;

    // c[s]=tot;
    // err2(s,tot);

    ll new_h=h[s];

    ll sum=(tot);

    ll tmp1=(sum+new_h);

    // err2(s,tot);


    if(tmp1%2!=0)
    {
        // err2(s,tmp1);
        // c[s]=tot;
        ok=false;
        return {0,0};
    }

    ll gd=tmp1/2;ll bd=sum-(gd);

    // err3(s,gd,bd);

    if(gd<0 || bd<0)
    {
        ok=false;
        return {0,0};
    }



    ll req=(bd-tot_bd);
    
    if(req<0)
    {
        ll tmp2=gd;ll tmp3=bd;

        gd-=abs(req);

        gd-=c[s];

        if(gd!=min_gd)
        {
            // c[s]=tot;
            ok=false;
            return {0,0};
        }

        else 
        {
            // c[s]=tot;
            return {tmp2,tmp3};
        }

    }

    else 
    {
        ll tmp2=gd;ll tmp3=bd;
        if(req>c[s])
        {
            // c[s]=tot;
            ok=false;
            return {0,0};
        }

        c[s]-=req;

        gd-=c[s];

        if(min_gd!=gd)
        {
            // c[s]=tot;
            ok=false;
            return {0,0};
        }
        else 
        {
            // c[s]=tot;
            return {tmp2,tmp3};
        }

    }



    // err3(s,gd,bd);
    // err4(gd,min_gd,bd-c[s],tot_bd);

    // if(tmp1%2!=0 || gd<min_gd || bd<0 || gd<0 || bd-c[s]>tot_bd)
    // {
    //     ok=false;
    //     return {0,0};
    // }
    
    // // err3(s,gd,min_gd);
    // else 
    // {
    //     c[s]=tot;
    //     return {gd,max(bd,tot_bd)};
    // }

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
        ok=true;
        ll n,m;
        cin>>n>>m;
        c=V(n+1);
        h=V(n+1);
        c2=V(n+1);
        adj=VV(n+1);

        // err();
        
        rep(i,1,n+1)
        cin>>c[i];

        rep(i,1,n+1)
        cin>>h[i];

        rep(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        // err();
        dfs(1,0);
        
        if(ok)
        {
            cout<<"YES"<<endl;
        }
        else 
        cout<<"NO"<<endl;

    }

}


// 20 167
// 19 16 18 20 0 0 13 0 0 18 0 26 14 0 0 23 0 0 0 0
// -5 -16 -18 -20 0 0 -13 0 0 -18 0 -44 -14 -6 0 -23 0 0 0 0
// 1 9
// 18 12
// 4 14
// 17 1
// 1 12
// 12 8
// 14 1
// 20 1
// 12 13
// 2 12
// 15 12
// 7 19
// 7 1
// 3 12
// 1 10
// 16 6
// 12 11
// 1 5
// 1 16