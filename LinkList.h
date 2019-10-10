/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   LinkedList.h
 * Author: william
 *
 * Created on October 4, 2019, 6:32 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Link.h"
#include <iostream>
#include "stack"

using namespace std;


template <class T>
class LinkedList {

public:

    Link<T> *fillLnk(T);

    void prntLnk(Link<T> *);

    void destroy(Link<T> *);

    Link<T> *findEnd(Link<T> *);

    Link<T> *pushFrt(Link<T> *, T);

    Link<T> *pushBck(Link<T> *, T);

    bool findVal(Link<T> *, T);

    T cntVal(Link<T> *, T);

    T lstSize(Link<T> *);

    Link<T> *popFrt(Link<T> *, T &);

    Link<T> *popBck(Link<T> *, T &);

    T getElementAt(Link<T> *list, int index);

    Link<T> *linkedList(Link<T> *link);

    void swap(T *a, T *b);

    Link<T> *partition(Link<T> *, Link<T> *);

    void quickSortUtil(Link<T> *, Link<T> *);

    void quickSort(Link<T> *);
    void quickSortprioritized(Link<T> *);
    void quickSortUtilprioritized(Link<T> *, Link<T> *);
    Link<T> *partitionprioritized(Link<T> *l, Link<T> *h);
    void PrintPrioritized(Link<T> *list);
};
template <class T>
Link<T> *LinkedList<T>::linkedList(Link<T> *link) {
    link->data = 0;
    link->priority=0;
    link->next = NULL;
    link->prev = NULL;
};

template <class T>
Link<T> *LinkedList<T>::popBck(Link<T> *list, T &val) {
    if (!list)return 0;
    Link<T> *front = list, *back;
    while (front->next) {
        back = front;
        front = front->next;
    }
    val = front->data;
    front->priority=front->priority+1;
    delete front;
    back->next = 0;
    return list;
}

template <class T>
Link<T> *LinkedList<T>::popFrt(Link<T> *list, T &val) {
    if (!list)return 0;
    val = list->data;
    Link<T> *front = list->next;
    front->prev = NULL;
    if (list != NULL) {
        front->next->prev = front;
    }
    delete list;
    return front;
}
template <class T>
T LinkedList<T>::lstSize(Link<T> *list) {
    Link<T> *front = list;
    T cnt = 0;
    while (front) {
        cnt++;
        front = front->next;
    }
    return cnt;
}
template <class T>
T LinkedList<T>::cntVal(Link<T> *list, T val) {
    Link<T> *front = list;
    T cnt = 0;
    while (front) {
        if (front->data == val)cnt++;
        front = front->next;
    }
    return cnt;
}
template <class T>
bool LinkedList<T>::findVal(Link<T> *list, T val) {
    Link<T> *front = list;
    while (front) {
        if (front->data == val)return true;
        front = front->next;
    }
    return false;
}
template <class T>
Link<T> *LinkedList<T>::pushBck(Link<T> *list, T val) {
    Link<T> *back = new Link<T>;
    back->data = val;
    back->next = 0;
    Link<T> *end = findEnd(list);
    end->next = back;
    if (end != NULL) {
        back->prev = end;
    }
    return list;
}
template <class T>
Link<T> *LinkedList<T>::pushFrt(Link<T> *list, T val) {
    Link<T> *front = new Link<T>;
    front->data = val;
    front->priority= 0;
    front->next = list;
    if (list != NULL) {
        list->prev = front;
    }
    front->prev = NULL;
    return front;
}
template <class T>
Link<T> *LinkedList<T>::fillLnk(T n) {
    //from end to front
    Link<T> *front = 0;
    T cnt = n;

    do {

        front = pushFrt(front, rand() % 9 + 1);
        cnt--;
    } while (cnt);
    return front;
}
template <class T>
Link<T> *LinkedList<T>::findEnd(Link<T> *list) {
    Link<T> *front = list, *back;
    while (front) {
        back = front;
        front = front->next;
    }
    return back;
}
template <class T>
void LinkedList<T>::destroy(Link<T> *list) {
    Link<T> *front = list;
    while (front) {
        Link<T> *temp = front;
        front = front->next;
        delete temp;
    }
    list->next = 0;
}
template <class T>
void LinkedList<T>::prntLnk(Link<T> *list) {
    Link<T> *front = list;
    cout << endl;
    while (front) {
        cout <<"data ->"<< front->data<<"--->> priority ->" <<front->priority<< endl;
        front->priority=front->priority+1;
        front = front->next;
    }
    cout << endl;
}


