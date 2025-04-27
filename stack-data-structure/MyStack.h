/**
 * Simple Stack Data Structure, templated list class.
 * 
 * @author
 * Anil Bhusal - Institute of Engineering, Pulchowk Campus
 */


#pragma once

#include <iostream>

template <typename Type>
class MyStack
{
    public:
        
        // Defining a constructor in such way that the head_ is nullptr intialize.
        MyStack() : head_(nullptr) { }

        // Adding data to the top of the Stack.
        void insert_top(const Type& data);

        // To peek data at the top of stack.
        const Type& peek_top();

        // Remove data from the front of the topof stack and return constant reference.
        const Type& pop_top();

        ~MyStack()
        {
            // We will walk through the head.
            StackNode* through = head_;

            while (through != nullptr)
            {
                // Copying the address that "through" pointer variable currently have.
                StackNode* to_delete = through;
                                
                // Assigning the address of next Node to "through" pointer variable.
                through = through->next;

                // Now, finally, we can delete the to_delete pointer. We could not
                // delete it before we stepped away from it above, because we needed
                // the next pointer information first.
                delete to_delete;

                // We don't strictly need to set toDelete to nullptr here because
                // it goes out of scope immediately after, but remember that you
                // should generally do this after deleting a pointer:
                to_delete = nullptr;
            }

            // std::cout << "Destructor called." << std::endl;
        }

    
    private:
        class StackNode
        {
            public:
                const Type& data;
                StackNode* next;
                StackNode(const Type& data) : data(data), next(nullptr) { }
        };

        StackNode* head_;
};

// Finish including the rest of the header from the additional header file.
// This is just done to spread out our writing among more manageable files.
#include "MyStack.hpp"