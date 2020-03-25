#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,r;
        cin>>a>>b>>c>>r;
        ll t=min(a,b);
        if(a>b)
        {
            b=a;
            a=t;
        }
        ll lb=c-r;
        ll ub=r+c;
        if(a>=lb && b<=ub)
        cout<<"0"<<endl;

        else if((lb<a && ub<a) || (lb>b && ub>b))
        cout<<b-a<<endl;

        else
        {
            if(a<lb && b>ub)
            {
                ll dif=ub-lb+1;
                ll ans= (b-a+1)-(dif);
                cout<<ans<<endl;
            }
            else
            {
                if(a>=lb)
                {
                    ll ans=b-ub;
                    cout<<ans<<endl;
                }
                else
                {
                    ll ans=lb-a;
                    cout<<ans<<endl;

                }
            }
            
        }
        
    }
}