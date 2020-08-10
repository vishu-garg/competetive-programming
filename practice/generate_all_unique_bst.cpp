#include<bits/stdc++.h>
using namespace std;
#define long long
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define pb push_back
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) :val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left , TreeNode *right) :val(x),left(left),right(right){}
};

vector<TreeNode*> construct_tree(int start, int end)
    {
        vector<TreeNode*> list;
        if(start>end)
        {
            // TreeNode *ptr=NULL;
            list.pb(NULL);
            return list;
        }

        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> lefttree,righttree;
            lefttree=construct_tree(start,i-1);
            righttree=construct_tree(i+1,end);
            for(int j=0;j<(int)lefttree.size();j++)
            {
                for(int k=0;k<(int)righttree.size();k++)
                {
                    TreeNode *node = new TreeNode;
                    node->val=i;
                    node->left=lefttree[j];
                    node->right=righttree[k];
                    // cout<<node->left->val<<endl;
                    list.pb(node);
                }
            }
        }
        return list;
    }
class Solution {
    public:

    vector<TreeNode*> generateTrees(int n)
    {
        if(n==0)
        {
            // TreeNode *node = new TreeNode;
            vector<TreeNode*> list;
            // list.pb(node);
            return list;
        }
        return construct_tree(1,n);
    }
};

int main()
{
    int n;
    cin>>n;
    Solution obj;
    obj.generateTrees(n);
}