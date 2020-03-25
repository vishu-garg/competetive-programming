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

int main()
{
    ll n;
    cin>>n;
    ll a[n][n],fnd0=-1,i0,j0;
    string minpath0="";
    rep(i,0,n)
    rep(j,0,n)
    {
        cin>>a[i][j];
        if(a[i][j]==0){
        fnd0=1;i0=i;j0=j;}
    }
    if(fnd0==1)
    {
        rep(i,0,i0)
        minpath0+="D";
        rep(i,0,j0)
        minpath0+="R";
        rep(i,i0+1,n)
        minpath0+="D";
        rep(i,j0+1,n)
        minpath0+="R";
        
    }
    ll mat2[n][n],mat5[n][n];
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            ll cnt2=0;
            if(a[i][j]!=0)
            {
             while(a[i][j]%2==0)
                {
                    cnt2++;
                    a[i][j]/=2;
                }
            }
            mat2[i][j]=cnt2;
        }
    }
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            ll cnt5=0;
            if(a[i][j]!=0)
            {
                while(a[i][j]%5==0)
                {
                    cnt5++;
                    a[i][j]/=5;
                }
               
            }
             mat5[i][j]=cnt5;
        }
    }
    // ll mat[n][n];
    // rep(i,0,n)rep(j,0,n)mat[i][j]=min(mat2[i][j],mat5[i][j]);
    ll ans2[n][n];ans2[0][0]=mat2[0][0];
    rep(i,1,n)
    {
        ans2[0][i]=ans2[0][i-1]+mat2[0][i];
        ans2[i][0]=ans2[i-1][0]+mat2[i][0];
    }
    rep(r,1,n)
    rep(c,1,n)
    {
        ll tmp;
        // if(r-1>=0)
        // tmp=ans2[r-1][c];
        // if(c-1>=0)
        // tmp=min(tmp,ans2[r][c-1]);
        tmp=min(ans2[r-1][c],ans2[r][c-1])+mat2[r][c];
        // tmp+=mat2[r][c];
        ans2[r][c]=tmp;
    }
    ll ans=ans2[n-1][n-1];
    string minpath2="";
        ll r1=n-1,c1=n-1;
        while(r1>0 && c1>0)
        {
            if(ans2[r1-1][c1]<ans2[r1][c1-1])
            {minpath2+="D";r1--;}
            else 
            {minpath2+="R";c1--;}
        }
        for(ll i=r1-1;i>=0;i--)
        minpath2+="D";
        for(ll i=c1-1;i>=0;i--)
        minpath2+="R";
        reverse(minpath2.begin(),minpath2.end());
    ll ans5[n][n];ans5[0][0]=mat5[0][0];
    // string minpath5[n][n];minpath5[0][0]+="";
    rep(i,1,n)
    {
        ans5[0][i]=mat5[0][i]+ans5[0][i-1];
        ans5[i][0]=mat5[i][0]+ans5[i-1][0];
        // minpath5[0][i]+=minpath5[0][i-1]+"R";
        // minpath5[i][0]+=minpath5[i-1][0]+"D";
    }
    rep(r,1,n)
    rep(c,1,n)
    {
        ll tmp;
        // if(r-1>=0)
        // tmp=ans5[r-1][c];
        // if(c-1>=0)
        // tmp=min(tmp,ans5[r][c-1]);
        // tmp+=mat5[r][c];
        tmp=min(ans5[r-1][c],ans5[r][c-1])+mat5[r][c];
        ans5[r][c]=tmp;
        // if(ans5[r-1][c]<ans5[r][c-1])
        // minpath5[r][c]+=minpath5[r-1][c]+"D";
        // else 
        // minpath5[r][c]+=minpath5[r][c-1]+"R";
    }
    string minpath5="";
        r1=n-1,c1=n-1;
        while(r1>0 && c1>0)
        {
            if(ans5[r1-1][c1]<ans5[r1][c1-1])
            {minpath5+="D";r1--;}
            else 
            {minpath5+="R";c1--;}
        }
        // cout<<"r1 --- c1"<<endl<<r1<<" --- "<<c1<<endl;
        for(ll i=r1-1;i>=0;i--)
        minpath5+="D";
        for(ll i=c1-1;i>=0;i--)
        minpath5+="R";
        reverse(minpath5.begin(),minpath5.end());
    // rep(i,0,n)
    // {rep(j,0,n)
    // {cout<<ans2[i][j]<<" ";}cout<<endl;}
    // rep(i,0,n)
    // {rep(j,0,n)
    // {cout<<ans5[i][j]<<" ";}cout<<endl;}
    ans=min(ans,ans5[n-1][n-1]);
    // cout<<minpath2[n-1][n-1];
    if(ans>1 && fnd0==1){
    cout<<"1";
    cout<<endl<<minpath0;}
    else{
    cout<<ans<<endl;
    if(ans==ans5[n-1][n-1])
    cout<<minpath5;
    else 
    cout<<minpath2;}
}