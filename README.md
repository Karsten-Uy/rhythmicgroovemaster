# Rhythmic Groove Master V1

The Rhythmic Groove Master V1 is a MIDI controller project designed to enhance your guitar or bass playing experience by allowing you to seamlessly incorporate drum sounds into your performances. Simply attach it to your instrument and unlock a world of rhythmic possibilities.

## Features
- Easy Integration: Attachable to guitars or bass guitars, providing effortless integration.
- Versatile Controls: Sends MIDI notes so any DAW with a MIDI drum controller can use it and map it to arbitrary sounds
- Hit-Hat Functionality: Special hit-hat buttons offer nuanced control over percussion elements.
- Arduino Pro Micro: Powered by Arduino Pro Micro for reliable performance.
- Open-Source: Project files and code available for customization and expansion.

## Button Mappings
A diagram of the buttons with respective note labels is below. For proper pedal functionality, the C2 pedal needs to be attached to pin 16 and the hit-hat pedal needs to be attached to pin 14 on the Arduino Pro-Micro board.

![IMG_0871](https://github.com/Karsten-Uy/rhythmicgroovemaster/assets/58119515/12634ba2-9c1b-42bb-8f03-dc17c9f9dced)

- Non-Hit-Hat Buttons: Sends the labelled note-on signals when pressed and note-off signals when released at respective notes.
- Hit-Hat Pedal: Sends rapid MIDI on/off pulses at notes E1 and F1 when pressed and released respectively.
- Hit-Hat Button: Sends MIDI on/off pulses at notes D#1 and D1 when the pedal is not pressed and pressed respectively.
