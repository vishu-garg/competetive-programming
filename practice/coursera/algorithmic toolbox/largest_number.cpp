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
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        rep(i,0,n)
        cin>>a[i];
        sort(a.begin(),a.end(),[&](ll a1, ll a2){
            ll d1=0,d2=0;
            ll tmp1=a1,tmp2=a2;
            while(tmp1>0)
            {
                d1++;
                tmp1/=10;
            }
            while(tmp2>0)
            {
                d2++;
                tmp2/=10;
            }
            ll num1=a1*(ll)(pow(10,d2));
            num1+=a2;
            ll num2=a2*(ll)(pow(10,d1));
            num2+=a1;
            return num1>num2;
        });
        rep(i,0,n)
        cout<<a[i];
        cout<<endl;
    }

}