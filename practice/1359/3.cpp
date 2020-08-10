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
    cin>>T;
    while(T--)
    {
        ld n,m,k;
        cin>>n>>m>>k;
        if(n==k)
        {
            cout<<"1"<<endl;
            continue;
        }
        // ll ans1=0;
        // ll t1=0,t2=0;
        // ll cnt=1;
        ll t=0;
        ll ans=2;
        ld avg=(n+m)/2;
        
        ld diff=abs(avg-k);
        
        if(avg==k)
        {
            cout<<"2"<<endl;
            continue;
        }
        else if(avg>k)
        {
            cout<<"2"<<endl;
            continue;   
        }
        ll t2=(k-n)/((n+m-(2*k)));
        ans=(2*t2+1);
        ld avg2=(((2*t2)*(avg))+(n))/((2*t2)+1);
        ll t3=t2+1;
        ld avg3=(((2*t3)*(avg))+(n))/((2*t3)+1);
        if(abs(avg3-k) < abs(avg2-k))
        cout<<2*t3+1;
        else 
        cout<<2*t2+1;
        cout<<endl;


    }

}