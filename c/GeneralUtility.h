// Precompiler directives /////////////////////////////////////////////////////

#ifndef GENERAL_UTILITY_H
#define GENERAL_UTILITY_H

// Header files ///////////////////////////////////////////////////////////////

#include "StandardConstants.h"

// global constants ////////////////////////////////////////////////////////////

   // none

// data structures /////////////////////////////////////////////////////////////

   // None

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
int privateCompareStrings( const char *leftStr, const char *rightStr );

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
void privateCopyString( char *dest, const char *source );

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
int privateGetStringLength( const char *str );

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
int privateToPower( int base, int exponent );


#endif		// GENERAL_UTILITY_H



