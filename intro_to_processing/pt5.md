<i>arrays</i>
<br/>An array is a set of data elements stored under the same name. Arrays can be created to hold any type of data, and each element can be individually assigned and read.
<br/>Array elements are numbered starting with zero. So, the first position of an array is 0, not 1.
<br/>Arrays are declared similarly to other data types, but they are distinguished with brackets. When an array is declared, the type of data it stores must be specified. After the array is declared, the array must be created with the keyword "new."
<br/>All three of the following was of creating, declaring, and assigning data to an array accomplish the same thing. What is different about each?
<br/><pre>
int[ ] data;
void setup() {
  size( 100, 100 );
  data = new int[ 5 ];
  data[ 0 ] = 19;
  data[ 1 ] = 40;
  data[ 2 ] = 75;
  data[ 3 ] = 90;
}

int[ ] data = new int[ 5 ];
void setup() {
  size( 100, 100 );
  data[ 0 ] = 19;
  data[ 1 ] = 40;
  data[ 2 ] = 75;
  data[ 3 ] = 90;
}

int[ ] data = { 19, 40, 75, 76, 90 };
void setup() {
  size( 100, 100 );
}</pre>
<br/>An array element is accessed using the name of the variable followed by brackets around the position from which you are trying to read.
<br/>For example:
<pre>int[] data = { 19, 40, 75, 76, 90 };
line( data[ 0 ], 0, data[ 0 ], 100 );
line( data[ 1 ], 0, data[ 1 ], 100 );
line( data[ 2 ], 0, data[ 2 ], 100 );
line( data[ 3 ], 0, data[ 3 ], 100 );
line( data[ 4 ], 0, data[ 4 ], 100 );
</pre>
<br/>The length field stores the number of elements in an array. This field is stored within the array and can be accessed with the dot operator.
<br/><pre>int[] data1 = { 19, 40, 75, 76, 90 };
int[] data2 = { 19, 40 };
int[] data3 = new int[ 127 ];
println( data1.length );
println( data2.length );
println( data3.length );</pre>
<br/>We can use the length field to allow for loops to do some of the tedious parts of dealing with arrays for us. This code does the same thing as the last code we wrote (the one that generated lines), but uses a for() structure to iterate through every value in the array.
<br/><pre>int[] data = { 19, 40, 75, 76, 90 };
for ( int i = 0; i < data.length; i++ ) {
  line( data[ i ], 0, data[ i ], 100 );
}</pre>
<br/>We can also use a for structure to put data inside an array:
<br/><pre>float[] sineWave = new float[ width ];

for ( int i = 0; i < width; i++ ) {
  //fill the array with values from sin()
  float r = map( i, 0, width, 0, TWO_PI );
  sineWave[ i ] = abs( sin( r ) );
}

for ( int i = 0; i < sineWave.length; i++ ) {
  //set the stroke values to numbers read from the array
  stroke( sineWave[ i ] * 255 );
  line( i, 0, i, height );
}</pre>
<br/>Storing the coordinates of many elements is another way to use arrays to make a program easier to read/manage. In the following example, the x[] array stores the x-coordinate for each of the 12 elements in the array, and the speed[] array stores a rate corresponding to each. If one wrote this program without arrays one would need 24 separate variables, which would suck. Changing the value assigned to numLines sets the number of elements drawn to the screen.
<br/><pre>int numLines = 12;
float[] x = new float[ numLines ];
float[] speed = new float[ numLines ];
float offset = 8;  //set space between lines

void setup() {
  size( 100, 100 );
  smooth();
  strokeWeight( 10 );
  for ( int i = 0; i < numLines; i++ ) {
    x[ i ] = i;  //set initial position
    speed[ i ] = 0.1 + ( i / offset );  //set initial speed
  }
}

void draw() {
  background( 204 );
  for ( int i = 0; i < x.length; i ++ ) {
    x[ i ] += speed[ i ];  //update line position
    if( x[ i ] > ( width + offset ) ) {  //if off the right,
    x[ i ] = -offset * 2;                //return to the left
    }
    float y = i * offset;  //set y-coordinate for line
    line( x[ i ], y, x[ i ] + offset, y + offset );  //draw line
  }
}</pre>
<br/>Here is another example of a different way to store information to arrays, this time using the mouse as data. What is happening here? Run the code, break it down, and see if you can figure out what is going on, and how. Is there a way to change it to get more interesting results?
<br/><pre>int num = 50;
int[] x = new int[ num ];
int[] y = new int[ num ];

void setup() {
  size( 500, 500 );
  noStroke();
  smooth();
  fill( 255, 102 );
}

void draw() {
  background( 0 );
  //shift the values to the right
  for ( int i = num - 1; i > 0; i-- ) {
    x[ i ] = x[ i - 1 ];
    y[ i ] = y[ i - 1 ];
  }
  
  //add the new values to the beginning of the array
  x[ 0 ] = mouseX;
  y[ 0 ] = mouseY;
  //draw the circles
  for ( int i = 0; i < num; i++ ) {
    ellipse( x[ i ], y[ i ], i/2.0, i/2.0 );
  }
}</pre>
<br/>To the <a href="http://www.caseyanderson.com/?page_id=2324">Intermediate Processing</a> page.