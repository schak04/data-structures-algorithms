#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* create(int val){
    Node* node = new Node();
    node->data = val;
    node->next = nullptr;
    return node;
}

Node* insertBegin(Node* header, int val){
    Node* node =create(val);
    if(header-> next == nullptr){
        header-> next = node;
        node-> next = header;
        header-> data++;
        return header;
    }
    
    node-> next = header-> next;
    header-> next = node;
    header-> data++;
    return header;
}

Node* insertLast(Node* header, int val){
    Node* node = create(val);
    if(header-> next == nullptr){
        return insertBegin(header, val);
    }
    Node* temp = header-> next;
    while(temp-> next != header){
        temp = temp-> next;
    }
    node-> next = temp->next;
    temp-> next = node;
    header-> data++;
    return header;
}

Node* insert(Node* header, int val, int index){
    if(index == 1){
        return insertBegin(header, val);
    }
    if(index == (header-> data)+1){
        return insertLast(header, val);
    }
    
    Node* node = create(val);
    Node* prev = header-> next;
    for(int i= 1; i< index-1;i++){
        prev = prev-> next;
    }
    node-> next = prev->next;
    prev-> next = node;
    header-> data++;
    return header;
}

// Function to delete the first node
Node* deleteBegin(Node* header){
    if(header-> next == nullptr){
        cout << "List is empty!" << endl;
        return header;
    }
    
    Node* temp = header-> next;
    if(temp-> next == header){ // Only one element in the list
        header-> next = nullptr;
    } else {
        Node* newFirst = temp-> next;
        header-> next = newFirst;
    }
    
    header-> data--;
    delete temp;
    return header;
}

// Function to delete the last node
Node* deleteLast(Node* header){
    if(header-> next == nullptr){
        cout << "List is empty!" << endl;
        return header;
    }
    
    Node* temp = header-> next;
    if(temp-> next == header){ // Only one element in the list
        return deleteBegin(header);
    }

    Node* prev = nullptr;
    while(temp-> next != header){
        prev = temp;
        temp = temp-> next;
    }
    prev-> next = header; // Update the previous node to point to the header
    header-> data--;
    delete temp;
    return header;
}

// Function to delete a node at a specific position
Node* deleteAt(Node* header, int index){
    if(header-> next == nullptr || index < 1 || index > header-> data){
        cout << "Invalid position or list is empty!" << endl;
        return header;
    }
    
    if(index == 1){
        return deleteBegin(header);
    }
    if(index == header-> data){
        return deleteLast(header);
    }

    Node* prev = header-> next;
    for(int i = 1; i < index-1; i++){
        prev = prev-> next;
    }
    
    Node* temp = prev-> next;
    prev-> next = temp-> next;
    header-> data--;
    delete temp;
    return header;
}

// Function to display the list
void display(Node* header){
    Node* temp = header->next;
    while(temp != header){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main(){
    Node* header = create(0);
    header = insertBegin(header,34);
    display(header);
    
    header = insertBegin(header, 20);
    header = insertBegin(header, 19);
    display(header);
    
    header = insertLast(header, 10);
    display(header);
    
    header = insert(header, 65, 5);
    display(header);
    
    // Deleting the first node
    header = deleteBegin(header);
    display(header);
    
    // Deleting the last node
    header = deleteLast(header);
    display(header);
    
    // Deleting at position 2
    header = deleteAt(header, 2);
    display(header);

    return 0;
}
