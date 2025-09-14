#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    if( argc == 1) {
        std::cout << "bad input" << std::endl;
    }

    // set up the list
    ULListStr list;
    for(int i=1; i<argc; i++){
        list.push_front(argv[i]);
    }


    const std::string& front = list.front();
    std::cout << front << std::endl;

    const std::string& back = list.back();
    std::cout << back << std::endl;
    

    // print the list
    for( int i=0; i<(int)list.size(); i++ ) {
        std::cout << list.get(i);
    }
    std::cout << std::endl;


    // four popback
    for(int i=0; i<4; i++) {
        list.pop_back();
    }
    // print the list
    for( int i=0; i<(int)list.size(); i++ ) {
        std::cout << list.get(i);
    }
    std::cout << std::endl;

    // four popbacks
    for(int i=0; i<4; i++) {
        list.pop_front();
    }

    if( list.empty() ) {
        std::cout << "good" << std::endl;
    }

    return 0;
}
