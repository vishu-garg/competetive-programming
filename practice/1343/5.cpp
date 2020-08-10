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

vector<vector<ll> > adj(200005);


// BY  BFS WE CALCULATED THE MINIMUM DISTANCE OF EVERY NODE FROM SOURCE NODE a
void bfs(ll a, vector<ll>& d)
{
    d[a]=0;
    queue<ll> q;
    q.push(a);
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        for(auto it : adj[v])
        {
            if(d[it]==INF){
                d[it]=d[v]+1;
                q.push(it);
            }
        }
    }
}

int main()
{
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;

        ll p[m],arr[m+1];

        rep(i,0,m)
        cin>>p[i];
        sort(p,p+m);
        arr[0]=0;
        rep(i,1,m+1)
        arr[i]=p[i-1]+arr[i-1];


        adj=vector<vector<ll> >(n+1);

        rep(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        vector<ll> da(n+1,INF),db(n+1,INF),dc(n+1,INF);
        bfs(a,da);
        bfs(b,db);
        bfs(c,dc);

        ll ans=LLONG_MAX;
        rep(i,1,n+1)
        {
            if(da[i]+db[i]+dc[i]<=m)
            {
                // roads from i->b will be visited twice and i->a & i->c will be visited once
                ll tmp=arr[db[i]];
                tmp+=arr[db[i]+da[i]+dc[i]];
                ans=min(ans,tmp);
            }
        }

        cout<<ans<<endl;
    }

}