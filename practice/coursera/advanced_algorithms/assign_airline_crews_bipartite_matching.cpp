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
ll n,m;
vector<vector<ll> > adj,adj2;
vector<ll> ans;

ll bfs(ll s, ll t, vector<ll>& parent)
{
//	err()
    fill(all(parent),-1);
    parent[s]=-2;
    queue<pll>  q;
    q.push({s,LLONG_MAX});
    while(!q.empty())
    { 
        ll cur=q.front().first;
        ll flow=q.front().second;
        q.pop();
//        cout<<cur<<"<-- "<<endl;
        for(ll i=0;i<adj2[cur].size();i++)
        {
            ll next=adj2[cur][i];
            if(parent[next]==-1 && adj[cur][next]>0)
            {
                parent[next]=cur;
                ll new_flow=min(flow,adj[cur][next]);
                if(next==t)
                return new_flow;
                q.push({next,new_flow});
            }
        }
    }
    return 0;

}

void print_match()
{
//	err()
    ll s=0;
    ll t=n+m+1;
    vector<ll>parent(n+m+2);
    ll flow;
//    cout<<bfs(s,t,parent);
    while(flow=bfs(s,t,parent))
    {
//    	err()
//    	cout<<endl;
//        ll crew_num=parent[n+m+1];
//        ll flight_num=parent[crew_num];
//        crew_num-=n;
//        ans[flight_num]=crew_num;
//        ll st=0;
//       cout<<crew_num<<" "<<flight_num<<" <==="<<endl;
//        while(parent[st]!=0)
//        st++;
//        cout<<st<<" ";err()
//        ll tmp=0;
//        while(parent[tmp]!=st)
//        tmp++;
//        cout<<tmp<<" ";err()
//        ans[st]=tmp-n;
        ll cur=t;
        ll st,tmp;
        while(cur!=s)
        {
            ll prev=parent[cur];
            adj[prev][cur]-=flow;
            adj[cur][prev]+=flow;
            if(prev<=n && prev>0 && cur<n+m+1 && cur>n)
            ans[prev]=cur-n;
            cur=prev;
        }
//        cur=t;
//        while(cur!=st)
//        {
//        	ll prev=parent[cur];
//        	if(prev==st)
//        	tmp=cur;
//        	cur=prev;
//		}
//		ans[st]=tmp-n;
    }
}

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        // ll n,m;
        cin>>n>>m;
        adj=vector<vector<ll> >(n+m+2,vector<ll>(n+m+2,0));
        adj2=vector<vector<ll> >(n+m+2);
        ans=vector<ll>(n+1,-1);
        rep(i,1,n+1)
        {
            adj[0][i]=1;
            adj2[0].pb(i);
            adj2[i].pb(0);
        }

        rep(i,n+1,n+m+1)
        {
            adj[i][n+m+1]=1;
            adj2[i].pb(n+m+1);
            adj2[n+m+1].pb(i);
        }

        rep(i,1,n+1)
        {
            rep(j,n+1,n+m+1)
            {
                int tmp;
                cin>>tmp;
                if(tmp==1)
                {
                    adj2[i].pb(j);
                    adj2[j].pb(i);
                    adj[i][j]=1;
                }
            }
        }
//		err()
        print_match();
        rep(i,1,n+1)
        cout<<ans[i]<<" ";
        cout<<endl;

    }

}