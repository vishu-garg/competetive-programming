#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl

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
        ll n,s;
        cin>>n>>s;
        if(n>=s)
        {
            cout<<"NO";
            return 0;
        }
        vector<ll>a(n);
        rep(i,0,n-1)
        a[i]=1;
        a[n-1]=(s-(n-1));
        ll num2=n;
        if(a[n-1]>n)
        {
            cout<<"YES"<<endl;
            rep(i,0,n)
            cout<<a[i]<<" ";

            cout<<endl<<n<<endl;
        }
        else 
        {
            cout<<"NO"<<endl;
        }
    }

}