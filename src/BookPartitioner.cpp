#include "BookPartitioner.hpp"

//*********************************************************//
//
//
//*********************************************************//
BookPartitioner::BookPartitioner( size_t startingPage, size_t numberOfPages, size_t numberOfDays )
:
startingPage_ ( startingPage ),
numberOfPages_( numberOfPages ),
numberOfDays_ ( numberOfDays )
{
    populatePagePartitions();
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

    // Loop through the pages left and distribute them to each day.
    for( size_t currPage = 0; currPage < numberOfPages_; ++currPage )
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

    std::cout << getResultAsString() << std::endl;
}


std::string BookPartitioner::getResultAsString()
{
    std::stringstream ss;
    for( size_t i = 0; i < startPages_.size(); i++ )
    {
        ss << "Day " << i+1 << " : " << startPages_.at(i) << ", " << endPages_.at(i) << "\n"; 
    }

    return( ss.str() );
}

//*********************************************************//
//
//
//*********************************************************//
void BookPartitioner::writeToCSV( std::string csvFileName )
{

}