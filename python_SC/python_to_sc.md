# Python to Supercollider
*Summer 2014, Casey Anderson*

Note: anything in between carrots (`<` to `>`) denotes user input.

*Note: Let's say you do not use iPython, and prefer to use Python in the command line as installed via OSX. Good news for you! The only thing you will need to change throughout this tutorial is the install code (i.e. instead of `ipython setup.py install`, you can just type `python setup.py install`).
## step one
Go [here](http://supercollider.sourceforge.net/downloads/) to download SuperCollider. We are going to focus on some very simple applications in SC, but if you are curious to read more about how it works, I would recommend checking out the [wiki](http://supercollider.sourceforge.net/wiki/) and/or the [SC book](http://supercolliderbook.net/) (alternately, if you find yourself swept off your feet by SC, you should sign up for the mailing list [warning: hundreds of emails a day...]), which will eventually function as a help database that lives in your email. You can search the mailing list via google, but I think that is more of a pain in the ass than doing so in GMail, for example. Once your download is complete, go ahead and install the program.

## step two
We are going to use [OpenSoundControl](http://opensoundcontrol.org/introduction-osc) to talk to SuperCollider via iPython, so we are going to need a Python Module in order to facilitate that connection. Open Sound Control (or OSC for short) is a network-based protocol to allow for communications between multiple computers or multiple programs on the same computer. We are basically going to use SuperCollider as our audio engine and Python as our controller.

Go [here](https://trac.v2.nl/wiki/pyOSC) to get the module for Python.

## step three

Once installed, launch your terminal. Navigate to the directory where your file ended up (ex: `cd Downloads`) and then type `ls` to get the path of the folder we downloaded. Change directories again to get inside that folder (ex: `cd pyOSC-0.3.5b-5294`) and then install setup (ex: `sudo ipython setup.py install`).

## step four

OSC is a network protocol: we have a sender who sends messages (with some network [IP] address) that is capable of passing messages to a receiver (if there is a receiver currently listening). If there is no receiver, the messages the sender outputs simply disappear. Our receiver is going to live in SuperCollider, so after you have installed the pyOSC module, let's switch gears to SC.

SC has two components to it: the lang (for example, a blank window which should appear if you hit <Command+N>), where you will tell SC what to do, and the server (those two modules at the bottom left of your screen...), which will receive information from the lang and run our audio (among other things, the details of which i will spare you from). The lang is where you type and execute code (by highlighting and pressing <Function+Enter>), which, if it does not involve audio, you can do without booting the server.

The window that says "post" is the console/post window. Messages/Errors from SC will appear there, and it is your primary tool to track the interaction between the lang and the server.

The server should be off on startup. For most fun things in SC you are going to need to boot the localhost server (and sometimes the internal one, but those are only for certain situations), so go ahead and do that (it should be in the lower left-hand corner of your screen). While you are at it, go ahead and make a new window (<Command+N>).

So, we get a startup dialog in the post window confirming what port the `Server` is on, the detected audio devices, what is set as input/output at boot, and various other default settings. Super exciting so far, I know.

## step five

So, let's start coding in our lang window. I am going to make two things: a `SynthDef` that plays a Sine Wave and an `OSCresponder` that listens for any message sent that is prepended with the symbol `'/print'`. Copy and paste the code below into a new window:

```
//receiving from iPython

s.boot;

(
SynthDef( \sin,	{ | amp = 0.01, freq = 333, trig = 1 |
	var env, sig;
	env = EnvGen.kr( Env.asr( 0.001, 0.9, 0.001 ), trig, doneAction: 0 );
	sig = LFTri.ar( [ freq, freq * 0.999 ], 0.0, amp ) * env;
	Out.ar( [ 0 ], sig * 0.6 );
}).add;

h = Synth( \sin, [ \amp, 0.4 ] );

x = OSCFunc( { | msg, time, addr, port |
	var pyFreq;
	
	pyFreq = msg[1].asFloat;
	( "freq is " + pyFreq ).postln;
	h.set( \freq, pyFreq );
}, '/print' );
)
```

You could use functions to generate audio in SC, but SC has an optimized way of taking in information about `UGens` (building blocks for dealing with control or audio information) and their interconnections: `SynthDef`s (i.e. `Synth Definitions`). A `SynthDef` tells the server how to generate audio and translates that information to bite code. You can think of a `SynthDef` and its resulting `Synth`s in a similar manner that one thinks about classes and instances: a `SynthDef` is the skeleton that defines a particular instance (or multiple instances) of a (lot of) playing `Synth`(s).

The first thing we need to do is create a `SynthDef` that will let our server know how to create a Sine Wave. We name our sine wave (ex: `\sin`), and then define its arguments and their defaults (in this case, I am declaring arguments named `amp` [amplitude], `freq` [frequency], and `trig` [or trigger, which I use for gating], and setting their default values). I then create two variables, `env` (short for envelope, or what will allow our synth to turn on or off [though that is not really what it is doing, but it will sound that way to us]) and `sig` (short for signal).

The `env` variable contains two `UGen`s: `EnvGen`, which controls how my envelope behaves, and `Env`, which controls what type of envelope I am using. Here I am using an `asr` (attack, sustain, release) envelope. When the `EnvGen` activates the `Env`, it will have an `attack` of 0.001 (seconds) and will then `sustain` at an amplitude of 0.9 (notice that I am not using my `amp` argument here...more on that later [fyi: amplitude in SC is always a floating point number between 0.0 and 1.0]). When the `EnvGen` is deactivated, the `Env` will release (turn off) in 0.001 seconds.

The `EnvGen` controls when the `Env` is active. If active (i.e. if my `trig` argument is set to 1) it will apply the Envelope to the `SinOsc`, causing it to start playing. If inactive (i.e. if my `trig` argument is set to 0), it will either do nothing (i.e. we will get no sound), or if it was already playing, will stop playing my `SinOsc` (releasing, or fading out, the sound in 0.001 seconds).

Notice that `EnvGen` gets a `.kr` here, which means it is a control rate `UGen`. Control rate `UGen`s do not generate audio, but instead operate on audio. `doneActions` (seemingly the least reliable part of SC...) control what happens to the Synth when it is finished. In this case, my `doneAction` is set to 0, which means "do nothing when the envelope is finished." Generally, the only two `doneActions` you need to worry about are "0" or "2" (2 frees the enclosed synth, i.e. deletes it from the server). Seriously, these never seem reliable and I hate them. Unfortunately, you need them (particularly for envelopes).

The `sig` variable contains our signal generator, in this case a `SinOsc UGen`. You can check the help file on `SinOsc` if you want, but, basically, all I am doing in here is taking in a frequency (via the `freq` argument), setting the phase to 0.0, and creating a placeholder for `amp`, which will control the volume of my `SinOsc`. One nice thing about SC is multi-channel expansion: I am using an array of two `freq` arguments here, though one is multiplying whatever that argument is set by 0.999. This will do two things: one, it will create stereo `SinOsc`'s, simply by inserting an array of two `freq`'s, and two, one will be 0.001 hz lower than the other, which will produce a slight phase cancellation (which I think is more fun than a boring sine tone). The `sig` variable is, finally, multiplied by the `env` variable, which is what will allow our `SinOsc` to have an attack or release.

The last part of this that we need to be worried about is the `Out UGen`. As you can probably imagine, this is what actually converts the digital information associated with the interaction of the above `UGen`s in my `SynthDef` into audio that can be played out of speakers. Here you can specify the number of channels the `Out UGen` will run the synth on (since we have two here, it will be stereo), and then also specify what is actually being played out. I added another volume scaling instance here, multiplying my `sig` variable by 0.6, to give the synths more head-room.

Once the `SynthDef` is sent to the server, we can tell the server to create an instance of this `Synth` by assigning it to a variable (in this case `h`), and simply typing the following: `h = Synth( \sin );`. Notice that I also took this opportunity to set the `amp` argument I mentioned earlier to 0.4, which again functioned to give my playing synth more headroom (that way if I wanted to run four of these I would be less likely to get distortion).

Now that we have assigned an instance of `Synth(\sin)` to `h`, we can alter `h` on the fly. If you were to type `h.set( \amp, 0.9 )`, you could change the amplitude level of that particular instance of the `Synth`. `.set` is what is going to give us the ability to change the frequency from iPython without having to stop the `Synth`.

The `OSCFunc` here is assigned to a variable (`x`), so I could reference it elsewhere if I wanted to. I have set the `OSCFunc` to respond to any message being sent over the server prepended with the message <code>'\print'</code>. For our purposes, we can ignore the time and responder arguments, and simply focus on <code>msg</code>, which is where we will receive frequency data from <code>pyOSC</code>.
<br/>In order to do this, I created a variable called <code>pyFreq</code>, and set it to store whatever value comes in at position 1 in the <code>msg</code> array. I am also converting that number to a floating point one, though, apparently, <code>pyOSC</code> passes this information along for us (so this part is redundant). I then post <code>pyFreq</code> to the post window (so I can monitor what frequency my <code>SinOsc</code> is playing), and use <code>h.set</code> to set the symbol <code>freq</code>, from our <code>SynthDef \sin</code>, to <code>pyFreq</code>. The last thing we have to do is add the responder to the server. Go ahead and execute all of this code, and let's move back to iPython.
## step six
Launch iPython via the command line. Here is the code we are going to use:
<pre><code>In [1]: import OSC
In [2]: import time, random
In [3]: client = OSC.OSCClient()
In [4]: client.connect( ( '127.0.0.1', 57120 ) )
In [5]: msg = OSC.OSCMessage()
In [6]: msg.setAddress("/print")
In [7]: msg.append(500)
In [8]: client.send(msg)</code></pre>
Great! Now we can set the frequency of our <code>SinOsc</code> from iPython via <code>OSC</code>. If you are curious how the <code>msg</code> is formatted, prior to sending out to SC, simply type <code>msg</code> in the command line and hit enter. When you do so, you should see something like this:
<pre><code>Out[12]: ['/print', ',i', 500]</code></pre>
The simplest way to change the frequency that SC is playing would be to do the following:
<pre>In [18]: msg[0] = 4000
In [19]: client.send(msg)</pre>
However, it would be more convenient to define a new function that will handle changing frequencies, or could play a melody, or whatever.
<br/>While this is a pretty stripped down example, it suggests nice possibilities for us. For example, since Python is good at scraping data from the web relatively quickly (which SC, for example, does not really do at all [to my knowledge]), we could easily create a SynthDef that will "read" the news to us by sending the results of our scraping to SC and calling the .speak function on that data. Even better, at least for me, is the possibility of both reading, misreading/chopping/stuttering text from the web while simultaneously making horrible noises (which will likely be the next tutorial to follow up on this). Huzzah!