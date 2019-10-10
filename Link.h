
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.h
 * Author: rcc
 *
 * Created on September 24, 2019, 11:23 AM
 */

#ifndef LINK_H
#define LINK_H
template <class T>
struct Link{
    T data;
    int priority;
    Link *next;
    Link *prev;
};

#endif /* LINK_H */