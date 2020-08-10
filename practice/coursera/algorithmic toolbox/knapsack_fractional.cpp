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
#define float double
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
        ll n,w;
        cin>>n>>w;
        vector<pair<float,float> > a(n);
        rep(i,0,n)
        cin>>a[i].first>>a[i].second;
        sort(a.begin(),a.end(),[&](pair<ll,ll> a1 , pair<ll,ll> b){
            float f1=(float)a1.first/a1.second;
            float f2=(float)b.first/b.second;
            return f1>f2;
        });

        // rep(i,0,n)
        // cout<<a[i].first<<" "<<a[i].second<<"<---"<<endl;

        ll cnt=0;
        float ans=0;
        while(w>0 && cnt<n)
        {
            ll quant=min((float)w,a[cnt].second);
            // err1(quant)<<endl;
            float val=float(a[cnt].first/a[cnt].second);
            // err1(val);
            val*=(float)quant;
            // err1(val)<<endl;
            ans+=val;
            w-=quant;
            cnt++;
        }
        cout<<fixed<<setprecision(5)<<ans<<endl;

    }

}