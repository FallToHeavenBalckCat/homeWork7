
//单链表仅为户头结点
class MyLinkedList {
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        //初始化函数，直接一个参数和两个参数
        ListNode(): val(0),next(nullptr){}
        ListNode(int x): val(x),next(nullptr){}
        ListNode(int x,ListNode* n):val(x),next(n){}
    };
    int len;
    ListNode* head;    
public:
    MyLinkedList() {
        len=0;//注意这里的变量不要自己重新定义而是吧私有变量初始化
        head=new ListNode();
    }
    
    int get(int index) 
    {
        if(index<0||index>(len-1)) return -1;
        ListNode* ip=head->next;
        while(index--) ip=ip->next;
        return ip->val;
    }
    
    void addAtHead(int val) 
    {
        if(val<0||val>1000) return;//val值无效，直接返回
        ListNode* t=new ListNode(val);
        t->next=head->next;
        head->next=t;
        len++;
    }
    
    void addAtTail(int val) {
        if(val<0||val>1000) return;//val值无效，直接返回
        ListNode* t=new ListNode(val);
        ListNode* ip=head;
        while(ip->next)  ip=ip->next;
        ip->next=t;
        len++;
    }
    
    //在第index插入结点，要从head开始（实际上是从index-1后边插入，插入后就变成了第index个结点，获取index的值，要从head-next开始。
    void addAtIndex(int index, int val) {
        if(index>len)  return;
        if(index<=0) 
        {
            addAtHead(val);
        }
        else if(index==len)
        {
            addAtTail(val);
        }
        else
        {
            if(val<0||val>1000) return;//val值无效，直接返回
            //因为index是从0开始的，所以while(index--)找到就是第index-1个结点，如果ip是从1开始，
            ListNode *ip=head;
            ListNode* t=new ListNode(val);
            while(index--) ip=ip->next;
            t->next=ip->next;
            ip->next=t;
            len++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>len-1) return ;
        ListNode*ip=head;
        while(index--) ip=ip->next;
        ListNode* t=ip->next;
        ip->next=t->next;
        delete t;
        len--;
    }

    int getLen(){
        return len;
    }
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







