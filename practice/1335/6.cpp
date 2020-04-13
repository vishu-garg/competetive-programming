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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
   cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        V a(n);
        unordered_map<ll,V> mp;
        ll cnt[201][n];
        rep(i,0,201)
        rep(j,0,n)
        cnt[i][j]=0;
        // set<ll> s;
        rep(i,0,n)
        {
            cin>>a[i];
            mp[a[i]].pb(i);
            // s.insert(a[i]);
        }
        rep(i,1,n)
        {
            rep(j,1,201)
            {
                cnt[j][i]=cnt[j][i-1];
            }
            cnt[a[i]][i]++;
        }
        ll ans=0;
        for(ll it=1;it<=200;it++)
        {
            V ind=mp[it];
            ll tmp=ind.size();
            ll m2=tmp;
            ll  mx=tmp/2;
            // ll cnt=0;
            rep(i,0,mx)
            {
                ll ans2=(2*(i+1));
                ll max_b=0;
                rep(j,1,201)
                {
                    if(j==it)
                    continue;
                    ll lwr_lmt=cnt[j][ind[i]];
                    ll upr_lmt=cnt[j][ind[m2-i-1]];
                    max_b=max(max_b,upr_lmt-lwr_lmt);
                }
                // cout<<max_b<<"<---"<<endl;
                ans2+=max_b;
                tmp=max(tmp,ans2);
            }
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;



    }

}


// IN THIS QUESTION WHEN I USED LL WITH COUNT THE MLE OCCURED 
// WHEN I USED SIMPLE LOWERBOUND TO CALCULATE LWR_LMT AND UPR_LMT THE TLE OCCURED