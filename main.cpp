#include <iostream>
#include <string>
#include <assert.h>

#include "BST.h"

/*
Gavin Travis MA2

MA2 Questions:
- What is the move constructor?
	- The move constructor is an operation for creating a new object 
	by transferring the data from an existing object. The transfer takes
	the existing data and gives "ownership" to the new object, leaving the
	original object empty. This is helpful because it saves the time and space
	needed to copy all of the contents of the original object over to the new 
	object.
- What is a move assignment operator?
	- the move assignment operator is similar to the move constructor, in
	that it transfers the contents of an object to a different object with
	the key difference being that the move operation happens on an existing object
	instead of during object contstruction/initialization.

- For each function, explain the worst-case time complexity
	- BST::empty() is O(1) or constant time. It only checks if _root is nullptr
	- BST::add() is O(n) since we cannot guarantee the BST will be balanced, 
	therefore BST could be a degenerate linked list! I did not see any self
	balancing features in the starter code.
	- BST::makeEmpty() calls makeEmptyHelper() which recursively traverses the
	whole tree so the time complexity is O(n)
	- BST::printLevelOrder() also traverses all nodes in the tree and will have
	O(n) time complexity
	- BST::cloneTree() traverses the whole tree and will have O(n) time

*/

int main(){

	/* MA TODO: Implement */
	/* Create a BST string tree (bst_test) ; add the following string values to the bst_test in order: "C", "p", "t", "s", "2", "3" , "B", "S", "T"*/

	/* MA TODO: Implement */
	// Test1: Test printLevelOrder()
	/* Print the tree you created using
	    a. In-order print
	    a. Level-order print
	    a. Post-order print
	    a. Pre-order print */

	BST<std::string> bst_test;
	std::vector<std::string> str_load = { "C", "p", "t", "s", "2", "3" , "B", "S", "T"};
	for (auto i : str_load) { bst_test.add(i); }

	std::cout << "In order print: ";
	bst_test.printInOrder();
	std::cout << std::endl << "Level order print: ";
	bst_test.printLevelOrder();
	std::cout << std::endl << "Post order print: ";
	bst_test.printPostOrder();
	std::cout << std::endl << "Pre order print: ";
	bst_test.printPreOrder();
	std::cout << std::endl;


	/* MA TODO: Implement */
	// Test2: Test copy constructor -1
	/* Create a new BST tree (bst_copy1) ; initialize bst_copy1 with 'bst_test's data, using the copy constructor */
	/* Test condition: Check if the size of bst_copy1 is same as bst_test; and  bst_copy1 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy constructor test-1 passed!"";
		* else *print the message: "Copy constructor test-1 failed!"" and print both bst_test and bst_copy1 using level order print.*/

	BST<std::string> bst_copy1(bst_test);
	if (bst_test.size() == bst_copy1.size() && bst_copy1.contains("B") && bst_copy1.contains("S") && bst_copy1.contains("T")) {
		std::cout << "Copy constructor test-1 passed!" << std::endl;
	} else {
		std::cout << "Copy constructor test-1 failed!" << std::endl;
		bst_test.printLevelOrder();
		bst_copy1.printLevelOrder();
	}


	/* MA TODO: Implement */
	// Test3: Test copy constructor - 2
	/* Update one of the strings in bst_copy1 tree using the following statement:  */
	   // bst_copy1.getNode("B")->setValue("A");
	/* Assuming copy constructor does a deep copy, the above statement should update bst_copy1 only, and not bst_test. */
	/* Test condition: 
	    * if bst_test contains "B" and it doesn't contain "A", test passes. Print the message: "Copy constructor test-2 passed!"";
		* else *print the message: "Copy constructor test-2 failed!"" and print bst_test using level order print.*/
	
		bst_copy1.getNode("B")->setValue("A");
		if (bst_test.contains("B") && bst_copy1.contains("A")) {
			std::cout << "Copy constructor test-2 passed!" << std::endl;
		} else {
			std::cout << "Copy constructor test-2 failed!" << std::endl;
			bst_test.printLevelOrder();
		}


	/* MA TODO: Implement */
	// Test4: Test copy assignment
	/* Create a new BST tree (bst_copy2) ; initialize bst_copy2 with 'bst_test's data, using the copy assignment operator. */
	/* Test condition: Check if the size of bst_copy2 is same as bst_test and  bst_copy2 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy assignment operator test passed!"";
		* else *print the message: "Copy assignment operator test failed!"" and print both bst_test and bst_copy2 using level order print.*/

	BST<std::string> bst_copy2;
	bst_copy2 = bst_test;
	if (bst_test.size() == bst_copy2.size() && bst_copy2.contains("B") && bst_copy2.contains("S") && bst_copy2.contains("T")) {
		std::cout << "Copy assignment operator test passed!" << std::endl;
	} else {
		std::cout << "Copy assignment operator test failed!" << std::endl;
		bst_test.printLevelOrder();
		bst_copy2.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test5: Test move constructor
	/* Create a new BST tree (bst_move1) ; initialize bst_move1 with 'bst_test's data, using the move constructor */
	/* Test condition: Check if the size of bst_move1 is 9 and  bst_move1 contains the values "B", "S", "T", and bst_test is empty (use the empty() function of BST to check if bst_test is empty.).  
	    * if so, print the mesaage: "Move constructor test passed!"";
		* else *print the message: "Move constructor test failed!"" and print bst_move1 using level order print.*/
	BST<std::string> bst_move1(std::move(bst_test));
	if (bst_move1.size() == 9 && bst_move1.contains("B") && bst_move1.contains("S") && bst_move1.contains("T")) {
		std::cout << "Move constructor test passed!" << std::endl;
	} else {
		std::cout << "Move constructor test failed!" << std::endl;
		bst_move1.printLevelOrder();
	}


	/* MA TODO: Implement */
	// Test6: Test move assignment 
	/* Create a new BST tree (bst_move2) ; initialize bst_move2 with rvalue BST<string>({"B","S","T"}), using the move assignment operator */
	/* Test condition: Check if the size of bst_move2 is 3 and  bst_move2 contains the values "B", "S", "T". 
	    * if so, print the mesaage: "Move assignment operator test passed!"";
		* else *print the message: "Move assignment operator test failed!"" and print  bst_move2  using level order print.*/
	BST<std::string> bst_move2;
	bst_move2 = std::move(BST<std::string>({"B","S","T"}));
	if (bst_move2.size() == 3 && bst_move2.contains("B") && bst_move2.contains("S") && bst_move2.contains("T")) {
		std::cout << "Move assignment operator test passed!" << std::endl;
	} else {
		std::cout << "Move assignment operator test failed!" << std::endl;
		bst_move2.printLevelOrder();
	}

	return 0;
}