## Intro to Electronics
*Summer 2014, Casey Anderson*

Electricity = the flow of electrons.

In order to measure electricity, one needs to be able to figure out the number of electroncs in "the flow."

*Example 1*
There is a large tank of water (atop a very tall building). This tank has a pipe coming out of it that is capable of distributing water to a small bucket on the ground below (next to the building). For the time being, the pipe has a stopper of some sort in one end.

The water in the tank has an evenly distributed number of dust particles in it (in this case, 10 specks of dust in ever cubic centimeter of water).

Since the dust particles are evenly distributed, one can confidently deduce the following:

1. If x amount of water flows through the pipe, one can calculate the number of specks of dust which have flowed through the pipe.
2. By knowing the number of specks of dust which have flowed through the pipe, one can calculate the volume of water.

This example is analagous to electricity, however the "dust specks" are electrons.

### "Flow Rate"
  * Measured as a volume of water flowing through the pipe during a defined period of time.
  * In electronics, the flow rate is referred to as Current (symbol: I)
  * Current is measured in amperes (or amps, symbol: A)
  * 1 amp = the quantity of 1 coulomb (unit of measurement describing the number of electrons, i.e. amount of "charge") passing a point in one second

### "Flow Pressure"
  * Imagine that the building, in Example 1, is three stories in one scenario and one story in another. How would one described the difference between these two scenarios?
  * The energy contained in the water in the tank defines the water pressure. In other words, the higher the water tank, the more energy potentially exists if it were to flow.
  * In electronics, flow pressure is defined by the difference in numbers of electrons between two points.
  * This is referred to as the potential difference, but is generally simply denoted by the term Voltage (symbol: V). Potential Difference and Voltage refer to the SAME electrical characteristic.
  * The word "potential" is key in one's understanding of Voltage. Example, regardless of whether or not a 9V battery is in use, it POTENTIALLY has a 9V difference between its two terminals regardless of whether it is in use or not.
  * In other words, the battery has the potential to drive an electron through a circuit due to its 9V difference in charge.

*Example 2*
A battery powers a small lightbulb.
This could be described as series of related events:

  * The battery generates electrons at one terminal and takes in electrons at the other terminal
  * The bulb lights up as electrons flow around the circuit
  * The electrons flow around the circuit due to potential difference of battery

Batteries force electrons around a circuit only when the circuit is complete. If one end of the battery is not connected there will be incomplete/open (i.e. no electron flow), but the battery will still have the POTENTIAL to cause such a flow upon completion of the circuit. The higher the battery's voltage, the harder a cell can force electrons around a circuit.

As a subtle alteration to this example, disconnect the battery from the lightbulb. Such an action results in the following changes to our circuit:

  * The bulb does not light up
  * There is no electron flow
  * Air, an insulator, prevents electrons from jumping from one conductor (i.e. wire) to the other.

### "Flow ease"
  * The last measurable characteristic from Example 1 refers to how easy/difficult it is for water to flow out of the pipe.
  * If the size of the opening (i.e. diameter) of the water pipe can be changed, one could make the opening smaller, resulting in an increase of resistance and a decrease of the rate of flow of the water.
  * Electrically, resistance functions the same way: a resistor can allow current flow to speed up or slow down, depending on its value.

Ohm's Law
  * If there is one (and only one) formula one ought to memorize regarding electricity, this is it.
  * V/I = a constant
    -where the constant depends on the substance through which current flows and voltage is 
    applied across
  * In other words, if a voltage (V, measured in volts) is applied across a resistance (R, measured in ohms), a current (I, measured in amps) will flow.
  * To put it more simply: V/I = R