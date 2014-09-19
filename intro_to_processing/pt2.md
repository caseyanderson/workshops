# An Introduction to Processing (pt. 2)

Note: anything in between carrots (`<` to `>`) denotes user input.

*Quick reference links*

[Processing](http://processing.org/)

[OpenProcessing](http://www.openprocessing.org/)

## data types

Boolean = true or false

Float = a number with a decimal point, ex: 0.4, 4000.0, -0.9

Integer = a whole number, ex: -12, 2, 5000

## variables

Variables allow you to store data, as well as reuse the same data through a program. Every variable needs a name and a value. Additionally, you cannot use a variable until it is declared, which saves the data type and the corresponding name.

*for example:*
```
int x;
float y;
boolean b;

x = 50;
y = 0.4;
b = true;
```

You can print the values for each variable individually (by typing `print(x);`, for example), or you could do this:
```
print("b is " + b + " and x is " + x + " and y is " + y );
```

After declaring a data type for a variable it cannot be changed. Also, keep in mind that the equals sign has a slightly different meaning in this context: it is an assignment operator that says "assign the value from the right side of the equals to the variable on the left. Compare the following:
```
int x = 5;
5 = 12;
```
The second line will produce an error because 12 cannot be the value of 5.

Generally, the practice with variables is to give them names that will help you easily remember what data type it is and what it is used for.

## loops

Computers are particularly good at doing the same thing quickly over and over again. This allows one to save space when programming (literally, as in have less lines of code), abstract multiple actions into one function (or loop, more on this soon), and have less to troubleshoot when a program does not work (often).

Loops are structures that set up conditions for repeated behavior until some specified time. One of the simpler loops is a `for()` loop. A `for()` loop performs repetitive calculations...think of it like this:
```
for ( init; test; update ) {
  statements
}
```

Prior to looking at this more concretely, remember that Booelan logic is basically a two part structure: test (will return true or false), behave accordingly (i.e., if this particular thing is the case [true], then perform this function...a simple `if()` structure).

More specifically, a `for()` loop behaves like this:
 1. the init statment is run
 2. the test is evaluated (true, false)
 3. if the test is true, continue to step 4. if the test is false, jump to step 6.
 4. run the statements within the block (the code within brackets)
 5. run the update statement and jump to step 2.
 6. exit the structure and continue running the program.

*for example:*
```
for ( int i = 20; i < 80; i += 5 ) {
  line( 20, i, 80, i + 15 );
}
```

So, to break this down:

1. `i` is set to 20
2. the test statement runs, in other words, is `i` less than 80?
3. at the beginning of the structure, this is true (20 is less than 80), so the `line()` statement in the block is performed (a line is drawn from 30, 30, to 80, 35).
4. the update statement is run, and `i` is incremented by 5 (remember, `i += 5` is equivalent to `i = i + 5`)
5. the for loop jumps back to the test statement. now that `i` is 35, is 35 less than 80? this is true.
6. another line is drawn, this time from coordinates 20, 35, to 80, 50
7. this continues until `i` is NOT greater than 80, at which point the structure terminates (stops).

Before running this code, how many lines will be drawn before `i` is greater than 80?

Try running the code now.

The benefit of this is that you do not have to write 12 `line()` statements. When programming, often times multiple lines of code can be condensed into smaller blocks using things like `for()` structures. A `while()` loop is similar to `for()`, basically saying while this is the case (or as long as this is the case) perform this statement continuously. I recommend sticking with `for()` loops over `while()` loops, as the `while()` loop has the potential to freeze your code/computer until it is true.

Back to [Pt. 1](pt1.md), Onward to [Pt. 3](pt3.md)