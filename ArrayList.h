#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include "ListInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
/**
 * Array-Based implementation
 * @tparam ItemType
 */
class ArrayList : public ListInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 50;    // Small capacity to test for a full list
    ItemType items[DEFAULT_CAPACITY + 1];      // Array of list items (not using element [0]
    int itemCount;                            // Current count of list items
    int maxItems;                             // Maximum capacity of the list

    void merge(int first, int mid, int last);
    void mergeSort(int first, int last) ;

public:
    explicit ArrayList();
    // Copy constructor and destructor are supplied by compiler
    ~ArrayList();

    bool isEmpty() const;

    int getLength() const;

    bool insert(int newPosition, const ItemType &newEntry);

    bool remove(int position);

    void clear();

    /**
     *
     * @param position
     * @return
     * @throws PrecondViolatedExcep if position < 1 or position > getLength().
     */
    ItemType getEntry(int position) const noexcept(false);

    /**
     *
     * @param position
     * @param newEntry
     * @throws PrecondViolatedExcep if position < 1 or position > getLength().
     */
    void replace(int position, const ItemType &newEntry) noexcept(false);

    void sort();
};

#include "ArrayList.cpp"

#endif