//swap two node
template <class T>
void LinkedList<T>::swap(T *a, T *b) {
    T t = *a;
    *a = *b;
    *b = t;
}

//partition
template <class T>
Link<T> *LinkedList<T>::partition(Link<T> *l, Link<T> *h) {
    //set pivot
    int x = h->data;
    h->priority=h->priority+1;

    Link<T> *i = l->prev;

    for (Link<T> *j = l; j != h; j = j->next) {
        j->priority=j->priority+1;
        if (j->data <= x) {
            if (i == NULL) {
                i = l;
            } else {
                i = i->next;
            }
            i->priority=i->priority+1;
            j->priority=j->priority+1;
            swap(&(i->data), &(j->data));
        }
    }
        if (i == NULL) {
            i = l;
        } else {
            i = i->next;
        }
        i->priority=i->priority+1;
        h->priority=h->priority+1;
        swap(&(i->data), &(h->data));
        return i;
}

template <class T>
void LinkedList<T>::quickSortUtil(Link<T> *l, Link<T> *h) {
    if (h != NULL && l != h && l != h->next) {
        Link<T> *c = partition(l, h);
        quickSortUtil(l, c->prev);
        quickSortUtil(c->next, h);

    }
}


template <class T>
void LinkedList<T>::quickSort(Link<T> *front) {
    Link<T> *end = findEnd(front);
    quickSortUtil(front, end);

}

template <class T>
T LinkedList<T>::getElementAt(Link<T> *list, int index) {
    Link<T> *front = list;
    int cut = 0;
    while (front) {
        if (cut == index) {
              front->priority = front->priority + 1;
              return front->data;
         }
    }
    return 0;
}


//partition
template <class T>
Link<T> *LinkedList<T>::partitionprioritized(Link<T> *l, Link<T> *h) {
    //set pivot
    int x = h->priority;

    Link<T> *i = l->prev;

    for (Link<T> *j = l; j != h; j = j->next) {
        if (j->priority <= x) {
            if (i == NULL) {
                i = l;
            } else {
                i = i->next;
            }
            swap(&(i->priority), &(j->priority));
        }
    }
    if (i == NULL) {
        i = l;
    } else {
        i = i->next;
    }
    swap(&(i->priority), &(h->priority));
    return i;
}

template <class T>
void LinkedList<T>::quickSortUtilprioritized(Link<T> *l, Link<T> *h) {
    if (h != NULL && l != h && l != h->next) {
        Link<T> *c = partitionprioritized(l, h);
        quickSortUtilprioritized(l, c->prev);
        quickSortUtilprioritized(c->next, h);

    }
}


template <class T>
void LinkedList<T>::quickSortprioritized(Link<T> *front) {
    Link<T> *end = findEnd(front);
    quickSortUtilprioritized(front, end);

}

template <class T>
void LinkedList<T>::PrintPrioritized(Link<T> *list) {
    Link<T> *front = list;
    Link<T> *end = findEnd(list);
    cout << endl;
    while (end) {
        cout <<"data ->"<< end->data<<"--->> priority ->" <<end->priority<< endl;
        end->priority=end->priority+1;
        end = end->prev;
    }
    cout << endl;

}





#endif /* LINKEDLIST_H */

