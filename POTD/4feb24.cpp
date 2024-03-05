







// ! Not solved

// # link: https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1

    #include<bits/stdc++.h>
    using namespace std;

    class Node{

        public:
            int data;
            Node* next;

            Node(int val): data(val) , next(NULL) {}
    };

    class LinkedList{
        public:
            Node* head;
            Node* tail;

            LinkedList(): head(NULL), tail(NULL) {}

            void insert(int val){
                
                if(head == NULL){
                    head = new Node(val);
                    tail = head;
                } else {
                    tail->next = new Node(val);
                    tail = tail->next;
                }
            }
    };



    void printList(Node* n){
        while(n){
            cout << n->data;
            n = n->next;
        }
        cout << '\n';
    }
     


    Node* reverseLinkedList(Node* head){
        
        Node* h1 = head;
        Node* h2 = head->next;
        Node* h3 = NULL;
        
        while(h1){
            
            h1->next = h3;
            h3 = h1;
            h1 = h2;
        if(h2) h2 = h2->next;
        }

        // cout << "check reverse: ";
        // printList(h3);
        
        return h3;
    }
    
    pair<Node*, Node*> arrange(Node* head1, Node* head2){
        pair<Node*, Node*>res(head1,head2);
        
        if(head1->data==0) {
            res.first = head2;
            res.second = head1;
            return res;
        }
        
        if(head2->data==0) {
            res.first = head1;
            res.second = head2;
            return res;
        }

        //        cout << "\ncheck subs ";
        // printList(head1);
        // cout << "\n head2: ";
        // printList(head2);

        // cout << '\n';
        

        return res;
        
        
        // int len1 = 0, len2 = 0;.
        
        bool isFirstGreater = true , checked = false;
        
        while(head1 && head2){
            
            if(!checked && head2->data < head1->data){
                checked = !checked;
            }
            
            if(!checked && head1->data < head2->data){
                isFirstGreater = checked =false;
            }
            
            head1 = head1->next;
            head2 = head2->next;
        }
        
        if(head1){
          res.first = head1;
          res.second = head2;  
          return res;
        }
        
        if(head2){
             res.first = head2;
            res.second = head1;
            return res;
        }
        
        if(isFirstGreater){
            
            res.first = head1;
          res.second = head2;  
        //   return res;
          
        } else {
            
            res.first = head2;
            res.second = head1;
            // return res;
        }
        
        return res;
    }
    
    Node* subsLinkedList( Node* greater,  Node* smaller){
        
        // Node* res = NULL;

        LinkedList res;
        Node* result;
        bool flag =true;
        int carry = 0, a, multi = 1;
        // reversing the linked list
        
        greater = reverseLinkedList(greater);
    //    cout << "smaller: ";
       printList(smaller);cout << '\n';
        smaller = reverseLinkedList(smaller);
        
        // cout << "\ncheck subs ";
        // printList(greater);
        // cout << '\n';

        while(greater && smaller){
            
            a = greater->data;
            a += carry;
            
            if(a < smaller->data){
                
                carry = -1;
                 a += 10;
            }
            
              res.insert(a-(smaller->data));
              
              multi *= 10;
              
              greater = greater->next;
              smaller = smaller->next;
            //   if (flag){ result = res; flag = !flag;}
            //   res = res->next;
        }
        
        while(greater){
            
            a = greater->data;
            a += carry;
            
            if(a < 0){
                
                carry = -1;
                 a += 10;
            }
            
            if(a || greater->next){

                res.insert(a);
            } 
            
            greater = greater->next;
        }

      

        
        return reverseLinkedList(res.head);
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        
         pair<Node*, Node*> res = arrange(head1, head2);
        Node* greater = res.first;
        Node* smaller = res.second;
        
        // cout << greater->data << smaller->data << '\n';
        
    
        return subsLinkedList(greater, smaller); 
        // return NULL;
    }



    int main()
    {
        int t=1;
        // cin >> t;

   

        // cin >> l1;

        for(int i = 0; i < t;++i){
            int n;
            cin >> n;

            LinkedList LL1;
            string l1,l2;

            cin >> l1;

            for(int j = 0; j < n; ++j){
            int x = (l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;

        LinkedList LL2;

        cin >> l2;

        for(int j = 0; j < m; ++j){
            int x = (l2[j]-'0');
            LL2.insert(x);
        }

        Node* res = subLinkedList(LL1.head,LL2.head);
        printList(res);
        }


        

     
        
        cout << endl;
        return 0;
    }





//     3
// 100
// 2
// 12