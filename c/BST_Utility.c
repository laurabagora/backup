#include "BST_Utility.h"

// prototypes

/*
Name: clearTree
Process: recursively returns dynamically allocated data to the OS
Function input/parameters: working pointer for recursion (StudentDataType *)
Function output/parameters: none
Function output/returned: empty tree (NULL)
Device input/ ---: none
Device output/ ---: none
Dependencies: free, clearTree (recursively)
*/
StateDataType *clearTree( StateDataType *wkgPtr )
{
  if (wkgPtr != NULL)
  {
    wkgPtr->rightChildPtr = clearTree(wkgPtr->leftChildPtr);
    wkgPtr->leftChildPtr = clearTree(wkgPtr->rightChildPtr);
    free(wkgPtr);
  }
  return NULL;
}

/*
Name: privateCompareStrings
Process: compares two strings as follows:
         - if left string is alphabetically greater than the right string, 
         returns value greater than zero
         - if left string is alphabetically less than the right string, 
         returns value less than zero
         - if strings are alphabetically equal but one is longer, 
           longer one is greater
         - otherwise, returns zero
Function input/parameters: two strings to be compared (const char *)
Function output/parameters: none
Function output/returned: result as specified above (int)
Device input/ ---: none
Device output/ ---: none
Dependencies: privateGetStringLen
*/
int privateCompareStrings( const char *leftStr, const char *rightStr )
{ 
  int index = 0, left, right, min;
  left = privateGetStringLen( leftStr );
  right = privateGetStringLen( rightStr );

  while (index < left && index < right)
  {
    min = leftStr[index] - rightStr[index];
    if (min != 0)
    {
      return min;
    }
    index++;
  }
  min = left - right;
  return min;
}

/*
Name: privateCopyString
Process: copies one string into another,
         assumes destination string has appropriate capacity
Function input/parameters: source string (const char *)
Function output/parameters: destination string (const char *)
Function output/returned: none
Device input/ ---: none
Device output/ ---: none
Dependencies: none
*/
void privateCopyString( char *dest, const char *source )
{
  int index = 0;
  while (source[index] != NULL_CHAR)
  {
    dest[index] = source[index];
    index++;
    dest[index] = NULL_CHAR;
  }
}

/*
Name: copyTree
Process: recursively duplicates the provided tree
         using a pre order traversal strategy
Function input/parameters: working pointer for recursion (StateDataType *)
Function output/parameters: none
Function output/returned: pointer to duplicate tree (StateDataType *)
Device input/ ---: none
Device output/ ---: none
Dependencies: initializeStateNodeFromNode, copyTree (recursively)
*/
StateDataType *copyTree( StateDataType *wkgPtr )
{
  if (wkgPtr != NULL)
  {
    StateDataType *new = initializeStateNodeFromNode(*wkgPtr);
    new->leftChildPtr = copyTree(wkgPtr->leftChildPtr);
    new->rightChildPtr = copyTree(wkgPtr->rightChildPtr);
    return new;
  }
  return NULL;
}

/*
Name: displayInOrder
Process: recursively displays tree using in order traversal
Function input/parameters: working pointer for recursion (StateDataType *)
Function output/parameters: none
Function output/returned: none
Device input/ ---: none
Device output/ ---: none
Dependencies: stateDataToString, printf
*/
void displayInOrder( StateDataType *sdtPtr, int *itemNum )
{
  char str[STD_STR_LEN];
  if (sdtPtr != NULL)
  {
    displayInOrder(sdtPtr->leftChildPtr, itemNum);
    stateDataToString(*sdtPtr, str);
    *itemNum = *itemNum + 1;
    printf("%d) %s", *itemNum, str);
    displayInOrder(sdtPtr->rightChildPtr, itemNum);
  }
}

