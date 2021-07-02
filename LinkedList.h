#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <memory>

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

/**
 * TODO 3: Change Node* with shared_ptr. -- 30 marks.
 */

using namespace std;
template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
   shared_ptr<Node<ItemType>> headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items 
   
   /**
    * Locates a specified node in this linked list.
    *
    * @pre  position is the number of the desired node;    position >= 1 and position <= itemCount.
    * @post  The node is found and a pointer to it is returned.
    * @param position  The number of the node to locate.
    * @return  A pointer to the node at the given position.
    * @throws PrecondViolatedExcep if invalid index.
    */
   shared_ptr<Node<ItemType>> getNodeAt(int position) const noexcept(false);

public:
   explicit LinkedList();
   LinkedList(const LinkedList<ItemType>& aList);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   
  /**
   *
   * @param position
   * @return
   * @throws PrecondViolatedExcep if position < 1 or position > getLength()
   */
   ItemType getEntry(int position) const noexcept(false);

   /**
    *
    * @param position
    * @param newEntry
   * @throws PrecondViolatedExcep if position < 1 or position > getLength()
    */
   void replace(int position, const ItemType& newEntry) noexcept(false);

   void sort();
};

#include "LinkedList.cpp"
#endif 
