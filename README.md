# PLAY

Tis repository is the software repository for the PLAY project. The PLAY app aim to convert video game controllers (VGCs) input signal into MIDI and/or OSC messages.

The PLAY project investigates the creative possibilities of VGCs as human-computer interfaces (HCIs) for musical performance and composition. The aim is to transform VGCs into adaptive musical instruments, offering a new perspective on composing and performing virtuosic music, particularly for individuals without traditional instrument expertise.



## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
    - [Mapping](#mapping)
- [Contributing](#contributing)
- [License](#license)
- [Credits](#credits)
- [Project Team](#project-team)

## Features
- Supported wired and Bluetooth VGCs: Xbox wireless controller, PS5 Dualsense controller, Nintendo Switch Joycons.
- Enable/disable the controller's IMU accelerometer and gyroscope.
- Convert input signal into MIDI and/or OSC messages.
- Customisable MIDI channel and OSC receiver IP/port.


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

Contributions to the PLAY project are welcome! If you encounter any issues or have ideas for improvements, please submit them as GitHub issues or create a pull request with your proposed changes.

## License

PLAY is licensed under the MIT License. You are free to use and distribute the software in accordance with the terms of the license. If you use this in your project kindly give credit to the team.

## Credits 

We gratefully acknowledge the support from [The Oxford Research Centre in the Humanities (HCP)](https://www.torch.ox.ac.uk/humanities-cultural-programme), Jesus College Oxford and [Royal Northern College of Music](https://www.rncm.ac.uk/) for funding parts of this project.


## Project Team
- Dr. Robert Laidlow: [Robert.laidlow@oxford.ac.uk](mailto:Robert.laidlow@oxford.ac.uk)
- Dr. Hongshuo Fan: [Hongshuo.fan@rncm.ac.uk](mailto:Hongshuo.fan@rncm.ac.uk)
- Dr. Bofan Ma: [Bofan.ma@rncm.ac.uk](mailto:Bofan.ma@rncm.ac.uk)
- Ellen Sargen: [ellensargen@gmail.com](mailto:ellensargen@gmail.com)

## References
[JUCE](https://github.com/juce-framework/JUCE)
[JoyShockLibrary](https://github.com/JibbSmart/JoyShockLibrary)
[DualSense on Windows [API]](https://github.com/Ohjurot/DualSense-Windows)
[DS4Windows](https://github.com/Ryochan7/DS4Windows)
[Nintendo_Switch_Reverse_Engineering](https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering)



