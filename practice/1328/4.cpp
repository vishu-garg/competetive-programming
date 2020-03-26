#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 

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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        rep(i,0,n)cin>>a[i];
        ll ans[n];
        ll x=1;
        ans[0]=1;
        ll ind=-1;
        rep(i,1,n)
        {
            if(a[i]==a[i-1]){ans[i]=ans[i-1];ind=i;}
            else 
            {
                if(ans[i-1]==1)
                ans[i]=2;
                else 
                ans[i]=1;
            }
        }
        // rep(i,0,n)
        // cout<<ans[i]<<" ";
        cout<<endl;
        if(a[n-1]==a[0] || (a[n-1]!=a[0] && ans[n-1]!=ans[0]))
        {
           ll cnt=1;
           rep(i,0,n)
           {
               if(ans[i]==2)
               {
                   cnt=2;
                   break;
               }
           }
           cout<<cnt<<endl;
           rep(i,0,n)
           cout<<ans[i]<<" ";
           cout<<endl;
           continue;    
        }
        if(ind!=-1)
        {
            // cout<<"## "<<ind<<endl;
            rep(i,ind,n)
            {
                if(ans[i]==2)ans[i]=1;
                else ans[i]=2;
            }
            cout<<"2"<<endl;
            rep(i,0,n)
            cout<<ans[i]<<" ";
            cout<<endl;
            continue;
        }
        cout<<"3"<<endl;
        rep(i,0,n-1)
        cout<<ans[i]<<" ";
        cout<<"3"<<endl;
    }
}