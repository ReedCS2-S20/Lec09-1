	# Alternative olution to Homework 07, Exercise 1
	#
	# CSCI 221 S20
	#

	# This code asks for two integers and then outputs
	# their product. This version uses the shift-based
	# algorithm suggested in Lecture 09-1.
	#

        .data
promptx:	.asciiz "Enter an integer: "
prompty:	.asciiz "Enter another integer: "
feedback1:	.asciiz "Their product is "
feedback2:	.asciiz ".\n"

	.globl main
	.text

main:
	# Key:
	#      $t0 - the product
	#      $t1 - the value of x, the first number
	#      $t2 - the value of y, the second number

	# Method:
	#      I keep shifting y left until it reaches 0.
	#      I keep shifting x right, multiplying it by 2.
	#      Before each pair of shifts, I check the righmost
	#      bit of y to see if the current x should be
	#      included in the product.

begin_main:
	# Get x
	li	$v0, 4		# print(promptx)
	la	$a0, promptx	# 
	syscall			#
	li	$v0, 5		# x = input()
	syscall			#
	move	$t1, $v0	#

	# Get y
	li	$v0, 4		# print(prompty)
	la	$a0, prompty	# 
	syscall			#
	li	$v0, 5		# y = input()
	syscall			#
	move	$t2, $v0	#

multiply:	
	li	$t0, 0		# product = 0    
multiply_loop:	
	beqz	$t2, report     # if y == 0 goto report
	andi    $t3, $t2, 1     # bit = y & 1
	beqz    $t3, skip
	addu	$t0, $t0, $t1   # sum += x
skip:	
	sll     $t1, $t1, 1     # x *= 2
	sra	$t2, $t2, 1     # y /= 2
	b	multiply_loop

report:
	li	$v0, 4		# print(feedback1)
	la	$a0, feedback1	# 
	syscall			#

	li	$v0, 1		# print(product)
	move	$a0, $t0	# 
	syscall			#

	li	$v0, 4		# print(feedback2)
	la	$a0, feedback2	# 
	syscall			#
	
end_main:
	li	$v0, 0		# return 0
	jr	$ra		#
