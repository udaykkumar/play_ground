#ifndef __02_08_2019_HPP_INCLUDED__
#define __02_08_2019_HPP_INCLUDED__
#include <iostream>

namespace daily_interview
{
    struct node
    {
        size_t data_;
        struct node *next_;

        node(size_t data) : data_(data), next_(nullptr) { }

        size_t          get()
        {
            return data_;
        }
        struct node *&next()
        {
            return next_;
        }
    };


    struct list
    {
        struct node *head_;

        list() : head_(nullptr) {}

        void add(const size_t data);
        void show();
    };

    size_t intersection(struct list &list1, struct list &list2);
}

#endif
