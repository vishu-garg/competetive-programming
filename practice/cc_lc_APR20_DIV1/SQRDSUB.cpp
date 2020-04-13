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
    ll t=1;
   cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        rep(i,0,n)
        {
            cin>>a[i];
            // if(a[i]%4==0)
            // a0.pb(i);
            // if(a[i]%4==2)
            // a2.pb(i);
            a[i]%=4;
        }
        ll c4=-1,c2=-1,ans[n];
        repb(i,n-1,0)
        {
            if(a[i]%4==0)
            {ans[i]=(n-i);c4=i;}
            else if(a[i]%4==2)
            {
                if(c2!=-1 && c4!=-1)
                {
                    ll tmp=min(c2,c4);
                    ans[i]=n-tmp;
                }
                else if(c2!=-1)
                {
                    ans[i]=n-c2;

                }
                else if(c4!=-1)
                {
                    ans[i]=n-c4;
                }
                else 
                {
                    ans[i]=0;
                }
            }
            else 
            {
                if(i==n-1)
                ans[i]=1;
                else 
                ans[i]=1+ans[i+1];
            }
        }
        ll sum=0;
        rep(i,0,n)sum+=ans[i];
        cout<<sum<<endl;
    }

}