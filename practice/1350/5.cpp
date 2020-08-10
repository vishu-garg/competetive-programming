#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll int
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

ll n,m,t;

vector<vector<ll> >adj,island,vis;
queue<pll> q;

void find_island(ll i, ll j)
{
//	cout<<i<<" "<<j<<" *****  "<<endl;
    vis[i][j]=1;
    if(i+1<n && adj[i+1][j]==adj[i][j])
    {
        island[i][j]=0;
        island[i+1][j]=0;
    }
    if(i-1>=0  && adj[i-1][j]==adj[i][j])
    {
        island[i-1][j]=0;
        island[i][j]=0;
    }
    if(j+1<m  && adj[i][j+1]==adj[i][j])
    {
        island[i][j+1]=0;
        island[i][j]=0;
    }
    if(j-1>=0  && adj[i][j-1]==adj[i][j])
    {
        island[i][j-1]=0;
        island[i][j]=0;
    }
//    err()
    if(i+1<n && vis[i+1][j]==-1)
    find_island(i+1,j);
    if(j+1<m && vis[i][j+1]==-1)
    find_island(i,j+1);
    if(i-1>=0 && vis[i-1][j]==-1)
    find_island(i-1,j);
    if(j-1>=0 && vis[i][j-1]==-1)
    find_island(i,j-1);
//    if(i==0 && j==1)
//    {
//    	cout<<island[i][j]<<"<---"<<endl;
//    	cout<<island[i+1][j]<<"<--"<<endl;
//    	cout<<island[i][j+1]<<"<---"<<endl;
//    	cout<<island[i][j-1]<<"<---"<<endl;
////    	cout<<island[i-1][j]<<"<---"<<endl;
//	}
//    if(i+1<n)island[i][j]=min(island[i+1][j]+1,island[i][j]);
//    if(i-1>=0)island[i][j]=min(island[i][j],island[i-1][j]+1);
//    if(j-1>=0)island[i][j]=min(island[i][j],island[i][j-1]+1);
//    if(j+1<m)island[i][j]=min(island[i][j],island[i][j+1]+1);
//    cout<<i<<" "<<j<<" ===== "<<island[i][j]<<endl;
}

void bfs()
{
	while(!q.empty())
	{
		pll pr=q.front();
        ll i=pr.first,j=pr.second;
		q.pop();
		
		ll dst=island[i][j];
        if(i+1<n && vis[i+1][j]==-1)
        {
            island[i+1][j]=min(island[i+1][j],dst+1);
            q.push({i+1,j});
            vis[i+1][j]==1;
        }
        if(i-1>=0 && vis[i-1][j]==-1)
        {
            island[i-1][j]=min(island[i-1][j],dst+1);
            q.push({i-1,j});
            vis[i-1][j]=1;
        }
        if(j-1>=0 && vis[i][j-1]==-1)
        {
            island[i][j-1]=min(island[i][j-1],dst+1);
            q.push({i,j-1});
            vis[i][j-1]=1;
        }
        if(j+1<m && vis[i][j+1]==-1)
        {
            island[i][j+1]=min(island[i][j+1],dst+1);
            q.push({i,j+1});
            vis[i][j+1]=1;
        }
	}
}

int main()
{
     fast;
    ll T=1;
//     cin>>t;
    while(T--)
    {
        // ll n,m,t;
        cin>>n>>m>>t;
        adj=vector<vector<ll> >(n,vector<ll>(m));
        vis=vector<vector<ll> >(n,vector<ll>(m,-1));
        island=vector<vector<ll> >(n,vector<ll>(m,INF));
//        string s[n];
        // cout<<"here"<<endl;
        rep(i,0,n)
       	rep(j,0,m)
       	{
       		char ch;cin>>ch;
			   adj[i][j]=ch-'0';	
		}
        
        
        
        find_island(0,0);
        
//        rep(i,0,n)
//        {rep(j,0,m)
//        cout<<island[i][j]<<" ";cout<<endl;}
        
        vis=vector<vector<ll> >(n,vector<ll>(m,-1));

        rep(i,0,n)
        rep(j,0,m){
            if(island[i][j]==0){q.push({i,j});vis[i][j]=1;}
        }
        
        bfs();
        
//        err()
//        
//        rep(i,0,n)
//        {rep(j,0,m)
//        cout<<island[i][j]<<" ";cout<<endl;}
//        
//        err()
        
//        rep(i,0,n)
//        {
//        	rep(j,0,m)
//        	{
//        		if(island[i][j]==LLONG_MAX-1ll || island[i][j]==LLONG_MAX)
//        		island[i][j]=-1;
//			}
//		}
//		cout<<LLONG_MAX-1ll<<endl;
//		rep(i,0,n)
//		{
//			rep(j,0,m)
//			cout<<island[i][j]<<" ";
//			cout<<endl;
//		}
		while(t--)
		{
			int i,j;
			long long p;
			cin>>i>>j>>p;
			i--;j--;
			if(island[i][j]==INF || p<=island[i][j])
			{
				cout<<adj[i][j]<<endl;
				continue;
			}
			else 
			{
				ll num=p-island[i][j];
//				cout<<num<<" "<<adj[i][j]<<" <---"<<endl;
				if(num%2==0)
				cout<<adj[i][j]<<endl;
				else 
				cout<<(adj[i][j]^1)<<endl;
			}
		}
		
//        err()
        return 0;
    }

}