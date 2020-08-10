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

ll Merge(vector<ll>&a,ll l1, ll r1, ll l2, ll r2)
{
    ll i=l1,j=l2;
    vector<ll>v2;
    int ans=0;
    while(i<=r1 && j<=r2)
    {
        if(a[i]>a[j])
        {
            ans+=(r1-i+1);
            v2.pb(a[j]);
            j++;
        }
        else 
        {
            v2.pb(a[i]);
            i++;
        }
    }
    while(i<=r1)
    {v2.pb(a[i]);i++;}
    while(j<=r2)
    {v2.pb(a[j]);j++;}
    rep(i,l1,r2+1)
    a[i]=v2[i-l1];
    return ans;
}

ll Mergesort(vector<ll>&a, ll l , ll r)
{
    if(l>=r)
    return 0;
    ll mid=(l+r)/2;
    ll ans=0;
    ans+=Mergesort(a,l,mid);
    ans+=Mergesort(a,mid+1,r);
    ans+=Merge(a,l,mid,mid+1,r);
    return ans;
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<ll>v(n);
        rep(i,0,n)cin>>v[i];
        ll ans=Mergesort(v,0,n-1);
        cout<<ans<<endl;
        return 0;
    }

}