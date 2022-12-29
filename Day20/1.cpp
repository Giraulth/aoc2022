#include <bits/stdc++.h>
using namespace std;

struct Node { 
  int data; 
  Node *next;
  Node *prev;

  // Parameterised constructor with default argument
  Node(int val=0) :data(val),next(nullptr), prev(nullptr){}

};

int main() {

    ifstream file("day20.txt");
    string str;
    vector<Node*> l;
    vector<int> nums;
    Node* head;
    Node* zero;
    
    while (std::getline(file, str))
    {
        l.push_back(new Node(stoi(str)));
    }

    for (int i = 0; i < l.size() - 1 ; i++){
        l[i]->next = l[i+1];
        l[i+1]->prev = l[i];
    }

    head = l[0];
    l[0]->prev = l[l.size()-1];
    l[l.size()-1]->next = l[0];

    for (int i = 0; i < l.size(); i++){
        Node* curr = l[i];
        if (curr->data == 0)
            zero = curr;
        Node* prev = curr->prev;
        Node* next = curr->next;
        prev->next = curr-> next; 
        next->prev = prev;

        Node* newPrev = curr;
        Node* newNext = curr;
        
        if (curr->data > 0) {
            for (int j = 0; j < curr->data; j++){
                newPrev = newPrev->next;
            }
        }
        else {
            for (int j = 0; j >= curr->data; j--){
                newPrev = newPrev->prev;
            }
        }

        newNext = newPrev->next;

        curr->prev = newPrev;
        newPrev->next = curr;
        curr->next = newNext;
        newNext->prev = curr;

        if (curr == head){
            head = next;
        }
    }

    int res = 0;
    Node* first = zero;
    Node* second = zero;
    Node* third = zero;
    for (int i = 0; i < 1000%l.size(); i ++){
        first = first->next;
    }
    for (int i = 0; i < 2000%l.size(); i ++){
        second = second->next;
    }
    for (int i = 0; i < 3000%l.size(); i ++){
        third = third->next;
    }
    
    res += first->data + second->data + third->data;
    cout << res << endl;

    return 0;
}
