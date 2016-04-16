/**
 * Full Name:Furkan Artunç
 * ID: 150130048
 * Date: 20/12/2015
 */
#ifndef STRUCTS_H_
#define STRUCTS_H_
#include <string>
using namespace std;

struct Node
{
    int std_num;
    string type;
    string card;
    Node* next;
};

struct Stack
{
    Node *head;
    void create();
    void close();
    void push(Node);
    Node pop();
    bool isempty();
};

struct Queue
{
    Node *front;
    Node *back;
    void create();
    void close();
    void print_queue();
    void enqueue(Node);
    Node dequeue();
    bool isempty();
};
#endif // STRUCTS_H_
