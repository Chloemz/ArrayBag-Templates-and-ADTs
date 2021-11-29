/** @author: Chloe Zambrano
Email: Chloe.zambrano94@myhunter.cuny.edu
CSCi235-01
Project 2
Array Bag: Implements arraybag functions using Templates and ADTs 
*/

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */
//don't need to #include "ArrayBag.hpp" because cpp's included in the hpp
#include <iostream>
#include <vector>

/** Obviously a default constructor*/
template<class ItemType>
ArrayBag<ItemType>::ArrayBag() //can also do ArrayBag():item_count_(0)
{
    item_count_=0;
}//end default constructor

/** @return item_count_ : the current size of the bag*/
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return item_count_;
}//end getCurrentSize

/** @return true if item_count_ == 0, false otherwise*/
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return(item_count_ == 0); //item_count_ type is 'int' so this works
}//end isEmpty()

/**
 @return true if new_entry was successfully added to items_, false otherwise*/
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &new_entry)
{
    bool RoomLeft = (item_count_ < DEFAULT_CAPACITY); //new bool to check if array is at max size
    if(RoomLeft)//if array has room left, add new entry
    {
        items_[item_count_] = new_entry;
        item_count_++; //item_count_ is incrememented after adding new_entry
        return true; //bool returns true since function was applied
    }
    else
        return false;   
}//end add

/**
     looks for @param target in items_ array,
     @return the index target in the array items_ 
     or -1 if the array does not contain the target.
     **/
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
    bool isFound = false;
    int result = -1;
    int searchIndex = 0;

    //Logic: if bag is empty. itemCount is 0 >= loop is skipped.
    while(!isFound && (searchIndex < item_count_)) //!isFound is false allows for while loop to stop after 1st instance isFound becomes true
    {
        if(items_[searchIndex] == target)
        {
            isFound=true;
            result = searchIndex; //result turns from false to true
        }
        else
        {
            searchIndex++; //keep searching 
        }
    }
    return result;//returns true if if-statement was applicable
}//end getIndexOf

/** @return true if @param an_entry is removed from items_ & false otherwise,
*/
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &an_entry)
{
    int index = getIndexOf(an_entry); //if index is found it will replace matched item with 0
   
    //new bool to check if array isn't empty and there's a matched element to remove
    bool canRemoveItem = !isEmpty() && (index > -1); 
    
    if(canRemoveItem) 
    {
        item_count_--; //reduce item count
        items_[index] = items_[item_count_]; //reduce array size for both
    }
    return canRemoveItem;//returns true if applicable
}//end remove


/** @post removes all instances of @param an_entry */
template<class ItemType>
void ArrayBag<ItemType>::removeAllInstances(const ItemType &an_entry)
{
    //while loop only works (i.e removes entry) when condition is applicable  
    while(remove(an_entry)==true);

}//end removeAllInstances

/** @post Obviously clears item count*/
template<class ItemType>
void ArrayBag<ItemType>::clear()
{
    item_count_ = 0;
}//end clear

/** @return true if an_entry is found in items_ array, false otherwise*/
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &an_entry) const
{
    return getIndexOf(an_entry) > -1;
}//end contains

/** @return the # of times an_entry is found in items_ array*/
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
    int frequency = 0;
    int curIndex = 0;
    while(curIndex < item_count_)
    {
        if(items_[curIndex]== an_entry){
            frequency++; //increase for each time entry is repeated in ArrayBag
        }
        curIndex++; //increase for each time entry is repeated in ArrayBag to keep looking
    }
    return frequency;
}//end getFrequencyOf

/** @return a vector having the same contents as items_ */
template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;

    for(int i= 0; i< item_count_; i++)
        bagContents.push_back(items_[i]);
    return bagContents;
}//end toVector

