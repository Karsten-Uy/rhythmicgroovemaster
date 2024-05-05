
#include "MIDIUSB.h"
#include <Control_Surface.h>

// Input Pins

const int L1IN = 2;
const int L2IN = 3;
const int L3IN = 4; // Hi hat
const int L4IN = 5;
const int L5IN = 6;
const int L6IN = 7;

const int R1IN = 8;
const int R2IN = 9;
const int R3IN = 10;

const int K1IN = 16;
const int K2IN = 14; // Hi Hat pedal

// Button States

bool L1STATE;
bool L2STATE;
bool L3STATE;
bool L4STATE;
bool L5STATE;
bool L6STATE;
bool R1STATE;
bool R2STATE;
bool R3STATE;
bool K1STATE;
bool K2STATE;

// other

const int BCHANNEL = 0;
const int DEBOUNCETIME = 10;
const int RELEASEVEL = 127;

//-----------------------------------------
// MIDIUSB Functions

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

// Actual stuff

void setup() {

  Serial.begin(9600);

  pinMode(L1IN,INPUT_PULLUP);
  pinMode(L2IN,INPUT_PULLUP);
  pinMode(L3IN,INPUT_PULLUP);
  pinMode(L4IN,INPUT_PULLUP);
  pinMode(L5IN,INPUT_PULLUP);
  pinMode(L6IN,INPUT_PULLUP);
  pinMode(R1IN,INPUT_PULLUP);
  pinMode(R2IN,INPUT_PULLUP);
  pinMode(R3IN,INPUT_PULLUP);
  pinMode(K1IN,INPUT_PULLUP);
  pinMode(K2IN,INPUT_PULLUP);

  L1STATE = LOW;
  L2STATE = LOW;
  L3STATE = LOW;
  L4STATE = LOW;
  L5STATE = LOW;
  L6STATE = LOW;
  R1STATE = LOW;
  R2STATE = LOW;
  R3STATE = LOW;
  K1STATE = LOW;
  K2STATE = LOW;

}

void loop() {

  // Non Hats

  if (digitalRead(L1IN) != L1STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(L1IN) != L1STATE) {

      L1STATE = !L1STATE;

      if (L1STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::C[2], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::C[2], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  if (digitalRead(L2IN) != L2STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(L2IN) != L2STATE) {

      L2STATE = !L2STATE;

      if (L2STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::Db[2], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::Db[2], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  if (digitalRead(L4IN) != L4STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(L4IN) != L4STATE) {

      L4STATE = !L4STATE;

      if (L4STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::Gb[2], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::Gb[2], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  if (digitalRead(L5IN) != L5STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(L5IN) != L5STATE) {

      L5STATE = !L5STATE;

      if (L5STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::G[2], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::G[2], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  if (digitalRead(L6IN) != L6STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(L6IN) != L6STATE) {

      L6STATE = !L6STATE;

      if (L6STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::Ab[2], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::Ab[2], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  if (digitalRead(R1IN) != R1STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(R1IN) != R1STATE) {

      R1STATE = !R1STATE;

      if (R1STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::A[2], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::A[2], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  if (digitalRead(R2IN) != R2STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(R2IN) != R2STATE) {

      R2STATE = !R2STATE;

      if (R2STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::Bb[2], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::Bb[2], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  if (digitalRead(R3IN) != R3STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(R3IN) != R3STATE) {

      R3STATE = !R3STATE;

      if (R3STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::B[2], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::B[2], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  if (digitalRead(K1IN) != K1STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(K1IN) != K1STATE) {

      K1STATE = !K1STATE;

      if (K1STATE != LOW) {
        noteOn(BCHANNEL, MIDI_Notes::C[3], 0);
      } else {
        noteOn(BCHANNEL, MIDI_Notes::C[3], RELEASEVEL);
      }

      MidiUSB.flush();

    }

  }

  // Hi hat pedal

  if (digitalRead(K2IN) != K2STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(K2IN) != K2STATE) {

      K2STATE = !K2STATE;

      if (K2STATE == LOW) { // when pressed
        noteOn(BCHANNEL, MIDI_Notes::E[2], RELEASEVEL);
        delay(1);
        noteOn(BCHANNEL, MIDI_Notes::E[2], 0);
      } else { // when let go
        noteOn(BCHANNEL, MIDI_Notes::F[2], RELEASEVEL);
        delay(1);
        noteOn(BCHANNEL, MIDI_Notes::F[2], 0);
      }

      MidiUSB.flush();
    }

  }

  // Hi hats

  if (digitalRead(L3IN) != L3STATE) {

    delay(DEBOUNCETIME);

    if (digitalRead(L3IN) != L3STATE) {

      L3STATE = !L3STATE;

      if (!K2STATE) { // If hat pedal is pressed, CH

        if (L3STATE == LOW) {
          noteOn(BCHANNEL, MIDI_Notes::D[2], RELEASEVEL);
          delay(1);
          noteOn(BCHANNEL, MIDI_Notes::D[2], 0);
        }
 
      } else { // else OH

        if (L3STATE == LOW) {
          noteOn(BCHANNEL, MIDI_Notes::Eb[2], RELEASEVEL);
          delay(1);
          noteOn(BCHANNEL, MIDI_Notes::Eb[2], 0);
        }

      }

      MidiUSB.flush();

    }

  }

}



