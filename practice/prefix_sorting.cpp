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
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        rep(i,0,n)
        cin>>v[i];
        ll pnt1=0,pnt2=n-1;

        while(pnt2>0)
        {
            ll flag=0;
            for(ll i=pnt1;i<=pnt2;i++)
            {
                if(v[i]>v[pnt1])
                {
                    reverse(v.begin(),v.begin()+i+1);
                    flag=1;
//                    err()
                    break;
                }
            }
            if(flag==0)
            {
                reverse(v.begin(),v.begin()+pnt2+1);
                pnt2--;
            }
//            cout<<pnt2<<endl;
//            rep(i,0,n)
//            cout<<v[i]<<" ";
//            err()
        }

        rep(i,0,n)
        cout<<v[i]<<" ";


    }

}