#include <iostream>
#include "LinkList.h"

int main() {

    srand(static_cast<unsigned int>(time(0)));


    //Initialize Variables

    LinkedList<int>* linkedList;
    Link<int>* link;
    link=linkedList->fillLnk(10);
    linkedList->prntLnk(link);


    //Display the results
    int val=90;
    cout<<"Testing pushing a value from the front"<<endl;
    link=linkedList->pushFrt(link,val);
    cout<<"Value from the front = "<<val<<endl;
    linkedList->prntLnk(link);
    cout<<"Size of the list = "<<linkedList->lstSize(link)<<endl;


    cout<<"Testing pushing a value from the back"<<endl;
    link=linkedList->pushBck(link,val);
    cout<<"Value from the back = "<<val<<endl;
    linkedList->prntLnk(link);
    cout<<"Size of the list = "<<linkedList->lstSize(link)<<endl;


    //Display the results
    //int val;
    cout<<"Testing popping a value from the front"<<endl;
    link=linkedList->popFrt(link,val);
    cout<<"Value from the front = "<<val<<endl;
    linkedList->prntLnk(link);
    cout<<"Size of the list = "<<linkedList->lstSize(link)<<endl;


    cout<<"Testing popping a value from the Back"<<endl;
    link=linkedList->popBck(link,val);
    cout<<"Value from the Back = "<<val<<endl;
    linkedList->prntLnk(link);
    cout<<"Size of the list = "<<linkedList->lstSize(link)<<endl;

    //sort
    cout<<"Sort the link"<<endl;
    linkedList->quickSort(link);
    linkedList->prntLnk(link);


    //using priority to mark last link vistor, every time vistor link need to update priority  of the link
    cout<<"priority the link"<<endl;
    linkedList->quickSortprioritized(link);
    linkedList->PrintPrioritized(link);


    linkedList->destroy(link);
    return 0;
}