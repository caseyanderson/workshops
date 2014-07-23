# An introduction to Python (pt. 1, Installation)

*Quick reference links*

[Homebrew](http://brew.sh/)

[iPython](http://ipython.org/)

[Pip](http://pypi.python.org/pypi/pip)

[Sublime Text 2](http://www.sublimetext.com/2)

[iTerm2](http://www.iterm2.com/) (I actually prefer this to the Mac OSX Terminal, but either is fine)

## XCode

Download, and install, Xcode from the app store (this takes forever, so please do it prior to the workshop).

You also need Apple Developer Tools (in the Mac App store) and the Command Line Developer Tools (on the Apple Developer website). Go to the [Apple Developer](https://developer.apple.com/) site and register for a free account (if you do not already have one), then search for them to download both of the aforementioned plugins.

While we are at it, go to Applications>Utilities>Terminal and run the Terminal application. We are going to be using it a lot, so I would recommend adding it to your dock for quick access.

## Homebrew
Install Homebrew by entering this into the Terminal:

```
ruby -e "$(curl -fsSL https://raw.github.com/Homebrew/homebrew/go/install)"
```

When it is done, you can run ```brew update``` and then ```brew doctor``` in the terminal to make sure everything is working correctly (Homebrew will tell you if not).

Additionally, you need to add the Homebrew directory to your system path. In the terminal, type ```cd``` and hit enter to go to your user directory. Now type ```nano .bash_profile``` and paste this into the file:

```
export PATH=/usr/local/bin:$PATH
```

Now restart the Terminal.

## Python
You may have noticed that there are multiple versions of Python available online (2.7.something and 3). We are going to focus on version 2.7.3, which you can easily install, via Homebrew, by typing the following into the command line:

```
brew install python
```

This will also install Pip, which is a great package manager specifically for Python.

After installing Python, go to your .bash_profile file and add the following:

```
export PATH=/usr/local/share/python:$PATH
```

To confirm that everything is in order, type ```which python``` in the Terminal and hit enter. If everything is working correctly, the Terminal will return ```/usr/local/bin/python```.

*everything else*

Okay, so now we are going to install a handful of other things that will be useful when programming in Python. They are as follows: virtualenv, virtualenvwrapper, numpy, scipy, and iPython.
*virtualenv and virtualenvwrapper*
```
pip install virtualenv
pip install virtualenvwrapper
```
*Numpy*
```
pip install numpy
```
*SciPy*
```
brew install gfortran
pip install scipy
```
*Flask*
```
pip install Flask
```
*iPython*
```
pip install ipython
```

To test to make sure everything works, run ipython from the terminal by typing the following:

```
ipython
```

And then try to import one of the modules we installed. For example:

```
In [1]: from flask import Flask
In [2]: Flask.<AND THEN PRESS THE TAB KEY>
```

If you get a long list of methods, you did it correctly. If not, review the steps above and make sure you did not actually skip anything.

Last but not least, we are going to need access to a text editor of some sort. There are lots of options, but the two I normally recommend are [TextMate](http://macromates.com/) or [SublimeText2](http://www.sublimetext.com/). I use SublimeText, but you can use whatever you want. Nonetheless, you will need a text editor, that frequently will be open right next to your Terminal window, for any serious programming.