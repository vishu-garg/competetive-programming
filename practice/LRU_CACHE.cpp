#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int val;
    int key;
    Node *next;
    Node *prv;
    
    Node()
    {
        val=0;
        key=0;
        next=nullptr;
        prv=nullptr;
    }
    
};


class LRUCache {

    unordered_map<int,Node*>mp;
    
    Node *head;
    Node *rear;
    
    int cnt,size;
    
    
    public:
    LRUCache(int capacity) {
        
        head=new Node;
        rear=head;
        
        cnt=0;
        
        size=capacity;
        
    }
    
    int get(int key) {
        
        if(cnt==0 || mp.find(key)==mp.end())
        {
            return -1;
        }

        // Node *tmp=head;
        // while(tmp!=NULL)
        // {cout<<tmp->val<<" ";tmp=tmp->next;}
        // cout<<endl;
        // cout<<rear->val<<endl;
        
        
        int value=mp[key]->val;

        if(rear!=head && rear!=mp[key])
        {

            
            if(mp[key]==head)
            {head=head->next;}
            if(mp[key]->next!=NULL)
            {mp[key]->next->prv=mp[key]->prv;}
            if(mp[key]->prv!=NULL)
            {mp[key]->prv->next=mp[key]->next;}
            mp[key]->prv=rear;
            mp[key]->next=rear->next;
            rear->next=mp[key];
            rear=mp[key];
            // cout<<rear->val<<endl;
        }

        // tmp=head;
        // while(tmp!=NULL)
        // {cout<<tmp->val<<" ";tmp=tmp->next;}
        // cout<<endl;

        
        return value;
        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            mp[key]->val=value;

            if(rear!=head && mp[key]!=rear)
            {
                
                if(mp[key]==head)
                head=head->next;


                if(mp[key]->next!=NULL)
                {mp[key]->next->prv=mp[key]->prv;}
                if(mp[key]->prv!=NULL)
                mp[key]->prv->next=mp[key]->next;
                mp[key]->prv=rear;
                mp[key]->next=rear->next;
                rear->next=mp[key];
                rear=mp[key];
                // cout<<rear->val<<endl;
            }

            return;
        }
        
        if(cnt==size)
        {
            mp.erase(head->key);
            if(rear==head)
                rear=head->next;
            
            head=head->next;

            add(key,value);
            return;
        }
        
        cnt++;
        
        add(key,value);

        // Node *tmp=head;
        // while(tmp!=NULL)
        // {cout<<tmp->val<<" ";tmp=tmp->next;}
        // cout<<endl;
        
        return;
        
    }
    
    void add(int key, int value)
    {
        if(cnt==1)
        {
            head->val=value;
            head->key=key;
            Node *ptr=new Node;
            head->next=ptr;
            ptr->prv=rear;
            rear=head;
            
            mp[key]=head;
            
        }
        else 
        {

            Node *ptr=rear->next;
            ptr->key=key;
            ptr->val=value;
            Node *ptr2=new Node;
            ptr->next=ptr2;
            ptr2->prv=ptr;
            ptr->prv=rear;
            rear=ptr;
            mp[key]=ptr;
        }
    }
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache* obj=new LRUCache(3);

    obj->put(2,1);
    obj->put(3,2);
    // cout<<obj->get(3);
    // cout<<obj->get(2);
    obj->put(4,3);
    obj->put(5,7);
    // cout<< obj->get(2);
    // cout<< obj->get(3);
    // cout<< obj->get(4);
    // cout<<obj->get(1)<<endl;
    // // obj->put(3,3);
    // cout<<obj->get(2)<<endl;

}

// ["LRUCache","put","put","get","get","put","get","get","get"]
// [[2],[2,1],[3,2],[3],[2],[4,3],[2],[3],[4]]