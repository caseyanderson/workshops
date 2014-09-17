<i>draw() and setup()</i>
<br/>Programs that run continuously must include a draw() function. Any code inside of a draw() block runs in a loop either until the stop button is pressed or the window is closed. A program cannot have multiple draw() functions.
<br/>The draw() function draws a new frame to the display window at the end of one "pass" (or iteration), and then loops back to the beginning.
<br/>The rate at which frames are drawn to the window is dictated by the frameRate. frameRate defaults to 60 frames per second, but you can change the frame rate by adding frameRate( whatever ) to your draw() function.
<br/>Run the code below to see all of this in action.
<br/><pre>void draw() {
  println( frameCount );
}</pre>
<br/>This program prints each frame number to our post window.
<br/>Now try adding a frameRate line that specifies some slower amount of frames per second.
<pre>//example (10 fps)
void draw() {
  frameRate( 10 );
  println( frameCount );
}</pre>
<br/>Now the draw() loop is drawing 10 frames per second, and printing the number of frames it has created (since startup) in our post window (Processing calls this the console). The difference is pretty obvious.
<br/>another example:
<pre>float y = 0.0;

void draw() {
  frameRate( 30 );
  background( 204 );
  y += 0.5;
  line( 0, y, 100, y );
}</pre>
<br/>What is happening here?
What could we improve upon?
Why does draw() know about the variable y?
<br/><br/><pre>float y = 0.0;

void draw() {
  frameRate( 90 );
  background( 204 );
  y += 0.5;
  line( 0, y, 100, y );
  if ( y > 100 ) {
    y = 0;
  }
}</pre>
<br/>The order of events here is important. The draw() loop is running at a rate of 30 fps, but the first thing that actually happens is that the background is filled with that gray-shade. Try moving the line statement above the background statement. What happens? Why?
<br/><br/>The line is getting drawn, but it is getting drawn over almost immediately afterwards because the background statement happens next.
<br/>It is kind of silly to redraw the background on every loop of the draw function. If the background was changing, then this would make sense, but in this case it it is not. We can use a setup() function to delineate between actions that only need to happen once, and actions that need to happen continuously. In the case of an unchanging background, we can go ahead and set the background once, outside of the draw loop.
<br/>This would look like this.
<pre>float y = 0.0;

void setup() {
  size( 500, 500 );  //setup is also good to set the window size
  background( 204 );
}

void draw() {
  frameRate( 90 );
  y += 0.5;
  line( 0, y, 100, y );
  if ( y > 100 ) {
    y = 0;
  }
}
</pre>
<br/>This is a good example of the difference between setup() and draw(). From the computer's standpoint, a new line is drawn with every pass of the draw() loop. So, if the background, or everything but the line, is not reset to that gray color on each iteration through the loop, we will slowly get a window full of black (made up of lots of black lines).
<br/>Now let's go back to our earlier version of the example.
<pre>float y = 0.0;

void draw() {
  frameRate( 90 );
  background( 204 );
  y += 0.5;
  line( 0, y, 100, y );
  if ( y > 100 ) {
    y = 0;
  }
}</pre>
<br/>One of the nice things about variables is that we can use the same one for different things. For example:
<pre>float y = 0.0;

void draw() {
  frameRate( 90 );
  background( y * 1.4 );
  y += 0.5;
  line( 0, y, 100, y );
  if ( y > 100 ) {
    y = 0;
  }
}</pre>
<br/>What is happening here?
<br/>Deciding what parts of the program need to go in a setup() statement, and what parts need to go into a draw() loop depends on the type of behavior needed. The important thing to remember is that setup() will always be executed first, and will only be executed once. The draw() loop will begin immediately after setup() is complete, and will loop repeatedly.
<br/>to <a href="http://www.caseyanderson.com/?page_id=2308">part 4</a>.