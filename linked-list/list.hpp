/**
 * Simple linked-memory (Linked List), templated list class.
 * 
 * @author
 * Anil Bhusal - Pulchowk Campus, Institute of Engineering
 */

// Note: When you define functions within the class definition, you can
// assume that all member variable definitions in the class are in scope,
// regardless of where they are defined. So, we can refer to head_ in the
// List constructor near the top, before the line where head_ is defined.
// More info:
// https://stackoverflow.com/questions/13094898/do-class-functions-variables-have-to-be-declared-before-being-used

#include "list.h"

template <typename T>
const T& List<T>::operator[](unsigned index)
{
    // Start a "ptr" pointer variable of type "ListNode" to advance through
    // the list.
    ListNode* ptr = head_;
    
    // Advancing through the list until the data at index is found.
    // If the index is greater than the number of "ListNode"'s
    // then return the data of the last ListNode.
    while (index > 0 && ptr->next != nullptr)
    {
        ptr = ptr->next;
        index--;
    }

    // Returning the data of ith ListNode or data of last ListNode.
    return ptr->data;
}

template <typename T>
void List<T>::insert_at_front(const T& data)
{
    // Create a new ListNode at heap memory.
    ListNode* node = new ListNode(data);

    // Set the new node’s next pointer point the current
    // head of the List:
    node->next = head_;

    // Setting the value of pointer variable "head_" to the address of new ListNode.
    head_ = node;
} 


/**
 * Finds and returns the ListNode containing `data` in the
 * List or `nullptr` if the data is not found.
 */
template <typename T>
typename List<T>::ListNode* List<T>::_find(const T& data)
{
    ListNode* thru = head_;
    while (thru != nullptr)
    {
        if (thru->data == data)
        {
            return thru;
        }
    }

    return nullptr;

}