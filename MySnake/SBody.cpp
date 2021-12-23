#include "SBody.h"


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
    node* addnode(int x, int y)
    {
        node* tmp = new node;
        tmp->next = nullptr;
        tmp->past = nullptr;
        tmp->x = x;
        tmp->y = y;
        size++;
        return tmp;
    }

public:
    SBody() {
        Head = nullptr;
        Tail = nullptr;
        size = 0;
    }


    /*  void AddTail(T x) {
          node* tmp = addnode(x);

          if (Tail) Tail->next = tmp;
          tmp->past = Tail;
          Tail = tmp;
          if (!Head) Head = Tail;
          size++;
      }*/

    void AddHead(int x, int y) {
        node* tmp = addnode(x, y);


        if (Head) Head->past = tmp;
        tmp->next = Head;
        Head = tmp;
        if (!Tail)  Tail = Head;
        size++;
    }


    /*void Insert(T x, int i) {
        node* tmp = Head;
        if (i <= 0) AddHead(x);
        while (i > 0 && tmp->next != NULL) {
            tmp = tmp->next;
            i--;
        }
        node* newtmp = addnode(x);
        if (tmp->past != NULL) {
            node* tmp2 = tmp->past;
            tmp2->next = newtmp;
            newtmp->past = tmp2;
        }
        tmp->past = newtmp;
        newtmp->next = tmp;
    }*/

    void DeleteTail() {
        node* tmp = Tail;
        Tail = tmp->past;
        delete tmp;
        size--;
    }

    /*void Ndelete(int i) {
        node* tmp = Head;
        if (i < 0) return;
        if (i == 0) {
            tmp = Head;
            Head = Head->next;
            delete tmp;
            size--;
            return;
        }
        for (i; i > 0; i--) {
            if (tmp->next == NULL) return;
            tmp = tmp->next;

        }
        node* tmp2 = tmp->past; node* tmp3 = tmp->next;
        if (Tail == tmp) {
            tmp2->next = tmp->next;
            Tail = tmp2;
            delete tmp;
            size--;
            return;
        }
        tmp2->next = tmp3;
        tmp3->past = tmp2;
        delete tmp;
        size--;
    }*/
    void move(int x, int y) {

        AddHead(x, y);
        DeleteTail();
    }

};