#include<bits/stdc++.h>
using namespace std;
typedef long long int ii;
 int d,x,y;

ii modularaj(ii a,ii b,ii m)
{
    ii sum=1;
    while(b!=0)
    {
        ii u=b%2;
        if(u==1)
        sum=(sum*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return sum;
}



int main()
{
    ii a,t1,t2,t3,n,m=998244353.;
    cin>>a>>t1>>t2>>t3>>n;
    ii b=(3*n+9);
    ii j=modularaj(a,b,m);
    for(ll )
    cout<<w;
}