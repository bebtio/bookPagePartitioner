#ifndef BOOK_PARTITIONER_HPP
#define BOOK_PARTITIONER_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <fstream>

class BookPartitioner
{
public:
    BookPartitioner( size_t startingPage, size_t numberOfPages, size_t numberOfDays );
    
private:

    std::string getResultAsString();
    void printToFile( std::string fileName = "bookParitions.txt" );
    void populatePagePartitions();
    bool errorCheck();

    std::vector< size_t > startPages_;
    std::vector< size_t > endPages_;

    size_t startingPage_;
    size_t endPage_;
    size_t numberOfDays_;
};

#endif