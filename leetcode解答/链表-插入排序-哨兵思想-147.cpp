struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    if(head==nullptr) return head;
    
    ListNode * guard = new ListNode(INT_MIN);
    guard->next=head;
    
    
    ListNode * b=guard;
    ListNode * e=head;
    ListNode * n = e->next;
    ListNode * tmp;
    while(n!=nullptr){
        if(n->val>=e->val){
            e=n;
            n=n->next;
            continue;
        }
        tmp=b;
        while(n->val>=tmp->next->val){
            tmp=tmp->next;
        }
        e->next=n->next;
        n->next=tmp->next;
        tmp->next=n;
        n=e->next;
    }
    return  guard->next;
}
