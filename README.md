# Console Snowflake Animation

This program creates a console-based animation that simulates falling snowflakes using pointers and dynamic memory in C++. The snowflakes are represented by `*` symbols that move downward frame by frame, with new snowflakes being added at the top.

## Key Features

- Demonstrates the use of pointers in C++ for dynamic memory management.
- Simulates snowflake movement in a grid using a dynamic array of strings.
- Implements a console animation with periodic updates.
- A great example to showcase the difference between C++ and other languages in managing memory and pointers.

## How It Works

1. The program initializes a grid of `rows x columns` (dimensions specified by the user).
2. Snowflakes (`*`) are randomly placed on the grid.
3. At each iteration:
   - Snowflake pointers are shifted downward by one row.
   - The bottom row is deleted and memory is reallocated for a new top row.
   - The new top row is populated with random snowflakes.
4. The animation continues indefinitely, updating every 500 milliseconds.