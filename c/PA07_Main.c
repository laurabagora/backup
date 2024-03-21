// header files
#include "File_Input_Utility.h"
#include "BST_Utility.h"

// constant definitions
   // none

// prototypes
int getDataFromFile( const char *fileName, StateDataType **rootPtr );

// main function
int main( int argc, char *argv[] )
   {
    StateDataType *rootPtr, *cpdRootPtr;
    StateDataType toRemove, removedVal;
    int startNumber = 0;
    char fileName[ STD_STR_LEN ] = "StateTempData.csv";
    char stateString[ STD_STR_LEN ];

    // set title
    printf( "\nBinary Search Tree Test Program\n" );
    printf(   "===============================\n" );

    // initialize iterator
    initializeBST( &rootPtr );

    // upload data, check for success
       // function: getDataFromFile
    if( getDataFromFile( fileName, &rootPtr ) > 0 )
       {  
        // show in order traversal
           // function: displayInOrder
        printf( "\nIn order traversal: \n" );
        startNumber = 0;   
        displayInOrder( rootPtr, &startNumber );

        printf( "\nCreating duplicate tree\n" );
        cpdRootPtr = copyTree( rootPtr );

        printf( "\nInorder Display of copied tree:\n" );   
        startNumber = 0;   
        displayInOrder( cpdRootPtr, &startNumber );

        printf( "\nRemoving North Carolina\n" );
        privateCopyString(toRemove.state, "North Carolina" );  
        removeItem( &rootPtr, &removedVal, toRemove );
        stateDataToString( removedVal, stateString );
        printf( "Removed from Tree: %s\n", stateString );
 
        printf( "\nPreorder Display:\n" );      
        startNumber = 0;   
        displayPreOrder( rootPtr, &startNumber );
      
        printf( "\nRemoving Alabama\n" );
        privateCopyString(toRemove.state, "Alabama" ); 
        removeItem( &rootPtr, &removedVal, toRemove );
        stateDataToString( removedVal, stateString );
        printf( "Removed from Tree: %s\n", stateString );

        printf( "\nPostorder Display:\n" );      
        startNumber = 0;   
        displayPostOrder( rootPtr, &startNumber );
      
        printf( "\nRemoving Wyoming\n" );
        privateCopyString(toRemove.state, "Wyoming" ); 
        removeItem( &rootPtr, &removedVal, toRemove );
        stateDataToString( removedVal, stateString );
        printf( "Removed from Tree: %s\n", stateString );

        printf( "\nInorder Display:\n" );      
        startNumber = 0;   
        displayInOrder( rootPtr, &startNumber );
       }

    else
       {
        printf( "\nERROR: Data not found - program aborted\n" );
       }
    // end program

       // clear BST
          // function: clearTree
       rootPtr = clearTree( rootPtr );
       //cpdRootPtr = clearTree( cpdRootPtr );

       // show program end
          // function: printf
       printf( "\nEnd Program\n" );

       // return success
       return 0;
   }

/*
Name: getDataFromFile
Process: uploads data from file with unknown number of data sets,
         has internal Boolean to test for data input success
Function input/parameters: file name (char *)
Function output/parameters: pointer to BST head pointer (StateDataType **)
Function output/returned: number of values found (int)
Device input/file: data from HD
Device output/monitor: none
Dependencies: openInputFile, readStringToLineEndFromFile, 
              readStringToDelimiterFromFile, 
              checkForEndOfInputFile, readCharacterFromFile, readDoubleFromFile,
              insert, printf, closeInputFile
*/
int getDataFromFile( const char *fileName, StateDataType **rootPtr )
   {
    StateDataType stateDataNode;
    char dummyInput[ STD_STR_LEN ];
    int index = 0;
    bool verbose = true;  // Set to true to verify data upload, false otherwise

    if( openInputFile( fileName ) )
       {
        if( verbose )
           {
            printf( "\nBegin Loading Data From File\n" );
           }

        readStringToLineEndFromFile( dummyInput );

        readStringToDelimiterFromFile( COMMA, stateDataNode.state );

        while( !checkForEndOfInputFile() )
           {
            stateDataNode.avgTemp = readDoubleFromFile();

            // remove comma
            readCharacterFromFile();

            stateDataNode.lowestTemp = readDoubleFromFile();

            // remove comma
            readCharacterFromFile();

            stateDataNode.highestTemp = readDoubleFromFile();

            *rootPtr = insert( *rootPtr, stateDataNode );

            if( verbose )
               {
                printf( "%2d) State name: %s, ", 
                                               index + 1, stateDataNode.state );

                printf( "Avg Temp: %5.2f, ", stateDataNode.avgTemp );

                printf( "Low Temp: %5.2f, ", stateDataNode.lowestTemp );

                printf( "High Temp: %5.2f\n", stateDataNode.highestTemp );

               }

            // reprime - read next state name
            readStringToDelimiterFromFile( COMMA, stateDataNode.state );
       
            index++;
           }

        if( verbose )
           {
            printf( "End Loading Data From File\n\n" );
           }

        closeInputFile();
       }

    return index;
   }

