#include "SBody.h"


 
    SBody::node*SBody::addnode(int x, int y)
    {
        node* tmp = new node;
        tmp->next = nullptr;
        tmp->past = nullptr;
        tmp->x = x;
        tmp->y = y;
        size++;
        return tmp;
    }


    SBody::SBody() {
        Head = nullptr;
        Tail = nullptr;
        size = 0;
        AddHead(20, 10);
    }
    int SBody::getx() {
        return Head->x;
    }
    int SBody::gety() {
        return Head->y;
    }
    int SBody::getTx() {
        return Tail->x;
    }
    int SBody::getTy() {
        return Tail->y;
    }

    /*  void AddTail(T x) {
          node* tmp = addnode(x);

          if (Tail) Tail->next = tmp;
          tmp->past = Tail;
          Tail = tmp;
          if (!Head) Head = Tail;
          size++;
      }*/

    void SBody::AddHead(int x, int y) {
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

    void SBody::DeleteTail() {
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
    void SBody::move(char cord, int dir) {
        if (cord =='x') {
            AddHead(getx() + dir, gety());
        }
        if (cord =='y') {
            AddHead(getx() , gety() + dir);
        }
        
    }
    bool SBody::checkTail(int x,int y, bool flag) {
        node* tmp;
        if (!flag) tmp = Head->next;
        else tmp = Head;
        while (tmp)
        {
            if (x == tmp->x && y == tmp->y) return true;
            tmp = tmp->next;
        }
        return false;

    }


