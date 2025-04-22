/**
 * Simple Queue Data Structure, templated list class.
 * 
 * @author
 * Anil Bhusal - Pulchowk Campus, Institute of Engineering
 */

#include "MyQueue.h"

template <typename Type>
void MyQueue<Type>::insert_at_back(const Type& data)
{
    counter++;
    // Create a new Node at heap memory.
    Node* new_node = new Node(data);

    // Set the new node’s next pointer point the current
    // head of the Linked List and set the current node’s previous pointer point newly
    // created Node.
    new_node->next = head_;
    head_->previous = new_node;


    // Setting the value of pointer variable "head_" to the address of new Node
    // and setting the value of pointer variable "previous" of newly create Node
    // to 'nullptr'
    head_ = new_node;
    new_node->previous = nullptr;

    // Assigning the tail_ to the address of first Node created.
    if (counter == 1)
    {
        tail_ = new_node;
    }

}

template <typename Type>
void MyQueue<Type>::remove_front()
{
    Node* temp;
    if (tail_ == nullptr)
    {
        std::cout << "Nothing to Dequeue. " << std::endl;
    }
    else
    {
        // Assigning the address of second last Node (if present) to the temporary varibale "temp".
        temp = tail_->previous;
        
        // Checking if there is only one Node.
        if (temp == nullptr)
        {
            // Deleting the node.
            delete tail_;

            // Assigning the tail_ pointer to the nullpointer for safety.
            tail_ = nullptr;
        }
        else
        {
            // Assigning the value of tail_ to a temporary variable.
            temp = tail_;
            
            // Assigning the address of second last node to the variable tail_.
            tail_ = tail_->previous;

            delete temp;
            temp = nullptr;

        }

    }
}

template <typename Type>
const Type& MyQueue<Type>::pop()
{
    Node* temp;
    if (tail_ == nullptr)
    {
        std::cout << "Nothing to Pop. " << std::endl;
    }
    else
    {
        // Assigning the address of second last Node (if present) to the temporary varibale "temp".
        temp = tail_->previous;

        Type& temp_data;
        
        // Checking if there is only one Node.
        if (temp == nullptr)
        {   
            // Assigning the data of the front Node to temp_data
            temp_data = tail_->data;

            // Deleting the front Node.
            delete tail_;
            tail_ = nullptr;

            return temp_data;
            
        }
        else
        {

            // Assigning the value of tail_ and it's associated data to temporary variables.
            temp = tail_;
            temp_data = tail_->data;
            
            // Assigning the address of second last node to the variable tail_.
            tail_ = tail_->previous;

            delete temp;
            temp = nullptr;

            return temp_data;

        }

    }
}

template <typename Type>
const Type& MyQueue<Type>::operator[](unsigned index)
{
    // Start a "ptr" pointer variable of type "Node" to advance through
    // the list.
    Node* ptr = head_;
    
    // Advancing through the list until the data at index is found.
    // If the index is greater than the number of "Node"'s
    // then return the data of the last Node.
    while (index > 0 && ptr->next != nullptr)
    {
        ptr = ptr->next;
        index--;
    }

    // Returning the data of ith Node or data of last Node.
    return ptr->data;
}


/**
 * Finds and returns the Node containing `data` in the
 * List or `nullptr` if the data is not found.
 */
// template <typename Type>
// typename Queue<Type>::Node* Queue<Type>::_search(const Type& data)
// {
//     Node* thru = head_;
//     while (thru != nullptr)
//     {
//         if (thru->data == data)
//         {
//             return thru;
//         }
//     }

//     return nullptr;
// }