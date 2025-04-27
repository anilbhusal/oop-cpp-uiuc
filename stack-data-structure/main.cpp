/**
 * Simple Stack using Linked List, templated list class.
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
#include "MyStack.h"

int main()
{
    MyStack<int> stack;

    // We'll be able to store const references to these objects in the List
    // because these constants on the stack exist in the same function scope
    // that lasts until the end of main().
    const int item_a = 5;
    const int item_b = 6;

    stack.insert_top(item_a);
    std::cout << "Data on top: " <<stack.peek_top() << std::endl;
    stack.insert_top(item_b);
    std::cout << "Data on top after adding item_b: " <<stack.peek_top() << std::endl;

    return 0;

}