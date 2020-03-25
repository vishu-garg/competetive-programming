#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]-'0')%8==0)
        {
            cout<<"YES"<<endl;
            cout<<s[i];
            return 0;

        }
        for(int j=i+1;j<s.length();j++)
        {
            if(((10*(s[i]-'0'))+(s[j]-'0'))%8==0)
            {
                cout<<"YES"<<endl;
                cout<<s[i]<<s[j];
                return 0;
            }

            for(int k=j+1;k<s.length();k++)
            {
                if(((100*(s[i]-'0'))+(10*(s[j]-'0'))+(s[k]-'0'))%8==0)
                {
                    cout<<"YES"<<endl;
                    cout<<s[i]<<s[j]<<s[k];
                    return 0;
                }
            }

        }
    }
    cout<<"NO";
    return 0;
}