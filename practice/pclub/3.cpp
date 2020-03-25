#include <iostream>
using namespace std;
long long int d, z, y;
long long int modularExponentiation(long long int p,long long int x, long long int n,long long int M)
{
long long int result=p%M;
while(n>0)
{
if(n % 2 ==1)
result=(result * x)%M;
x=(x*x)%M;
n=n/2;
}
return result;
}
void extendedEuclid(long long int c,long long int m)
{
if(m == 0)
{
d = c;
z = 1;
y = 0;
}
else
{
extendedEuclid(m, c%m);
long long int temp = z;
z = y;
y = temp - (c/m)*y;
}
}
long long int modInverse(int c, int M)
{
extendedEuclid(c,M);
return (z%M+M)%M;
}
int main()
{
long long t;
cin>>t;
while(t--){
long long int a=10,p,q,r,ans1,ans2,a3,a4,m=10;
cin>>p>>q>>r;
ans1=modularExponentiation(p,10,q,10);
ans2=modInverse(r,10);
cout((ans1%m)*(ans2%m))%m;
}
return 0;
}