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
bool visited[100005];
stack<ll> st;
vector<vector<ll> > adj(100005);
vector<vector<ll> > scc(100005);
ll n,m,cost[100005];

void fillorder(ll s)
{
    visited[s]=true;
    rep(i,0,adj[s].size())
    {
        if(visited[adj[s][i]]==false)
        fillorder(adj[s][i]);
    }
    st.push(s);
}


vector<vector<ll> > gettranspose()
{
    vector<vector<ll> > lst(100005);

    rep(i,0,n)
    {
        rep(j,0,adj[i].size())
        lst[adj[i][j]].pb(i);
    }
    return lst;
} 

void dfsutil(ll s, ll k)
{
    visited[s]=true;
    scc[k].pb(s);
    rep(i,0,adj[s].size())
    {
        if(visited[adj[s][i]]==false)
        dfsutil(adj[s][i],k);
    }
}

int main()
{
    cin>>n;
    rep(i,0,n)
    cin>>cost[i];
	cin>>m;
    rep(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
    }
    
    rep(i,0,n)
    visited[i]=false;
    
	rep(i,0,n)
    {
        if(visited[i]==false)
        fillorder(i);
    }
    
//    rep(i,0,n)
//    {
//    	rep(j,0,adj[i].size())
//    	cout<<adj[i][j]<<" ";
//    	cout<<endl;
//	}
    
//    err()
    adj=gettranspose();
    
//    rep(i,0,n)
//    {
//    	rep(j,0,adj[i].size())
//    	cout<<adj[i][j]<<" ";
//    	cout<<endl;
//	}

    rep(i,0,n)
    visited[i]=false;

    ll k=0;
	

    while(!st.empty())
    {
        int v=st.top();
//        cout<<v<<" ";
        st.pop();
        if(visited[v]==false)
        {
            dfsutil(v,k);
//            err()
//            rep(i,0,scc[k].size())
//            cout<<scc[k][i]<<" ";
//            cout<<endl;
            k++;
        }
    }
//    err()
//    cout<<k;
    ll ans=1;
    ll tot_cost=0;
    rep(i,0,k)
    {
        rep(j,0,scc[i].size())
        {
            scc[i][j]=cost[scc[i][j]];
        }
        sort(scc[i].begin(),scc[i].end());
        ll tmp=*(scc[i].begin());
        tot_cost+=tmp;
        ll ans_tmp=count(scc[i].begin(),scc[i].end(),tmp);
        ans=(((ans)%M)*((ans_tmp)%M))%M;
    }
    cout<<tot_cost<<" "<<ans%M<<endl;
}