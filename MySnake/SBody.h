#pragma once


class SBody
{
private:

   struct node {
            struct node* next;
            struct node* past;
            int x;
            int y;
        };
        node* Head;
        node* Tail;
        int size;
        node* addnode(int x, int y);
        




public:
    SBody();
    int gety();
    int getx();
    int getTx();
    int getTy();
    void AddHead(int x, int y);


    void DeleteTail();

    bool checkTail(int x, int y, bool flag = 0);
    void move(char cord, int dir);
   
};