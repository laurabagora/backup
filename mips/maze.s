#Create maze
	.data
GRID_WIDTH:	.word	80		# need to add 1 to print as string
GRID_HEIGHT:	.word	23
GRID_SIZE:	.word	1840		# because I can't precalculate it in				# MIPS like I could in MASM
NORTH:		.word	0
EAST:		.word   1
SOUTH:		.word	2
WEST:		.word	3
RGEN:		.word	1140671485	# a sufficiently large prime for rand
POUND:		.byte	35		# the '#' character
SPACE:		.byte	32		# the ' ' character
NEWLINE:	.byte	10		# the newline character
rsdPrompt:	.asciiz "Enter a seed number (1073741824 - 2147483646): "
smErr1:		.asciiz "That number is too small, try again: "
bgErr:		.asciiz "That number is too large, try again: "
newLine:	.asciiz "\n"
grid:	.space	1841		# ((79 + 1) * 23) + 1 bytes reserved for grid
rSeed:	.word	0		# a seed for generating a random number
	.text
	.globl main
main:
	sw	$ra, 0($sp)	# save the return address
	jal	srand		# get a random seed
	jal	ResetGrid	# reset the grid to '#'s
	li	$t0, 1		# set up for start of generation at (1,1)
	sw	$t0, -4($sp)	# push first param
	sw	$t0, -8($sp) 	# push second param
	jal	Visit		# start the recursive generation
	jal	PrintGrid	# display the grid
	lw	$ra, 0($sp)	# restor the return address
	jr	$ra		# exit the program

ResetGrid:
	
	# save the registers
	sw	$s0, -4($sp)	# $s0 will be the loop counter
	sw	$s1, -8($sp)	# $s1 will hold the array bound
	sw	$s2, -12($sp)	# $s2 will be the grid base address
	sw	$s3, -16($sp)	# $s3 will hold the character
	sw	$s4, -20($sp)	# $s4 will hold the grid width
	sw      $s5, -24($sp)   # $s5 will hold the newline character
	sw	$s6, -28($sp)	# $s6 used for calculations
	
	# load the working values
	li	$s0, 1		# initialize the counter
	lw	$s1, GRID_SIZE	# initialize the array bound
	la	$s2, grid	# get the base address
	lb	$s3, POUND	# store the '#' ASCII code
	lw	$s4, GRID_WIDTH # store the grid width
	lb	$s5, NEWLINE	# store the newline ASCII code
  
ResetLoop:
	sb	$s3, 0($s2)	# put a '#' in the grid
	addi	$s0, $s0, 1	# increment the loop counter
	addi	$s2, $s2, 1	# point at next char position
	div	$s0, $s4	# divide the counter by grid width
	mfhi	$s6		# get remainder in calculation register
	bnez	$s6, NoNewLine	# keep going
	
	sb	$s5, 0($s2)     # put a newline in the grid
	addi	$s0, $s0, 1	# increment the loop counter
	addi	$s2, $s2, 1	# point at next char position
	
NoNewLine:
	blt	$s0, $s1, ResetLoop	# if less than end, loop again
	
	# when we fall out of the loop, restore the registers and return
	lw	$s0, -4($sp)	
	lw	$s1, -8($sp)	
	lw	$s2, -12($sp)	
	lw	$s3, -16($sp)	
	lw	$s4, -20($sp)	
	lw      $s5, -24($sp)   
	lw	$s6, -28($sp)	
	jr	$ra		# return
	
srand:
	# For this function, we only need to preserve 3 registers.  We use
	# $a0 and $v0 for I/0, and we use $s0 as a scratch register.

	# save the registers
	sw	$v0, -4($sp)	# $v0 will be the service code
	sw	$a0, -8($sp)	# $a0 will point to the grid string
	sw	$s0, -12($sp)	# $s0 will hold the input for testing
	
	# prompt for a random seed and get the value
	la	$a0, rsdPrompt
	li	$v0, 4		# print_string
	syscall

input10:
	li	$v0, 5		# read_int
	syscall
	li	$s0, 1073741823		# put 2147483646 in t0 for comparison
	bgtu	$v0, $s0, input11	# input bigger than 1073741823?
	la	$a0, smErr1	# no, point to error and
	li	$v0, 4		# print_string
	syscall
	j	input10		# try again

input11:
	li	$s0, 2147483646	# upper bound in register t0 for comparison
	bleu	$v0, $s0, input12	# less than or equal 2147483646?
	la	$a0, bgErr	# no, point to error and
	li	$v0, 4		# print_string
	syscall
	j	input10		# try again

