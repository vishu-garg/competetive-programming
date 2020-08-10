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
vector<ll> v;

ll calc(ll l , ll r)
{
    if(l==r)
    return v[l];

    ll mid=(l+r)/2;
    ll num1=calc(l,mid);
    ll num2=calc(mid+1,r);
    // cout<<l<<" "<<r<<" "<<num1<<" "<<num2<<"<---"<<endl;
    if(num1==num2)
    return num1;
    else 
    {
        ll maj=((r-l+1)/2)+1;
        ll cnt1=0,cnt2=0;
        rep(i,l,r+1)
        {
            if(v[i]==num1)cnt1++;
            if(v[i]==num2)cnt2++;
        }
        if(cnt1>=maj)
        return num1;
        else if(cnt2>=maj)
        return num2;
        else 
        return -1;
    }
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
        v=vector<ll>(n);
        rep(i,0,n)cin>>v[i];
        ll ans=calc(0,n-1);
        if(ans!=-1)
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
    }

}