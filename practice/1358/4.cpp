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
//     cin>>T;
    while(T--)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll>a(2*n+1);
        rep(i,1,n+1)
        cin>>a[i];
        
        rep(i,n+1,2*n+1)
        a[i]=a[i-n];

        vector<ll>days(2*n+1);
        days[0]=0;
        rep(i,1,2*n+1)
        days[i]=(days[i-1]+a[i]);
        vector<ll>cnt(2*n+1,0);
        rep(i,1,2*n+1)
        {
            cnt[i]+=cnt[i-1];
            cnt[i]+=((a[i]*(a[i]+1))/2);
        }

        ll ans=0;
        rep(i,1,2*n+1)
        {
            if(days[i]>=x)
            {
                ll starting_month=upper_bound(all(days),days[i]-x)-days.begin();
                ll days_taken_from_starting_month=x-(days[i]-days[starting_month]);
                // cout<<starting_month<<endl;
                ll tot_hugs_except_from_starting_month=cnt[i]-cnt[starting_month];
                ll tot_hugs_taken_from_starting_month=((a[starting_month]*(a[starting_month]+1))/2)-(((a[starting_month]-days_taken_from_starting_month)*(a[starting_month]+1-days_taken_from_starting_month))/2);
                ll tot_hugs=tot_hugs_except_from_starting_month+tot_hugs_taken_from_starting_month;
                // cout<<tot_hugs_taken_from_starting_month<<endl;
                ans=max(ans,tot_hugs);
            }
        }
        cout<<ans<<endl;

    }

}