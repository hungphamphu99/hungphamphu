;bubble sort

.data 0                 -- Initialize the data segment
.global INPUT             -- Declare the symbol INPUT as global
    3 8 5 2 9 6             -- Set an alias LEN with the value 6, likely representing the length of the array

.alias LEN 6             -- Set an alias LEN with the value 6, likely representing the length of the array

.program 100               -- Set the program counter to 100 
    sub R0, (LEN), 1         -- Subtract 1 from LEN and store the result in R0, likely initializing a loop counter for the outer loop


.WHILE                     -- Begin a while loop
    li R1, INPUT           -- Load the base address of the array into register R1

.FOR                        -- Begin a for loop
    add R3, R1, 0           -- Calculate the address of the current element in the array and store it in R3
    add R4, R3, 1           -- Calculate the address of the next element in the array and store it in R4

    li R5, (R3)             -- Load the value of the current element into register R5
    li R6, (R4)             -- Load the value of the next element into register R6

    sub R7, R5, R6           -- Compare the current and next elements and store the result in R7
    brn R7, NOSWAP          -- Branch to NOSWAP if the current element is less than or equal to the next element

    si (R3), R6             -- Swap the current and next elements in the array
    si (R4), R5

.NOSWAP                     -- Label for the branch destination if no swapping occurs
    add R1, R1, 1           -- Move to the next element in the array

    sub R2, R0, R1          -- Calculate the number of iterations left in the inner loop and store the result in R2
    brnz R2, FOR            -- Branch back to the beginning of the inner loop if there are more iterations left

    sub R0, R0, 1           -- Decrement the outer loop counter
    brnz R0, WHILE          -- Branch back to the beginning of the outer loop if there are more iterations left

.EXIT                       -- Label indicating the end of the program
    exit                    -- Exit the program
.end                        -- End of the program