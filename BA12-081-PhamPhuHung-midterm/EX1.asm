.data 0
.global a
	1 2 3 4

.data 16
.global b
	5 6 7 8

.data 32
.global c
	0

.alias n 4 
.program 100
	li R1, a
	li R2, b
	li R3, c

.boucle
    add R6, R4, R2
    li R7, (R4)
	li R8, (R6)
    mult R9, R7, R8
	add R10, R9, R10

.loop
    add R4, R4, 1			
	sub R5, R4, n
	brnz R5, boucle

	li R11, 0
	sub R12, R10, R11  
	brp R12, SKIPRELU 
	li R10, 0

.SKIPRELU
    si (R3), R10

	li R10, 0
    li R4, 0        

.exit
	exit
.end
