#include <iostream>
#include <vector>
#include <queue>

void printQ( std::priority_queue<int, std::vector<int>, std::greater<> > q ) {
    while ( ! q.empty() ) {
        std::cout << q.top() << " " ;
        q.pop();
    }
    std::cout << "\n";
}
int findKthLargest( std::vector<int> &nums, int k) {

    std::priority_queue<int, std::vector<int>, std::greater<> > pq;
    for ( auto n : nums ) {
        if ( pq.size() < k ) {
            pq.push(n);
        } else {
            if ( n > pq.top() ) {
                pq.pop();
                pq.push(n);
            }
        }

        std::cout << " Push " << n << " PQ size " << pq.size() ;
        if ( pq.size() > 0 )
            std::cout << " top " << pq.top() << "\n";
        else
            std::cout <<  "\n";

    }

    printQ(pq);
    return pq.top();
}


int main(int argc, char const *argv[]) {
    /* code */
    {
        std::vector<int> nums = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
        std::cout << findKthLargest( nums, 4) << "\n";
    }

    {
        std::vector<int> nums = { 3, 2, 1, 5, 6, 4};
        std::cout << findKthLargest( nums, 2) << "\n";
    }

    return 0;
}