There is a good tutorial on this here :
https://www.youtube.com/watch?v=vpwYyWo8PE4
(you need hairless Midi Controller and Loop Midi)

Set the hairless midi input to the Serial Com your arduino is printing to
and the output to loopMIDI. (add a new port in Loop Midi if none exisits).

This will then seen e.g. pia pianoteq or HELM (as seen in the video above).

Currently hairless MIdi is crashing after a few nootes. We need to figure out why.

	-> likely because baud rates did mismatch.


