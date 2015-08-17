FFT

~bSamp = Buffer.read( s, "/Users/mdp/Desktop/salton_sea_test_tracks_01_12_14.wav" );
~len = ((~bSamp.numFrames)/(~bSamp.sampleRate));

(
SynthDef( \play, { | amp = 0.9, dur = 1, trig = 1, bufnum, rate = 1, effectsBus |
    var env, line, play, sig;

    env = EnvGen.kr( Env.asr( 0.01, amp, 0.01 ), trig, doneAction: 2 );        //notice that doneAction is set to 2 here
    line = Line.kr( 0.0, 1.5, dur, 0.9, doneAction: 0 );
    play = PlayBuf.ar( 1, bufnum, line, loop: 1 ) * env;
    Out.ar( effectsBus, play );        //so this sample is being played, but not monitored (i.e. not audible) on a bus
}).add;

SynthDef( \bpf_delay, { | inBus, bD = 0.0, maxd = 2, delaytime = 0.0, freq = 0.0, trig = 0, rq = 0.5, sF, dur, amp = 0.0 |
    var delay, env, in, line;

    in = In.ar( inBus, 2 );                    //here i establish a way to read input from elsewhere into this Synth
    line = Line.kr( Rand(sF, sF * 12), Rand(sF, sF * 12), dur );           //i use lots of random number generators on prototyping stuff, here is an example of one way of doing this
    delay = BPF.ar( DelayN.ar( in, maxd, Rand(0.01, maxd ) ), line, rq, amp);
    env = EnvGen.kr( Env.perc( 0.01, dur, amp ), trig, doneAction: 2 );
    Out.ar( [ 0, 1 ], env * delay);
}).add;

)

b = Bus.audio(s, 2 );                   //make an audio bus
~vol = Bus.control(s, 1).set(0.99);     //make and set a control bus (ditto next two lines)
~dur = Bus.control(s, 1).set(20.0);
~rq  = Bus.control(s, 1).set(0.3);

~y = Synth(\play, [\amp, 0.99, \trig, 1, \dur, ~len, \bufnum, ~bSamp, \effectsBus, b.index ]);

// OSC
OSCFunc({|msg, time, addr, recvPort|

    if( msg[1] == 1,{
        Synth.after(~y, \bpf_delay, [\inBus, b.index, \sF, 50, \trig, 1, \dur, ~dur.asMap, \rq, ~rq.asMap, \amp, ~vol.asMap ] );
    });
}, '/1/push1');

OSCFunc({|msg, time, addr, recvPort|
//  msg[1].postln;
    ~vol.set(msg[1] );
}, '/1/fader1');

OSCFunc({|msg, time, addr, recvPort|
    var len;
    len = msg[1].linlin( 0.0, 1.0, 5, 40 );
//  len.postln;
    ~dur.set( len );
}, '/1/fader2');

OSCFunc({|msg, time, addr, recvPort|
    var len;
    len = msg[1].linlin( 0.0, 1.0, 0.1, 0.01 );
//  len.postln;
    ~rq.set( len );
}, '/1/fader3');

s.scope;

Quarks.gui;
