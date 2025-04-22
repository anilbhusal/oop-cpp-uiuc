/**
 * Simple C++ main using a linked-memory list class.
 * 
 * @author
 *      Anil Bhusal <Institute of Engineering, Pulchowk Campus>
 */

 #include "list.h"
 #include <iostream>
 
 int main() {
   List<int> list;
 
   // We'll be able to store const references to these objects in the List
   // because these constants on the stack exist in the same function scope
   // that lasts until the end of main().
   const int item_a = 100;
   const int item_b = 300;
   
   std::cout << "Printing the addresses of the two integers:" << std::endl;
   std::cout << "item_a --> " << &item_a << " and item_b --> " << &item_b << " ." << std::endl;
   std::cout << std::endl;

   std::cout << "Inserting element 100 at front..." << std::endl; 
   list.insert_at_front(item_a);
   std::cout << "list[0]: " << list[0] << std::endl;
   std::cout << std::endl;
 
   std::cout << "Inserting element 300 at front..." << std::endl; 
   list.insert_at_front(item_b);
   std::cout << "list[0]: " << list[0] << std::endl;
   std::cout << "list[1]: " << list[1] << std::endl;
   std::cout << std::endl;

   std::cout << "Printing the addresses of the two integers stored in 'data' variable in the first and second Node class: "<<
                "inside of List class. " << std::endl;
   std::cout << "Node : 2 --> " << &list[1] << " and Node : 1 --> " << &list[0] << " ." << std::endl;
   std::cout << std::endl;
 
   return 0;
 }