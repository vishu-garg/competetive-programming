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
        ll a1,a2,k1,k2;
        cin>>a1>>a2>>k1>>k2;
        ll n;
        cin>>n;
        

        ll mx=0;
        if(k1>k2)
        {
            swap(k1,k2);
            swap(a1,a2);
        }
        ll i=0;
        ll ans=0;
        ll n2=n;
        while(i<a1+a2 && n>0)
        {
            if(i<a1)
            {
                if(n>=k1)
                {n-=k1;ans++;}
                else 
                n=0;
            }
            else
            {
                if(n>=k2)
                {n-=k2;ans++;}
                else 
                n=0;
            }
            i++;
        }

        n=n2;
        n=n-((k1-1)*a1)-((k2-1)*a2);
        // cout<<n<<endl;
        if(n<=0)
        cout<<"0";
        else 
        {
            cout<<min(a1+a2,n);
        }
        cout<<" "<<ans<<endl;
    }

}