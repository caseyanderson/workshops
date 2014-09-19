# An Introduction to Processing (pt. 1)

Note: anything in between carrots (`<` to `>`) denotes user input.

*Quick reference links*

[Processing](http://processing.org/)

[OpenProcessing](http://www.openprocessing.org/)

## basics

Hitting the play button (top left of the Processing window) runs a patch. Hitting the stop button (next to the play button) stops a patch. That black bar thing at the bottom of the Processing window is the post window. This is where Processing will communicate with you, including telling you what is not working and why.

Copy and paste the following text into a Processing window.

`//two backslashes mean the text is a comment`

When something is commented ("commented out") the computer ignores it.

You can comment things out manually, on each line, or you can select multiple lines at once and type `<Command + />`. You can do the same thing to uncomment multiple lines of code.

Lastly, you can type `/*` to indicate the beginning of a block of comments, and specify the end of with `*/`

## drawing

Copy the below code into the Processing window and hit Play.

`ellipse( 50, 50, 80, 80 );`

Strings of numbers inside of parentheses are called parameters.

Try changing the parameters to the ellipse code above. What does each parameters do?

## drawing some circles

Copy the code below into a Processing window and press play.

```
void setup() {
  size( 480, 120 );
  smooth();
}

void draw() {
  if ( mousePressed ) {
    fill( 0 );
  } else {
    fill( 255 );
  }
  ellipse( mouseX, mouseY, 80, 80 );
}
```

What happens?
How big is the window?
What does fill do?
What do `mouseX` and `mouseY` mean, and what are they doing here?
What does `setup` do?

You can go about exploring this patch one of two ways: look up each function that we do not know in the reference (simply highlight something, like `mousePressed`) and hit `<Shift+Command+F>`, or just start randomly changing things.

Try changing some values to the above code. For example, to make a larger window, change both parameters of size to 1000:

`size( 1000, 1000 );`

## other shapes
```
void setup() {
  size( 1000, 1000 );
  background( 150 );
  smooth();
}

void draw() {
  point( 20, 500 );    //a single point/dot
  line( 50, 20, 500, 20 );  //a line, x1, y1, x2, y2
  rect( 100, 10, 300, 400 );  //a rectangle, x top left, y top left, width, height
}
```

The above code draws the rectangle by specifying x and y locations (at top left), the width, and the height. To draw the rectangle based on some specific center point, not the upper left hand coordinates, you need to add `rectMode(CENTER);` prior to drawing the rectangle. Changing the `rectMode` of the `rect()` object changes the meaning of the parameters. In `rectMode(CENTER)`, the parameters are center x, center y, width, height.

add `rectMode(CENTER)` to your code up there.

You can also draw the rectangle by specifying the top left corner and bottom right corner, or, more specifically, using `rectMode(CORNERS)`. There are multiple modes for ellipses also (`CENTER`, `CORNER`, and `CORNERS`).

Try replacing the ellipse in the previous examples with a rectangle, and try different rectangle modes. What seems to make the most sense for what the application does?
Below is an example:

```
//drawing some rectangles
void setup() {
  size( 1000, 1000 );
  smooth();
}

void draw() {
  if( mousePressed ) {
    fill( 204, 102, 0 );
  } else {
    fill( 255 );
  }
//  rectMode( CORNERS );
  rectMode( CENTER );
  rect( mouseX, mouseY, 80, 80 );
//  remember to try the default mode by commenting out rectMode entirely
}
```
## more basics

`setup()` and `draw()` are functions which enable a program to run continuously. `setup()` runs once, when the program starts, and `draw()` runs continuously. So, we can think of `draw()` as a loop (because it is)...one image frame is drawn to the display window at the end of each pass through `draw()`.

`fill()` sets the color used to fill shapes. The color is specified in terms of either `RGB` or `HSB` (depending on `colorMode`), but it defaults to `RGB` (range from 0-255).
`if else` means if this one thing, do this, otherwise (`else`) do this other thing (we could also leave it blank, in which case it would not do anything else if it did not detect a mouse click).

In this case I am filling a rectangle with a kind of darkish dirty shade of orange if and only if the mouse is pressed down, otherwise, the rectangle will be white (as far as the computer is concerned, the rectangle is still "filled" with white).

`mouseX` and `mouseY` allow you to use the position of the mouse pointer on the screen to pass information to, in this case, the center x and center y locations of our rectangle.

[next](pt2.md)