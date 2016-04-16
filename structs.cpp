#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

using namespace std;


void Stack::create(){
    head = NULL;
};

void Stack::close(){
    Node *p;
    while (head){
        p = head;
        head = head->next;
        delete p;
    }
}
void Stack::push(Node push_data){
    Node *newnode = new Node;
    newnode->std_num = push_data.std_num;
    newnode->card=push_data.card;
    newnode->type=push_data.type;
    newnode->next = head;
    head = newnode;
}

Node Stack::pop(){
    Node *topnode;
    Node temp;
    topnode = head;
    head = head->next;
    temp.std_num = topnode->std_num;
    temp.card=topnode->card;
    temp.type=topnode->type;
    delete topnode;
    return temp;
}

bool Stack::isempty(){
    return (head == NULL);
}

/**The above shows stack,the below shows queue **/

void Queue::create(){
    front = NULL;
    back = NULL;
}

void Queue::close(){
    Node *p;
    while (front) {
        p = front;
        front = front->next;
        delete p;
    }
}

void Queue::enqueue(Node newdata){
    Node* newnode;
    newnode = new Node;
    newnode->std_num = newdata.std_num;
    newnode->card = newdata.card;
    newnode->type = newdata.type;
    newnode->next = NULL;
    if ( front==NULL )
    {
        back = newnode;
        front = back;
    }
    else
    {
        back->next = newnode;
        back = newnode;
    }
}

Node Queue::dequeue() {
    Node *topnode;
    Node temp;

    topnode = front;
    front = front->next;
    temp.std_num = topnode->std_num;
    temp.card=topnode->card;
    temp.type=topnode->type;

    delete topnode;
    return temp;
}


bool Queue::isempty() {
    return front == NULL;
}


