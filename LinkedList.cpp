#include "LinkedList.h"  // Header file

/**
 * TODO 3: Change Node* with shared_ptr.
 */

/**********************************************************************************************************************/
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {}

/**********************************************************************************************************************/
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &aList) : itemCount(aList.itemCount) {
    auto origChainPtr = make_shared<Node<ItemType>>(aList.headPtr);  // Points to nodes in original chain

    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original list is empty
    else {
        // Copy first node
        headPtr = make_shared<Node<ItemType>>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        auto newChainPtr = make_shared<Node<ItemType>>(headPtr);      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
        while (origChainPtr != nullptr) {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            auto newNodePtr = make_shared<Node<ItemType>>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }

        newChainPtr->setNext(nullptr);              // Flag end of chain
    }
}

/**********************************************************************************************************************/
template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

/**********************************************************************************************************************/
template<class ItemType>
int LinkedList<ItemType>::getLength() const {
    return itemCount;
}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType &newEntry) {
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert) {
        // Create a new node containing the new entry
        auto newNodePtr = make_shared<Node<ItemType>>(newEntry);

        if (newPosition == 1) {// Attach new node to chain
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        } else {
            // Find node that will be before new node
            auto prevPtr = getNodeAt(newPosition - 1);

            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }

        this->itemCount++;  // Increase count of entries
    }

    return ableToInsert;
}

/**********************************************************************************************************************/
template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= this->itemCount);
    if (ableToRemove) {
        auto curPtr = make_shared<Node<ItemType>>(nullptr);
        if (position == 1) {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        } else {
            auto prevPtr = getNodeAt(position - 1);// Find node that is before the one to delete

            curPtr = prevPtr->getNext();// Point to node to delete

            // Disconnect indicated node from chain by connecting the prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }

        // Return node to system
        curPtr->setNext(nullptr);


        itemCount--;  // Decrease count of entries
    }

    return ableToRemove;
}

/**********************************************************************************************************************/
template<class ItemType>
void LinkedList<ItemType>::clear() {
    while (!isEmpty())
        remove(1);
}

/**********************************************************************************************************************/
template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet) {
        auto nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    } else {
        string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw (PrecondViolatedExcep(message));
    }
}

/**********************************************************************************************************************/
template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType &newEntry) {
    // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet) {
        auto nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    } else {
        string message = "replace() called with an invalid position.";
        throw (PrecondViolatedExcep(message));
    }
}

/**********************************************************************************************************************/
template<class ItemType>
shared_ptr<Node<ItemType>> LinkedList<ItemType>::getNodeAt(int position) const {
    // Debugging check of precondition

    if (!((position >= 1) && (position <= itemCount)))
        throw PrecondViolatedExcep("Invalid index");

    // Count from the beginning of the chain
    auto curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}


/*********************************************************************************************************************/
template<class ItemType>
void LinkedList<ItemType>::sort() {
    /**
     * TODO 4. Sorts the list using BubbleSort algorithm as described in the lecture and chp 11. -- 30 marks
     */

    /**
     * HINTS:
     *  You need to adapt the bubbleSort method from our lecture to work on the linked list! here are some hints
     *  and guidelines on how the algorithm should looks like.
     *
     *  - you will need three pointers: *currentNode(nullptr), *nextNode(nullptr), *firstSortedNode(nullptr);
     *  - should have as many passes as this->itemCount-1.
     *  - for each pass
     *      - start with current in the head and next with head->next
     *      - repeat while the next is not the first node sorted (in correct order).
     *          - if current comes after next,
     *              - swap. Swap only the item, not the pointers. You will need a temp item variable.
     *              - remember to signal that the list is not sorted yet.
     *          - otherwise move to the next and next->next nodes.
     *      - at the end of each pass set the first sorted as the last current node you processed and increase the pass count!.
     */


    shared_ptr<Node<ItemType>> currentNode = nullptr, nextNode = nullptr, firstSortedNode = nullptr;
    ItemType item;
	bool sorted = false;
	int pass = 1;
	while (!sorted && (pass < this->itemCount-1))
 	{


 		sorted = true;
		while(nextNode != firstSortedNode)
 		{
		    currentNode = headPtr;
		    nextNode = headPtr->getNext();

 			if (currentNode->getItem() > nextNode->getItem())
 			{
                //Exchange entries
                item = currentNode->getItem();
                currentNode->setItem(nextNode->getItem());
                nextNode->setItem(item);
 				//std::swap(currentNode->getItem(), nextNode->getItem());
 				sorted = false;
 			}


		}
        //end of pass, set first sorted node as the last current node, increment pass
        firstSortedNode = currentNode;
 		pass++;
 	}




}
