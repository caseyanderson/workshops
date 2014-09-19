# An Introduction to Processing (pt. 4)

Note: anything in between carrots (`<` to `>`) denotes user input.

*Quick reference links*

[Processing](http://processing.org/)

[OpenProcessing](http://www.openprocessing.org/)

## functions

A function is a self-contained programming module. Processing has lots of built in functions, like line(), or size() (etc.), but as you get more comfortable with programming, and Processing, it is important to keep in mind that you can make your programs more robust by developing your own functions. The question should be: am I typing the same lines of code over and over again, and if so, is there a way to abstract this code so I can re-use it more easily? This is referred to as modularity. Think of it like you were a painter, and you built all of your own brushes (and mixed your own paints, etc,). You could build a new brush for each painting, and let the construction of the brush be dictated by whatever you were trying to paint (per each painting), or you could think about what is common across all projects that would allow you to build a paint brush specifically for use in any project needing a paintbrush with characteristics x. This idea of modularity, and tools that perform general functions, is the core idea behind object oriented programming, and what will ultimately make your programming more efficient.

Functions normally have parameters that define their actions. line() has four parameters, x1, y1, x2, y2. A different line will be created depending on what values you put in the parameters.

One easy way to imagine a function is to think of a box that has some device inside. The device inside the box can act on data in pre-defined ways. Typically, a box (function) has an input into the box and code inside that utilizes the input to produce an output. The nice thing about this is that you do not have to understand every solitary calculation that occurs within a box in order to successfully use it (line() is a good example...we do not care how line is drawing lines, we just
care that it draws them from x1, y1, to x2, y2). The box, in this case, is just an interface. It has some behavior, and it responds to external stimulus (in this case, data) in certain ways.

This way of thinking is called abstraction, and is a powerful way to work with programming.

```
void setup() {
  size( 100, 100 );
  noStroke();
  smooth();
  noLoop();
}

void draw() {
  fill( 255 );
  ellipse( 50, 50, 60, 60 );
  fill( 0 );
  ellipse( 50 + 10, 50, 30, 30 );
  fill( 255 );
  ellipse( 50 + 16, 45, 6, 6 );
}
```

The code up there is not that long, but if we wanted to make multiple eyes, it would quickly become ridiculous (6 lines of code per eye...). Furthermore, the same lines of code would be rewritten over and over again. So, to save space, and to make our work a little simpler, we can take this opportunity to break this patch down into a function that we could call repeatedly. This would allow us to save space, save time from having to troubleshoot multiple lines of basically identical code, and focus on the few things that make each eye different (for example, their position in the window).

```
void setup() {
  size( 100, 100 );
  noStroke();
  smooth();
  noLoop();
}

void draw() {
  eye( 65, 44 );
  eye( 20, 50 );
}

void eye( int x, int y ) {
fill( 255 );
ellipse( x, y, 60, 60 );
fill( 0 );
ellipse( x + 10, y, 30, 30 );
fill( 255 );
ellipse( x + 16, y - 5, 6, 6 );
}
```

What are the differences between this version and the previous one?

For every subsequent eye that we want to add, we could just write another line of code that calls where each eye should be.

Try making a design of some sort, or multiple shapes, and abstracting it into a function. Use the patch above as an example.