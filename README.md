# PLAY

Tis repository is the software repository for the PLAY project. The PLAY app aim to convert video game controllers (VGCs) input signal into MIDI and/or OSC messages.

The PLAY project investigates the creative possibilities of VGCs as human-computer interfaces (HCIs) for musical performance and composition. The aim is to transform VGCs into adaptive musical instruments, offering a new perspective on composing and performing virtuosic music, particularly for individuals without traditional instrument expertise.



## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
    - [MIDI Mapping](#midi-mapping)
- [Contributing](#contributing)
- [License](#license)
- [Credits](#credits)
- [Project Team](#project-team)

## Features
- Current support VGCs: Xbox wirelless controller, PS5 Dualsense controller, Nitendo Switch Joycons.
- Enable/disable controller's IMU accelerometer and gyroscope.
- Convert input signal into MIDI and/or OSC messages.
- Customizedable MIDI channel and OSC port.


## Installation
1. Go the [GitHub release page](https://github.com/HongshuoFan/PLAY/releases).
2. Download the latest version of the software package (macOSX only for now).
3. Unzip the software package.
4. Copy the PLAY app to your application folder.

Note: If you see 'Open a Mac app from an unidentified developer', go to this [page](https://support.apple.com/en-gb/guide/mac-help/mh40616/13.0/mac/13.0) for a solution.

## Usage
1. Pair the controller with your computer.
2. Lunch the PLAY app.
3. Select your controller using the drop down menu.
4. Enable MIDI and/or OSC sender.

Option: enable/disable controller's IMU accelerometer and gyroscope.

### Mapping:

**Xbox wireless controller**

Controller input  |  MIDI message | OSC address     |
:----------------:|:-------------:|:---------------:|
Button A          |  Note 60      |  /buttons/a     |
Button B          |  Note 61      |  /buttons/b     |
Button X          |  Note 62      |  /buttons/x     |
Button Y          |  Note 63      |  /buttons/y     |
Dpad Up           |  Note 64      |  /dpad/up       |
Dpad Down         |  Note 65      |  /dpad/down     |
Dpad Left         |  Note 66      |  /dpad/left     |
Dpad Right        |  Note 67      |  /dpad/right    |
Button Rb         |  Note 68      |  /buttons/rb    |
Button Lb         |  Note 69      |  /buttons/lb    |
Button view       |  Note 70      |  /buttons/view  |
Button Share      |  Note 71      |  /buttons/share |
Button menu       |  Note 72      |  /buttons/menu  |
Left trigger      |  MIDI CC 1    |  /leftTrigger   |
Right trigger     |  MIDI CC 2    |  /rightTrigger  |
Left stick X      |  MIDI CC 7    |  /leftStick/x   |
Left stick Y      |  MIDI CC 8    |  /leftStick/y   |
Right stick X     |  MIDI CC 10   |  /rightStick/x  |
Right stick Y     |  MIDI CC 11   |  /rightStick/y  |

 
## Contributing

## License

## Credits 

## Project Team

## References