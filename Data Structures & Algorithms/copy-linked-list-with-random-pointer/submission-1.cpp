/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  
  void insertCopyInBetween(Node*head){

      Node*temp = head ;

      while(temp !=nullptr){

        Node*current = temp->next;

        Node*copy = new Node(temp->val);

        temp->next = copy ;
        copy->next = current ;

        temp = current ;


        
      }
  }


  void connectRandomPointers(Node*head){

       Node*temp = head ;

       while(temp != nullptr){
          

          Node*copy = temp->next;

          if(temp->random){
            copy->random = temp->random->next;
          }

          else{
            copy->random = nullptr;
          }
       }

       temp = temp->next->next;
  }

  Node*getDeepCopy(Node*head){
     
     Node*temp = head ;
     Node*dummyNode = new Node(-1);

     Node*result = dummyNode;

     while( temp != nullptr){

          result->next = temp->next;
          result = result->next;

          temp->next = temp->next->next;
          temp = temp->next;
     }

     return dummyNode->next;

  }
    Node* copyRandomList(Node* head) {
        
      insertCopyInBetween(head);
      connectRandomPointers(head);
     return getDeepCopy(head);


    }
};
