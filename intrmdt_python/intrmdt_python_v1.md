# Intermediate Python

Note: anything in between carrots (`<` to `>`) denotes user input.

*Quick reference links*

[Homebrew](http://brew.sh/)

[iPython](http://ipython.org/)

[Pip](http://pypi.python.org/pypi/pip)

[Atom](https://atom.io/) or [Sublime Text 2](http://www.sublimetext.com/2)

[iTerm2](http://www.iterm2.com/) (I actually prefer this to the Mac OSX Terminal, but either is fine)

[Dive Into Python](http://www.diveintopython.net/) - great reference

## Dictionaries
A dictionary (or `dict` for short) is a built-in datatype in python. `dicts` are key/value pairs between curly braces.

*For example:*
```
d = {'name':'boris'}
```
The line above creates a `dict` with the `key` `'name'` and stores it to the variable `d`. Entering `d` at the command line will return the entire `dict`.
```
In [9]: d
Out[9]: {'name': 'boris'}
```
To add a new key-value pair, simply assign the new key a value at `d`. If the key (which is case-sensitive) is not already in use t will be added to the dict d with its value. If the key is already in use the new value will simply overwrite the previous one.

*For Example*
```
In [21]: d = {'name': 'boris', 'age':40, 'hair':'bald'}

In [22]: d
Out[22]: {'age': 40, 'hair': 'bald', 'name': 'boris'}

In [23]: d['eyes']='brown'

In [24]: d
Out[24]: {'age': 40, 'eyes': 'brown', 'hair': 'bald', 'name': 'boris'}

In [25]: d['age']=60

In [26]: d
Out[26]: {'age': 60, 'eyes': 'brown', 'hair': 'bald', 'name': 'boris'}
```
This example illustrates how to add a new key-value pair to a dictionary (`'eyes'` and `'brown'`) as well as how to update or overwrite the value of a pre-existing key (`'age'`).

## Lists

## Objects

## Classes
