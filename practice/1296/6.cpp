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
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

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

// vector<vector<ll> >adj;

// bool dfs(ll a,ll b, ll prv , vector<ll> &v)
// {
//     if(a==b)
//     {
//         v.pb(b);
//         return true;
//     }
//     for(auto it : adj[a])
//     {
//         if(it!=prv)
//         {
//             if(dfs(it,b,a,v))
//             {
//                 v.pb(a);
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     ll t=1;
// //     cin>>t;
//     while(t--)
//     {
//         ll n;
//         cin>>n;
//         adj=vector<vector<ll> >(n+1);
//         map<pair<ll,ll>,ll>ans;
//         vector<pair<ll,ll> > v4;
//         rep(i,1,n)
//         {
//             ll u,v;
//             cin>>u>>v;
//             adj[u].pb(v);
//             adj[v].pb(u);
//             ans[{u,v}]=0;
//             ans[{v,u}]=0;
//             v4.pb({u,v});
//         }


//         // ll ans[n+1];
//         // rep(i,0,n+1)
//         // ans[i]=0;

//         ll m;
//         cin>>m;

//         vector<pair< pair<ll,ll>,ll> > v3;
//         rep(i,0,m)
//         {
//             ll a,b,g;
//             cin>>a>>b>>g;
//             v3.pb({{a,b},g});
//             vector<ll> v;
//             dfs(a,b,0,v);
//             rep(i,1,(ll)v.size()){
//             ans[{v[i],v[i-1]}]=max(ans[{v[i],v[i-1]}],g);
//             ans[{v[i-1],v[i]}]=max(ans[{v[i-1],v[i]}],g);}
//         }

//         rep(i,0,n-1)
//         {
//             if(ans[v4[i]]==0)
//             ans[v4[i]]=(1e6);
//         }

//         // rep(i,0,)


//         rep(i,0,m)
//         {
//             ll a=v3[i].first.first;
//             ll b=v3[i].first.second;
//             ll g=v3[i].second;
//             vector<ll> v=dfs(a,b,0);
//             ll mn=1e6;
//             rep(i,1,(ll)v.size())
//             {
//                 mn=min(ans[{v[i],v[i-1]}],mn);
//             }
//             if(mn!=g)
//             {
//                 cout<<"-1";
//                 return 0;
//             }
//         }

//         rep(i,0,n-1)
//         cout<<ans[v4[i]]<<" ";
//     }

// }


// EFFICIENT SOLUTION PRECALCULATE P[i] stroing immediate parents of all vectices when reached from i;

// #include<bits/stdc++.h>
// #include<algorithm>
// using namespace std;
 
// #define ll int
// #define ld long double
 
// #define rep(i,a,b) for(ll i=a;i<b;i++)
// #define repb(i,a,b) for(ll i=a;i>=b;i--)
 
// #define err() cout<<"=================================="<<endl;
// #define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
// #define err1(a) cout<<#a<<" "<<a<<endl
// #define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
// #define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
// #define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
// #define pb push_back
// #define all(A)  A.begin(),A.end()
// #define allr(A)    A.rbegin(),A.rend()
// #define ft first
// #define sd second
 
// #define pll pair<ll,ll>
// #define V vector<ll>
// #define S set<ll>
// #define VV vector<V>
// #define Vpll vector<pll>
 
// #define endl "\n"
 
// const ll logN = 20;
// const ll M = 1000000007;
// const ll INF = 1e12;
// #define PI 3.14159265

// int pow1(int a,int b){
//     int res=1;
//     while(b>0){
//         if(b&1){
//         	res=res*a;
// 		}
//         a=a*a;
//         b>>=1;
//     }
//     return res;
// }

// ll n,m;
// vector<vector<pair<ll,ll> > > g;
// vector<ll> val;

// void dfs(ll v, ll pv, ll pe, vector<pair<ll,ll> >&p)
// {
//     p[v]=make_pair(pv,pe);
//     for(auto it : g[v])
//     {
//         ll to=it.first;
//         ll idx=it.second;
//         if(to==pv)continue;
//         dfs(to,v,idx,p);
//     }
// }

// int main()
// {
//     cin>>n;
//     g=vector<vector<pair<ll,ll> > >(n);
//     rep(i,0,n-1)
//     {
//         ll u,v;
//         cin>>u>>v;
//         u--,v--;
//         g[u].pb(make_pair(v,i));
//         g[v].pb(make_pair(u,i));
//     }

//     vector<vector<pair<ll,ll> > >p(n,vector<pair<ll,ll> >(n));
//     for(ll i=0;i<n;i++)
//     dfs(i,-1,-1,p[i]);

//     val=vector<ll>(n-1,1e6);

//     cin>>m;

//     vector<pair<pair<ll,ll>,ll> >q(m);
//     rep(i,0,m)
//     {
//         cin>>q[i].first.first>>q[i].first.second>>q[i].second;
//         --q[i].first.first;
//         --q[i].first.second;
//     }

//     sort(q.begin(),q.end(),[&](pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll>b){
//         return a.second<b.second;
//     });

//     for(ll i=0;i<m;i++)
//     {
//         ll u=q[i].first.first;
//         ll v=q[i].first.second;
//         while(v!=u)
//         {
//             ll pv=p[u][v].first;
//             ll pe=p[u][v].second;
//             val[pe]=q[i].second;
//             v=pv;
//         }
//     }

//     for(ll i=0;i<m;i++)
//     {
//         ll u=q[i].first.first;
//         ll v=q[i].first.second;
//         ll mx=1e6;
//         while(v!=u)
//         {
//             ll pv=p[u][v].first;
//             ll pe=p[u][v].second;
//             mx=min(mx,val[pe]);
//             v=pv;
//         }
//         if(mx!=q[i].second)
//         {
//             cout<<"-1";
//             return 0;
//         }
//     }

//     rep(i,0,n-1)
//     cout<<val[i]<<" ";
//     return 0;
// }