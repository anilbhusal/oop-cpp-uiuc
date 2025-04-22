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

#pragma once

#include <iostream>



template <typename T>
class List
{
    public:
        // To get the data at given index from the list.
        const T& operator[](unsigned index);

        // To insert the data of type "T" at the front of the list.
        void insert_at_front(const T& data);

        // Defining a constructor in such way that the head_ is nullptr intialize.
        List() : head_(nullptr) { }

        // Defining a destructor to delete memory allocated by the ListNode objects
        // when the List is destroyed
        ~List()
        {
            // We will walk through the head.
            ListNode* through = head_;

            while (through != nullptr)
            {
                // Copying the address that through pointer currently have.
                ListNode* to_delete = through;
                
                // Assigning the address of next ListNode to through pointer variable.
                through = through->next;

                // Now, finally, we can delete the toDelete pointer. We could not
                // delete it before we stepped away from it above, because we needed
                // the next pointer information first.
                delete to_delete;

                // We don't strictly need to set toDelete to nullptr here because
                // it goes out of scope immediately after, but remember that you
                // should generally do this after deleting a pointer:
                to_delete = nullptr;

            }

            // Checking whether destructor is called.
            std::cout << "--> Destructor has been called." << std::endl;
            std::cout << "--> Freeing up all the memory." << std::endl;
        }

        private:
            class ListNode
            {
                public:
                    const T& data;
                    ListNode* next;
                    ListNode(const T& data) : data(data), next(nullptr) { }
            };

            ListNode* head_;
            ListNode* _find(const T& data);

};

// Finish including the rest of the header from the additional header file.
// This is just done to spread out our writing among more manageable files.
#include "List.hpp"