// Header file
#include "RedBlackTreeUtility.h"

// constants
const char SEMICOLON_BREAK[] = "; ";
const char THICK_DIVIDER = '=';
const char THIN_DIVIDER = '-';

// functions

// TODO: Set functions here
/*
Name: clearTree
Process: recursively returns dynamically allocated data to the OS
         using a post order traversal strategy
Function input/parameters: working pointer for recursion (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: empty tree (NULL)
Device input/---: none
Device output/---: none
Dependencies: free
*/
RedBlackNodeType *clearTree( RedBlackNodeType *localPtr )
{
   // check if pointer is empty
  if (localPtr != NULL)
  {
    clearTree(localPtr->leftChildPtr);
    clearTree(localPtr->rightChildPtr);
    free(localPtr);
  }
  return NULL;
}

/*
Name: copyTree
Process: copies a Red Black tree from another Red Black tree
         using a pre order traversal strategy,
         appropriately links child parent pointers to current node
Function input/parameters: pointer to source node (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: pointer to destination node (RedBlackNodeType *)
Device input/---: none
Device output/---: none
Dependencies: createNodeFromNode, copyTree (recursively)
*/
RedBlackNodeType *copyTree( RedBlackNodeType *srcPtr )
{
  RedBlackNodeType *new = NULL;

  // check if pointer is empty and return newly created pointer
  if (srcPtr == NULL)
  {
    return new; 
  }
  // put data into new pointer 
  new = createNodeFromNode(srcPtr);
  new->leftChildPtr = copyTree(srcPtr->leftChildPtr);

  // check if left and right pointers are empty
  if (new->leftChildPtr != NULL)
  {
   new->leftChildPtr->parentPtr = new;
  }
  new->rightChildPtr = copyTree(srcPtr->rightChildPtr);
  if (new->rightChildPtr != NULL)
  {
   new->rightChildPtr->parentPtr = new;
  }
  return new;
}

/*
Name: createNodeFromData
Process: creates a Red Black tree node from the node data given,
         all links are set to NULL
Function input/parameters: data (char), color (int)
Function output/parameters: none
Function output/returned: pointer to created node (RedBlackNodeType *)
Device input/---: none
Device output/---: none
Dependencies: malloc
*/
RedBlackNodeType *createNodeFromData( char data, int nodeColor )
{
   RedBlackNodeType *new = (RedBlackNodeType*)malloc(sizeof(RedBlackNodeType));
   new->data = data;
   new->color = nodeColor;
   new->parentPtr = NULL;
   new->leftChildPtr = NULL;
   new->rightChildPtr = NULL;
   return new;
}

/*
Name: createNodeFromNode
Process: allocates memory for node,
         copies an individual tree node from another node,
         all links are set to NULL
Function input/parameters: pointer to source node (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: pointer to destination node (RedBlackNodeType *)
Device input/---: none
Device output/---: none
Dependencies: one line of code - createNodeFromData
*/
RedBlackNodeType *createNodeFromNode( RedBlackNodeType *srcPtr )
{
   return createNodeFromData(srcPtr->data, srcPtr->color);
}

/*
Name: displayInOrder
Process: traverses across tree, prints semicolon-delimited list,
         displays "data / color" using in order strategy
Function input/parameters: pointer to current working node (RedBlackNodeType *),
                           pointer to row start flag 
                           for first line of output (bool *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: displayed as specified
Dependencies: printf, displayInOrder (recursively)
*/
void displayInOrder( RedBlackNodeType *wkgPtr, bool *rowStartFlag )
{
   // in order goes display, print, display
   if (wkgPtr != NULL)
   {
      displayInOrder(wkgPtr->leftChildPtr, rowStartFlag);

      // check to see if a semicolon is needed
      if (!*rowStartFlag)
      {
         printf(SEMICOLON_BREAK);
      }
     *rowStartFlag = false;
     printf("%c/%c", wkgPtr->data, (char)wkgPtr->color);
     displayInOrder(wkgPtr->rightChildPtr, rowStartFlag);
   }
}

