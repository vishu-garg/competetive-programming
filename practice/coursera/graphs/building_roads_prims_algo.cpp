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

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll> >vec;
        rep(i,0,n)
        {
            ll x,y;
            cin>>x>>y;
            vec.pb({x,y});
        }   
        sort(all(vec));
        
        vector<vector<pair<ll,double> > >adj(n+1);

        rep(i,0,n)
        {
            rep(j,i+1,n)
            {
                double dist=((vec[j].second-vec[i].second)*(vec[j].second-vec[i].second))+((vec[j].first-vec[i].first)*(vec[j].first-vec[i].first));
                dist=sqrt(dist);
                adj[i+1].pb({j+1,dist});
                adj[j+1].pb({i+1,dist});
            }
        }

        

        double cst[n];
        rep(i,1,n+1)
        cst[i]=(double)(INF);
        
        cst[1]=0;
        priority_queue<pair<double,ll> , vector<pair<double,ll> >  ,greater<pair<double,ll> > >pq;

        rep(i,1,n+1)
        pq.push({cst[i],i});
        
        // cout<<pq.top().first<<endl;
        ll vis[n+1]{0};
        
        while(!pq.empty())
        {
            pair<double,ll> pr=pq.top();
            pq.pop();
            ll v=pr.second;
            vis[v]=1;
            for(auto it: adj[v])
            {
                if(vis[it.first]==0 && cst[it.first]>it.second)
                {
                    cst[it.first]=it.second;
                    // cout<<v<<" "<<it.first<<" "<<it.second<<"<---"<<endl;
                    pq.push({cst[it.first],it.first});
                }
            }
        }

        double ans=0;
        rep(i,1,n+1)
        ans+=cst[i];
        cout<<fixed<<setprecision(10)<<ans<<endl;


        
    }

}