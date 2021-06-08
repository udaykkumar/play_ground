
"""
Commentary:

Priority Queues are 
	1. Abstract Datatype
	2. Each element has certain periority
	3. Supports only comparable elements

	Example:
		PQ - [] ; smaller number are bigger priority

		PQ.insert(2) -> [2]
		PQ.insert(4) -> [4]
		PQ.poll()    -> [ ]
		PQ.insert(7) -> [4,7]
		PQ.insert(1) -> [4,7,1]
		PQ.poll()    -> [4,7] , 1
		PQ.poll()	 -> [7], 4
		PQ.poll()	 -> [], 7


PQ Uses Heap
	Lets talka little about Heap :
		Heap is a Tree based Data structure that satisfies heap invariant
		Means 
			 A is a parent of B then -	
				A is Ordered with respect to B for all Nodes A, B in Heap
				
			Means Value of A <= Value of child nodes
			or 	  Value of A >= Value of child nodes
			or 	Value of Parent <= Value of child nodes  [ Min Heap ]
			or  Value of Parent >  Value of child nodes  [ Max Heap ]
	Note -> PQ Can be implemented with other Data structures also not just Heap
	Note -> Trees are supposed contain cycles


Uses of PQ 
	1. Dijkstra's shortest path algorithm
	2. Handy in fetching nextbest and nextworst
	3. used in Hoffman encoding
	4. Best First search algorithms
	5. Minimum Spanning Tree - Directed Graphs


Complexity in implementing PQ using Binary Tree
	Binary Heap Construction -> O(n)
	Polling					 -> O(lon(n))
	Peek 					 -> O(1)
	Adding 					 -> O(nlog(n))
		
	Extras
		Naive Remove		-> O(n) 		( Linear scan + remve , Quite a slow )
		Better Remove 		-> O(nlon(n)) 	( using hash table )
		Native Contains 	-> O(n)		    ( Linear scan + remve , Quite a slow )
		Better Contains 	-> O(1) 		( using hash table )

	Note - there is a Space penalty for hash table way implementation O(n)


Turning Min PQ to Max PQ
	Why do it ?
		because most programming libs provide one variant , ususally min PQ,
		sometimes we need the other

	One Hack is to negate (!) the comparable interfaces aka compare function

	Hack 2 : negate numbers before inserting and negate after inserting ;-) 
			 pretty cool hack

			 13 , 5 , 6, 8, 9
			 -> PQ [ 13, 5, 6, 8, 9]
			 -> PQ.poll() -> 5
			 -> PQ [ -13, -5, -6, -8, -9 ]
			 -> PQ.poll() -> -13 -> negate(-13) -> 13 viola


Adding elements to Binary Heap
	PQ != Heap ; its an ADT that defines PQ Behavior

	There are many heaps
		Binary Heap
		Fibonacci Heap
		Binomial Heap
		Pairing Heap

	Binary Heap
		Binary Heap is a binary tree that supports "heap invariant"
		
		Complete Binary Tree - is a tree in which at every level, 
		except the last is completely filled and all the nodes are as far lest as possible

	if i be the parent index of node
		 left child = 2*i + 1
		right child = 2*i + 2  

			or

		 left child = 2*i
		right child = 2*i -1  


	insert(heap, x)	
		if heap is empty():
			heap[0] = x
			return
	
		index = last_empty_index(heap)
		
		increment_last_empty_index(heap)

		heap[index] = x

		# Bubble UP ..
		while index != 0: # << this is root
			parent_index = parent(index)
			if heap[ parent_index] < heap[index]
				break # heap property is satisfied
			
			swap( heap[ parent_index ], heap[index] )
			index = parent_index




















"""
