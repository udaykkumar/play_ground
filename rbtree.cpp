// rbtree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ref : https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/


#include <iostream>
#include <cassert>
#include <queue>

enum color {
    Red,
    Black
};

struct rb_node {

    bool is_red() const {
        return color_ == Red;
    }

    bool is_black() const {
        return color_ == Black;
    }

    void mark_red() {
        color_ = Red;
    }

    void mark_black() {
        color_ = Black;
    }

    void make_root() {
        mark_black();
        parent_ = nullptr;
    }

    rb_node* make_root_node(int key) {
        this->mark_black();
        this->key_ = key;
        this->parent_ = nullptr;
        return this;
    }

    rb_node* make_a_node(rb_node*p, int key) {
        this->mark_red();
        this->key_ = key;
        this->parent_ = p;
        (key > p->key_) ?
            p->right_ = this : p->left_ = this;
        return this;
    }

    int key_;
    rb_node* left_;
    rb_node* right_;
    rb_node* parent_;
    color color_;

};


struct rb_tree {

    void insert(int key) {
        // if there is root , insert as BST and proceed with fixing violations
        // else make a root node
        if (has_root()) {
            assert(root_ && "now root can not be null");
            rb_node* parent= nullptr;
            for (rb_node* current = root_; current != nullptr; ) {
                parent = current;
                current = (key > current->key_) ?
                    current->right_ : current->left_;
            }

            assert(parent && "parent can not be null ");
            rb_node* k = insert_node(parent, key);
            assert(k->parent_ == parent && "parent links are not correctly set");

            //  Fix any violations with rb tree properties
            //
            fix_violations(k);
        }
        else {
            root_ = make_root(key);
        }
    }

    void show() {
        if (root_ == nullptr)
            return;
        std::queue<rb_node*> q;
        q.push(root_);
        while (!q.empty())
        {
            rb_node* current = q.front();
            q.pop();
            std::cout << current->key_ << " ";
            if (current->left_ != nullptr)
                q.push(current->left_);
            if (current->right_ != nullptr)
                q.push(current->right_);
        }
        std::cout << std::endl;
    }

    // constructor
    rb_tree() : root_(nullptr) {}

private:

    // root is always black
    bool has_root() const {
        return root_ != nullptr && root_->is_black();
    }

    // if given node is root node
    bool is_root( rb_node *node) const {
        return node != nullptr && node == root_;
    }

    // given node get the grand parent
    rb_node* grand_parent(rb_node *node) const {
        return node && node->parent_ ? node->parent_->parent_ : nullptr;
    }

    // given node and grand parent g
    // get uncle
    rb_node* uncle(rb_node* k, rb_node* g) const {
        return k->parent_ == g->left_ ?
                g->right_ : g->left_;
    }

    // create a node and make it root
    rb_node* make_root(int key) {
        return (new rb_node())->make_root_node(key);
    }

    // create a node and insert at applicable position
    rb_node* insert_node(rb_node* parent, int key) {
        return (new rb_node())->make_a_node(parent, key);
    }

    // fix rb tree violations if any
    void fix_violations(rb_node* k) {
        //  if parent of this new node k is black
        // no need to fix any violations
        while (k && k->parent_->is_red()) {

            // get grant parent
            rb_node* g = grand_parent(k);
            assert(g && "grant parent must exist");

            rb_node* p = k->parent_;
            assert(p && "parent must exist");

            // get the uncle
            rb_node* u = uncle(k, g);

            if (p->is_red() && u && u->is_red()) {
                k->parent_->mark_black();
                u->mark_black();
                is_root(g) ? g->mark_black() : g->mark_red();
            }
            else if (p->is_red() && (u == nullptr || u->is_black())) {

                if (p == g->right_ && k == p->right_) {
                    left_rotate(g);
                    // sibling as red
                    p->left_->mark_red();
                }
                if (p == g->right_ && k == p->left_) {

                    right_rotate(g);
                    left_rotate(g);

                    // sibling as red
                    p->left_->mark_red();
                }
                else if (p == g->left_ && k == g->left_) {
                    right_rotate(g);
                    // sibling as red
                    p->right_->mark_red();
                }
                else if (p == g->left_ && k == g->right_) {
                    right_rotate(g);
                    left_rotate(g);
                    // sibling as red
                    p->right_->mark_red();
                }

                // parent as black
                p->mark_black();

            }
            else {
                assert(false && "this should never happen");
            }
        }
    }

    void right_rotate(rb_node* k) {
        rb_node* new_parent = k->left_;
        k->left_ = new_parent->right_;
        if (new_parent->right_ != nullptr) {
            new_parent->right_->parent_ = k;
        }
        new_parent->parent_ = k->parent_;
        if (k->parent_ == nullptr) {
            root_ = new_parent;
        }
        else if (k == k->parent_->left_) {
            k->parent_->left_ = new_parent;
        }
        else {
            k->parent_->right_ = new_parent;
        }
        new_parent->right_ = k;
        k->parent_ = new_parent;
    }

    void left_rotate(rb_node* k) {
        rb_node* new_parent = k->right_;
        k->right_ = new_parent->left_;
        if (new_parent->left_ != nullptr) {
            new_parent->left_->parent_ = k;
        }
        new_parent->parent_ = k->parent_;
        if (k->parent_ == nullptr) {
            root_ = new_parent;
        }
        else if (k == k->parent_->left_) {
            k->parent_->left_ = new_parent;
        }
        else {
            k->parent_->right_ = new_parent;
        }
        new_parent->left_ = k;
        k->parent_ = new_parent;
    }

private:
    // root node
    struct rb_node* root_;
};


#include <chrono>

int main()
{
    std::vector<size_t> itemsCount;
    size_t MaxItems = 10000000;
    for (size_t items = 10; items < 10000000; items *= 2)
    {
        itemsCount.push_back(items);
    }

    for (auto items : itemsCount)
    {
        std::cout << " Inserting " << items << " items in the tree\n";
        rb_tree tree;
        auto start = std::chrono::high_resolution_clock::now(); // Start the timer
        for (size_t i = 0; i < items; i++)
        {
            tree.insert(i);
        }
        auto end = std::chrono::high_resolution_clock::now(); // Stop the timer

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); // Calculate the duration in milliseconds
        std::cout << "Time taken for inserting " << items << " items: " << duration.count() << " milliseconds" << std::endl;
    }

    return 0;
}
