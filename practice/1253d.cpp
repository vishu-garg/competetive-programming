//https://codeforces.com/problemset/problem/1253/D
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

vector<vector<ll> >adj(200005);
vector<ll> vis(200005);
vector<ll> comp;

void dfs(ll src)
{
    comp.pb(src);
    vis[src]=1;
    for(auto it : adj[src])
    {
        if(vis[it]==0)
        {
            dfs(it);
        }
    }
}

int main()
{
    ll t=1;
//    cin>>t;
    while(t--)
    {
       ll n,m;
       cin>>n>>m;
        rep(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        rep(i,1,n+1)
        vis[i]=0;

        ll mx=0,ans=0;

        rep(i,1,n+1)
        {
            if(vis[i]==0)
            {
                comp.clear();
                dfs(i);
                sort(all(comp));
                if(comp[0]<mx)
                ans++;
                mx=max(comp.back(),mx);
            }
        }
        cout<<ans;
    }

}

//We can also do it using union find method instead of DFS.
//Code using UNION FIND:



/*
    #include<bits/stdc++.h>

    #define forn(i, n) for (int i = 0; i < (int)(n); ++i)
    #define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
    #define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
    #define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
    #define pb push_back
    #define ms(a, x) memset(a, x, sizeof(a))

    #define endl '\n'
    using namespace std;

    const int INF = 0x3f3f3f3f;
    typedef long long ll;
    typedef pair<int, int> pii;
    const int N=2e5+5;
    int pre[N];
    int mx[N],mn[N];
    int find(int x){
        return x==pre[x]?x:pre[x]=find(pre[x]);
    }
    void join(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy) return;
        pre[fx]=fy;
        mx[fy]=max(mx[fy],mx[fx]);
        mn[fy]=min(mn[fy],mn[fx]);
    }
    bool vis[N];
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n,m;
        cin>>n>>m;
        for1(i,n){
            pre[i]=mx[i]=mn[i]=i;
        }
        forn(i,m){
            int x,y;
            cin>>x>>y;
            join(x,y);
        }
        int ans=0;
        for1(i,n){
            int tmp=find(i);
            if(!vis[tmp]){
                vis[tmp]=1;
                for(int j=mn[tmp];j<=mx[tmp];j++){
                    if(find(j)!=find(i)){
                        join(i,j);
                        ans++;
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
*/