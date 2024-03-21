// header files
#include "StackUtility.h"

// function prototypes

/*
Name: clearStack
Process: clears StackType, returns NULL
Function input/parameters: pointer to stack type (StackType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: clearDataStructure
*/
StackType *clearStack( StackType *stackData )
{
    return clearDataStructure(stackData);
}

/*
Name: createStack
Process: creates StackType, returns pointer to it
Function input/parameters: initial capacity (int)
Function output/parameters: none
Function output/returned: pointer to stack type (StackType *)
Device input/---: none
Device output/---: none
Dependencies: createDataStructure
*/
StackType *createStack()
{
    return createDataStructure();
}

/*
Name: peekTop
Process: captures value at top of stack, returns,
         returns true if successful, 
         otherwise, sets return value to empty, returns false
Function input/parameters: pointer to stack type (StackType *)
Function output/parameters: pointer to return value (StateDataType *)
Function output/returned: Boolean result of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: getItemAtIndex, getListSize
*/
bool peekTop( StateDataType *returnVal, const StackType stackData )
{
    // get first index and return true
    return(getItemAtIndex(returnVal, stackData, getListSize(stackData) - 1));
}

/*
Name: popStack
Process: captures value at top of stack, removes and returns,
         returns true if successful, 
         otherwise, sets return value to empty, returns false
Function input/parameters: pointer to stack type (StackType *)
Function output/parameters: pointer to return value (StateDataType *)
Function output/returned: Boolean result of operation
Device input/---: none
Device output/---: none
Dependencies: removeItemAtIndex, getListSize
*/
bool popStack( StateDataType *returnVal, StackType *stackData )
{
    return removeItemAtIndex(stackData, returnVal, getListSize(*stackData) - 1);
}

/*
Name: pushStack
Process: sets value at top of stack,
         returns true if successful, false otherwise
Function input/parameters: pointer to stack type (StackType *)
Function output/parameters: value to be pushed (const StateDataType)
Function output/returned: Boolean result of operation
Device input/---: none
Device output/---: none
Dependencies: insertItemAtIndex, getListSize
*/
bool pushStack( StackType *stackData, const StateDataType toBePushed )
{
    return insertItemAtIndex(stackData, toBePushed, getListSize(*stackData));
}