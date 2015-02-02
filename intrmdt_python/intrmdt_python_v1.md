# Intermediate Python

Note: anything in between carrots (`<` to `>`) denotes user input.

*Quick reference links*

[Homebrew](http://brew.sh/)

[iPython](http://ipython.org/)

[Pip](http://pypi.python.org/pypi/pip)

[Atom](https://atom.io/) or [Sublime Text 2](http://www.sublimetext.com/2)

[iTerm2](http://www.iterm2.com/) (I actually prefer this to the Mac OSX Terminal, but either is fine)

## Dictionaries
A dictionary (or `dict`) is a built-in datatype in python. `dicts` consist of key/value pairs between curly braces.

*For example:*
```python
d = {'name':'boris'}
```
The line above creates a `dict` with the `key` `'name'` and stores it to the variable `d`. Entering `d` at the command line will return the entire `dict`.
```python
In [9]: d
Out[9]: {'name': 'boris'}
```
To add a new key-value pair assign the new key a value at `d`. If the key is not already in use it will be added to `d`. If the key is already in use the new value will simply overwrite the previous one.

*For Example*
```python
In [21]: d = {'name': 'boris', 'age': 40, 'hair':'bald'}

In [22]: d
Out[22]: {'age': 40, 'hair': 'bald', 'name': 'boris'}

In [23]: d['eyes']='brown'

In [24]: d
Out[24]: {'age': 40, 'eyes': 'brown', 'hair': 'bald', 'name': 'boris'}

In [25]: d['age']=60

In [26]: d
Out[26]: {'age': 60, 'eyes': 'brown', 'hair': 'bald', 'name': 'boris'}
```
Here a new key-value pair was added to `d` (`'eyes'` and `'brown'`) and the value associated with the key `'age'` was updated to `60` (`d` used to list the `'age'` of `'boris'` as `40`).

But what if you need to remove something from a `dict`? There are a few ways to do this:
1. `del`
2. `pop`

#### Using del

`del` deletes an item from a dictionary by key (or, more generally, removes a value at a specific index). It's probably the simplest way to get rid of something in a `dict`
```python
In [19]: d = {'name': 'boris', 'age': 40, 'hair':'bald'}

In [20]: d
Out[20]: {'age': 40, 'hair': 'bald', 'name': 'boris'}

In [21]: del d['age']

In [22]: d
Out[22]: {'hair': 'bald', 'name': 'boris'}
```
So the value `'40'` has now been removed from the `dict d` at the index (or in this case, key) `'hair'`.

#### Using pop
```python
In [28]: d.pop('hair')
Out[28]: 'bald'

In [29]: d
Out[29]: {'age': 40, 'name': 'boris'}

In [30]: d = {'name': 'boris', 'age':40, 'hair':'bald

In [31]: d.pop('hair')
Out[31]: 'bald'

In [32]: d
Out[32]: {'age': 40, 'name': 'boris'}
```
The main different between `del` and `.pop` is that `.pop` will return the value removed at index.

*Quick Notes*
* `dicts` are not typed. It is very common to see a variety of datatypes in the same `dict`. One can even store a `dict` as a value inside of another `dict`.
* `dicts` allow provide the ability to add and remove key/value pairs at any time.
* `dicts` are unordered.

## Lists
A `List` is an ordered set of elements within square brackets. Elements can be added or removed from a `List` dynamically and can be of arbitrary type (i.e. the same `List` can contain an `int`, `float`, and `str` element with no issue)

`Lists` must be declared prior to usage:
```python
In [1]: h = [ 'this', 'is', 'a', 'list' ]

In [2]: h
Out[2]: ['this', 'is', 'a', 'list']
```

`Lists` count from zero, so the first item in the `List` is actually at index 0:
```python
In [3]: h[0]
Out[3]: 'this'
```

To find the size of a `List` (i.e. the number of elements contained therein) use `len`:
```python
In [18]: len(h)
Out[18]: 4
```

To return a portion of a `List`, but not the entire thing, one can `slice` it.

*For Example*
```python
In [41]: h = [ 'this', 'is', 'a', 'list' ]

In [42]: h
Out[42]: ['this', 'is', 'a', 'list']

In [43]: h[1:3]
Out[43]: ['is', 'a']
```

`h[1:3]` returns each element from index 1 and stops before index 3, which prints elements at index 1 and 2.

#### Slicing Shortcut
```python
In [5]: h[:3]
Out[5]: ['this', 'is', 'a']

In [6]: h[3:]
Out[6]: ['list']
```

The `List` object interprets an omitted number to the left of the colon as a 0 and an omitted number to the right as `len(h)-1` (in this case).

`append` and `insert` are the two most common ways to add an element to a `List`

#### Insert Example
```python
In [20]: h = [ 'this', 'is', 'a', 'list' ]

In [21]: h
Out[21]: ['this', 'is', 'a', 'list']

In [22]: h.insert(3, 'great')

In [23]: h
Out[23]: ['this', 'is', 'a', 'great', 'list']
```

#### Append Example
```python
In [30]: h.append('certainly')

In [31]: h
Out[31]: ['this', 'is', 'a', 'great', 'list', 'certainly']
```

`insert` adds an element to a `List` at index, `append` simply adds an element to the end of a `List`.

`extend` concatenates two Lists and returns a new one:

*For Example*
```python
In [31]: h
Out[31]: ['this', 'is', 'a', 'great', 'list', 'certainly']

In [32]: i = [ 'the', 'best', 'list']

In [33]: h.extend(i)

In [34]: h
Out[34]: ['this', 'is', 'a', 'great', 'list', 'certainly', 'the', 'best', 'list']
```

`index` allows one to search a `List` by `value`

*For Example*
```python
In [36]: h.index('certainly')
Out[36]: 5
```

This is helpful if you know what value you are looking for in a (potentially) gigantic `List` but have no idea where it is specifically.

#### Removing Elements from a List

There are two basic ways to remove an element from a `List`: `pop` and `remove`.

#### Using pop
```python
In [8]: h = ['this', 'is', 'a', 'great', 'list', 'certainly', 'the', 'best', 'list']

In [9]: h
Out[9]: ['this', 'is', 'a', 'great', 'list', 'certainly', 'the', 'best', 'list']

In [10]: h.pop()
Out[10]: 'list'

In [11]: h
Out[11]: ['this', 'is', 'a', 'great', 'list', 'certainly', 'the', 'best']
```

`pop()` removes and returns an item from a List at index. If no index is specified `pop()` removes and returns the last item of a `List`.

#### Using remove
```python
In [37]: h
Out[37]: ['this', 'is', 'a', 'great', 'list', 'certainly', 'the', 'best', 'list']

In [38]: h.insert(2, 'is')

In [39]: h
Out[39]: ['this', 'is', 'is', 'a', 'great', 'list', 'certainly', 'the', 'best', 'list']

In [40]: h.remove('is')

In [41]: h
Out[41]: ['this', 'is', 'a', 'great', 'list', 'certainly', 'the', 'best', 'list']
```

`remove()` gets rid of the first occurrence of value. In the above example, the value `'is'` was removed at index 1. In order to remove the second occurrence of `'is'` one would have to run `h.remove('is')` again.

## Objects

An `object` is a self-contained, generalized data structure. `objects` typically have both `attributes` (which describe the data contained therein) and `methods` (functions which belong to the `object` and act on the `object`’s data). In python everything is an `object`, which allows everything to be assigned to a variable or passed to a function as a parameter.

#### Display all attributes with dir(self)
```python
In [11]: h = ['this', 'is', 'a', 'great', 'list', 'certainly', 'the', 'best', 'list']

In [12]: dir(h)
Out[12]:
['__add__',
'__class__',
'__contains__',
'__delattr__',
'__delitem__',
'__delslice__',
'__doc__',
'__eq__',
'__format__',
'__ge__',
'__getattribute__',
'__getitem__',
'__getslice__',
'__gt__',
'__hash__',
'__iadd__',
'__imul__',
'__init__',
'__iter__',
'__le__',
'__len__',
'__lt__',
'__mul__',
'__ne__',
'__new__',
'__reduce__',
'__reduce_ex__',
'__repr__',
'__reversed__',
'__rmul__',
'__setattr__',
'__setitem__',
'__setslice__',
'__sizeof__',
'__str__',
'__subclasshook__',
'append',
'count',
'extend',
'index',
'insert',
'pop',
'remove',
'reverse',
'sort']
```

In the above example, an instance of a List object is stored at h. By calling `dir(h)` one can return all of the attributes that `List` has access to.

One can normally assume that an `object` will have an attribute describing its usage in what is called a `doc string`. One can query the `doc string` by simply calling `.__doc__` on an `object`.

*For Example*
```python
In [31]: h.__doc__
Out[31]: "list() -> new empty list\nlist(iterable) -> new list initialized from iterable's items"
```



## Classes
