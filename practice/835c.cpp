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
ll cnt[11][105][105];
// cnt[0][0][0]=0;
int main()
{
    ll n,q,c;
    cin>>n>>q>>c;
    rep(i,0,n)
    {
        ll x,y,s;
        cin>>x>>y>>s;
        cnt[s][x][y]++;
    }
    rep(i,0,c+1)
    {
        rep(x,1,101)
        rep(y,1,101)
        {
            cnt[i][x][y]+=cnt[i][x-1][y]+cnt[i][x][y-1]-cnt[i][x-1][y-1];
        }
    }

    rep(i,0,q)
    {
        ll t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        ll ans=0;
        rep(i,0,c+1)
        {
           ll tmp=(i+t)%(c+1);
           ll amnt=cnt[i][x2][y2]-cnt[i][x2][y1-1]-cnt[i][x1-1][y2]+cnt[i][x1-1][y1-1];
           ans+=(amnt*tmp); 
        }
        cout<<ans<<endl;
    }
}