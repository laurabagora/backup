#include "DNA_lib.h"

int main()
{
    // initialization
        // initialize random number generator
            // function: initializeRandom
    initializeRandom();

        // declare necessary variables
    char seq1[DNA_SEQ_LEN + 1]; // +1 for null-terminator
    char seq2[DNA_SEQ_LEN + 1];
    int shifts, sequence, max_shifts, similarityScore;

        // print program title
            // function: printf
    printf("\nDNA Similarity Score Calculator\n");
    printf("===============================\n\n");

        // declare the variable to control the loop
    char continueFlag;
    
    // processing
        // begin program loop
    do
    {
        // generate DNA sequence 1
            // function: getDNASequence
        getDNASequence(seq1, DNA_SEQ_LEN);
        //char seq1[] = "ACTGATCAC";

        // print the sequence
            // function: puts
        printf("Sequence 1: %s\n", seq1);
        
        // generate DNA sequence 2
            // function: getDNASequence
        getDNASequence(seq2, DNA_SEQ_LEN);
        //char seq2[] = "TTAGCTCGA";

        // print the sequence
            // function: puts
        printf("Sequence 2: %s\n\n", seq2);

        // ask the user for the number of shifts or if the system should decide
            // function: printf
        printf("How many shifts would you like to try (hit enter for default)? "
            );
        // read the user's option
            // function: getShifts
        shifts = getShifts();

        // print the number of shifts
            // function: printf
        printf("Calculating the DNA Similarity Score using a maximum of "
            "%d shifts...\n\n", shifts);
        // calculate similarity score
            // function: getSimilarityScore
        similarityScore = getSimilarityScore(seq1, seq2, shifts, 
                                            &sequence, &max_shifts);

        // print the result to the user
            // function: printf
        printf("Similarity Score: %d\n", similarityScore);

        // check if the comparison with no shifts results in the maximum score
        if (sequence == NO_SHIFT)
        {
            // print a message
                // function: printf
            printf("No shift results in the maximum alignment score.\n");
        }
        // otherwise, inform the number of shifts and the shifted sequence
        else
        {
            // print a message
                // funciton: printf
            printf("The maximum alignment score is obtained by shifting "
                "Sequence %d by %d shifts.\n", sequence, max_shifts);
        }

        // ask if the user wants to generate a new sequence
        printf("\nGenerate new sequences [y|n]? ");
        // read the user's choice
            // function: getChoiceYN
        continueFlag = getChoiceYN();
    }
    // repeat if the user wants to generate new sequences
    while (continueFlag == 'y');

    // end program
        // print a message
            // function: printf
    printf("Program ended.\n");
        // return success
    return 0;
}