/*
Name: displayPostOrder
Process: traverses across tree, prints semicolon-delimited list,
         displays "data / color" using post order strategy
Function input/parameters: pointer to current working node (RedBlackNodeType *),
                           pointer to row start flag 
                           for first line of output (bool *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: displayed as specified
Dependencies: printf, displayPostOrder (recursively)
*/
void displayPostOrder( RedBlackNodeType *wkgPtr, bool *rowStartFlag )
{
   // post order goes display, display, print
   if (wkgPtr != NULL)
   {
      displayPostOrder(wkgPtr->leftChildPtr, rowStartFlag);
      displayPostOrder(wkgPtr->rightChildPtr, rowStartFlag);

      // check to see if a semicolon is needed
      if (!*rowStartFlag)
      {
         printf(SEMICOLON_BREAK);
      }
     *rowStartFlag = false;
     printf("%c/%c", wkgPtr->data, (char)wkgPtr->color);
   }
}

/*
Name: displayPreOrder
Process: traverses across tree, prints semicolon-delimited list,
         displays "data / color" using pre order strategy
Function input/parameters: pointer to current working node (RedBlackNodeType *),
                           pointer to row start flag 
                           for first line of output (bool *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: displayed as specified
Dependencies: printf, displayPreOrder (recursively)
*/
void displayPreOrder( RedBlackNodeType *wkgPtr, bool *rowStartFlag )
{
   // preorder goes print, display, display
   if (wkgPtr != NULL)
   {
      // check to see if a semicolon is needed
      if (!*rowStartFlag)
      {
         printf(SEMICOLON_BREAK);
      }
     *rowStartFlag = false;
     printf("%c/%c", wkgPtr->data, (char)wkgPtr->color);
     displayPreOrder(wkgPtr->leftChildPtr, rowStartFlag);
     displayPreOrder(wkgPtr->rightChildPtr, rowStartFlag);
   }
}

/*
Name: displayTree
Process: controller function for calling appropriate tree traversal
Function input/parameters: pointer to current tree root (RedBlackNodeType *),
                           control codes INORDER_TRAVERSE, POSTORDER_TRAVERSE,
                           PREORDER_TRAVERSE
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: displayed as specified
Dependencies: displayInOrder, displayPostOrder, displayPreOrder, printf
*/
void displayTree( RedBlackNodeType *rootPtr, ControlCodes traverseCode )
{
   // make sure the bool is true to start with before calling to functions
   bool flag = true;
   switch (traverseCode)
   {
   // check the pre, post, and in order (default)
   case PREORDER_TRAVERSE:
      printf("Preorder\n");
      displayPreOrder(rootPtr, &flag);
      break;

   case POSTORDER_TRAVERSE:
      printf("Postorder\n");
      displayPostOrder(rootPtr, &flag);
      break;

   default:
      printf("Inorder\n");
      displayInOrder(rootPtr, &flag);
      break;
   }
}

/*
Name: findTreeHeight
Process: recursively finds height of tree
Function input/parameters: working pointer for recursion (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: height of tree (int)
Device input/---: none
Device output/---: none
Dependencies: getMax
*/
int findTreeHeight( RedBlackNodeType *localPtr )
{
   int leftHeight, rightHeight;

   // check if pointer is empty
   if (localPtr == NULL) 
   {
      return -1;
   }
   // get the left height and right height for parameters
   leftHeight = findTreeHeight(localPtr->leftChildPtr);
   rightHeight = findTreeHeight(localPtr->rightChildPtr) + 1;

   // call to get max to finish up the process
   return getMax(leftHeight, rightHeight);
}

/*
Name: initializeRBT
Process: returns NULL to tree root pointer to prepare tree for use
Function input/parameters: none
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: none
*/
RedBlackNodeType *initializeRBT()
{
   return NULL;
}

/*
Name: insert
Process: sets first node if tree is empty, otherwise calls helper
         to set nodes, then calls RBT resolver to rebalance tree
         if node is successfully inserted by helper,
         prints inserting/resolving statement and root color set to black
Function input/parameters: tree root pointer (RedBlackNodeType *),
                           data to be inserted (char)
Function output/parameters: none
Function output/returned: pointer to updated tree root (RedBlackNodeType *)
Device input/---: none
Device output/---: none
Dependencies: printf, createNodeFromData, insertHelper, resolveRBT
*/
RedBlackNodeType *insert( RedBlackNodeType *treeRoot, char inData )
{
   RedBlackNodeType *new;

   printf("Inserting %c and resolving\n", inData);

   // check if empty
   if(treeRoot == NULL)
   {
      // put data into new with red 
      new = createNodeFromData(inData, RED);

      // sets it back to black and returns that new pointer
      printf("     - Root set to black\n");
      new->color = BLACK;
      return new;
   }
   // call the helper to help with this process
   new = insertHelper(treeRoot, inData);

   // check if empty and call to resolve to fully insert
   if (new != NULL)
   {
      resolveRBT(&treeRoot, new);
   }
   return treeRoot;
}

