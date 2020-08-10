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
    ll t1=1;
     cin>>t1;
    while(t1--)
    {
        ll n,t,a,b;
        cin>>n>>t>>a>>b;
        
        ll s_tme[n];
        ll dif[n];
        
        ll cnt0=0,cnt1=0;
        
        rep(i,0,n)
        {
        cin>>dif[i];
        if(dif[i])
        cnt1++;
        else 
        cnt0++;
        }
        rep(i,0,n)
        cin>>s_tme[i];
        
        vector<pair<ll,ll> >v;
        rep(i,0,n)
        v.pb(make_pair(s_tme[i],dif[i]));
        sort(v.begin(),v.end());
        v.pb({t+1,0});
        ll cnt3=0,cnt4=0;
        ll ans=0;
        for(ll i=0;i<=n;i++)
        {
            ll need=cnt3*a+cnt4*b;
            ll has=v[i].first-1-need;
            if(has>=0){
                ll canA=min((cnt0-cnt3),has/a);
                has-=canA*a;
                ll canB=min((cnt1-cnt4),has/b);
                ans=max(ans,cnt3+cnt4+canA+canB);
            }
            ll l=i;
            while(l<v.size() && v[l].first==v[i].first){
                if(v[l].second==1)
                cnt4++;
                else 
                cnt3++;
                l++;
            }
            i=l-1; // l-1 because i will be insreased above by updation due i++ in for loop so  next time we get i=l in the loop;
        }
        cout<<ans<<endl;
    }
}