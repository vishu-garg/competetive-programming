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
        V a(n);
        rep(i,0,n)
        cin>>a[i];
        ll m;
        cin>>m;
        V b(m);
        rep(i,0,m)
        cin>>b[i];
        ll l;
        cin>>l;
        V c(l);
        rep(i,0,l)
        cin>>c[i];
        ll ans[n+1][m+1][l+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(ll k=0;k<=l;k++)
                {
                    if(i==0 || j==0 || k==0)
                    ans[i][j][k]=0;
                    else if(a[i-1]==b[j-1]&& b[j-1]==c[k-1])
                    ans[i][j][k]=ans[i-1][j-1][k-1]+1;
                    else 
                    ans[i][j][k]=max(ans[i-1][j][k],max(ans[i][j-1][k],ans[i][j][k-1]));
                }
            }
        }
        cout<<ans[n][m][l];
    }

}