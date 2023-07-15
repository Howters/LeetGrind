/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode *head=NULL, *tail = NULL, *node;

struct ListNode* newNode(int val){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
 void pushHead(int val){
     if(head == NULL){
         head = tail = newNode(val);
     }
     else{
         struct ListNode* node = newNode(val);
         node->next = head;
         head = node;

     }
 }
  void pushTail(int val){
     if(head == NULL){
         head = tail = newNode(val);
     }
     else{
         struct ListNode* node = newNode(val);
         node->next = NULL;
         tail -> next = node;
         tail = node;

     }
 }

 void pushMid(int val){
     struct ListNode * newNodes = newNode(val);
     if(head == NULL){
         pushHead(val);
     }
     else if( val <= head->val){
         pushHead(val);
     }
     else if(val >= tail->val){
         pushTail(val);
     }
     else{
         struct ListNode * node = head;
         while(node->next->val <= val){
             node = node->next;
         }
             newNodes->next = node->next;
             node->next = newNodes;
     }



 }
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    head = NULL;
    while(l1 ){
        pushMid(l1->val);
        
        l1 = l1->next;
       
    }
    while(l2){
        pushMid(l2->val);
        
        l2 = l2->next;
    }
    return head;
}