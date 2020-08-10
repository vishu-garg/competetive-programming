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
        ll h,n;
        cin>>h>>n;
        vector<pair<pair<ll,ll>,ll> >vec;
        rep(i,0,n)
        {
            ll t,x,y;
            cin>>t>>x>>y;
            pair<ll,ll> p=make_pair(x,y);
            pair<pll,ll> p2=make_pair(p,t);
            vec.pb(p2);
        }
        sort(all(vec));
        vector<pll> v;
        rep(i,0,n)
        {
           pair<pll,ll> p2=vec[i];
           ll hgt=p2.first.second;
//           if(p2.second==1)
//           hgt=h-hgt;
//           cout<<i<<" "<<hgt<<"<---"<<endl;
//			cout<<i<<" "<<p2.first.first<<" "<<p2.first.second<<" "<<endl;
//			cout<<p2.first.first<<"  -----  "<<p2.first.second<<endl;
           v.pb({p2.first.first,p2.first.second});
//           cout<<hgt<<" "<<p2.second<<"<---"<<endl;
        }
        ll ans[n];
        rep(i,0,n)
        ans[i]=0;

        rep(i,0,n-1)
        {
            double max_0=-(1e9+7),min_1=1e9+7;
//            cout<<v[i].first<<" "<<v[i].second<<"###"<<endl;
            rep(j,i+1,n)
            {
                pll p2=v[j];
//                cout<<j<<" "<<p2.first<<" "<<p2.second<<" "<<endl;
                ll tp=vec[j].second;
//                cout<<p2.first<<" "<<p2.second<<" "<<" ---- ";
                double tngt=(double)((p2.second-v[i].second))/(double)(p2.first-v[i].first);
//                cout<<tngt<<"<----"<<endl;
				if(tngt>max_0 && tngt<min_1)
				{
					ans[i]++;
					ans[j]++;
				}
				if(tp==1)
                {
                    min_1=min(min_1,tngt);
                }
                else if(tp==0)
                {
                    max_0=max(max_0,tngt);   
                }
            }
        }
        rep(i,0,n)
        cout<<ans[i]<<" ";
        cout<<endl;    
    }

}