
        .data
request_digit:   .asciiz "Enter a digit: "
	.globl main
	.text
main:
  sw    $ra,-4($sp)
  sw    $fp,-8($sp)
  move  $fp,$sp
  addiu $sp,$sp,-32

  li    $v0,4
  la    $a0,request_digit
  syscall
  li    $v0,5
  syscall
  move  $t0,$v0

  li    $v0,4
  la    $a0,request_digit
  syscall
  li    $v0,5
  syscall
  move  $a1,$v0

  li    $v0,4
  la    $a0,request_digit
  syscall
  li    $v0,5
  syscall
  move  $a2,$v0

  li    $v0,4
  la    $a0,request_digit
  syscall
  li    $v0,5
  syscall
  move  $a3,$v0

  move  $a0,$t0
  jal   four_digits
  move  $a0,$v0
  li    $v0,1
  syscall

  li    $v0,0
  addiu $sp,$sp,32
  lw    $fp,-8($sp)
  lw    $ra,-4($sp)
  jr    $ra

two_digits:
  sll   $t0,$a0,1
  sll   $t1,$a0,3
  addu  $v0,$t1,$t0
  addu  $v0,$v0,$a1
  jr    $ra

times100:
  sll   $v0,$a0,2
  sll   $a0,$v0,3
  addu  $v0,$v0,$a0
  sll   $a0,$a0,1
  addu  $v0,$v0,$a0
  jr    $ra
	
four_digits:
  sw    $ra,-4($sp)
  sw    $fp,-8($sp)
  move  $fp,$sp
  addiu $sp,$sp,-32
  sw    $a2,-16($fp)
  sw    $a3,-20($fp)
  jal   two_digits
  sw    $v0,-12($fp)
  lw    $a0,-16($fp)
  lw    $a1,-20($fp)
  jal   two_digits
  lw    $a0,-12($fp)
  sw    $v0,-12($fp)
  jal   times100
  lw    $t1,-12($fp)
  addu  $v0,$v0,$t1
  addiu $sp,$sp,32
  lw    $fp,-8($sp)
  lw    $ra,-4($sp)
  jr    $ra
