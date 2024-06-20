== Lesson 3: What is a Decibel ?
- logarithmic unit of ratio.
- 1dB is 1/10 of Bel. 10dB \= 1 Bel.
- A Bel is a description of orders of magnitude. 10:1 is 1 Bel, 100:1 is
  2 Bel.
- In mathematical terms $10^n colon 1$ where $n$ is the Bel.
- a Doubling is aproximately 3dB that is 2:1.
- dB is a relative scale.
- Ampltiude is not power but Power is Amp sqaured.
- negative dB directional beacause of log. -5dB is a gain and +5dB could
  be positive. n dB \= log(a/b).
- dB math is not the same because these are logarithmic.

== Lesson 4:
<lesson-4>
- While using GNU Radio using Signal Source be careful because it might
  overload the CPU. Throttle it according to your Sample rate.
-

== Lesson 5:
<lesson-5>
=== HACKRF Hardware:
<hackrf-hardware>
- the first three lights on the RF One are power signs. if all the three
  are not on then we are either in a lower power mode or something is
  wrong.
- RX/TX stand for recieve or transmit.
- the last three lights indicate something that is specific to the
  software you are using with the RF One.
- The reset button reboots the hardware. Another way would be to just to
  remove and plug. it is the samething if you click it.
- DFU is for firmware update or things. do0 not need it.
- Antenna Ports:
- these are SMA connectors. These are female connectors. Wifi connectors
  are male connectors RPSMA.
- Telescopic Antennas can do a wide range of frequencies.
- NEVER USE HackerRF without anything connected. Also be aware of max
  loads.
- clock in and clock out is to sync multiple HackerRF Ones or you have a
  more precise and accurate equipment.
- Max sample rates are dependent on USB port. 20 Million seems to be the
  number. a good number or the default number is 10 million samples per
  second. you can do that using: hackrf\_transfer -r /dev/null -s
  20000000

== Lesson 6: Complex Numbers:
<lesson-6-complex-numbers>
- complex numbers make sense as a translation vector. they are neither
  imaginary nor real they have both components. a + bi.
- exponentiation of $i$ is going around the unit circle. actually any
  complex number exponeated works but if the magnitude is not 1 it will
  either increase or decrease. if it is on the unit circle then it would
  go round and round.
- Tau is just 2 pi.
- when you see e^i theta it just a helix in 3D.
