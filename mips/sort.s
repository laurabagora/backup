#Create a file sorts a given input
            .data
prompts:    .asciiz "Reads in a set of numbers and bubble sorts them\n"
input_num:  .asciiz "How many numbers: "
input_list: .asciiz "Number: "
error_mes:  .asciiz "Error: That number is not in the range 1-10\n"
output:     .asciiz "The sorted array: "
ends:       .asciiz "end"
array:      .align 2
            .space 40
res:        .asciiz ", "
            .text
            .globl main

#prompt user for what the program does and calls to procedures
main:       li $v0, 4
            la $a0, prompts
            syscall
          
            # call to readnums procedure
            jal ReadNums
       
            # count is already loaded into s1
            # call to bsort function
            jal Bsort

            # count is already loaded into s1
            # call to printnums function
            jal printNums
   
# reads in numbers
ReadNums:  
            # load $s0 register with 10 memories
            # i used v0 as a perameter instead of s0
            la $v0, array
            # count is going to be loaded soon

            # call in input numbers
            li $v0, 4
            la $a0, input_num
            syscall

            #call for user input for numbers
            li $v0, 5
            syscall

            # count is now returned in s1
            move $s1, $v0

            # check if input is less than 1 
            blt $s1, 1, error

            #check if input is greater than 10
            bgt $s1, 10, error

            #load array
            # set increment count and index to zero
            add $s2, $zero, $zero
            add $s3, $zero, $zero

            # go to loop
            j arrLoop

   arrLoop: 
            #goes to count number
            beq $s2, $s1, endNum

            # get user input
            la $v0, 4
            la $a0, input_list
            syscall 

            li $v0, 5
            syscall
 
            #load array with user input
            sw $v0, array($s3)

            # add 4 to index from the 4 count
            addi $s3, $s3, 4
 
            #increment count
            addi $s2, $s2, 1
     
            # call back to loop
            j arrLoop

    # error message  
    error: 
            # print error message
            li $v0, 4
            la $a0, error_mes
            syscall

            # jump back to readNums
            jal ReadNums 

   # end of readNums
   endNum:  
          # this just ends this procedure to go to the next in main
          move $t0, $t6

# bubble sort the array
Bsort:

    # load array to $s2
    # i used s2 instead of s0
    la $s2, array  
    # the count is already stored into s1

    # initalize increment (i = 0)
    add $t0, $zero, $zero

    # create first loop (i=0, i<n, i++)
    loop1:
           # check if count equals increment (i<n)
           beq $t0, $s1, ending

           # initalize second loops (j=0) and (n-1-i)
           add $t1, $zero, $zero

           # get (n-1)-i
           addi $t3, $t2, -1
           sub $t2, $s1, $t0

    # go through loop2 (j=0, j < n-1-i, j++)
    loop2:
           #loop to check if (j<n-i-1)
           beq $t1, $t3, next

           # load array[j]
           lw $t7, 0($s2)

           # load array[j+1]
           addi $s2, $s2, 4
           lw $t8, 0($s2)

           # check if array[j] > array[j+1]
           bgt $t7, $t8, swap

           # if it not greater than the no swap
           # increment (j++)
           addi $t1, $t1, 1

           # call back to loop2
           j loop2

   next:
           # go back to loop 1 and increment
           add $t0, $t0, 1
           j loop1

    # if it is greater, then swap
    swap:
           # subtract 4 to get previous index in t8
           addi $s2, $s2, -4
           sw $t8, 0($s2)

           # store into original index of t7
           # by adding 4 to get the next index
           addi $s2, $s2, 4
           sw $t7, 0($s2)

   ending:
          # this just ends procedure
          move $t0, $t6

# print numbers from array
printNums:
     # prints output array prompt
     li $v0, 4
     la $a0, output
     syscall
          
     # set increment before loop
     add $t1, $zero, $zero

     # load array into $s2
     # i used s2 instead of s0
     la $s2, array
     # count is already loaded into s1

     LoopP: 
            # check if incrememnt equals count
            beq $t1, $s1, exit
 
            # gets the seperate indexes in array
            lw $s6, 0($s2)
            move $a0, $s6

            # print integers from array
            li $v0, 1
            syscall
  
            #print commas seperating integers
            li $v0, 4
            la $a0, res
            syscall

            #reincrement count
            addi $t1, $t1, 1

            # reincrament array count
            addi $s2, $s2, 4

            # call bacck to loop
            j LoopP

#exits the program
exit:       
            #print end for end of array
            li $v0, 4
            la $a0, ends
            syscall

            #exits
            li $v0, 10
            syscall