/*
Name: displayPostOrder
Process: recursively displays tree using post order traversal
Function input/parameters: working pointer for recursion (StateDataType *)
Function output/parameters: none
Function output/returned: none
Device input/ ---: none
Device output/ ---: none
Dependencies: stateDataToString, printf
*/
void displayPostOrder( StateDataType *sdtPtr, int *itemNum )
{
  char str[STD_STR_LEN];
  if (sdtPtr != NULL)
  {
    displayPostOrder(sdtPtr->leftChildPtr, itemNum);
    displayPostOrder(sdtPtr->rightChildPtr, itemNum);
    *itemNum = *itemNum + 1;
    stateDataToString(*sdtPtr, str);
    printf("%d) %s", *itemNum, str);
  }
}

/*
Name: displayPreOrder
Process: recursively displays tree using pre order traversal
Function input/parameters: working pointer for recursion (StateDataType *)
Function output/parameters: none
Function output/returned: none
Device input/ ---: none
Device output/ ---: none
Dependencies: stateDataToString, printf
*/
void displayPreOrder( StateDataType *sdtPtr, int *itemNum )
{
  char str[STD_STR_LEN];
  if (sdtPtr != NULL)
  {
    *itemNum = *itemNum + 1;
    stateDataToString(*sdtPtr, str);
    printf("%d) %s", *itemNum, str);
    displayPreOrder(sdtPtr->leftChildPtr, itemNum);
    displayPreOrder(sdtPtr->rightChildPtr, itemNum);
  }
}

/*
Name: privateGetStringLen
Process: finds length of string
Function input/parameters: string (const char *)
Function output/parameters: none
Function output/returned: calculated length of string (int)
Device input/ ---: none
Device output/ ---: none
Dependencies: none
*/
int privateGetStringLen( const char *str )
{
  int index = 0;

  while( str[ index ] != NULL_CHAR )
   {
    index++;
   }
  return index;
}
/*
Name: initializeBST
Process: sets BST root pointer to NULL, root pointer is returned by address
Function input/parameters: address of working pointer (StateDataType **)
Function output/parameters: address of updated working pointer 
                            (StateDataType **)
Function output/returned: none
Device input/ ---: none
Device output/ ---: none
Dependencies: none
*/
void initializeBST( StateDataType **bstPtr )
{
  *bstPtr = NULL;
}

/*
Name: initializeStateNodeFromData
Process: captures data from individual data items, 
         dynamically creates new node,
         copies data, and returns pointer to new node         
Function input/parameters: data to be copied
                           name (const char *)
                           temperatures (double)
Function output/parameters: none
Function output/returned: pointer to new node as specified (StateDataType *)
Device input/ ---: none
Device output/ ---: none
Dependencies: malloc, sizeof, privateCopyString
*/
StateDataType *initializeStateNodeFromData( const char *state, double avgTemp, 
                                              double lowTemp, double highTemp )
{
   StateDataType *new = (StateDataType*)malloc(sizeof(StateDataType));
   privateCopyString(new->state, state);
   new->avgTemp = avgTemp;
   new->lowestTemp = lowTemp;
   new->highestTemp = highTemp;
   new->leftChildPtr = NULL;
   new->rightChildPtr = NULL;
   return new;
}

/*
Name: initializeStateNodeFromNode
Process: captures data from source node pointer, dynamically creates new node,
         copies data, and returns pointer to new node         
Function input/parameters: node to be copied (StateDataType)
Function output/parameters: none
Function output/returned: pointer to new node as specified (StateDataType *)
Device input/ ---: none
Device output/ ---: none
Dependencies: initializeStateNodeFromData
Notes: one line of code
*/
StateDataType *initializeStateNodeFromNode( const StateDataType source )
{
  return initializeStateNodeFromData(source.state, source.avgTemp, 
                              source.lowestTemp, source.highestTemp);
}

