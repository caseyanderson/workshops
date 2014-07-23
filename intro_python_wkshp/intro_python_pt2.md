# An introduction to Python (pt. 2, Programming)

Note: anything in between carrots (`<` to `>`) denotes user input.

## Intro to Python

Python is a general-purpose, interpreted, high-level programming language. The syntax of the language has been optimized to emphasize code readability, as well as brevity. Python supports many different programming approaches, but the one to focus on, should you choose to work with this language more thoroughly in the future, is object orientation.

Object orientation is a programming philosophy/paradigm based around objects, consisting of data fields and methods, and their interactions. The common assumption for any object is that it is capable of accepting some sort of input and producing some sort of output. Generally, one object is designed to perform a generalized, abstract function, that is context independent.

For example, a car contains a computer capable of performing a complex series of calculations during its operations. Nonetheless, we do not need to understand every single thing going on inside of the car in order to be able to effectively drive it. We simply need to know that we can change the direction of the car with the steering wheel, increase the speed of the car with the gas pedal, and decrease the speed with the brake.

Another good example of object orientation: painters do not design a new (set of) paintbrush(es), from scratch, for every single painting they create. Instead, a painter has certain paint brushes usable for a general task (for example, broad brush strokes) applicable across any painting requiring such a stroke. This is a good example of abstraction and generalization, and can become a powerful way of thinking when programming.

## Strings

any character surrounded by quotes. Quotes must be balanced. In other words, I could say

```
a = 'this'
..a = “this”
#but not:
a = 'this
#See the difference there?
```

Similarly, if we are going to declare a variable as a string, we have to use quotes.

```
a = this
#does not work because the word this is not defined.
```

Python allows for numerous manipulations to strings. More specifically, if we go back to our original example:

```
a = 'this'
```

We could use various operations on it to get various information from our variable containing the string 'this'.

*For example:*

```
In [4]: len(a)
Out[4]: 4
```

We could also say:

```
In [5]: type(a)
Out[5]: str    # str is short for string
```

Lastly, we can return a part of the string by doing the following:

```
In [6]: a[:3]
Out[6]: 'thi'
```

Similarly, we can see what other functions are possible with a by entering `a.<TAB>` into the terminal.

This is a good strategy for working with iPython in general. Any time I get a new package/module, the first thing I do (after importing it) is to type its name followed by a period and then tab.

From this list, we can type out any of the functions followed by a `?` to see a brief description of what it does.
*For example:*

```
In [7]: a.upper?
Type:       builtin_function_or_method
String Form:<built-in method upper of str object at 0x104488750>
Docstring:
S.upper() -> string

Return a copy of the string S converted to uppercase.
```

So let's convert our string, contained in the variable `a`, to a capitalized version of itself. Try this:

```
In [8]: a.upper()
Out[8]: 'THIS'
```

However, if you try this:

```
In [9]: a
Out[9]: 'this'
```

So, if we wanted to permanently change a, we could do this:

```
In [10]: a = a.upper()

In [11]: a
Out[11]: 'THIS'
```

## Integers/Floats

There are two basic types of numbers: integers and floating point numbers (floats for short). Integers are any whole number (positive or negative), whereas floats are any number with a decimal point. Try this:

```
In [12]: a = 5

In [13]: type(a)
Out[13]: int
```

Whereas:
```
In [14]: a = 4.0

In [15]: type(a)
Out[15]: float
```

If you want to, you could now enter `a.<TAB>` to see what other methods `a` (the variable that now stores a floating point number [4.0]) has.

## Assignment operator, more variables

In Python, `=` does not mean what you would normally think it does. Our previous example:
```
In [16]: a = 4.0
```

Means “assign 4.0” to the variable named `a`. This is why we cannot say the following:
```
In [17]: 5 = 6
  File "<ipython-input-17-6d9c0c29354b>", line 1
    5 = 6
SyntaxError: can't assign to literal
```

