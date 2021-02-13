#ifndef __ITERATOR_HPP_INCLUDED__
#define __ITERATOR_HPP_INCLUDED__

#include <iostream>

namespace bira
{
struct list
{
private:
    struct node;

public:
    struct iterator
    {
        iterator() : current_(nullptr) {}

        iterator(node *p) : current_(p) {}

        iterator operator ++()
        {
            current_ = current_->next();
            return *this;
        }

        bool operator != ( iterator rhs )
        {
            return current_ != rhs.current_;
        }

        int get()
        {
            return current_->get();
        }

    private:
        node *current_;
    };

    iterator begin()
    {
        return iterator(head_);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    list() : head_(nullptr), size_(0) {}

    size_t size() const
    {
        return size_;
    }

    void add(const int data);
    void reverse();
    void traverse();

private:
    node *head_;
    size_t size_;

    struct node
    {
        node(int x) : data_(x), next_(nullptr) {}

        node *&next()
        {
            return next_;
        }

        int get() const
        {
            return data_;
        }

    private:
        int data_;
        node *next_;
    };

    node *&root()
    {
        return head_;
    }
};

} // namespace bira

#endif
