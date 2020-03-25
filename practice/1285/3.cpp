#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x;
    cin>>x;
    ll num1,num2;
    ll temp=sqrt(x);
    for(ll i=1;i<=temp;i++)
    {
        if(x%i==0)
        {
            ll t1=i;
            ll t2=x/i;
            ll lcm=(t1*t2)/(__gcd(t1,t2));
            if(lcm==x)
            {
                num1=i;
                num2=x/i;
            }
        }
    }
    cout<<num1<<" "<<num2;
}