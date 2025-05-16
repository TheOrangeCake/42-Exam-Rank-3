The exam date was May 2025 at 42 Lausanne.

----------
## filter
This code passed the exam.

The logic:
- Read from stdin.
- Copy what was read from char *buffer to char *line until '\n' character. (Else block)
- Process the line, print it out, then reset the line pointer line[pos] to 0 so it starts from the start again. (If block)
- Repeat untill read return 0.

NOTE:
  - The code was done in a hacky way to pass the exam. It is not an example of good code so beware of that.
  - the char line[70000] is to avoid malloc. You can implement ft_strjoin if you wish to dynamically allocate memory.
  - I had trouble using buffer[Huge_number] with the grading bot before (the result was correct in my terminal but not when the bot ran it) so this time i used a smaller buffersize.
 
----------
## scanf
This code was implemented by me to revise for the exam. I am confidence in it but by no mean blindy trust it as i didnt get it for my exam.

The logic:
- You get a character from stdin using fget(), check what it is. If it is not what you want, give it back with unget().
- Int `result` to keep track of how many % you successfully assigned. 
- For interger (case x):
    - Check for sign.
    - Transform the string of number to int just like ft_atoi(). The pit fall here is to correctly increase the `result` only in case of successfully assigned something (I used variable int first to keep track of this).
- For string (case s):
    - Very straight forward: You copy the string until hitting any whitespace.
- For character (case c): This one sound easy but actually has a huge pit fall. Check note.
    - You do fget() to get the character then assign.

NOTE:
  - There is a different based on the way the Format string passed through scanf is formatted: `%c%c%c` is different from `%c %c %c`. To manage this, you would need to bypass all whitespace in the format string. In my code, it is in ft_scanf(): bypass whitespace until hitting a %.
  - After that, you would need to skip space in case integer and case string, but NOT in case c.

----------
## nqueens
This code passed the exam. However the exam doesn't require print out the total number of solutions, so adjust the code accordingly. Function atoi() is allowed so don't need to code ft_atoi().

The logic: Using an array, the size of the array represent the column, the value of each cell represent the row. So something like [1, 3 , 0, 2] mean: (format queen(x, y)
  - first queen is at columm 0, row 1 : queen(1, 0).
  - second queen is at columm 1, row 3: queen(3, 1).
  - third queen is at columm 2, row 0: queen(0, 2).
  - fourth queen is at columm 3, row 2: queen(2, 3).
```
[1, 3, 0, 2]
x | x | Q | x
Q | x | x | x
x | x | x | Q
x | Q | x | x
```

- Malloc a board with number passed in the program. Initiate it to -1, Calloc() should work.
- Try to place queen using recursive:
    - Base case when all queens are placed : (queen == max). Print out all the result.
    - Place queen at position. Check if the position is valid. If it is then recursive with queen + 1. Else just continue.
    - Check queen:
        - board[i] == board[queen]; mean to check horizontally. 
          Remember i is column, you increase i every loop to check where the queen is in that column. Board[i] = 2 then the queen is at row 2.
          Board[queen] mean checking the current column. Board[queen] = 2 means the queen we are checking is in row 2.
        - The other condition is to check past diagonals. I am tired so do the simulation yourself. It helps a alot to draw it out.

----------
Good luck on your exam!
