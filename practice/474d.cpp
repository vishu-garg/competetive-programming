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

int main()
{
    ll t=1,k;
    cin>>t>>k;
    ll arr[100005];
    arr[0]=1;
    arr[1]=1;
    if(k==1)
    arr[1]=2;
    rep(i,2,100001)
    {
        arr[i]+=(arr[i-1])%M;
        if(i-k)>=0
        arr[i]+=(arr[i-k])%M;
        arr[i]%=M;
    }

    rep(i,2,100001)
    {
        arr[i]+=arr[i-1];
        arr[i]%=M;
    }
    arr[0]=0;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll ans=(arr[b]-arr[a-1]+M)%M;
        cout<<ans<<endl;
    }
}