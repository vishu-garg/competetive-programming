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

int main()
{
    fast;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {


        ll n;
        cin>>n;
        Vpll coord(n);
        rep(i,0,n)
        cin>>coord[i].first>>coord[i].second;
        V c(n);
        rep(i,0,n)
        cin>>c[i];
        V k(n);
        rep(i,0,n)
        cin>>k[i];


        V par(n),cst(n);

        rep(i,0,n)
        {
            par[i]=-1;
            cst[i]=c[i];
        }

        ll ans=0;
        V power_plants;
        Vpll connection;

        vector<bool> used(n,false);

        for(ll i=0;i<n;i++)
        {
            ll v=-1;
            for(ll i=0;i<n;i++)
            {
                if(!used[i] && (v==-1 || cst[v]>cst[i]))
                v=i;
            }
            ans+=cst[v];
            if(par[v]==-1)
            {
                power_plants.pb(v+1);
            }
            else 
            {
                connection.pb({v+1,par[v]+1});
            }

            used[v]=true;

            for(ll i=0;i<n;i++)
            {
                if(!used[i] && cst[i]>((abs(coord[i].first-coord[v].first)+abs(coord[i].second-coord[v].second))*(k[i]+k[v])))
                {
                    cst[i]=(abs(coord[i].first-coord[v].first)+abs(coord[i].second-coord[v].second))*(k[i]+k[v]);
                    par[i]=v;
                }
            }

        }

        cout<<ans<<endl;

        cout<<power_plants.size()<<endl;
        errA(power_plants);

        cout<<connection.size()<<endl;
        for(auto it:connection)
        cout<<it.first<<" "<<it.second<<endl;


    }

}