So a 6 can never be assigned (or put inside) a 5, so this line of code will always throw an error.

Variables must be assigned prior to their use, otherwise python throws an error because it does not understand what you want it to do.

Try this:
```
In [18]: x
---------------------------------------------------------------------------
NameError                                 Traceback (most recent call last)
<ipython-input-18-401b30e3b8b5> in <module>()
----> 1 x

NameError: name 'x' is not defined
```

Nonetheless, variables, once assigned (and therefore established as a particular type), can be converted to other data types. For example:
```
In [21]: a = 5

In [22]: float(a)
Out[22]: 5.0
```

Or similarly:
```
In [23]: a = 4.9

In [24]: int(a)
Out[24]: 4
```
## Lists

A compound data type used to group together other values. A list is written as a series of comma-separated values (or items) between square brackets. They do not need to be of uniform type. For example:
```
In [25]: a = ['spam', 'eggs', 100, 1234]

In [26]: a
Out[26]: ['spam', 'eggs', 100, 1234]
```

Individual items in a list are referenced by their index, or position. We can reference individual items by entering the variable and the position (counting from 0) into the interpreter.
*For example:*
```
In [27]: a[0]
Out[27]: 'spam'
In [28]: a[3]
Out[28]: 1234
In [29]: a[:2]
Out[29]: ['spam', 'eggs']
```

Individual items/elements in a string can be rewritten as follows:
```
In [30]: a[1] = 2

In [31]: a
Out[31]: ['spam', 2, 100, 1234]
```

If we do not happen to know how long a particular string is, we can make the interpreter figure it out be calling `len()` on it:
```
In [32]: len(a)
Out[32]: 4
```
## if statements
Let's take a look at a nice example of a function that contains Boolean Logic (true or false datatypes)

```
x = int(input('please enter an integer: ') )

if x < 0:
    x = 0
    print 'negative changed to zero'
elif x == 0:
    print 'Zero'
elif x == 1:
    print 'single'
else:
    print 'more'
```

Quite a bit to talk about here. Let's break it down line by line:

1. We called a statement that takes any input at the command line, converts it to an `int`, and assigns it to the variable `x`.
2. After that, we start our test. If `x` is less than 0, set `x` to 0 and `print` the statement 'negative changed to zero'.
3. `Elif` (means else if) `x` RETURNS 0, `print` zero. Else if `x` returns 1, `print` single. If none of those things are the case (the final `else`), print the string more.

Before you try to type this in, notice the whitespace. Python groups statements together (in functions like this one, or otherwise) via whitespace. The normal Python protocol is to use four spaces to denote the first line belonging to a previous one (the line under the first if statement), or you can use indents.

Try to enter this into your interpreter with a different input value (not 42).

## for statements

Type this into your interpreter:
```
words = ['cat', 'widow', 'defenestrate']

for w in words:
    print w, len(w)
```
Python's `for` statement iterates over the items of any sequence (a list or a string), in the order that they appear in the sequence. So, the above function declares a list called `words` with three items: cat, widow, and defenestrate (all strings). Then, it says `for w` (used as an index here) in the list `words` `print` `w` (the item at that position and the length of that particular item). This is why we get the sequence of words with their string length returned. Upon completion of the `for` loop (when the loop has iterated over each item in the list) the loop terminates.

## range

The last built in function to be concerned with, at a basic level, is the range function. Range
generates lists containing arithmatic progressions.

*For example:*
```
In [33]: range(10)
Out[33]: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

and
```
In [34]: range(5, 10)
Out[34]: [5, 6, 7, 8, 9]
```
## Defining Functions

By defining a function (using `def`), we can call it again for later use.

*For example:*
```
def fib(n):
    a, b = 0, 1
    while a < n:
        print a,
        a, b = b, a+b
```

Here we actually call the function and set `n`, so it will print the Fibonacci series up to (in this case) whatever `n` is:

*For Example:
```
In [39]: fib( 2000 )
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597
```