/*
Name: insertHelper
Process: recursively finds place to add node, 
         places node using "look down" strategy,
         returns newly inserted node pointer, 
         if duplicated nodes/keys attempted, returns NULL
Function input/parameters: working pointer for recursion (RedBlackNodeType *),
                           data to be inserted (char)
Function output/parameters: none
Function output/returned: pointer to inserted node (RedBlackNodeType *)
Device input/---: none
Device output/---: none
Dependencies: createNodeFromData, insertHelper (recursively)
*/
RedBlackNodeType *insertHelper( RedBlackNodeType *wkgPtr, char inData )
{
   int inserted = wkgPtr->data - inData;

   // check if greater than zero and empty
   if (inserted > 0) 
   {
      if ( wkgPtr->leftChildPtr == NULL)
      {
         // put data into this pointer and get it all set up for recursion
         wkgPtr->leftChildPtr = createNodeFromData(inData, RED);
         wkgPtr->leftChildPtr->parentPtr = wkgPtr;
         return wkgPtr->leftChildPtr;
      }
      return insertHelper(wkgPtr->leftChildPtr, inData);
   }
   // check if less than zero and empty
   else  if (inserted < 0) 
   {
      if ( wkgPtr->rightChildPtr == NULL)
      {
         // put data into this pointer and get it all set up for recursion
         wkgPtr->rightChildPtr = createNodeFromData(inData, RED);
         wkgPtr->rightChildPtr->parentPtr = wkgPtr;
         return wkgPtr->rightChildPtr;
      }
      return insertHelper(wkgPtr->rightChildPtr, inData);
   }
   return NULL;
}

