// cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string_view>
#include <bitset>
#include "Logger.h"
#include "LinkedList.h"
#include "thread"

/*void* operator new(size_t size)
{
    std::cout << "Allocating bytes : " << size << std::endl;
    return malloc(size);
}*/

void log_test(int n) 
{
    INFO("thread %d", n);
}

int main()
{
    /*LinkedList<int> list;

    for (int i = 0; i < 5; i++) {
        list.add(i);
    }

    list.printList();

    list.reverseList();

    list.printList();*/

    std::thread threads[10];

    for (int i = 0; i < 10; i++)
        threads[i] = std::thread(log_test, i);

    for (int i = 0; i < 10; i++)
        threads[i].join();


    return 0;
}
