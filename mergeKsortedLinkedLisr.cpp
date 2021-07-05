/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 void insert(ListNode* root, int data){
     ListNode* node = root;
     ListNode* temp = new ListNode(data);

     while(node->next!=NULL){
         node = node->next;
     }
     node->next = temp;
     temp->next = NULL;

 }
 struct compare {
    bool operator()(
        struct ListNode* a, struct ListNode* b)
    {
        return a->val > b->val;
    }
};
 

ListNode* Solution::mergeKLists(vector<ListNode*> &arr) {
   int k = arr.size();
     priority_queue<ListNode*, vector<ListNode*>, compare> pq;
 
    // push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);
     
      // Handles the case when k = 0
      // or lists have no elements in them   
      if (pq.empty())
        return NULL;
   
      struct ListNode *dummy = new ListNode(0);
      struct ListNode *last = dummy;
   
    // loop till 'pq' is not empty
    while (!pq.empty()) {
 
        // get the top element of 'pq'
        struct ListNode* curr = pq.top();
        pq.pop();
 
          // add the top element of 'pq'
          // to the resultant merged list
          last->next = curr;
          last = last->next; 
       
          // check if there is a node
        // next to the 'top' node
        // in the list of which 'top'
        // node is a member
        if (curr->next != NULL)
            // push the next node of top node in 'pq'
            pq.push(curr->next);
    }
 
    // address of head node of the required merged list
    return dummy->next;
    }
