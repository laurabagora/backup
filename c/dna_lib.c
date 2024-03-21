// header files
#include "DNA_lib.h"

const char* NUCLEOTIDES = "ACGT";

// functions definition
void initializeRandom()
{
    // Initialization, should only be called once
        // function: srand, time
    srand(time(NULL));
}

char getChoiceYN()
{
    // declare the variables
    char choice;
    // read the choice
        // function: scanf
    scanf(" %c", &choice);
    // convert choice to lower case
        // function: tolower
    choice = tolower(choice);
    // repeat while the choice is invalid
    while (choice != 'y' && choice != 'n')
    {
        // print an error message
            // function: printf
        printf("Invalid option. Please type 'y' to repeat or 'n' to exit: ");
        // read the new option
            // function: scanf
        choice = getchar();
        // convert choice to lower case
            // function: tolower
        choice = tolower(choice);
    }
    // return the choice
    return choice;
}

int getNucleotide(int length)
{
    // generate a random number between 0 and length-1
    int randomIndex = rand() % length;    
    // return the generated index
    return randomIndex;
}

void getDNASequence(char* DNASeq, int length)
{
    for (int i = 0; i < length; i++)
    {
        // generate a random index to select a nucleotide from NUCLEOTIDES
            // function: getNucleotide
        int randomIndex = getNucleotide(strlen(NUCLEOTIDES));
        // set the DNASeq with the random nucleotide
        DNASeq[i] = NUCLEOTIDES[randomIndex];
    }

    // null-terminate the DNA sequence
    DNASeq[length] = '\0';
}

int getShifts()
{
    // declare variables
    char value[4];
    int attempt, shifts = -1;

    // begin loop
    do
    {
        // read the value
            // function: fgets
        fflush(stdin);
        fgets(value, sizeof(value), stdin);
        // check for enter/return
        if (strlen(value) == 1 && value[0] == '\n')
        {
            // return the default value
            shifts = DEFAULT_SHIFTS;
        }
        else
        {
            // convert the input to integer
                // function: atoi
            attempt = atoi(value);
            // check if the number is within the valid range
            if (attempt >= 0 && attempt <= DNA_SEQ_LEN / 2)
            {
                // return the user's choice
                shifts = attempt;
            }
            // otherwise, check if the value is negative
            else if (attempt < 0)
            {
                // print a message
                    // function: printf
                printf("Invalid option. The number of shifts cannot be negative. "
                    "Please try again: ");
            }
            // otherwise, the value is too large
            else
            {
                // print a message
                    // function: printf
                printf("Invalid option. The number of shifts cannot be more than "
                    "half of the DNA sequence's length. Please try again: ");
            }
        }
    }
    // repeat while the value is not valid
    while (shifts == -1);
    // return shifts
    return shifts;
}

int getScoreShifted(const char* shift_seq, int shift_index,
                    const char* baseline_seq, int length)
{
    // declare the variable to store the score
    int score = 0;
    int j = shift_index;

    // for each index in the baseline_seq
    for (int i = 0; i < length - shift_index; i++)
    {
        // if the nucleotide in baseline matches the corresponding nucleotide
        //  in the shifted sequence
        if (baseline_seq[i] == shift_seq[j])
        {
            // count the alignment
            score++;
        }
        // increment the index for the shifted sequence
        j++;
    }
    // return the score
    return score;
}

int getSimilarityScore(const char* seq1, const char* seq2, int num_shifts,
                   int* sequence, int* max_shifts)
{
    // declare the variable to store the score
    int max_score;
    // declare variables to store the score for each sequence
    int score_seq1, score_seq2;

    // create the baseline score (no shift)
        // function: getScoreShifted
    max_score = getScoreShifted(seq1, 0, seq2, strlen(seq1));

    // initialize the sequence with NO_SHIFT
    *sequence = NO_SHIFT;
    // initialize the maximum number of shifts with zero
    *max_shifts = 0;

    // for each possible number of shifts
    for (int shift = 1; shift <= num_shifts; shift++)
    {
        // calculate the score to seq_1 with 'shift' shifts
            // function: getScoreShifted
        score_seq1 = getScoreShifted(seq2, shift, seq1, strlen(seq1));
        // calculate the score to seq_2 with 'shift' shifts
            // function: getScoreShifted
        score_seq2 = getScoreShifted(seq1, shift, seq2, strlen(seq1));

        // check if the score for seq1 is greater than the max_score
        if (score_seq1 > max_score)
        {
            // set the variables to match the new score
            max_score = score_seq1;
            *sequence = SEQ_1;
            *max_shifts = shift;
        }

        // check if the score for seq2 is greater than the max_score
        if (score_seq2 > max_score)
        {
            // set the variables to match the new score
            max_score = score_seq2;
            *sequence = SEQ_2;
            *max_shifts = shift;
        }
    }
    // return the maximum alignment score
    return max_score;
}