input12:	
	# number is good, save and move on
	sw	$v0, rSeed
	
	# restore the registers
	lw	$v0, -4($sp)	
	lw	$a0, -8($sp)	
	lw	$s0, -12($sp)

	jr	$ra		# return
	
rand:
	# For this function, we only need to preserve 3 registers.  We use
	# $s0 - $s2 as scratch registers.

	# save the registers
	sw	$s0, -16($sp)	# $s0 random
	sw	$s1, -20($sp)	# $s1 will hold generator and min
	sw	$s2, -24($sp)	# $s2 will hold new seed and max
	
	# linear congruence
	lw	$s1, RGEN	# load the generator
	lw	$s2, rSeed	# last seed
	multu	$s1, $s2	# result goes in hi/lo registers
	mfhi	$s0		# lo result is new seed
	mflo	$s2		# hi result is new random
	sw	$s2, rSeed

	# fit the random into the range
	lw	$s2, -12($sp)	# get the max
	lw	$s1, -8($sp)    # get the min
	sub	$s2, $s2, $s1	# s2 is now range (max - min)
	addiu	$s2, $s2, 1	# increment the range
	divu	$s0, $s2	# remainder is in hi register
	mfhi	$s0		# get it back
	addu	$s0, $s0, $s1	# add the minimum to put it in range
	sw	$s0, -4($sp)	# store the random in the return

	# restore the registers
	lw	$s0, -16($sp)	
	lw	$s1, -20($sp)	
	lw	$s2, -24($sp)

	jr	$ra		# return

XYToIndex:
	# For this function, we only need to preserve 3 registers.  We use
	# $s0 - $s2 as scratch registers.
	
	# save the registers
	sw	$s0, -16($sp)	# $s0 will hold grid width
	sw	$s1, -20($sp)	# $s1 will hold x
	sw	$s2, -24($sp)	# $s2 will hold y
  
  	# get the values for our calculation
  	lw	$s0, GRID_WIDTH	# load the grid width
  	lw	$s1, -8($sp)	# load x
  	lw	$s2, -12($sp)	# load y
  	
  	# calculate and store in return
  	multu	$s0, $s2	# result goes in hi/lo registers
  	mflo	$s0		# hopefully only need LO
  	addu	$s0, $s0, $s1	# add x
  	sw	$s0, -4($sp)	# store result in return

  	# restore the registers
	lw	$s0, -16($sp)	
	lw	$s1, -20($sp)	
	lw	$s2, -24($sp)

	jr	$ra		# return

IsInBounds:
	# For this function, we only need to preserve 3 registers.  We use
	# $s0 - $s2 as scratch registers.
	
	# save the registers
	sw	$s0, -16($sp)	# $s0 will hold bounds for testing and return
	sw	$s1, -20($sp)	# $s1 will hold x
	sw	$s2, -24($sp)	# $s2 will hold y
  
  	# get the values for our calculation
  	lw	$s1, -8($sp)	# load x
  	lw	$s2, -12($sp)	# load y
  	
  	# test width
  	lw	$s0, GRID_WIDTH		# load the grid width
  	bgtu	$s1, $s0, OutOfBounds	# catches both >= grid width and < 0
  	
  	# test height
  	lw	$s0, GRID_HEIGHT	# load the grid height
  	bgeu	$s2, $s0, OutOfBounds	# catches both >= grid height and < 0
  	
  	li	$s0, 1		# neither failed, so set true (1)
  	sw	$s0, -4($sp)
  	j	EndBounds
  	
OutOfBounds:
	li	$s0, 0		# something failed, so set false (0)
	sw	$s0, -4($sp)

EndBounds:
  	# restore the registers
	lw	$s0, -16($sp)	
	lw	$s1, -20($sp)	
	lw	$s2, -24($sp)

	jr	$ra		# return

