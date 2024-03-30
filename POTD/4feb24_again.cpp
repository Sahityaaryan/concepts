

Node* ReverseList(Node* &head){
        Node* prevptr=NULL;
        Node* currptr=head;
        Node* nextptr;
        
        while(currptr!=NULL){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
        }
        
        head=prevptr;
         
         return head;
     
      }
    
    
    int lengthList(Node* head){
        Node* temp=head;
        int count=0;
        while(temp!=NULL)  {
            count++;
            temp=temp->next;
        }
        
        return count;
        
    }
    
    // Zero Removal code
    
      void preZerosRemoval(Node* &head){
      
        while(head->data==0 && head->next!=NULL){
            head=head->next;
        }
        
    }
    
    
    
    Node* subtractionList(Node* &gL, Node* &lL){
       
       Node* head=NULL;
       Node* temp=head;
       Node* temp1=gL;    
       Node* temp2=lL;
       
       Node* n;
       
       while(temp2!=NULL){
           if(temp1->data<temp2->data){
               temp1->data=temp1->data+10;
               temp1->next->data=temp1->next->data-1;
           }
           n=new Node(temp1->data-temp2->data);
               if(head==NULL){
                   head=n;
                   temp=head;
                             }
               else{
                  temp->next=n;
                  temp=n;
                   }
           temp1=temp1->next;
           temp2=temp2->next;
       }
       
       while(temp1!=NULL){
           if(temp1->data>0){
              n=new Node(temp1->data);
               if(head==NULL){
                   head=n;
                   temp=head;
               }
               else{
                  temp->next=n;
                  temp=n;
               }
           
        //   temp1=temp1->next;
           }
         
         else if(temp1->next!=NULL && temp1->data==0){
              n=new Node(temp1->data);
               if(head==NULL){
                   head=n;
                   temp=head;
               }
               else{
                  temp->next=n;
                  temp=n;
               }
           
        //   temp1=temp1->next;
           }
           
         
         else{
             if( temp1->next!=NULL && temp1->next->data>=0 ){
                
               temp1->data=temp1->data+10;
               temp1->next->data=temp1->next->data-1;
               
               
                  n=new Node(temp1->data);
                  
                  
               if(head==NULL){
                   head=n;
                   temp=head;
               }
               
               else{
                  temp->next=n;
                  temp=n;
               }
               
        //   temp1=temp1->next;
           
             }
         }
             temp1=temp1->next;
       }
       
       ReverseList(head);
      preZerosRemoval(head);
       return head;
    }
    
  
    
    
Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
   
     preZerosRemoval(l1);
     preZerosRemoval(l2);
     
    Node* temp1=l1;
    Node* temp2=l2;
    int n1=lengthList(l1);
    int n2=lengthList(l2);
    
    if(n1>n2){
        ReverseList(l1);
        ReverseList(l2);
       return subtractionList(l1,l2);
    }
    
    else if(n1<n2){
        ReverseList(l1);
        ReverseList(l2);
       return subtractionList(l2,l1);
    }
    
    else{
        while(temp1!=NULL && temp2!=NULL){
        if(temp1->data>temp2->data){
          ReverseList(l1);
          ReverseList(l2);
        return subtractionList(l1,l2);
        
        }
        
      else  if(temp1->data<temp2->data){
        ReverseList(l1);
        ReverseList(l2);
       return subtractionList(l2,l1);
        
        }
        
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        }
    Node* n=new Node(0);
    return n;
    }
}