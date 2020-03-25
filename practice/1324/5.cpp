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
vector<ll>a(3000);
ll n,h,l,r;
ll dp[2020][2020];

ll calc_max(ll tme , ll num)
{
    if(num==n)
    return 0;
    if(dp[tme][num]!=-1)
    return dp[tme][num];
    ll tc=tme+a[num];
    ll is_a=0,is_a2=0;
    if(tc%h>=l && tc%h<=r)is_a=1;
    if((tc-1)%h>=l && (tc-1)%h<=r)is_a2=1;
    
    return dp[tme][num]=max(is_a+calc_max(tc%h,num+1),is_a2+calc_max((tc-1)%h,num+1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>h>>l>>r;
    rep(i,0,n)
    cin>>a[i];

    rep(i,0,2020)
    {
        rep(j,0,2020)
        {
            dp[i][j]=-1;
        }
    }

    cout<<calc_max(0,0);
    
}