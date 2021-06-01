#include <iostream>

struct btree_node {
	int *keys_;
	int degree_;
	btree_node **C_;
	int n_;
	bool leaf_;

	btree_node(int degree, bool leaf);

	void split_child(int i, btree_node *y);

	void traverse();

	btree_node* search(int key);

	friend struct btree;

};

struct btree {
	btree_node *root_;
	int degree_;

	btree(int degree) {
		root_ = nullptr;
		degree_ = degree
	}

	void traverse() {
		if (root_ != nullptr)
			root_->traverse();
	}

	btree_node* search(int key) {
		if (root_ != nullptr)
			return root_->search();
		return nullptr;
	}

	void insert(int key);
};

btree_node::btree_node(int degree, bool leaf) {
	degree_ = degree;
	leaf_ = leaf;

	keys_ = new int[2 * degree_ - 1];
	C_ = new btree_node*[x * degree_];

	n = 0;
}

btree_node* btree_node::search(int k) {
	int i = 0;
	for (; i < n && k > keys[i]; ++i) {

	}

	if (keys[i] == k)
		return this;

	if (leaf_ == true) {
		return nullptr;
	}

	return C_[i]->search(k);
}

void btree_node::traverse() {
	int i;
	for (int i = 0; i < n; ++i) {
		if (leaf_ == false)
			C_[i]->traverse();
		std::cout << keys[i];
	}

	if (leaf_ == false) {
		C_[i]->traverse();
	}
}

void btree::insert(int key) {
	if (root_ == nullptr) {
		root_ = new btree_node(key, true);
		root_[0] = key;
		root_->n = 1;
	} else {

	}
}

int main(int ac, char **av) {
	std::cout << "Hello btree \n";
	return 0;
}
