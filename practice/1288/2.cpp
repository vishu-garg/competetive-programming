#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll A,B;
        cin>>A>>B;
        ll maxb=0;
        while(B>0)
        {
            maxb++;
            B=B/10;
        }
        ll num=(ll)pow(10,(maxb));
        cout<<maxb<<" ";
        num-=1;

        if(num==B)
        cout<<A*maxb<<endl;
        else 
        cout<<A*(maxb-1)<<endl;

    }
}