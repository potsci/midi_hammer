
#include "config.h"
#ifdef UNO
#include "MidiSenderUno.h"
#include <MIDI.h>
// seems like including usb_midi.h is necessary if not in the main .ino file?
// Otherwise it doesn't know what usbMIDI is
// #include <a.h>

// For the uno, we cannnot simply use usb midi, so we need to find a work around, which sends the midi_signal via the serial port and then use hairless_midi and loopMidi to make it available as a system input
// Hairless Midi : https://projectgus.github.io/hairless-midiserial/
// Loop Midi:  https://www.tobias-erichsen.de/software/loopmidi.html
// See also arduino/test_serialMidi for minimal example using just one pull up button sending one note to the serial port.

// see here for teensy midi example (and suggested use of 74hc405/1):
// https://www.pjrc.com/teensy/td_midi.html

// MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI)
MIDI_CREATE_DEFAULT_INSTANCE()

void MidiSenderUno::sendNoteOn(int pitch, int velocity, int channel)
{
    MIDI.sendNoteOn(pitch, velocity, channel);
}

void MidiSenderUno::sendNoteOff(int pitch, int velocity, int channel)
{
    MIDI.sendNoteOff(pitch, velocity, channel);
}

//?
void MidiSenderUno::sendControlChange(int controlNumber, int controlValue, int channel)
{
    MIDI.sendControlChange(controlNumber, controlValue, channel);
}

void MidiSenderUno::initialize()
{
    // no need to do anything here
}

void MidiSenderUno::loopEnd()
{
    while (MIDI.read())
    {
    }
}
#endif
