Push Swap: Optimal Sorting with Two Stacks

📜 Description

The Push Swap project is a classic algorithmic challenge within the 42 curriculum. The primary goal is to sort a stack of unique integers (Stack A) using the minimum possible number of operations, moving values between Stack A and an auxiliary Stack B.

The challenge lies in optimizing the sorting algorithm to achieve the lowest possible move count, often measured against established thresholds (e.g., for 100 numbers, the target is usually < 1500 moves).

Overview

This program:

Parses a list of unique integers provided as command-line arguments, handling syntax errors, duplicate checks, and numerical overflow.

Initializes Stack A with the input numbers.

Executes a custom sorting algorithm (Radix Sort) to move the numbers from Stack A to Stack B and back, printing the sequence of required operations (e.g., ra, pb, sa).

Terminates, leaving Stack A sorted.

🛠️ Instructions

Compilation

The project uses the standard compilation process for C projects, linking against the libft library. Ensure your libft repository is compiled and present in the project root.

To compile the push_swap executable:

make
cc -Wall -Wextra -Werror -o push_swap *.c moves/*.c -I libft -I . -L libft -l ft


Execution

The program accepts one or more integer arguments.

1. Basic Sorting

Run the program with a list of numbers. The output is the sequence of moves.

./push_swap 2 4 1 5 3 
# Example output: pb ra ra pb ra ra pa ra pa ra


2. Error Handling

The program must terminate with Error (printed to stderr) and a non-zero exit code on invalid input:

./push_swap 1 2 3 1
# Output: Error


3. Testing Efficiency (Using the Checker)

To verify the output moves are correct and to count their total, pipe the push_swap output to the checker program:

# Verify correctness and count moves for 5 numbers:
./push_swap 2 4 1 5 3 | ./checker_linux 2 4 1 5 3
# Output: OK

# Count moves for a large list (requires the test runner script or manual counting):
./push_swap $(seq 1 100 | shuf) | wc -l 
# (This counts the number of lines generated)


📚 Resources

Classic References

Radix Sort: The primary large-scale sorting algorithm used. Understanding Least Significant Bit (LSB) logic is essential.

Linked Lists (Doubly/Circular): Understanding how to manage next and prev pointers for optimal stack operations (ra, rra).

Indexing/Ranking: The method used to convert arbitrary input integers (including negatives) into a normalized, zero-based index range [0, size-1] so that the bitwise Radix Sort can function correctly.

AI Usage Disclosure

This project utilized a Large Language Model (LLM) built by Google (Gemini) for the following specific tasks:

Debugging Assistance: The LLM was used to trace and identify critical logical errors within the radix_sort function, specifically correcting an incorrect rra loop and ensuring stable sorting based on 0-based indexing.

Test Environment Generation: The LLM generated the comprehensive push_swap_tester.py script to automate error handling, efficiency testing, and random input generation, which significantly accelerated the testing and validation process.

Code Review/Refactoring: The LLM reviewed helper functions (move_min_to_top, rotate, reverse) to confirm doubly linked list pointer management was correct and Norminette-compliant.
