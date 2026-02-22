#include "config.h"
#ifdef UNO
#include "MidiSenderUno.h"
// seems like including usb_midi.h is necessary if not in the main .ino file?
// Otherwise it doesn't know what usbMIDI is
#include <a.h>

// see here for teensy midi example (and suggested use of 74hc405/1):
// https://www.pjrc.com/teensy/td_midi.html

void MidiSenderUno::sendNoteOn(int pitch, int velocity, int channel)
{
    usbMIDI.sendNoteOn(pitch, velocity, channel);
}

void MidiSenderUno::sendNoteOff(int pitch, int velocity, int channel)
{
    usbMIDI.sendNoteOff(pitch, velocity, channel);
}

//?
void MidiSenderUno::sendControlChange(int controlNumber, int controlValue, int channel)
{
    usbMIDI.sendControlChange(controlNumber, controlValue, channel);
}

void MidiSenderUno::initialize()
{
    // no need to do anything here
}

void MidiSenderUno::loopEnd()
{
    while (usbMIDI.read())
    {
    }
}
#endif
