#ifndef BST_UTILITY_H
#define BST_UTILITY_H

// header files
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "StandardConstants.h"

// external constants


// data types

typedef struct stateDataStruct
   {
    char state[ MIN_STR_LEN ];
    double avgTemp;
    double lowestTemp;
    double highestTemp;

    struct stateDataStruct *leftChildPtr;
    struct stateDataStruct *rightChildPtr;
   } StateDataType;

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
StateDataType *clearTree( StateDataType *wkgPtr );

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
int privateCompareStrings( const char *leftStr, const char *rightStr );

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
void privateCopyString( char *dest, const char *source );

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
StateDataType *copyTree( StateDataType *wkgPtr );

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
void displayInOrder( StateDataType *sdtPtr, int *itemNum );

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
void displayPostOrder( StateDataType *sdtPtr, int *itemNum );

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
void displayPreOrder( StateDataType *sdtPtr, int *itemNum );

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
int privateGetStringLen( const char *str );

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
void initializeBST( StateDataType **bstPtr );

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
                                              double lowTemp, double highTemp );

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
StateDataType *initializeStateNodeFromNode( const StateDataType source );

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
StateDataType *insert( StateDataType *wkgPtr, const StateDataType inData );

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
bool isEmpty( StateDataType *sdtPtr);

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
                                                      StateDataType *childPtr );

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
                      StateDataType *removedData, const StateDataType outData );

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
                                                  const StateDataType outData );

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
StateDataType *search( StateDataType *wkgPtr, const StateDataType searchData );

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
void setStateNodeToEmpty( StateDataType *node );

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
void setStateNodeData( StateDataType *destPtr, const StateDataType source );

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
void stateDataToString( StateDataType stateData, char str[] );

#endif   // BST_UTILITY_H