Visit:
	# first, save the old frame pointer and return address on the stack
	# and point the frame pointer to the bottom of the frame. At this
	# point, offsets are relative to the stack pointer, not the frame
	# pointer.
	# TODO: Fill in the code to match the comments.
        sw $fp, -12($sp)      # save the old frame pointer
        sw $ra, -16($sp)      # save the return address
        move $fp, $sp         # copy the stack pointer to the frame pointer

	# now we can save any registers we need. The offsets are the same for
	# both the stack and frame pointers (use the $FP column in the stack
	# frame chart in the project document).
	# TODO: store the registers noted in the stack frame chart
	#	to the appropriate locations.
        sw $s0, -20($sp)      # will hold current x or scratch
        sw $s1, -24($sp)      # will hold current y
        sw $s2, -28($sp)      # hold grid value
        sw $s3, -32($sp)      # hold space value
        sw $s4, -36($sp)      # hold pound value
        sw $s5, -40($sp)      # hold value for future use
        sw $s6, -44($sp)      # hold value for future use     
        sw $s7, -48($sp)      # hold value for future use  
	sw $t0, -52($sp)      # $t0 will be used to hold x2
	sw $t1, -56($sp)      # $t1 will be used to hold y2
	sw $t2, -60($sp)      # $t2 will be used to hold dx
	sw $t3, -64($sp)      # $t3 will be used to hold dy
	
  	# ok, before things get too complicated, let's set the current grid
  	# location to ' '.  These registers have just been saved to the 
  	# stack frame so I can overwrite them.  Note that I could use
  	# either $sp or $fp as they are currently pointing to the same
  	# place.
  	lw	$s0, -4($sp)	# load x into $s0
  	lw	$s1, -8($sp)	# load y into $s1
  	lb	$s4, SPACE	# preload a blank character

	# Create an local array containing the 4 directions by loading the
	# direction into $s5 and then storing it into the appropiate location
	# in the stack frome.  Still using either $sp or $fp with the same
	# offsets.
	# TODO: Store $s5 to the appropriate location for each direction
	lw	$s5, NORTH
	sw $s5, -68($sp)	 		# North goes into the local array index 0
	lw	$s5, EAST
	sw $s5, -72($sp)			# East goes into the local array index 1
	lw	$s5, SOUTH
	sw $s5, -76($sp)			# South goes into the local array index 2
	lw	$s5, WEST
	sw $s5, -80($sp)			# West goes into the local array index 3
				
	# TODO: Finally, set the stack pointer to the top of the stack frame.
	#	After this, items in the stack frame can be accessed by the
	#	stack pointer with positive offsets or the frame pointer
	#	with negative offsets.
        addiu   $sp, -84        # point to the top of the stack frame

	# Set my current location to be an empty passage.
  	#   grid[ XYToIndex(x,y) ] = ' ';
	sw	$s0, -8($sp)	# push x above current registers on stack
	sw	$s1, -12($sp)   # push y
	jal	XYToIndex
	lw	$s2, -4($sp)	# put return in $s2
	la	$s3, grid	# put base address in $s3
	addu	$s3, $s3, $s2	# add offset into grid
	sb	$s4, 0($s3)	# put a blank at the location

	# Shuffle the local array
	li	$s6, 0		# initialize the loop
	li	$s7, 4		# set loop bound
	
ShuffleLoop:
	bgeu	$s6, $s7, VisitLoopEntry	#when done shuffling, go visit

	# pick a random direction
	li	$s5, 3		# set up to do a random 0 to 3
	sw	$0, -8($sp)	# min param set
	sw	$s5, -12($sp)	# max param set
	jal	rand		# get the random
	lw	$s2, -4($sp)	# and put it in $s2
	
	# set up to swap directions
	la	$s3, 4($sp)	# base address of array in $s3
	la	$s1, 4($sp)     # and in #s1
	li	$s5, 4		# multiply by 4 for offset
	mult	$s2, $s5
	mflo	$s2		# get the result back in $s2
	addu	$s3, $s3, $s2	# add offset to base
	mult	$s6, $s5
	mflo	$s5		# get loopcount offest back in $s5
	addu	$s1, $s1, $s5	# add offset to base
	
	# now $s3 and $s7 point into the array and we swap values
	lw	$s5, 0($s1)
	lw	$s2, 0($s3)
	sw	$s5, 0($s3)
	sw	$s2, 0($s1)
	
	# next loop iteration
	addi	$s6, $s6, 1
  	j	ShuffleLoop

VisitLoopEntry:
	# now we visit; reset the loop counter
	li	$s6, 0

VisitLoop:
	li	$s2, 4	# loop bound
	bgeu	$s6, $s2, VisitReturn	# when done, clean up and return

	# get the direction
	li	$s5, 4		# offset by 4s to get direction
	mult	$s6, $s5
	mflo	$s5
	move	$s3, $sp	# base address of array in $s3
	addiu	$s3, $s3, 4	#  "     "      "   "    "  "
	addu	$s3, $s3, $s5
	lw	$s7, 0($s3)	# dir[i] now in $s7

	# $s2 and $s5 will be dx and dy respectively
	li	$s2, 0		#initialize to 0
	
	# use $s5 to hold the directions and test
	lw	$s5, NORTH
	beq	$s7, $s5, SetNorth
	lw	$s5, EAST
	beq	$s7, $s5, SetEast
	lw	$s5, SOUTH
	beq	$s7, $s5, SetSouth

	# not the other three directions, so set West
	li	$s2, -1
	li	$s5, 0
	j	EndDirCase

