#include <iostream>
#include "BookPartitioner.hpp"


//*********************************************************//
//
//
//*********************************************************//
int main( int argc, char *argv[] )
{

    size_t startPage(0);
    size_t numPages(0);
    size_t numDays(0);

    if( argc != 4 )
    {
        std::cout << "Please enter in this order: Starting Page, Number of Pages to Read, Number of days to read\n";
    }
    else
    {
        std::stringstream ss;
        ss << argv[1] << " " << argv[2] << " " << argv[3];
        ss >> startPage >> numPages >> numDays;
        
        BookPartitioner bp( startPage, numPages, numDays );
    }
    return( 0 );
}