/*
Name: isEmpty
Process: returns true if tree is empty, false otherwise
Function input/parameters: tree root pointer (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isEmpty( RedBlackNodeType *localPtr )
{
   return localPtr == NULL;
}

/*
Name: resolveRBT
Process: recursively checks tree for need to rebalance, 
         conducts rebalance as needed
Function input/parameters: address of tree root pointer (RedBlackNodeType **),
                           working pointer for recursion 
                           which starts at the location 
                           of the inserted node (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: printf, rotateLeft, rotateRight, swapColors, 
                      displayTreeStructure, displayDivider
*/
void resolveRBT( RedBlackNodeType **treeRoot, RedBlackNodeType *wkgPtr )
{
   RedBlackNodeType *parent, *grand, *uncle, *great;

   // make sure the parent and grandparents are not empty
   if (wkgPtr->parentPtr != NULL && wkgPtr->parentPtr->parentPtr != NULL)
   {
      // put the data into the new pointers
      parent  = wkgPtr->parentPtr;
      grand = wkgPtr->parentPtr->parentPtr;

      // check if the grandparents left child is equal to the parent
      if (grand->leftChildPtr == parent)
      {
         // if it is then set the uncle to the grandparents right child
         uncle = grand->rightChildPtr;
      }
      else
      {
         // if it is not then set the uncle to the grandparents left child
         uncle = grand->leftChildPtr;
      }
      // set the parents color to red
      if (parent->color == RED)
      {
         printf("   - Parent is red\n");
         // check if the uncles color is red and not empty
         if (uncle->color == RED && uncle != NULL)
         {
            // print the red statements and change grandparent to red
            printf("   - Uncle is red\n");
            printf("   - Grandparent is red\n");
            grand->color = RED;

            // change everything to black 
            printf("   - Uncle is black\n");
            uncle->color = BLACK;
            printf("   - Parent is black\n");
            parent->color = BLACK;

            // makes sure its all resolved
            printf("      - Resolving Grandparent\n");
            resolveRBT(treeRoot, grand);
         }
         // if the uncles color is not red and is empty
         else
         {
            printf("   - Uncle is black\n");

            // check if the grandchilds left child is equal
            // to the parent and working pointer
            if(grand->leftChildPtr == parent)
            {
               if(parent->leftChildPtr == wkgPtr)
               {
                  // checking for the left left case
                  printf("   - Left Left Case\n");
                  printf("      - Rotate Right from left side of grandparent\n");

                  // check is grandparent is not empty
                  if(grand->parentPtr == NULL)
                  {
                     // rotate over for new data
                     *treeRoot = rotateRight(parent, grand);
                  }
                  // if they are not equal
                  else
                  {
                     // rotate over for new data and initalize great grandparent
                     great = grand->parentPtr;
                     great->leftChildPtr = rotateRight(parent, grand);
                  }
                  // swap the grandparents and parents colors
                  printf("      - Swap grandparent/parent colors\n");
                  swapColors(grand, parent);
               }
               else
               {
                  // checking for the left right case
                  printf("   - Left Right Case");
                  printf("      - Rotate left from left side of grandparent\n");

                  // change over to the left to get the left left case
                  grand->leftChildPtr = rotateLeft(wkgPtr, parent);
                  printf("   - Left Left Case");

                  // call to resolve left left case
                  printf("      - Resolve for left left case\n");
                  resolveRBT(treeRoot, wkgPtr->leftChildPtr);
               }
            }
            else
            {
               // check if the parents right child is equal to the working pointer
               if( parent->rightChildPtr == wkgPtr)
               {
                  // checking the right right cases
                  printf("   - Right Right Case\n");
                  printf("      - Rotate left from right side of grandparent\n");

                  // check if grandparent is empty
                  if (grand->parentPtr == NULL)
                  {
                     // rotate left to get new data
                     *treeRoot = rotateLeft(parent, grand);
                  }
                  // if not empty then set the great grandparents up
                  else
                  {
                     great = grand->parentPtr;
                     great->rightChildPtr = rotateLeft(parent, grand);
                  }

                  // finish by swapping the grandparents and parents colors
                  printf("      - Swap grandparent/parent colors\n");
                  swapColors(grand, parent);
               } 
               else
               {
                  // now to the last case, right left case
                  printf("   - Right Left Case\n");
                  printf("      - Rotate right from right side of grandparent\n");

                  // rotate right to get to this point
                  grand->rightChildPtr = rotateRight(wkgPtr, parent);

                  // now in the right right case
                  printf("   - Right Right Case\n");
                  printf("      - Resolve for right right case\n");

                  // now call to resolve to finish the entire process
                  resolveRBT(treeRoot, wkgPtr->rightChildPtr);
               }             
            }
         }
      }
   }
   // lastly is working pointer and tree root
   if (wkgPtr == *treeRoot)
   {
      // set to black
      printf("   - Root color is black");
      wkgPtr->color = BLACK;
   }
   // call all of the displays
   printf("\n");
   displayTreeStructure(*treeRoot, NODE_COLOR);
   displayDivider(*treeRoot, THIN_DIVIDER);
   displayTreeStructure(*treeRoot, NODE_DATA);
   displayDivider(*treeRoot, THICK_DIVIDER);
}

/*
Name: rotateLeft
Process: "rotates" nodes to the left by resetting pointers
         to related nodes
Function input/parameters: old and new top node pointers (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: pointer to new top node (RedBlackNodeType *)
Device input/---: none
Device output/---: none
Dependencies: none
*/
RedBlackNodeType *rotateLeft( RedBlackNodeType *newTopPtr, 
                                                  RedBlackNodeType *oldTopPtr )
{
   // set the temp pointer to the left child on new
   RedBlackNodeType *temp = newTopPtr->leftChildPtr;

   // set the left on new to the old and the old right to the temp
   newTopPtr->leftChildPtr = oldTopPtr;
   oldTopPtr->rightChildPtr = temp;

   // check if temp pointer is empty
   if (temp != NULL) 
   {
      // set the temp to the old
      temp->parentPtr = oldTopPtr;
   }
   // set the new to the old and the old to the new to rotate the completely
   newTopPtr->parentPtr = oldTopPtr->parentPtr;
   oldTopPtr->parentPtr = newTopPtr;
   return newTopPtr;
}

