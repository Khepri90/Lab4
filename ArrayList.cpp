#include "ArrayList.h"

/*********************************************************************************************************************/
template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}


/*********************************************************************************************************************/
template<class ItemType>
ArrayList<ItemType>::~ArrayList() = default;

/*********************************************************************************************************************/
template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

/*********************************************************************************************************************/
template<class ItemType>
int ArrayList<ItemType>::getLength() const {
    return itemCount;
}

/*********************************************************************************************************************/
template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType &newEntry) {
    bool ableToInsert = (newPosition >= 1)
                        && (newPosition <= itemCount + 1)
                        && (itemCount < maxItems);
    if (ableToInsert) {
        // Make room for new entry by shifting all entries at positions >= newPosition toward the end of the array
        // (no shift if newPosition == itemCount + 1)
        for (int entryPosition = itemCount; entryPosition >= newPosition; entryPosition--)
            items[entryPosition + 1] = items[entryPosition]; // copy the entry right

        // Insert new entry
        items[newPosition] = newEntry;
        itemCount++;  // Increase count of entries
    }

    return ableToInsert;
}

/*********************************************************************************************************************/
template<class ItemType>
bool ArrayList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove) {
        // Remove entry by shifting all entries after the one at
        // position toward the beginning of the array
        // (no shift if position == itemCount)
        for (int entryPosition = position; entryPosition < itemCount; entryPosition++)
            items[entryPosition] = items[entryPosition + 1]; // copy entry on the right to left

        itemCount--;  // Decrease count of entries
    }

    return ableToRemove;
}

/*********************************************************************************************************************/
template<class ItemType>
void ArrayList<ItemType>::clear() {
    itemCount = 0;
}  // end clear

/*********************************************************************************************************************/
template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet) {
        return items[position];
    } else {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw (PrecondViolatedExcep(message));
    }
}

/*********************************************************************************************************************/
template<class ItemType>
void ArrayList<ItemType>::replace(int position, const ItemType &newEntry) {
    // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet) {
        items[position] = newEntry;
    } else {
        std::string message = "replace() called with an empty list or ";
        message = message + "invalid position.";
        throw (PrecondViolatedExcep(message));
    }
}


/*********************************************************************************************************************/
template<class ItemType>
void ArrayList<ItemType>::sort() {

    /**
      * Todo: Inspect this call.
      * Sorts the items array using MERGESORT algorithm.
      */
    this->mergeSort(0, this->itemCount);
}


/*********************************************************************************************************************/
template<class ItemType>
void ArrayList<ItemType>::merge(int first, int mid, int last) {
    /**
     * TODO 1: Implement the merge. -- 20 marks
     * Merge will merge in order the elements in the items array as described in the mergesort lecture, chp 11.
     */

     ItemType tempArray[DEFAULT_CAPACITY]; //temporary array

     //establish beginning and end of arrays
     int first1 = first;
     int last1 = mid;
     int first2 = mid + 1;
     int last2 = last;

     //while both arrays are not empty, copy the smaller item into temp array
     while ((first<= last1)&&(first2<=last2) )
     {
         if(items[itemCount] <= items[first1])
         {
             tempArray[itemCount] = items[first1];
             first1++;
         }else{
             tempArray[itemCount] = items[first2];
             first2++;
         }
         itemCount++;
     }

     //finish off the second subarray, if necessary
     while (first2 <= last2)
     {
         tempArray[itemCount] = items[first2];
         first2++;
         itemCount++;
     }
     //copy back to original array
     for (itemCount = first; itemCount<=last; itemCount++)
         items[itemCount] = tempArray[itemCount];


}
/******************************************************************************************************************/

template<class ItemType>
void ArrayList<ItemType>::mergeSort(int first, int last) {
    /**
     * TODO 2: Implement the mergeSort. -- 10 marks.
     * Sorts the items array by means of mergesort as described in the mergesort lecture, chp 11.
     */


    if (first < last)
    {
    //Sort each half
        int mid = first + (last - first) / 2; // Index of midpoint
    //Sort left half theArray
        mergeSort(first, mid);
    //Sort right half theArray
        mergeSort(mid + 1, last);
    //Merge the two halves
        merge(first, mid, last);
    }

}