/*
Name: insert
Process: recursively searches for available node in BST,
         creates new node and returns it to the calling function,
         if node is already in tree, data is overwritten
Function input/parameters: working pointer for recursion (StateDataType *),
                           node to be inserted (const StateDataType)
Function output/parameters: none
Function output/returned: pointer to new node as specified (StateDataType *)
Device input/ ---: none
Device output/ ---: none
Dependencies: privateCompareStrings, 
              setStateNodeData, initializeStateNodeFromNode
Notes: No redundant code permitted
*/
StateDataType *insert( StateDataType *wkgPtr, const StateDataType inData )
{
  int comparison = privateCompareStrings(wkgPtr->state, inData.state);

  if (wkgPtr != NULL) 
  {
    if (comparison > 0) 
    {
        wkgPtr->rightChildPtr = 
                insert(wkgPtr->rightChildPtr, *inData.rightChildPtr);
    } 
    else if (comparison < 0) 
    {
        wkgPtr->leftChildPtr = 
                  insert(wkgPtr->leftChildPtr, *inData.leftChildPtr);
    } 
    else 
    {
        setStateNodeData(wkgPtr, inData);
    }
  }
  else
  {
    return initializeStateNodeFromNode(inData);
  }
  return wkgPtr; 
}

/*
Name: isEmpty
Process: tests root node for NULL, returns result
Function input/parameters: pointer to root node (StateDataType *)
Function output/parameters: none
Function output/returned: result of test as specified (bool)
Device input/ ---: none
Device output/ ---: none
Dependencies: none
*/
bool isEmpty( StateDataType *sdtPtr)
{
  return sdtPtr == NULL;
}
/*
Name: removeFromMin
Process: recursively searches for min node,
         when found, node is unlinked from tree, and returned
Function input/parameters: pointers to parent and child nodes (StateDataType *)
Function output/parameters: none
Function output/returned: pointer to removed node (StateDataType *)
Device input/ ---: none
Device output/ ---: none
Dependencies: removeFromMin (recursively)
*/
StateDataType *removeFromMin( StateDataType *parentPtr,
                                                      StateDataType *childPtr )
{
  if (childPtr->leftChildPtr == NULL)
  {
    parentPtr->leftChildPtr = childPtr->rightChildPtr;
    return childPtr;
  }
  return removeFromMin(childPtr, childPtr->leftChildPtr);
}

/*
Name: removeItem
Process: searches for item, if found, creates new node from search pointer,
         then removes item from tree using helper function,
         otherwise returns NULL
Function input/parameters: address of pointer to root node (StateDataType *),
                           node to be removed with at least state name key
                                                           (const StateDataType)
Function output/parameters: address of updated root node pointer 
                            (StateDataType **)
Function output/returned: pointer to removed item node (StateDataType *)
Device input/ ---: none
Device output/ ---: none
Dependencies: search, initializeStateNodeFromNode, removeItemHelper
*/
bool removeItem( StateDataType **rootPtr, 
                      StateDataType *removedData, const StateDataType outData )
{
  StateDataType *found = search(*rootPtr, outData);

  if (found == NULL)
  {
    setStateNodeToEmpty(removedData);
    return false; 
  }
  setStateNodeData(removedData, *found);
  *rootPtr = removeItemHelper(*rootPtr, outData);
  return true;
}

