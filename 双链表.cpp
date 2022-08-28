class MyLinkedList {
public:
    MyLinkedList() {
        len=0;
        head=new ListNode();
        tail=new ListNode();
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int index) {
        if(index<0||index>len-1) return -1;
        auto ip=head->next;
        while(index--)  ip=ip->next;
        return ip->val;
    }
    
    void addAtHead(int val) {
        if(val<0 || val>1000) return ;
        ListNode* t=new ListNode(val);
        ListNode* id=head->next;
        t->next=id;
        id->pre=t;
        head->next=t;
        t->pre=head;
        len++;
    }
    
    void addAtTail(int val) {
        if(val<0||val>1000) return ;
        ListNode* t=new ListNode(val);
        ListNode* id=tail->pre;
        t->next=tail;
        tail->pre=t;
        id->next=t;
        t->pre=id;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if(val<0||val>1000) return;
        if(index>len) return;
        if(index<=0) addAtHead(val);
        else if(index==len) addAtTail(val);
        else{
            ListNode*t=new ListNode(val);
            ListNode*ip=head->next;
            while(index--) ip=ip->next;
            ListNode*pr=ip->pre;
            t->next=ip;
            ip->pre=t;
            pr->next=t;
            t->pre=pr;
            len++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>len-1) return;
        ListNode*ip=head->next;
        while(index--) ip=ip->next;
        ListNode*pr=ip->pre;
        ListNode*ne=ip->next;
        pr->next=ne;
        ne->pre=pr;
        delete ip;
        len--;
    }

private:
    struct ListNode{
        int val;
        ListNode* pre;
        ListNode* next;
        ListNode():val(0),pre(nullptr),next(nullptr){}
        ListNode(int x):val(x),pre(nullptr),next(nullptr){}
        ListNode(int x,ListNode* pr,ListNode* ne):val(x),pre(pr),next(ne){}
    };
    int len;
    ListNode* head;
    ListNode* tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */