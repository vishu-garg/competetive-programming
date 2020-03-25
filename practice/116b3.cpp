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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll b[n];
        ll ans[n];
        ans[0]=1;
        rep(i,0,n)
        {
            cin>>b[i];
        }
        ll f=0;
        rep(i,1,n)
        {
            ll t1=b[i];
            ll t2=b[i-1];
            ll tmp=1;
            for(ll j=0;j<32;j++)
            {
                ll k1=(t1<<j)&1;
                ll k2=(t2<<j)&1;
                if(k1==0 && k2==1)
                {
                    cout<<0<<endl;
                    f=1;
                    break;
                }
                else if(k1==1 && k2==1)
                {
                    tmp*=2;
                }
            }
            if(f==1)
            break;
            tmp=(tmp%M);
            ans*=tmp;
            ans=ans%M;
        }
        if(f==1)continue;
        cout<<ans<<endl;
    }
}