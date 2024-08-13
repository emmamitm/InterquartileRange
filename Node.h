//
// Created by Emma Mitchell on 9/16/23.
//

#ifndef LLIQR_NODE_H
#define LLIQR_NODE_H


#include <iostream>
#include <iomanip>

class Node {
public:
    int value;
    Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = abs(key);
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    float Q1;
    float Q3;
    float IQR=0.0;
    int countFast=1;
    int countSlow=1;
    if (head == nullptr){
        IQR=0.0;
        return IQR;
    }
    else if(head->next== nullptr){
        //one value in the list
        IQR= head->value;
        return IQR;
    }else{
        Node *fastptr =head;
        Node *slowptr= head;
        Node *movingptr = head;
        while (fastptr!= nullptr){
            if (fastptr->next== nullptr){//ODD
                //fast is on the last node
                if(countSlow%2 ==0){//if middle is even
                    int half = countSlow/2;
                    for (int i = 0; i < half-1; ++i) {
                        movingptr= movingptr->next;
                        slowptr= slowptr->next;
                    }
                    slowptr= slowptr->next;
                    IQR= slowptr->value-movingptr->value;
                    return IQR;
                } else{
                    if (countFast==3){
                        IQR= fastptr->value-slowptr->value;
                        return IQR;
                    }
                    float half = round((countSlow/2.0));
                    int loop = (int)half;
                    for (int i = 0; i < loop-2; ++i) {
                        movingptr=movingptr->next;
                    }
                    Q1= (movingptr->value+movingptr->next->value)/2.0;
                    for (int i = 0; i < loop-1; ++i) {
                        slowptr=slowptr->next;
                    }
                    Q3= (slowptr->value+slowptr->next->value)/2.0;
                    IQR = Q3-Q1;
                    return IQR;
                }
            } else if (fastptr->next->next== nullptr){//EVEN
                if (countSlow%2==0){
                    int half= countSlow/2;
                    for (int i = 0; i < half-1; ++i) {
                        movingptr= movingptr->next;
                    }
                    Q1= (movingptr->value+movingptr->next->value)/2.0;
                    for (int i = 0; i < half; ++i) {
                        slowptr= slowptr->next;
                    }
                    Q3= (slowptr->value+slowptr->next->value)/2.0;
                    IQR=  Q3 - Q1;
                    return IQR;

                } else{
                    float half= round(countSlow/2.0);
                    int loop = (int)half;
                    for (int i = 0; i < loop-1; ++i) {
                        movingptr=movingptr->next;
                    }
                    Q1= movingptr->value;
                    for (int i = 0; i < loop; ++i) {
                        slowptr=slowptr->next;
                    }
                    Q3= slowptr->value;
                    IQR = Q3-Q1;
                    return IQR;
                }


            }
            else{
                //increment fast by 2 and slow by 1
                fastptr= fastptr->next->next;
                countFast= countFast+2;
                slowptr= slowptr->next;
                countSlow=countSlow+1;
            }
        }
    }


    return IQR;
}

#endif //LLIQR_NODE_H