/*
Name: rotateRight
Process: "rotates" nodes to the right by resetting pointers
         to related nodes
Function input/parameters: old and new top node pointers (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: pointer to new top node (RedBlackNodeType *)
Device input/---: none
Device output/---: none
Dependencies: none
*/
RedBlackNodeType *rotateRight( RedBlackNodeType *newTopPtr, 
                                                  RedBlackNodeType *oldTopPtr )
{
   // set the temp pointer to the right child on new
   RedBlackNodeType *temp = newTopPtr->rightChildPtr;

   // set the right on new to the old and the old left to the temp
   newTopPtr->rightChildPtr = oldTopPtr;
   oldTopPtr->leftChildPtr = temp;

   // check if temp pointer is empty
   if (temp != NULL) 
   {
      // set the temp to the old
      temp->parentPtr = oldTopPtr;
   }
   // set the new to the old and the old to the new to rotate the completely
   newTopPtr->parentPtr = oldTopPtr->parentPtr;
   oldTopPtr->parentPtr = newTopPtr;
   return newTopPtr;
}

/*
Name: swapColors
Process: swaps or exchanges colors between two nodes
Function input/parameters: pointers to two nodes (RedBlackNodeType *)
Function output/parameters: none
Function output/returned: updated pointers to two nodes (RedBlackNodeType *)
Device input/---: none
Device output/---: none
Dependencies: none
*/
void swapColors( RedBlackNodeType *one, RedBlackNodeType *other )
{
   Colors temp = one->color;
   one->color = other->color;
   other->color = temp;
}


////////////////////////////////////////////////////////////////////////////////
// No student coding below this point
////////////////////////////////////////////////////////////////////////////////      

/*
Name: displayAtTreeLevel
Process: displays one horizontal "level" of a tree using text graphics
         with appropriate spacing and appropriate number of nodes
Function input/parameters: recursive working node (RedBlackNodeType *),
                           node height, display level, working level (int),
                           row start flag (bool),
                           control code for either data or color
Function output/parameters: none
Function output/returned: updated row start flag (bool *)
Device input/file: none
Device output/monitor: none
Dependencies: displayValue, displayEmptyNodeSpaces
*/
void displayAtTreeLevel( RedBlackNodeType *workingNode, int nodeHeight, 
                                  int displayLevel, int workingLevel, 
                                     bool *rowStartFlag, ControlCodes ctrlCode )
   {
    char charOut = workingNode->data;
  
    if( ctrlCode == NODE_COLOR )
       {
        charOut = (char)workingNode->color;      
       }
   
    if( workingLevel == displayLevel )
       {
        displayValue( charOut, nodeHeight, workingLevel, rowStartFlag );
       }
  
    else
       {
        if( workingNode->leftChildPtr != NULL )
           {
            displayAtTreeLevel( workingNode->leftChildPtr, nodeHeight,
                       displayLevel, workingLevel + 1, rowStartFlag, ctrlCode );
           }
  
        else
           {
            displayEmptyNodeSpaces( nodeHeight, displayLevel, 
                                     workingLevel + 1, rowStartFlag, ctrlCode );
           }
      
        if( workingNode->rightChildPtr != NULL )
           {
            displayAtTreeLevel( workingNode->rightChildPtr, nodeHeight,
                       displayLevel, workingLevel + 1, rowStartFlag, ctrlCode );
           }

        else
           {
            displayEmptyNodeSpaces( nodeHeight, displayLevel, 
                                     workingLevel + 1, rowStartFlag, ctrlCode );
           }              
       }
   }

/*
Name: displayChars
Process: recursively displays a specified number of specified characters
Function input/parameters: number of characters (int), 
                           character to be displayed (char)
Function output/parameters: none
Function output/returned: none
Device input/file: none
Device output/monitor: characters displayed as specified
Dependencies: printf
*/
void displayChars( int numChars, char outChar )
   {
    if( numChars > 0 )
       {
        printf( "%c", outChar );
      
        displayChars( numChars - 1, outChar );
       }
   }

/*
Name: displayDivider
Process: displays divider of correct length for tree
         using either THICK_DIVIDER or THIN_DIVIDER 
         depending on the control code,
         adds one endline to thick divider, two to thin for spacing
Function input/parameters: number of characters (int), 
                           character to be displayed (char)
Function output/parameters: none
Function output/returned: none
Device input/file: none
Device output/monitor: characters displayed as specified
Dependencies: printf
*/
void displayDivider( RedBlackNodeType *rootPtr, char dividerChar )
   {
    int treeHeight = findTreeHeight( rootPtr );
    int numChars = toPower( 2, treeHeight + 2 );

    displayChars( numChars, dividerChar );

    if( dividerChar == THIN_DIVIDER )
       {
        printf( "\n" );
       }

    printf( "\n" );
   }

