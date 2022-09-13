#include "BookPartitioner.hpp"

//*********************************************************//
//
//
//*********************************************************//
BookPartitioner::BookPartitioner( size_t startingPage, size_t endPage, size_t numberOfDays )
:
startingPage_ ( startingPage ),
endPage_      ( endPage      ),
numberOfDays_ ( numberOfDays )
{
    populatePagePartitions();
    printToFile();
    std::cout << getResultAsString() << std::endl;

}

//*********************************************************//
//
//
//*********************************************************//
void BookPartitioner::populatePagePartitions()
{
    // This is where we will store the number of pages per day.
    std::vector< size_t > dayBins( numberOfDays_, 0 );

    size_t currBin(0);

    size_t numberOfPages( endPage_ - startingPage_ + 1 );
    // Loop through the pages left and distribute them to each day.
    for( size_t currPage = 0; currPage < numberOfPages; ++currPage )
    {
        // Compute the index of the current bin. It should loop through the number
        // of days until we run out of pages.
        currBin = currPage % numberOfDays_;

        // Give each day bin a page until we run out.
        dayBins.at(currBin)++;
    }

    // Now loop through each of the bins, which should now contain the number
    // of pages to read per day, and assign start and end pages.
    size_t currPage( startingPage_ );
    for( size_t currDay = 0; currDay < dayBins.size(); ++currDay )
    {
        // Give the current Day the current starting page.
        startPages_.push_back( currPage );

        // Add to the current starting page the number of pages stored in dayBins.
        // We take one away to account for the starting page.
        endPages_  .push_back( currPage + dayBins.at( currDay ) - 1);

        // Update the starting page for the next iteration.
        // We add one to move the page one past the page we just gave endPages_.
        currPage             = endPages_.at( currDay ) + 1;
    }

}

//*********************************************************//
//
//
//*********************************************************//
std::string BookPartitioner::getResultAsString()
{
    std::stringstream ss;
    
    // Construct my fancy title.
    ss  << "\n";
    ss  << " |-----------------------------------------|\n";
    ss  << " |          Book Partitioner Pro           |\n";
    ss  << " |-----------------------------------------|\n";

    // Construct my fancy header.
    ss  << " | " 
        << std::setw(5) << "Day "  << " | " 
        << std::setw(5) << "Start" << " | " 
        << std::setw(5) << "End"   << " | " 
        << "Number of Pages |\n";

    // Print out the formatted output.
    for( size_t i = 0; i < startPages_.size(); i++ )
    {
        ss  << " | " 
            << std::setw(5)  << i+1                                     << " | "
            << std::setw(5)  << startPages_.at(i)                       << " | "
            << std::setw(5)  << endPages_.at(i)                         << " | " 
            << std::setw(15) << endPages_.at(i) - startPages_.at(i) + 1 << " | \n";
    }

    // Fancy footer.
    ss  << " |-----------------------------------------|\n";

    // return the string.
    return( ss.str() );
}

//*********************************************************//
//
//
//*********************************************************//
bool BookPartitioner::errorCheck()
{
    bool success( false );


    return( success );
}

//*********************************************************//
//
//
//*********************************************************//
void BookPartitioner::printToFile( std::string fileName )
{
    std::ofstream outputFile( fileName );

    if( outputFile.good() )
    {
        outputFile << getResultAsString();
    }

    outputFile.close();
}