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
        V v(n);
        rep(i,0,n)
        cin>>v[i];
        ll l_min[n],r_max[n];
        l_min[0]=v[0];
        rep(i,1,n)
        l_min[i]=min(l_min[i-1],v[i]);
        r_max[n-1]=v[n-1];
        repb(i,n-2,0)
        r_max[i]=max(r_max[i+1],v[i]);
        ll ans=-n;
        ll i=0,j=1;
        while(i<n && j<n)
        {
            if(l_min[i]<=r_max[j])
            {
                ll dif=j-i;
                ans=max(ans,dif);
                j++;
            }
            else 
            {
                i++;
            }
            if(i==j)
            j++;
        }
        l_min[n-1]=v[n-1];
        repb(i,n-2,0)
        {
            l_min[i]=min(l_min[i+1],v[i]);
        }
        r_max[0]=v[0];
        rep(i,1,n)
        r_max[i]=max(r_max[i-1],v[i]);
        if(ans>0)
        {
            cout<<ans;
            return 0;
        }
        i=n-1;j=n-2;
        while(i>=0 && j>=0)
        {
            if(l_min[i]<=r_max[j])
            {
                ll dif=j-i;
                ans=max(ans,dif);
                i--;
            }
            else 
            j--;
            if(i==j)
            j--;
        }
        cout<<ans;
        return 0;
    }

}