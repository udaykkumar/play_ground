/*
Hi, here's your problem today. This problem was recently asked by Google:

Given a singly-linked list, reverse the list. This can be done iteratively or recursively. Can you get both solutions?

Example:
Input: 4 -> 3 -> 2 -> 1 -> 0 -> NULL
Output: 0 -> 1 -> 2 -> 3 -> 4 -> NULL
 */

#ifndef __16_07_2019_HPP_INCLUDED__
#define __16_07_2019_HPP_INCLUDED__

#include <iostream>

struct list
{

private:
    struct node 
    {
        node(int data) :
            data_(data), next_(nullptr) {} 

        bool    has_next() { return next_ ? true : false; }
        node*&      next() { return next_; }
        int          get() { return data_; }

    private:
        int data_;
        struct node* next_;

    };


    node*  head_;
    size_t size_;

public:
    list() :
        head_(nullptr), size_(0) {}

    void add(const int data);
    void traverse();
    void reverse();
    size_t size() const { return size_; }
    node*&  root() { return head_; }
    
};
#endif