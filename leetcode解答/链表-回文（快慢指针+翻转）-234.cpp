struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void reverse(ListNode * Dummyhead){
    ListNode * pre=Dummyhead;
    ListNode * cur=Dummyhead->next;
    ListNode * nxt;
    while(cur!=nullptr){
        nxt=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nxt;
    }
    Dummyhead->next=nullptr;
    //达到效果，从Dummyhead->next之后完成了翻转;
}


bool isPalindrome(ListNode* head) {
    if(head==nullptr) return true;
    
    ListNode * fast=head;
    ListNode * slow=head;
    int len = 1;
    while(fast->next!=nullptr and fast->next->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        len++;
    }
    while(fast->next!=nullptr){
        fast=fast->next;
    }
    ListNode * end = fast;
    //end指向链表尾部
    //slow指向了dummyhead;
    reverse(slow);
    slow=head;
    for(int i=1;i<=len;i++){
        if(slow->val==fast->val){
            slow=slow->next;
            fast=fast->next;
        }
        else{
            reverse(end);
            return false;
        }
    }
    reverse(end);
    return true;

}

int main(){
    ListNode *h1=new ListNode(1);
    ListNode *h2=new ListNode(2);
    ListNode *h3=new ListNode(5);
    ListNode *h4=new ListNode(2);
    ListNode *h5=new ListNode(1);
    h1->next=h2;
    h2->next=h3;
    h3->next=h4;
    h4->next=h5;
    std::cout<<isPalindrome(h1);
}
