// header file
#include "File_Input_Utility.h"
#include "IteratorUtility.h"
#include "StackUtility.h"
#include "QueueUtility.h"

// local constants for program
const int INITIAL_NUM_STATES = 10;

// function prototypes
void showTitle();
bool uploadStateData( StateLLType *llType, const char *fileName );

int main()
   {
    // initialize function/program

       // initialize variables
       StateLLType *wkgLL;
       StateDataType tempData;
       IteratorType *iterator;
       StackType *stack;
       QueueType *queue;
       int index, testLimit, testStart = 0;

       // show title
          // function: showTitle
       showTitle();

    // set up data
    wkgLL = createDataStructure();
    iterator = createIterator();
    stack = createStack();
    queue = createQueue();

    // Upload data
    if( uploadStateData( wkgLL, "StateData.csv" ) )
       {

        // Testing for iterators
        printf( "\nIterator Test Bed ---------------------------------\n\n" );

        copyDataList( iterator->iterData, wkgLL );

        printf( "Iterate across list, first to last\n" );

        getFirst( iterator, &tempData );

        printf( "First name: %s\n", tempData.name );

        while( getNext( iterator, &tempData ) )
           {
            printf( "Next name: %s\n", tempData.name );
           }
   
        printf( "\nIterate across list, last to first\n" );

        getLast( iterator, &tempData );

        printf( "Last name: %s\n", tempData.name );

        while( getPrevious( iterator, &tempData ) )
           {
            printf( "Prior name: %s\n", tempData.name );
           }
   
        // Testing for Stacks
        printf( "\nStack Test Bed ------------------------------------\n\n" );

        printf( "Push items on stack:\n" );

        testLimit = 10;
        for( index = testStart; index < testLimit; index++ )
           {
            getItemAtIndex( &tempData, *wkgLL, index );

            printf( "Pushing: %s\n", tempData.name );

            pushStack( stack, tempData );
           }

        printf( "\nCurrent stack: " );

        testStart = 0;
        for( index = testStart; index < getListSize( *stack ); index++ )
           {
            getItemAtIndex( &tempData, *stack, index );

            printf( "%s | ", tempData.name );
           }

        printf( "<- Top of stack\n\nPop items from stack:\n" );

        testLimit = 5;
        for( index = testStart; index < testLimit; index++ )
           {
            popStack( &tempData, stack );

            printf( "Popping: %s\n", tempData.name );
           }

        printf( "\nCurrent stack: " );

        for( index = testStart; index < getListSize( *stack ); index++ )
           {
            getItemAtIndex( &tempData, *stack, index );

            printf( "%s | ", tempData.name );
           }

        printf( "<- Top of stack\n\nPush more items on stack:\n" );

        testStart = 10; testLimit = 15;
        for( index = testStart; index < testLimit; index++ )
           {
            getItemAtIndex( &tempData, *wkgLL, index );

            printf( "Pushing: %s\n", tempData.name );

            pushStack( stack, tempData );
           }

        printf( "\nCurrent stack: " );

        testStart = 0;
        for( index = testStart; index < getListSize( *stack ); index++ )
           {
            getItemAtIndex( &tempData, *stack, index );

            printf( "%s | ", tempData.name );
           }

        printf( "<- Top of stack\n\nPopping until empty:\n" );

        while( popStack( &tempData, stack ) )
           {
            printf( "Popping: %s\n", tempData.name );
           }

        // Testing for Queues
        printf( "\nQueue Test Bed ------------------------------------\n\n" );

        printf( "Enqueue items:\n" );

        testStart = 0; testLimit = 10;
        for( index = testStart; index < testLimit; index++ )
           {
            getItemAtIndex( &tempData, *wkgLL, index );

            printf( "Enqueueing: %s\n", tempData.name );

            enqueue( queue, tempData );
           }

        printf( "\nCurrent queue: Rear -> " );

        testStart = 0;
        for( index = testStart; index < getListSize( *queue ); index++ )
           {
            getItemAtIndex( &tempData, *queue, index );

            printf( "%s | ", tempData.name );
           }

        printf( " <- Front\n" );

        printf( "\nDequeue items from queue:\n" );

        testLimit = 5;
        for( index = testStart; index < testLimit; index++ )
           {
            dequeue( &tempData, queue );

            printf( "Dequeueing: %s\n", tempData.name );
           }

        printf( "\nCurrent queue: Rear -> " );

        for( index = testStart; index < getListSize( *queue ); index++ )
           {
            getItemAtIndex( &tempData, *queue, index );

            printf( "%s | ", tempData.name );
           }

        printf( " <- Front\n" );

        printf( "\nEnqueue more items:\n" );

        testStart = 10; testLimit = 15;
        for( index = testStart; index < testLimit; index++ )
           {
            getItemAtIndex( &tempData, *wkgLL, index );

            printf( "Enqueueing: %s\n", tempData.name );

            enqueue( queue, tempData );
           }

        printf( "\nCurrent queue: Rear -> " );

        testStart = 0;
        for( index = testStart; index < getListSize( *queue ); index++ )
           {
            getItemAtIndex( &tempData, *queue, index );

            printf( "%s | ", tempData.name );
           }

        printf( " <- Front\n" );

        printf( "\nDequeueing until empty:\n" );

        while( dequeue( &tempData, queue ) )
           {
            printf( "Dequeueing: %s\n", tempData.name );
           }

       }

    else
       {
        printf( "\nFile not found - Program aborted\n" );
       }

       
    // end program

       // report end program
          // function: printf
       printf( "\nProgram End\n" );

       // deallocate memory

       wkgLL = clearDataStructure( wkgLL );

       iterator = clearIterator( iterator );

       stack = clearStack( stack );

       queue = clearQueue( queue );

       // return program success
       return 0;
   }

void showTitle()
   {
    printf( "\nData Structure Test Program\n" );
    printf( "===========================\n" );
   }

/*
Name: uploadStateData
Process: uploads data from given file to state data array,
         ignores first (title) line in .csv file,
         then captures comma-delimited state name, population, growth, 
         and political majority data on each row,
         returns true if upload successful, false otherwise
Function input/parameters: file name (const char *)
Function output/parameters: updated array with uploaded values (StateDataType *)
Function output/returned: Boolean result of upload operation
Device input/HD: data uploaded from text file as specified
Device output/---: none
Dependencies: as needed
*/
bool uploadStateData( StateLLType *llType, const char *fileName )
   {
    StateDataType inputItem;
    int index = 0;
    bool verboseFlag = false;

    if( openInputFile( fileName ) )
       {
        // input top row, ignore
        readStringToLineEndFromFile( inputItem.name );

        // input first data line, read prime
        readStringToDelimiterFromFile( COMMA, inputItem.name );

        while( !checkForEndOfInputFile() )
           {
            // get population
            inputItem.population = readIntegerFromFile();
            readCharacterFromFile();

            // get growth percentage
            inputItem.growth = readDoubleFromFile();
            readCharacterFromFile();
        
            inputItem.majority = readCharacterFromFile();

            if( verboseFlag )
               {
                printf( "[%3d] name: %s, pop: %d, grth: %7.6f, %c\n",
                              index + 1, inputItem.name, inputItem.population,
                                         inputItem.growth, inputItem.majority );
               }
            
            insertItemAtIndex( llType, inputItem, index  );

            index++;
  
            // read re-prime
            readStringToDelimiterFromFile( COMMA, inputItem.name );
           }

        closeInputFile();

        return true;
       }

    return false;
   }


