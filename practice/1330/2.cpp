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
       ll n;
       cin>>n;
       ll ans=0;
       vector<ll> v(n),v2(n);
       set<pair<ll,ll> > a1;
       rep(i,0,n)
       {cin>>v[i];v2[i]=v[i];}
       map<ll,ll> mp,mp2;
       ll p2=-1;
       rep(i,0,n)
       {
           if(mp[v[i]]==1)
           {
               p2=i;
               break;
           }
           else 
           mp[v[i]]++;
       }
    //   cout<<p2<<" <---"<<endl;
       sort(v.begin(),v.begin()+p2);
       int fl=0;
       rep(i,0,p2)
       {
           if(v[i]==i+1)
           continue;
           else 
           {
               fl=1;
               break;
           }
       }
       if(fl!=1)
       {
           sort(v.begin()+p2,v.end());
           for(ll i=p2;i<n;i++)
               {
                   if(v[i]==i+1-p2)
                   continue;
                   else 
                   {
                       fl=1;
                       break;
                   }
               }
       }
       if(fl==0)
       {
           ans++;
           a1.insert({p2,n-p2});
       }
       reverse(v2.begin(),v2.end());
        p2=-1;
       rep(i,0,n)
       {
        //   cout<<v2[i]<<" ,";
           if(mp2[v2[i]]==1)
           {
               p2=i;
               break;
           }
           else 
           mp2[v2[i]]++;
       }
    //   cout<<p2<<"<---"<<endl;
       sort(v2.begin(),v2.begin()+p2);
       fl=0;
       rep(i,0,p2)
       {
           if(v2[i]==i+1)
           continue;
           else 
           {
               fl=1;
               break;
           }
       }
       if(fl!=1)
       {
           sort(v2.begin()+p2,v2.end());
           for(ll i=p2;i<n;i++)
               {
                   if(v2[i]==i+1-p2)
                   continue;
                   else 
                   {
                       fl=1;
                       break;
                   }
               }
       }
       if(fl==0)
       {
           ans++;
           a1.insert({n-p2,p2});
       }

      if(ans==0)
      {
          cout<<"0"<<endl;
          continue;
      }
      cout<<a1.size()<<endl;
      for(auto it : a1)
      cout<<it.first<<" "<<it.second<<endl;
    }

}