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
#define PI 3.14159265
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
        ll n;
        cin>>n;
        double tt;
        tt=((360.0)/(double)(2*n));
        // cout<<tt<<endl;
        double deg=tt;
        // deg/=(2.0);

        // double deg=double(180.0)-(tt);
        // double deg=(double(180.0)/(double)n);
        // if(deg==double(90))
        // deg=0.0;
        // else 

        // deg=(90.0)-(deg);
        // cout<<
        // deg/=(2.0);
        // cout<<((sin(deg*PI/(180.0))))<<" <---"<<endl;
        // double dist=1.0;
        // if(deg!=double(90))
        // double dist;
        // if(deg!=90)
        double dist;
        // dist=(0.5/(tan(deg*PI/(360.0))));
        dist=(1/(sin(deg*PI/(360.0))));
        // double dist2;
        // dist2=(1/(tan(deg*PI/(360.0))));

        // cout<<dist<<" "<<dist2<<endl;

        dist/=(sqrt(2));

        // else 
        // dist=1.0;

        // dist+=1;
        // dist*=(n-2);
        // dist+=(dist*(n/2-1));
        // if(n%4!=0)
        // dist/=(sqrt(2));
        // double tmp1=sqrt(2.0);
        // dist/=(tmp1);
        // deg+=(1.0);
        cout<<fixed<<setprecision(10)<<dist<<endl;
    }

}