#include<bits/stdc++.h>
using namespace std;
 

class Node{
public:
    int freq,key,value;
    Node* next = NULL;
    Node* prev = NULL;

    Node(int _key, int _value){
        key = _key;
        value = _value;
        freq = 1;
    }
};



class List{
public:
    
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    int size = 0;

    List(){    
        tail->prev = head;
        head->next = tail;
    }

    void addNode(Node* node){ // adding to the head
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
        head = node;
        size++;
    }

    void removeNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        size--;
    }
};

class LFUCache{

public:
    unordered_map<int, List*> freqList;
    unordered_map<int, Node*> keyNode;

    int maxSize = 0;
    int currSize = 0;
    int minFreq = 1;

    LFUCache(int capacity){
        maxSize = capacity;
        currSize = 0;
    }

    int get(int key){

        if(keyNode.find(key) == keyNode.end()){
            return -1;
        }
        
        // fetching the value 

        int value = keyNode[key]->value;
        Node* node = keyNode[key];

        // updating the node in the list
        
            // 1. removing the node from the previous frequency list

            int listSize = freqList[node->freq]->size;
            List* previousList = freqList[node->freq];

            if(listSize == 1){
                minFreq++;
            }

            List* newList = new List();

            // I am unable to find a list of the higher frequency then my newly created list will be there
            if(freqList.find(node->freq + 1) != freqList.end()){
                newList = freqList[node->freq + 1];
            }

            node->freq++;
            previousList->removeNode(node);
            newList->addNode(node);

        return value;
    }

    
    void put(int key, int value){

        Node* node = new Node(key,value);

        // 1. size check

        if(currSize == maxSize){

            // removing lfu of the minFrequency

            List* list = freqList[minFreq];
            Node* tail = list->tail;
            list->removeNode(tail->prev);
            list->size--;

            // adding the new node in the 1 frequency list

            minFreq = 1;

            if(freqList.find(minFreq) != freqList.end()){
                freqList[minFreq]->addNode(node);
                return;
            }

            freqList[minFreq] = new List();

            freqList[minFreq]->addNode(node);
        } else {
            
            freqList[minFreq]->addNode(node);
            currSize++;
        }
    }
};


int main(){
    
 cout << endl;
return 0;
}