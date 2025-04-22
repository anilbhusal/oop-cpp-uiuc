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

#include <iostream>
#include "MyQueue.h"

int main()
{
    MyQueue<int> queue;

    // We'll be able to store const references to these objects in the List
    // because these constants on the stack exist in the same function scope
    // that lasts until the end of main().
    const int item_a = 5;
    const int item_b = 6;

    std::cout << "Queuing  element item_a..." << std::endl; 
    queue.insert_at_back(item_a);
    std::cout << "queue[0]: " << queue[0] << std::endl;
    std::cout << std::endl;

    std::cout << "Queuing  element item_b..." << std::endl; 
    queue.insert_at_back(item_b);
    std::cout << "queue[0]: " << queue[0] << std::endl;
    std::cout << "queue[1]: " << queue[1] << std::endl;
    std::cout << std::endl;

    return 0;

}