/*
Name: displayEmptyNodeSpaces
Process: displays the appropriate number of dashes for a given level
         for null nodes, can display either dashes or 'B's
Function input/parameters: node height, display level, working level (int)
                           pointer to row start flag (bool *),
                           control code for either data or color
Function output/parameters: none
Function output/returned: updated row start flag (bool *)
Device input/file: none
Device output/monitor: characters displayed as specified
Dependencies: toPower, displayValue
*/
void displayEmptyNodeSpaces( int nodeHeight, 
                        int displayLevel, int workingLevel, 
                                     bool *rowStartFlag, ControlCodes ctrlCode )
   {
    int nodesToDisplay = toPower( 2, displayLevel - workingLevel ); 
    char charOut = SPACE;
  
    if( displayLevel == workingLevel )
       {
        charOut = DASH;
      
        if( ctrlCode == NODE_COLOR )
           {
            charOut = 'B';
           }
       }
  
    while( nodesToDisplay > 0 )
       {
        displayValue( charOut, nodeHeight, displayLevel, rowStartFlag );
      
        nodesToDisplay--;
       }
   }

/*
Name: displayTreeStructure
Process: repeatedly calls other function to display 
         the structure of an RB tree, can display either dashes or 'B's,
         displays error message if empty tree
Function input/parameters: tree root pointer (RedBlackNodeType *),
                           control code for either data or color
Function output/parameters: none
Function output/returned: none
Device input/file: none
Device output/monitor: characters displayed as specified
Dependencies: findTreeHeight, displayAtTreeLevel, printf
*/
void displayTreeStructure( RedBlackNodeType *rbTreeRoot, ControlCodes ctrlCode )
   {
    int displayLevel, nodeHeight = findTreeHeight( rbTreeRoot ) + 2;
    int workingLevel = 1;
    bool rowStartFlag;

    if( rbTreeRoot != NULL )
       {
        for( displayLevel = 1; displayLevel <= nodeHeight; displayLevel++ )
           {
            rowStartFlag = true;
          
            displayAtTreeLevel( rbTreeRoot, nodeHeight, 
                          displayLevel, workingLevel, &rowStartFlag, ctrlCode );
          
            printf( "\n" );
           }
       }
  
    else
       {
        printf( "\nEmpty Tree - No Display" );
       }
   }

/*
Name: displayValue
Process: displays a tree character value or color letter (R/B)
         after a calculated set of leading spaces
Function input/parameters: character data (char), 
                           node height, working level (int),
                           pointer to row start flag (bool *)
Function output/parameters: updated row start flag (bool *)
Function output/returned: none
Device input/file: none
Device output/monitor: character displayed as specified
Dependencies: toPower, displayChars, printf
*/
void displayValue( char data, int nodeHeight, 
                                          int workingLevel, bool *rowStartFlag )
   {
    int leadingSpaces;
  
    if( *rowStartFlag )
       {
        leadingSpaces = toPower( 2, nodeHeight - workingLevel );

        *rowStartFlag = false;
       }
  
    else
       {
        leadingSpaces = toPower( 2, nodeHeight - workingLevel + 1 ) - 1;
       }

    displayChars( leadingSpaces, SPACE );
  
    printf( "%c", data );         
   }

/*
Name: getMax
Process: finds the maximum between two values, returns
Function input/parameters: two values (int)
Function output/parameters: none
Function output/returned: maximum of two values (int)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
int getMax( int one, int other )
   {
    int max = one;
  
    if( other > max )
       {
        max = other;
       }
  
    return max;
   }

/*
Name: toPower
Process: recursively calculates a base to exponent value 
         for positive integer exponents
Function input/parameters: base, exponent (int)
Function output/parameters: none
Function output/returned: calculated value (int)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
int toPower( int base, int exponent )
   {
    if( exponent > 0 )
       {
        return toPower( base, exponent - 1 ) * base;
       }
  
    return 1;
   }

