## Syntax in Computation
Casey Anderson, 2016

There are two basic categories of programming languages: `General-Purpose Languages` (frequently abbreviated to `GPL`) and `Domain-Specific Languages` (`DSL`).

### GPL vs DSL

`Domain-Specific Languages` are programming languages that are written for a specific purpose. `HTML` is a good example of a `DSL` that everyone in the department uses regularly.

`General-Purpose Languages` are written to support a wide variety of needs. In other words, languages that fall into this category are written to allow the user to write applications for a number of different contexts. For example, one could make a Library database (to keep track of who has been lent what book) in `Java`, though `Java` was not created specifically for public libraries.

### High-level vs Low-level

A `high-level` programming language is designed in part for convenience / ease of use. In general the belief is that more complex / specialized aspects of computation get in the way of focusing on your specific application, so `high-level` languages `abstract` away some of the lower-level aspects of computation. For example, you do not need to worry about the specifics of memory management when using `Python`, but cannot ignore memory management in `C`.

`High-level` programming languages are generally believed to make the process of developing a program simpler and more understandable for the average person. For example, one can generally expect a larger library of built in objects/resusable code in a high-level language than in a `low-level` language.

A `low-level` programming language does not abstract away the nuts-and-bolts of your computer. The word "low" in this case refers to the small amount of abstraction between the language and machine language (generally machine code or assembly). In other words, you need to pay attention to more aspects of how your computer functions as a device in this style of programming. The benefit of working with languages like this is that one's programs can be incredibly small and incredibly efficient in terms of memory usage.

### Languages supported by MDP

* [NTK](http://www.netlabtoolkit.org/) - A high-level graphical programming environment by Phil van Allan. Everyone in MDP gets at least some experience using this platform, an exemplary introduction to programming that is powerful enough to become one's main tool.

* [Arduino](https://www.arduino.cc/) - A high level general purpose software/hardware platform for interfacing with electronics.

* [Python](https://www.python.org/) - A high level, general-purpose language that we emphasize for use with text, the web, image processing, video, and more!

* [JavaScript](https://en.wikipedia.org/wiki/JavaScript) - A high level programming language that currently dominates the web. We use JavaScript for everything from responsive websites to IoT, but you could also do video and some limited audio work with this language.

* [Processing](https://processing.org/) - Based on the same framework as Arduino (Wiring), Processing is a high-level visual programming environment. Processing is used for a variety of visual

* [SuperCollider](https://supercollider.github.io/) - A high-level, domain specific language for algorithmic and live electronic music composition and sound design.

MDP has carefully curated which programming languages make sense to support given the style of work in the department. Our preference has been to focus on high-level, general purpose programming languages. These languages all have a good balance between high-level functionality while also allowing one to go "lower" if necessary / desired.

### Choosing a Programming Language

Choosing a Programming Language for your application is not always a straight-forward task. Developers are a very opinionated bunch, so it is normal to hear or read something where someone makes extreme statements along the lines of the following:

"using [INSERTNAMEOFPROGRAMMINGLANGUAGE] for [INSERTAPPLICATION] is stupid, you should only use [INSERTOTHERPROGRAMMINGLANGAUGE]!"

I do not find such conversations particularly productive, but the basic thread here is that learning a new language is hard and keeping track of the differences between multiple languages is also hard.

Here is a list of questions I ask myself when I am wondering if I need to learn a new language:

1. am I sure that what I need to do cannot be accomplished in languages I already know?
2. how reusable is this new language going to be for subsequent projects? Is it a DSL that I will likely only be able to use for this one particular task?
3. Is there a substantial benefit for using language x over language y for my application or am I simply considering using language y because I saw something cool made in it / know someone else who uses it and thinks not using it is stupid?

Example code per a handful of different languages:

NTK - http://www.netlabtoolkit.org/
Arduino (basically Java) - http://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense
Processing (basically Java) - https://processing.org/tutorials/pvector/
Procedural Python - https://github.com/caseyanderson/ask_gertrude/blob/master/ask_gertrude_v7.py
openCV (python) - https://opencv-python-tutroals.readthedocs.org/en/latest/py_tutorials/py_feature2d/py_matcher/py_matcher.html#matcher
openFrameworks (C++) - http://openframeworks.cc/tutorials/03_graphics/generativemesh/
C - http://www.cprogramming.com/tutorial/c/lesson8.html
SuperCollider - CTA provides example from local machine
