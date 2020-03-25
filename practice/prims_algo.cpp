#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int MAX = 1e4+5;
typedef pair<ll,int>PII;
bool marked[MAX];
vector<PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII,vector<PII> , greater<PII> >Q;
    int y;
    ll mincost=0;
    PII p;
    Q.push(make_pair(0,x));
    while(!Q.empty())
    {
        //Select edge with min weight
        p=Q.top();
        Q.pop();
        x=p.second;
        if(marked[x]==true)
        continue;
        mincost+=p.first;
        marked[x]=true;
        for(int i=0;i<adj[x].size();i++)
        {
            y=adj[x][i].second;
            if(marked[y]==false)
            Q.push(adj[x][i]);
        }
    }
    return mincost;
}

int main()
{
    int nodes,edges,x,y;
    ll weight,mincost;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(weight,y));
        adj[y].push_back(make_pair(weight,x));
    }
    mincost=prim(1);
    cout<<mincost;
    return 0;
}