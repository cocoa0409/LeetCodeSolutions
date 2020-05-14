struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* head) {
    ListNode * prev=nullptr;
    ListNode * curr=head;
    ListNode * tmpNode;
    while(curr!=nullptr){
        tmpNode=curr->next;
        curr->next=prev;
        prev=curr
        curr=tmpNode;
    }
    return prev;
}
