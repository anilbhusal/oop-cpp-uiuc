/**
 * Simple Stack Data Structure using linked list, templated list class.
 * 
 * @author
 * Anil Bhusal - IOE, Pulchowk Campus
 */

 #include "MyStack.h"

 template <typename Type>
 void MyStack<Type>::insert_top(const Type& data)
 {

    // Create a new StackNode class at heap memory.
    StackNode* node = new StackNode(data);

    // Set the new StackNode's next pointer point the current
    // head of the Linked List of StackNode.
    node->next = head_;

    // Setting the value of pointer variable "head_" to the address of new StackNode.
    head_ = node;

 }

 template <typename Type>
 const Type& MyStack<Type>::peek_top()
 {
    // Returning the constant reference of the data stored at top StackNode.
    if (head_ == nullptr)
    {
        std::cout << "Nothing to peek. Empty MyStack !!!" << std::endl;
    }
    return head_->data;
 }

 template <typename Type>
 const Type& MyStack<Type>::pop_top()
 {
    // Creating a temporary pointer variable of StackNode.
    StackNode* temp;
    const Type& data;

    // Checking if MyStack contains any StackNode.
    if (head_ = nullptr)
    {
        std::cout << "Nothing to pop. Empty MyStack !!!" << std::endl;

    }
    
    // Assigning the head_ pointer variable to temp.
    temp = head_;
    head_ = temp->next;
    
    // Assigning data in the temp StackNode to varible data.
    data = temp->data;

    // Deleting temporary node "temp" and setting it to nullptr
    // for safety.
    delete temp;
    temp = nullptr;

    // Returning data
    return data;
 }