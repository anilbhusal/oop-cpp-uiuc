/**
 * Simple Queue Data Structure, templated list class.
 * 
 * @author
 * Anil Bhusal - Pulchowk Campus, Institute of Engineering
 */

#pragma once

#include <iostream>

template <typename Type>
class MyQueue
{
    public:

        // Defining a vairable counter to record the number of Nodes created.
        unsigned counter = 0;

        // Defining a constructor in such way that the head_ is nullptr intialize.
        MyQueue() : head_(nullptr), tail_(nullptr) 
        {
            std::cout << "Constructor Called. " << std::endl;
        }

        //To get data at a specific index.
        const Type& operator[](unsigned index);
        
        // Adding data to the tail of the Queue.
        void insert_at_back(const Type& data);

        // Removing data from the front of the Queue.
        void remove_front();
        
        // Remove data from the front of the Queue and return constant reference.
        const Type& pop();

        // Defining a destructor to delete memory allocated by the Node objects
        // when the List is destroyed.
        ~MyQueue()
        {
            // We will walk through the head.
            Node* through = head_;

            while (through != nullptr)
            {
                // Copying the address that "through" pointer variable currently have.
                Node* to_delete = through;
                                
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
        class Node
        {
            public:
                // To store the const reference of data or value of type Type.
                const Type& data;

                // Pointer to the next element.
                Node* next;

                // Pointer to the Previous element.
                Node* previous;

                // Node constructor.
                Node(const Type& data) : data(data), next(nullptr), previous(nullptr) { }
        };

        Node* head_;
        Node* tail_;
        // Node* _search(const Type& data);

};

// Finish including the rest of the header from the additional header file.
// This is just done to spread out our writing among more manageable files.
#include "MyQueue.hpp"
