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
VV adj;
V clr;
S st;
void dfs(ll s, ll prv , ll scnd_clr)
{
    ll c=1;
    // ll sz=adj[s].size()+1;
    // cout<<clr[s]<<" "<<sz<<endl;
    // cout<<clr[s]<<" "<<scnd_clr<<"<--"<<endl;
    for(auto it : adj[s])
    {
        if(it!=prv)
        {
            while (c==clr[s] || c==scnd_clr)c++;
            clr[it]=c;
            st.insert(c);
            dfs(it,s,clr[s]);
            c++;
        }
    }
}

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        adj=VV(n);;
        rep(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        // adj[0].pb(-1);
        clr=V(n);
        clr[0]=1;
        st.insert(1);
        dfs(0,-1,0);
        cout<<st.size()<<endl;
        rep(i,0,n)
        cout<<clr[i]<<" ";
    }

}