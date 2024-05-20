#Create a file that generates random numbers
            .data
prompts:    .asciiz "Numbers must be postive and prime, seed is a larger number\n"
input_low:  .asciiz "Multipler: "
input_high: .asciiz "Seed: "
input_gen:  .asciiz "How many of numbers generated: "
input_min:  .asciiz "What is the minimum: "
input_max: .asciiz "What is the maximum: "
value:      .align 2
            .space 100
res:        .asciiz " "
            .text
            .globl main

#prompt user for multiplier number
main:       li $v0, 4
            la $a0, prompts
            syscall
 
            li $v0, 4
            la $a0, input_low
            syscall

            #call for user input for multiplier
            li $v0, 5
            syscall

            move $s0, $v0

            #prompt user for seed number
            li $v0, 4
            la $a0, input_high
            syscall

            #call for user input for low
            li $v0, 5
            syscall

            move $s1, $v0
 
            #prompt user for min
            li $v0, 4
            la $a0, input_min
            syscall

