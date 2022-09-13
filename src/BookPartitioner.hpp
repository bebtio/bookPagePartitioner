#ifndef BOOK_PARTITIONER_HPP
#define BOOK_PARTITIONER_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <cmath>


class BookPartitioner
{
public:
    BookPartitioner( size_t startingPage, size_t numberOfPages, size_t numberOfDays );
    

    
    std::string getResultAsString();
    void writeToCSV( std::string csvFileName = "bookParitions.csv" );

private:

    void populatePagePartitions();

    std::vector< size_t > startPages_;
    std::vector< size_t > endPages_;

    size_t startingPage_;
    size_t numberOfPages_;
    size_t numberOfDays_;
};

#endif