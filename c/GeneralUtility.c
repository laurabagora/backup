#include "GeneralUtility.h"

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
Dependencies: privateGetStringLength
*/
int privateCompareStrings( const char *leftStr, const char *rightStr )
{
  int index = 0, left, right, min;

  // get the left and right string length
  left = privateGetStringLength( leftStr );
  right = privateGetStringLength( rightStr );

  // check if the index is in the bounds
  while (index < left && index < right)
  {
    // if so then compare strings and make sure left string is not 0
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
Process: copies string character for character up to NULL_CHAR of source string
Function input/parameters: source string to be copied (const char *)
Function output/parameters: destination string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
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
Name: privateGetStringLength
Process: finds length of string
Function input/parameters: c-style string (const char *)
Function output/parameters: none
Function output/returned: calculated length of string (int)
Device input/ ---: none
Device output/ ---: none
Dependencies: none
*/
int privateGetStringLength( const char *str )
{
  int index = 0;
  while( str[ index ] != NULL_CHAR )
   {
    index++;
   }
  return index;
}

/*
Name: privateToPower
Process: recursively calculates result of given base to given exponent,
         for exponents >= 0
Function input/parameters: base and exponent (int)
Function output/parameters: none
Function output/returned: result of specified calculations (int)
Device input/---: none
Device output/---: none
Dependencies: toPower (recursively)
*/
int privateToPower( int base, int exponent )
{
   if(exponent >= 0)
   {
    return (privateToPower(base, exponent - 1) * base);
   }
   return 1;
}