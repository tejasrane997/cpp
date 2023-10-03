// cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Logger.h"
#include "LinkedList.cpp"

int main()
{
    std::cout << "Hello World!\n";

    LinkedList<int> myList;
    

    myList.PrintList();
    for (int i = 1; i <= 5; i++)
        myList.Add(i);

    myList.PrintList();

        myList.ClearList();
        myList.PrintList();
}
