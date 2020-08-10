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
        ll a[n];
        rep(i,0,n)
        cin>>a[i];
        sort(a,a+n);
        ll mx[n];
        mx[0]=a[0]-1;
        set<ll> s;
        s.insert(mx[0]);
        ll a1,a2;
        rep(i,1,n)
        {
            if(mx[i-1]==a[i]-1 || mx[i-1]==a[i])
            {
                if(mx[i-1]==a[i]-1)
                mx[i]=a[i];
                else
                mx[i]=a[i]+1;
            }
            else if(mx[i-1]==a[i]+1)
            mx[i]=a[i]+1;
            else 
            mx[i]=a[i]-1;
            s.insert(mx[i]);
        }
        // cout<<s.size();
        a2=s.size();
        s.clear();
        ll mn[n];
        mn[0]=a[0]+1;
        s.insert(mn[0]);
        rep(i,1,n)
        {
            if(mn[i-1]==a[i] ||  mn[i-1]==a[i]-1 || mn[i-1]==a[i]+1)
            mn[i]=mn[i-1];
            else 
            mn[i]=a[i]+1;
            s.insert(mn[i]);
        }
        a1=s.size();
        cout<<a1<<" "<<a2<<endl;
    }

}