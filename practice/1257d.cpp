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
        ll  n;
        cin>>n;
        V a(n);
        rep(i,0,n)
        cin>>a[i];
        ll m;
        cin>>m;
        V b(n+1,0);
        rep(i,0,m)
        {
            ll p,end;
            cin>>p>>end;
            if(b[end]<p)
            b[end]=p;
        }
        repb(i,n-1,0)
        b[i]=max(b[i],b[i+1]);
        ll cnt=0;
        ll pos=0;
        ll flg=0;
        // rep(i,0,n+1)
        // cout<<b[i]<<" ";
        while(pos<n)
        {
            cnt++;
            ll npos=pos;
            ll mx=0;
            while(npos<n){
                mx=max(mx,a[npos]);
                if(mx>b[npos-pos+1])
                break;
                npos++;
                // cout<<cnt<<" "<<npos-1<<endl;
            }
            // cout<<pos<<" "<<npos<<"<---"<<endl;
            if(pos==npos)
            {
                flg=1;
                break;
            }
            pos=npos;
        }

        if(flg==1)
        cnt=-1;
        cout<<cnt<<endl;


    }

}