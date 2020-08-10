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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        rep(i,0,n)
        cin>>a[i];
        ll l[n],r[n];
        l[0]=1;
        rep(i,1,n)
        {
            if(a[i]>a[i-1])
            l[i]=l[i-1]+1;
            else 
            l[i]=1;
        }
        r[n-1]=1;
        repb(i,n-2,0)
        {
            if(a[i]<a[i+1])
            r[i]=r[i+1]+1;
            else 
            r[i]=1;
        }
        if(n==1)
        {
            cout<<1<<endl;
            return 0;
        }
        ll ans=r[1]+1;
        
        // rep(i,0,n)
        // cout<<l[i]<<" "<<r[i]<<"<---"<<endl;
        
        rep(i,1,n-1)
        {
            if(a[i+1]-a[i-1]>1)
            {
                ans=max(ans,l[i-1]+r[i+1]+1);
            }
            else
            {
                ans=max(ans,l[i-1]+1);
                ans=max(ans,r[i+1]+1);
            }
        }
        ans=max(ans,l[n-2]+1);
        cout<<ans<<endl;

    }  

}