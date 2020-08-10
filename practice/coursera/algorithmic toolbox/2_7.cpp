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

ll last(ll n)
{
	
    ll n1=n;
        if(n1==0)
        return 0;
        n+=2;
        ll m=10;
        ll lng=1;
        ll a=0,b=1;
        while(true)
        {
            ll tmp=(a+b)%m;
            a=b;
            b=tmp;
            if(b==1 && a==0)
            break;
            lng++;
        }
        ll num=n%lng;
        if(num==0 && n1>0)
        {return 9;}
        if(num==1)
        {return 0;}

        a=0;b=1;
        rep(i,2,num+1)
        {
            ll tmp=(a+b)%m;
            a=b;
            b=tmp;
        }
        if(b==0)
        return 9;
        else 
        return b-1;
}

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>m>>n;
        if(m==0)
        {cout<<last(n);return 0;}
        ll d1=last(n);
        ll d2=last(m-1);
//        cout<<d1<<" "<<d2<<endl;
        ll ans=(d1-d2)%10;
        if(ans<0)
        ans=(ans+10)%10;
        cout<<ans;

    }

}