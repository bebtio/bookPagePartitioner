#include <iostream>
#include "BookPartitioner.hpp"


//*********************************************************//
//
//
//*********************************************************//
int main( int argc, char *argv[] )
{

    size_t startPage(0);
    size_t endPage(0);
    size_t numDays(0);

    // Check that the correct number of inputs have been passed in.
    if( argc != 4 )
    {
        std::cout << "Please enter in this order: Starting Page, Last Page, Number of days to read.\n";
    }
    else
    {
        // Pull out the inputs from argv.
        std::stringstream ss;
        ss << argv[1] << " " << argv[2] << " " << argv[3];
        ss >> startPage >> endPage >> numDays;
        
        // Run the code!
        BookPartitioner bp( startPage, endPage, numDays );
    }
    
    return( 0 );
}