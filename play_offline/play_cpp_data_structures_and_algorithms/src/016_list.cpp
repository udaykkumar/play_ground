#include "016_list.h"

namespace ds
{


	list::list() :
		count_(0)
	{
		
	}

	list::~list()
	{
	}


	int  list::get(int index)
	{
		/// Trying to access anything less than what we have is an error
		/// also any negative index is considered error
		if ( index > count_ or index < 0 )
			return -1;

		return items_[index];
	}
    
    void list::insert(int index, int val)
    {
        // Check if the index is out of bound
	    if(index < 0 || index > count_)
	        return;

	    // Copy the current array
	    int * oldArray = items_;

	    // Increase the array length
	    count_++;

	    // Initialize a new array
	    items_ = new int[count_];

	    // Fill the new array with inserted data
	    for(int i = 0, j = 0; i < count_ ; ++i )
	    {
	        if(index == i)
	        {
	            items_[i] = val;
	        }
	        else
	        {
	            items_[i] = oldArray[j];
	            ++j;
	        }
	    }

	    // remove copied array
	    delete [] oldArray;
    
    }

    int  list::search(int val)
    {	
    	for (int i = 0; i < count_ ; ++i)
    	{
    		if ( items_[i] == val )
    			return i;
    	}
    	return -1;
    }
    
    void list::remove(int index)
    {
    	/// This is invalid index return immediately
    	if ( index < 0 )
    		return;

    	/// Okay generally I'd be happy mark the item as -1
    	/// and move on but then that wont be the correct way
    	

    	/// if its just one element delete it 
    	// and clean up everything
    	if ( count_ == 1 )
    	{
    		delete [] items_;
    		count_ -= 1;
    		return;
    	}

    	/// Create memory one less than count_
    	int *na = new int [count_ - 1]; 

    	/// Copy everything from items_ except the one pointed by index
    	for ( int i = 0; i < count_; ++i ) 
    	{
    		if ( i == index ) 
    			continue;

    		na[i] = items_[i];
    	}

    	/// delete the items_ and make it point to new array
    	delete []items_;
    	items_ = na;

    	/// update count_ 
    	count_ -= 1;
    }

    int  list::count() const
    {
    	return count_;
    }
}

int main(int argc, char const *argv[])
{
	{
		/// Create a list
		ds::list lst;

		/// add some numbers and delete them
		std::cout << "Insert elements to list " << std::endl;
		for (int i = 0; i < 5; ++i)
			lst.insert(i,i);
		
		/// get the added numbers
		std::cout << "elements in list " << std::endl;
		for (int i = 0; i < 5; ++i)
			std::cout << lst.get(i) << " ";
		std::cout << std::endl;

	}

	{
		/// Create a list
		ds::list lst;
		
		/// add some numbers beyond the boundary
		std::cout << "Insert elements to list " << std::endl;
		for (int i = 0; i < 6; ++i)
			lst.insert(i,i);
		
		/// get numbers beyond the boundary
		std::cout << "elements in list " << std::endl;
		for (int i = 0; i < 6; ++i)
			std::cout << lst.get(i) << " ";
		std::cout << std::endl;

	}

	{
		// Initialize a List
	    ds::list list;

	    // Add several items to the List
	    list.insert(0, 21);
	    list.insert(1, 47);
	    list.insert(2, 87);
	    list.insert(3, 35);
	    list.insert(4, 92);

	    // Print current List
	    std::cout << "List elements:" << std::endl;
	    for(int i = 0; i < list.count(); ++i)
	    {
	        std::cout << list.get(i) << " ";
	    }
	    std::cout << std::endl << std::endl;

	    // insert several items in the middle of the List
	    list.insert(2, 25);
	    list.insert(2, 71);

	    // Print the List again
	    std::cout << "New List elements:" << std::endl;
	    for(int i = 0; i < list.count(); ++i)
	    {
	        std::cout << list.get(i) << " ";
	    }
	    std::cout << std::endl << std::endl;

	    // search value 71
	    std::cout << "search element 71" << std::endl;
	    int result = list.search(71);
	    if(result == -1)
	        std::cout << "71 is not found";
	    else
	        std::cout << "71 is found at index " << result;
	    std::cout << std::endl << std::endl;

	    // remove index 2
	    std::cout << "remove element at index 2" << std::endl;
	    list.remove(2);
	    std::cout << std::endl;

	    // Print the List again
	    std::cout << "New List elements:" << std::endl;
	    for(int i = 0; i < list.count(); ++i)
	    {
	        std::cout << list.get(i) << " ";
	    }
	    std::cout << std::endl << std::endl;

	    // search value 71 again
	    std::cout << "search element 71 again" << std::endl;
	    result = list.search(71);
	    if(result == -1)
	        std::cout << "71 is not found";
	    else
	        std::cout << "71 is found at index " << result;
	    std::cout << std::endl;

	    
	}

	
	return 0;
}