#include<bits/stdc++.h>
using namespace std;



struct node{
    char val;
    vector<node*> children;
};

class Trie {

    node *root;    
    
public:
    /** Initialize your data structure here. */
    Trie() {
    // cout<<"============"<<endl;
     root=new node;
    //  cout<<"==========="<<endl;         
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // cout<<"==================="<<endl;
        word+='$';
        int ind=0;
        int len=word.length();
        node *cur_node=root;
        while(ind!=len)
        {
            bool find=false;
            for(auto it: cur_node->children)
            {
                if(it->val==word[ind])
                {
                    ind++;
                    cur_node=it;
                    find=true;
                    break;
                }
            }
            if(find)continue;
            node * it=new node;
            it->val=word[ind];
            cur_node->children.push_back(it);
            cur_node=it;
            ind++;
        }
        // cout<<"INSERTED APPLE...."<<endl;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        word+='$';
        int len=word.length();
        node* cur_node=root;
        int ind=0;
        while(ind!=len)
        {
            bool find=false;
            for(auto it : cur_node->children)
            {
                if(it->val==word[ind])
                {
                    cur_node=it;
                    find=true;
                    ind++;
                    break;
                }
            }
            if(find==false)
            return false;
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int len=word.length();
        node* cur_node=root;
        int ind=0;
        while(ind!=len)
        {
            bool find=false;
            for(auto it : cur_node->children)
            {
                if(it->val==word[ind])
                {
                    cur_node=it;
                    find=true;
                    ind++;
                    break;
                }
            }
            if(find==false)
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    // cout<<"1234455555555555555555555555555"<<endl;
    Trie obj;
    // cout<<"-------------"<<endl;
    obj.insert("apple");
    // obj.insert("app");
    if(obj.search("app"))
    {
        cout<<"app is found"<<endl;
    }
    else 
    {
        if(obj.startsWith("apple"))
        {
            cout<<"apple is found as a prefix"<<endl;
        }
        else 
        cout<<"apple found NOWHERE!!!"<<endl;
    }
    return 0;
}