/** @post prints the contents of items_ to the standard output separated by commas and followed by a new line.
Example: A, B, C, D, E \n
Note how there is no comma and space for the last item.
*/
template<class ItemType>
void ArrayBag<ItemType>::display() const
{
    for(int i = 0; i < ArrayBag<ItemType>::getCurrentSize(); i++)
    {
        if(i != ArrayBag<ItemType>::getCurrentSize()-1) //prints ", " between each array item except the last
            std::cout<< items_[i]<< ", ";
        else
            std::cout<< items_[i]<< std::endl;
    }
}//end display

/**
    @return duplicates all the items in the bag 
    meaning that for every item in the bag we add another copy of it. 
    Example: we originally have [A, B] and after duplication we have [A, B, A, B] or [A, A, B, B] or how ever order you want so long as there are 2 A's and 2 B's
    Returns true if successfully duplicated 
    but returns false if there is nothing to duplicate or if we go above the DEFAULT_CAPACITY which is 10 for this project
*/
template<class ItemType>
bool ArrayBag<ItemType>::duplicateItems()
{
    bool cantDupe = isEmpty() || ((2 * item_count_) > DEFAULT_CAPACITY); //new bool to check if array is not empty and <= max size
    if(cantDupe)
        return false;                   
    for(int i = 0; i < item_count_; i++){ 
        items_[item_count_+i] = items_[i];//duped element goes into the next spot of the array
    }
    item_count_ = 2*item_count_;
    return true;
}//end duplicateItems

/** @return true if all items with duplicates in the bag were removed and returns false if there are 1 or less items in the bag
Example: a duplicate would be [A, B, C, C, D, D, D, E]
What we should have after running this function: [A, B, C, D, E] (may be out of order depending on how you do it, that doesn't matter)
*/
template <class ItemType>
bool ArrayBag<ItemType>::removeDuplicates(){
    ItemType items_[];
    bool hasDuplicates = item_count_ >= 1; //new bool to check if item count exceeds 1 
    if(hasDuplicates){//will return false otherwise
        for(int x = 0; x < item_count_-1; x++){//making sure remove duplicates is in bound
            for(int k = x+1; k < item_count_; k++){
                if(items_[x] == items_[k]){
                    remove(items_[k]);
                    k--;    
                }
            }
        }
    }
    return hasDuplicates;
}//end removeDuplicates

/** 
implements Set Union. The union of two sets A and B is the set of elements which are in A, in B, or in both A and B.  
    @param a_bag to be combined with the contents of this (the calling) bag
    @post adds as many items from a_bag as space allows    
*/
template<class ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType> &a_bag)
{
    for(int i = 0; i < a_bag.getCurrentSize(); i++)
		ArrayBag<ItemType>::add(a_bag.items_[i]);
}//end operator+=

/** 
implements Set Difference  The (set) difference between two sets A and B is the set that consists of the elements of A which are not elements of  B 
    @param a_bag to be subtracted from this (the calling) bag
    @post removes all data from items_ that is also found in a_bag
Example if A has [1, 2, 3, 4, 5] and B has [4, 5, 6, 7], then A-=B will result in A containing [1, 2, 3] and B remaining the same
*/
template<class ItemType>
void ArrayBag<ItemType>::operator-=(const ArrayBag<ItemType> &a_bag)
{
    for(int i = 0; i < a_bag.getCurrentSize(); i++)
		ArrayBag<ItemType>::remove(a_bag.items_[i]);
		
}//end operator-=

/** 
implements Set Intersection  The intersection of two sets A and B is the set that consists of the elements that are in both A and B 
    @param a_bag to be intersected with this (the calling) bag
    @post items_ no longer contains data not found in a_bag    
Example if bag A has [1,2,3,4,5] and Bag B has [7,8,5,9] then A /= B will result in A containing only 5 since 5 is found in both bag A and bag B
*/
template<class ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType> &a_bag)
{
    int size = item_count_; //set size to item count so the count isn't affected by the changes in the for loop 
    
    for(int i = 0; i < size; i++){
        if(contains(items_[i])==true && a_bag.contains(items_[i])==false) //set intersection
            ArrayBag<ItemType>::remove(items_[i]);
    }
}//end operator/=