SetNorth:
	li	$s5, -1
	j	EndDirCase

SetEast:
	li	$s2, 1
	li	$s5, 0
	j	EndDirCase

SetSouth:
	li	$s5, 1

EndDirCase:
	# reload $s1 and $s0 in case we used them for something else
  	lw	$s0, -4($fp)	# load x into $s0
  	lw	$s1, -8($fp)	# load y into $s1

	move	$t2, $s2	# save dx and dy
	move	$t3, $s5
	
	sll	$s2, $s2, 1	# double it;
	addu	$t0, $s2, $s0	# add x, store x2 in $t0
	sll	$s5, $s5, 1	# double it
	addu	$t1, $s5, $s1	# add y, store y2 in $t1
	
	#---------------------------------------------------------
	# nested if statements to see if we recursively call Visit
	#---------------------------------------------------------
	# Is it in bounds ?
	sw	$t0, -8($sp)	# x param = x2
	sw	$t1, -12($sp)	# y param = y2
	jal	IsInBounds	# get the result
	lw	$s2, -4($sp)	# and put it in $s2
	beqz	$s2, NextVisitLoop	# not in bounds so go to next

	# Is it visited already?
	sw	$t0, -8($sp)	# x param = x2
	sw	$t1, -12($sp)	# y param = y2
	jal	XYToIndex	# get the result
	lw	$s2, -4($sp)	# and put it in $s2
	la	$s3, grid	# get the base address of the grid
	addu	$s3, $s3, $s2	# add the offset
	lb	$s5, 0($s3)	# get the byte there
	lb	$s2, POUND	# get a byte to compare
	bne	$s2, $s5, NextVisitLoop	# visited so go to next

	# Not visited, so knock down the wall
	sub	$s5, $t1, $t3	# subtract dy from y2
	sub	$s2, $t0, $t2	# subtract dx from x2
	
	sw	$s2, -8($sp)	# push x2-dx
	sw	$s5, -12($sp)	# push y2-dy
	jal	XYToIndex	# get the offset
	lw	$s7, -4($sp)	# and put it in $s7
	la	$s3, grid	# get base address
	addu	$s3, $s3, $s7	# add them together
	sb	$s4, 0($s3)	# store a blank there
	
	# Call Visit recursively
	# TODO: Uncomment these only AFTER you are sure the rest of Visit works.
	sw	$t0, -4($sp)	# push x2
	sw	$t1, -8($sp)	# push y2
	jal	Visit

NextVisitLoop:
	addiu	$s6, $s6, 1	# increment loop counter
	j	VisitLoop
    
VisitReturn:
	# TODO: Set the stack pointer back to where the frame pointer is.
	#	to the appropriate locations.
        move $sp, $fp         # point to the beginning of the stack frame
        lw $s0, -20($sp)      # will hold current x or scratch
        lw $s1, -24($sp)      # will hold current y
        lw $s2, -28($sp)      # hold grid value
        lw $s3, -32($sp)      # hold space value
        lw $s4, -36($sp)      # hold pound value
        lw $s5, -40($sp)      # hold value for future use
        lw $s6, -44($sp)      # hold value for future use     
        lw $s7, -48($sp)      # hold value for future use  
	lw $t0, -52($sp)      # $t0 will be used to hold x2
	lw $t1, -56($sp)      # $t1 will be used to hold y2
	lw $t2, -60($sp)      # $t2 will be used to hold dx
	lw $t3, -64($sp)      # $t3 will be used to hold dy

	# TODO: including the old frame pointer and the return address	
        lw   $fp, -12($sp)    # restore the old frame pointer
        lw   $ra, -16($sp)    # restore the return address 

	# and now we can return
	jr	$ra
	
PrintGrid:

	# save the registers
	sw	$v0, -4($sp)	# $v0 will be the service code
	sw	$a0, -8($sp)	# $a0 will point to the grid string
	
	# load the values and print
	li	$v0, 4		# print service
	la	$a0, grid	# string to print
	syscall

	# restore the registers
	lw	$v0, -4($sp)	
	lw	$a0, -8($sp)	

	jr	$ra		# return
