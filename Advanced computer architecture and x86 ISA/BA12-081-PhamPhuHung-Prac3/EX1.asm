.data 96
.global a 
	1 1 1 1 1 1 1 1 
	2 2 2 2 2 2 2 2 
	3 3 3 3 3 3 3 3
	4 4 4 4 4 4 4 4 
	5 5 5 5 5 5 5 5    
	6 6 6 6 6 6 6 6
	7 7 7 7 7 7 7 7  
	8 8 8 8 8 8 8 8
.global b
	1 1 1 1 1 1 1 1 
	2 2 2 2 2 2 2 2  
	3 3 3 3 3 3 3 3
	4 4 4 4 4 4 4 4  
	5 5 5 5 5 5 5 5 
	6 6 6 6 6 6 6 6
	7 7 7 7 7 7 7 7 
	8 8 8 8 8 8 8 8  
.global c
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
.alias n 8

.program 100
	li R1, a
	li R2, b
	li R3, c
    
.boucle1
    mult R11, R4, n          -- i * len

.boucle2
    add R15, R11, R5        -- i * len + j (c[i][j])
    add R24, R15, c

.boucle3
    
	mult R12, R6, n         -- k * len
    add R14, R11, R6        -- i * len + k  (a[i][k])
    add R13, R12, R5        -- k * len + j  (b[k][j])
    add R18, R14, a
    add R19, R13, b

    li R20, (R18)       
    li R21, (R19)
    mult R22, R20, R21      --     c[i][j]   +=   a[i][k] * b[k][j]
    add R23, R23, R22

.main
    add R6, R6, 1                     -- k
    sub R10, R6, n
    brnz R10, boucle3
    si (R24),R23                    -- 
    li R23,0
    li R6, 0

    add R5, R5, 1                   -- j
    sub R9, R5, n
    brnz R9, boucle2
    li R5, 0                                                         

    add R4, R4, 1                   -- i
    sub R8, R4, n
    brnz R8, boucle1
    
    exit
.end
