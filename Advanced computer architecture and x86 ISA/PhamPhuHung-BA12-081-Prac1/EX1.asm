
.data 0 
.global INPUT
    10                              -- Declare a global symbol INPUT with the value 10

.data 32
.global OUTPUT
    0 1                             -- Declare another global symbol OUTPUT with initial values 0 and 1

.program 16                         -- Set the program counter to 16
    li R0, (INPUT)                  -- Load the value of INPUT into register R0
    brz R0, EXIT                    -- If R0 is zero, exit the program
    sub R0, R0, 2                   -- Subtract 2 from R0
    brz R0, EXIT                    -- If the result is zero, exit the program
    add R1, OUTPUT, 2               -- Add 2 to the address of OUTPUT and store the result in R1 (points to the second element of OUTPUT)
    li R2, 0                        -- Initialize R2 with 0
    li R3, 1                        -- Initialize R3 with 1

.loop                               -- Begin a loop labeled .loop
    add R4, R2, R3                  -- Calculate the sum of R2 and R3 and store it in R4 (Fibonacci sequence)
    si (R1), R4                     -- Store the value of R4 in the memory location pointed to by R1 (store the Fibonacci number)
    add R1, R1, 1                   -- Increment R1 to point to the next memory location
    move R2, R3                     -- Move the value of R3 to R2
    move R3, R4                     -- Move the value of R4 to R3
    sub R0, R0, 1                   -- Decrement R0 (loop counter)
    brp R0, LOOP                    -- If R0 is positive, branch back to .loop

.exit                               -- Label for program exit
    exit                            -- Exit the program
.end                                -- End of the program