/*
Name: removeItemHelper
Process: recursively searches for item, removes node,
         returns dynamic memory of removed node to OS,
         returns updated link to parent (at each recursive level),
         only one return at end of function
Function input/parameters: pointer to working node (StateDataType *),
                           node to be removed with at least state name key
                                                           (const StateDataType)
Function output/parameters: none
Function output/returned: link to recursive parent
Device input/ ---: none
Device output/ ---: none
Dependencies: privateCompareStrings, setStateDataNode, removeFromMin, 
              free, removeItemHelper (recursively)
Notes: No redundant code permitted
*/
StateDataType *removeItemHelper( StateDataType *wkgPtr, 
                                                  const StateDataType outData )
{
  StateDataType *temp;
  int comparison = privateCompareStrings(outData.state, wkgPtr->state);

  if (comparison < 0) 
  {
    wkgPtr->leftChildPtr = 
          removeItemHelper(wkgPtr->leftChildPtr, outData);
  } 
  if (comparison > 0) 
  {
    wkgPtr->rightChildPtr = 
          removeItemHelper(wkgPtr->rightChildPtr, outData);
  } 
  else if (wkgPtr->rightChildPtr == NULL)
  {
    temp = wkgPtr;
    wkgPtr = wkgPtr->leftChildPtr;
    free(temp);
  }
    else if (wkgPtr->leftChildPtr == NULL)
  {
    temp = wkgPtr;
    wkgPtr = wkgPtr->rightChildPtr;
    free(temp);
  }
  else
  {
    if (wkgPtr->rightChildPtr->leftChildPtr != NULL) 
    {
      temp = removeFromMin(wkgPtr, wkgPtr->rightChildPtr);
      setStateNodeData(wkgPtr, *temp);
      free(temp);
    } 
    else
    {
      setStateNodeData(wkgPtr, *wkgPtr->rightChildPtr);
      temp = wkgPtr->rightChildPtr;
      wkgPtr->rightChildPtr = temp->rightChildPtr;
      free(temp);
    }
  }
  return wkgPtr;
}

/*
Name: search
Process: recursively searches for item, if found, returns pointer to node,
         otherwise, returns NULL
Function input/parameters: pointer to working node (StateDataType *),
                           node to be found with at least state name key
                                                           (const StateDataType)
Function output/parameters: none
Function output/returned: link to found node, or NULL, as specified
Device input/ ---: none
Device output/ ---: none
Dependencies: compareStrings
Notes: No redundant code permitted
*/
StateDataType *search( StateDataType *wkgPtr, const StateDataType searchData )
{
  int comparison = privateCompareStrings(searchData.state, wkgPtr->state);;

  if (wkgPtr != NULL)
  {
    if (comparison < 0)
    {
      return search(wkgPtr->leftChildPtr, searchData);
    } 
    else
    {
      return search(wkgPtr->rightChildPtr, searchData);
    } 
    return wkgPtr;
  }
  return NULL;
}

/*
Name: setStateNodeToEmpty
Process: sets state node to empty or default values
Function input/parameters: pointer to node (StateDataType *)
Function output/parameters: pointer to updated node (StateDataType *)
Function output/returned: none
Device input/ ---: none
Device output/ ---: none
Dependencies: none
*/
void setStateNodeToEmpty( StateDataType *node )
{
  node->state[0] = NULL_CHAR;
  node->avgTemp = 0.0;
  node->lowestTemp = 0.0;
  node->highestTemp = 0.0;
}

/*
Name: setStateNodeData
Process: copies data from source node to destination pointer
Function input/parameters: node to be copied (StateDataType)
Function output/parameters: destination pointer (StateDataType *)
Function output/returned: none
Device input/ ---: none
Device output/ ---: none
Dependencies: copyString
*/
void setStateNodeData( StateDataType *destPtr, const StateDataType source )
{
  privateCopyString(destPtr->state, source.state);
  destPtr->avgTemp = source.avgTemp;
  destPtr->lowestTemp = source.lowestTemp;
  destPtr->highestTemp = source.highestTemp;
}

/*
Name: stateDataToString
Process: sets data from node to formatted string
Function input/parameters: node with data to be set (StateDataType)
Function output/parameters: string array with result (char [])
Function output/returned: none
Device input/ ---: none
Device output/ ---: none
Dependencies: sprintf
*/
void stateDataToString( StateDataType stateData, char str[] )
{
 sprintf(str, "State name: %s, Avg Temp: %.2lf, Low Temp: %.2lf,"
             "High Temp: %.2lf", stateData.state, stateData.avgTemp, 
                            stateData.lowestTemp, stateData.highestTemp);
}