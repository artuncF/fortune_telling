/**
 * Full Name:Furkan Artunç
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include <fstream>

ofstream writer("out.txt");

using namespace std;

typedef struct Node deck;
typedef struct Node node;
typedef struct Stack stacky;
typedef struct Queue tailer;

void swap(deck*, int , int );
void recursive_shuffle(deck*,int);

int main()
{
    tailer shuffled_list;
    tailer end_list;         /**stack and queue's are initialized**/
    stacky basket;
    srand(time(NULL));
    basket.create();
    shuffled_list.create();
    end_list.create();

    deck init_deck[52]={{1,"H","A",'\0'},{2,"H","2",'\0'},{3,"H","3",'\0'},{4,"H","4",'\0'},{5,"H","5",'\0'},{6,"H","6",'\0'},{7,"H","7",'\0'},{8,"H","8",'\0'},{9,"H","9",'\0'},{10,"H","10",'\0'},{11,"H","J",'\0'},{12,"H","Q",'\0'},{13,"H","K",'\0'},
          {1,"D","A",'\0'},{2,"D","2",'\0'},{3,"D","3",'\0'},{4,"D","4",'\0'},{5,"D","5",'\0'},{6,"D","6",'\0'},{7,"D","7",'\0'},{8,"D","8",'\0'},{9,"D","9",'\0'},{10,"D","10",'\0'},{11,"D","J",'\0'},{12,"D","Q",'\0'},{13,"D","K",'\0'},
          {1,"C","A",'\0'},{2,"C","2",'\0'},{3,"C","3",'\0'},{4,"C","4",'\0'},{5,"C","5",'\0'},{6,"C","6",'\0'},{7,"C","7",'\0'},{8,"C","8",'\0'},{9,"C","9",'\0'},{10,"C","10",'\0'},{11,"C","J",'\0'},{12,"C","Q",'\0'},{13,"C","K",'\0'},
          {1,"S","A",'\0'},{2,"S","2",'\0'},{3,"S","3",'\0'},{4,"S","4",'\0'},{5,"S","5",'\0'},{6,"S","6",'\0'},{7,"S","7",'\0'},{8,"S","8",'\0'},{9,"S","9",'\0'},{10,"S","10",'\0'},{11,"S","J",'\0'},{12,"S","Q",'\0'},{13,"S","K",'\0'}};

    recursive_shuffle(init_deck,51);               /**This is one recursive call**/

    for(int i=0;i<52;i++)
    {                                                  /**deck is moved to queue named shuffled_list**/
        shuffled_list.enqueue(init_deck[i]);
    }
    writer<<"Shuffled deck:\n";
    shuffled_list.print_queue();

    node dummy;        /**It is initialized to store dequeued elements that make view better**/
    writer<<"Fortune telling steps:\n";
    int counter=1;     /**counter shows the numbers that are said by fortune teller**/
    Node* traverse;     /**traverse stores lists' head in each step**/
    while(!shuffled_list.isempty())
    {
        traverse=shuffled_list.front;
         if(counter==traverse->std_num)         /**if block computes the situations that fortune tellers' number is equal to card number**/
        {
            dummy=shuffled_list.dequeue();
            writer<<counter<<":"<<dummy.type<<":"<<dummy.card<<":"<<"match"<<"\n";
            end_list.enqueue(dummy);        /**appropriate numbers are stored in queue named end_list**/
            while(!basket.isempty())
            {
                shuffled_list.enqueue(basket.pop());
            }
            counter=1;
        }
        else
        {
            if(counter==13)   /**else block computes the not equality situation**/
            {
		dummy=shuffled_list.dequeue();
                writer<<counter<<":"<<dummy.type<<":"<<dummy.card<<":"<<"unmatch"<<"\n";
                basket.push(dummy);
                basket.close();
                counter=1;
            }
            else
            {
                dummy=shuffled_list.dequeue();
                writer<<counter<<":"<<dummy.type<<":"<<dummy.card<<":"<<"unmatch"<<"\n";
                 basket.push(dummy);
                counter++;
            }
        }
    }

    int sum=0;  /**stores the sum of appropriate card numbers that are stored another queue named end_list**/
    writer<<"Fortune results:\n";
    while(!end_list.isempty())
    {
        dummy=end_list.dequeue();             /**shows the results and at the same time end_list is being deallocated**/
        writer<<dummy.type<<":"<<dummy.card<<"\n";
        if(dummy.card=="A" || dummy.card=="J" || dummy.card=="Q" || dummy.card=="K") sum+=10; /**10 points to special cards**/
        else sum+=dummy.std_num;
    }
    writer<<"Sum: "<<sum<<"\n";
    if(sum>=50) writer<<"Your wish will come true!";  /**Shows the result of fortune telling**/
    if(sum<50)  writer<<"Bad luck!";

    basket.close();
    shuffled_list.close();  /**Allocated memory blocks are deallocated**/
    return 0;
}


void swap (deck* swap_deck, int i, int j)
{
	deck temp;                                          /**swaps two variables place in the list**/

	temp = swap_deck[j];
	swap_deck[j] = swap_deck[i];
	swap_deck[i] = temp;
}

void recursive_shuffle(deck* init_deck,int end_index)
{
    if(end_index==1) return;
    int dummy=rand()%(end_index-1);  /**In order to make recursive shuffle "Sattolo's algorithm"(described by Sandra Sattolo in 1986) is implemented**/
    swap(init_deck,end_index,dummy);  /**The algorithm has simple logic so it was not hard to implement as code**/
    recursive_shuffle(init_deck,end_index-1);
}


void Queue::print_queue()           /**This function is used to print shuffled list**/
{
    Node* traverse;
    traverse=front;
    int i=1;
    while(traverse)
    {
        writer<<i<<":"<<traverse->type<<":"<<traverse->card<<"\n";
        i++;
        traverse=traverse->next;
    }
}
