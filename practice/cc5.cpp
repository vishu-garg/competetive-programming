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

// ll dp[401];
ll cnt[401]={0};
int main()
{
    rep(i,1,401)
    {
        ll f=1;
        f+=(((13*12)-1)/5);
        ll d=(i-1)%100;
        ll c=(i-1)/100;
        f+=d;
        f+=(d/4);
        f+=(c/4);
        f-=(2*c);
        f%=7;
        if(f<0)
        f+=7;
        cnt[i]=cnt[i-1];
//         cout<<f<<" "<<i<<" ";
        if(f==6){
        cnt[i]+=1;}
        else if(f==0)
        {
            if(i%4!=0 && i%400!=0)
            {cnt[i]+=1;}
            // else 
            // dp[i]=0;
        }
//        cout<<endl;
        // else 
        // dp[i]=0;
        // if(dp[i]==1)
        // cnt[i]=cnt[i-1]+1;
        // else 
        // cnt[i]=cnt[i-1];
        // cout<<i<<" "<<f<<" "<<cnt[i]<<endl;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll m1,m2,y1,y2;
        cin>>m1>>y1;
        cin>>m2>>y2;
        if(m1<=2)
        y1--;
        if(m2<2)
        y2--;
        ll c1,c2,x1=0,x2=0;
        if(y1>400)
        {
            x1=(y1/400);
            // if(x1%400!=0)
            // x1+=400;
            // x1/=400;
            y1=(y1%400);
        }
//        cout<<x1<<" "<<y1<<endl;
        c1=(x1*cnt[400])+cnt[y1];
        if(y2>400)
        {
            x2=y2/400;
            // if(x2%400!=0)
            // x2+=400;
            // x2/=400;
            y2=(y2%400);
        }
//        cout<<x2<<" "<<y2<<endl;
        c2=(x2*cnt[400])+(cnt[y2]);
        // cout<<cnt[400]<<endl;
//        cout<<c1<<" "<<c2<<endl;
        cout<<c2-c1<<endl;
        // cout<<((x2-x1)*101)+(cnt[y2]-cnt[y1]+1)<<endl;
        // cout<<y1<<" "<<y2<<endl;
        // cout<<c1<<" "<<c2<<endl;
    }
}