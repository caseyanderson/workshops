### Intro to Electronics
*Disney, Casey Anderson*

Working in the Arduino environment necessarily involves at least a basic understanding of electronics.

So, What is electricity?

Electricity is any flow of electrons

How do we measure electricity? Or, what are we referring to when we measure?
We need to be able to say how many electrons were in the flow.

For example, let's think of the flow of water through a pipe. More specifically, let's imagine that we have a tank of water (atop a tall building), a pipe coming out of it, and a bucket of water. What would we want to know about these things?

Furthermore, let's say that the water has an evenly distributed number of dust particles in it. For example, there are 10 specks of dust in ever cubic centimeter of water...

If x amount of water flows through the pipe, we can calculate the number of specks of dust which have flowed through the pipe.

-or-

By knowing the number of specks of dust which have flowed through the pipe, we can calculate the volume of water.

This is the same with electricity, but instead is measured in coulombs. In this case, the dust specks are electrons.

How would we measure the rate at which the water flows through the pipe and into the bucket?

The “flow rate” would be measured as some volume of water which flowed through the pipe during a defined period of time.

But in our case we refer to flow rate as current, denoted by the symbol I (just imagine that it stands for “intensity”).

Electric Current is measure in amperes (or amps, symbol: A)

1 amp = the quantity of 1 coulomb passing a point in one second.

What else would be useful to know about our tank of water, tube, and bucket?
Flow pressure

Thinking back to our earlier example, we could imagine the building is three stories in one scenario and one story in another. What would be the difference between these two scenarios?

The energy contained in the water in the tank defines the water pressure. In other words, the higher the water tank, the more energy potentially exists if it were to flow.

With electricity, flow pressure is defined by the difference in numbers of electrons between two points. We refer to this as a potential difference because the difference depends on the positions of the points and how many electrons potentially exist.

Let's imagine another scenario in which we have a battery powering a small lightbulb. We could describe the order of events as follows:

1. battery generates electrons at one terminal and takes in electrons at the other terminal
2. bulb lights up as electrons flow around the circuit
3. electrons flow around the circuit due to potential difference of battery

A battery forces electrons around a circuit only when the circuit is complete. If it is not connected, no electrons flow, but the battery still has the POTENTIAL to make them flow.

If we were to disconnect the circuit, the scenario would change as follows:

1. Even though battery is not connected to the bulb, it still has the potential to light the bulb
2. Bulb is not lit up, no electrons flow
3. The circuit is disconnected, so no electrons can flow

Since the two terminals are not connected via the circuit, electrons cannot flow. Air, an insulator, prevents them from jumping from one conductor to the other.

Nonetheless, a battery has the POTENTIAL to light the bulb and so the difference in numbers of electrons between two points (terminals) is known as the potential difference.

This is normally referred to as voltage, or volts, and normally symbolized with a V.

The higher the voltage, the harder a cell can force electrons around a circuit
  so, voltage is a way of expressing electrical pushing power.

Resistors
used to control current and voltage in specified ways

it would be impractical to have resistors of every possible value...there would be millions

so, there is an agreed upon range of values, however made within a certain tolerance

  RESISTOR TOLERANCE – specified as a plus or minus percentage

  A 10ohm plus/minus 10% resistor

    -so, what is the actual range?
    9-11ohms

  resistors are also rated by the amount of power they can safely dissipate as heat without being   damaged.
    -this is the power rating, measured in watts
    typical resistors – 1/4W, 1/3W, 1/2W, etc.
    in other words, exceeding this value will likely melt the componen

  generally – higher the resister, the less current flows...

Ohm's Law
  volts - “pushing power”
  amps - “rate of electron flow”

  3V
  vs
  4V

  V/I = a constant
    -where the constant depends on the substance through which current flows and voltage is 
    applied across

  Draw picture
1. Cell has 2V
2. current of 0.4A
3. substance with a resistance of 5ohms

  cell has a voltage of 2V, so the voltage applied across the substance is also 2V.

  The current through the substance is 0.4A

  Ohm's Law:
    2V/0.4A = 5ohms
  the constant is commonly called the substance's resistance and is given the unit omega
    -pronounced ohm

  So the resistance is 5ohms
    -sometimes people use the letter R instead of omega

  So, if a voltage (V, measured in volts) is applied across a resistance (R, measured in ohms), a current (I, measured in amps) will flow.

  In other words: V/I = R

  What does the current depend on?
    -values of resistance and voltage
  
  How would you determine the current if you already knew the voltage?
    How would we do this with our example?
    V/R = I
    2V/5ohms = 0.4A

  So, what would a voltage of 10V, applied across a resistance of 20ohms, produce a current of?

    First, let's write this out:
    10V/20ohms = 0.5A

  What if we know the resistance and current and want to deduce the voltage?
    -in other words, if we have a resistance, and a current is made to flow through it, then a 
    voltage is produced across it
      how would we write this?
      V = IR
      5ohms x 0.4A = 2V

  What if we had a current of 1A flowing through a resistance of 5ohms
    how would we write this?
      1A * 5ohms = 5V
  
  Another way to remember
    draw triangle
    Cover up the missing one and do the calculation
    V/R = I
    V/I = R
    IR = V
    RI = V

  Note: voltage always applied ACROSS
    why?
      It is the force that pushes electrons...the pushing power
    
    current always flows THROUGH
    why?
      It is the rate at which electrons flow through