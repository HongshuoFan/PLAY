# PLAY

This repository houses the PLAY application, designed to transform video game controllers (VGCs) into dynamic musical instruments. The PLAY app converts the input signals from VGCs into MIDI and/or OSC messages, facilitating their use in musical performance and composition.


## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Mapping Guide](#mapping-guide)
- [Contributing](#contributing)
- [License](#license)
- [Credits](#credits)
- [Project Team](#project-team)
- [References](#references)

## Features
- **VGC Support**: Compatible with wired and Bluetooth VGCs including Xbox wireless controller, PS5 Dualsense controller, and Nintendo Switch Joycons.
- **IMU Support**: Option to enable/disable the controller's IMU accelerometer and gyroscope.
- **Customization**: Customizable MIDI channel and OSC receiver IP/port for tailored integration into musical setups.
- **Signal Conversion**: Ability to convert input signals into either MIDI or OSC messages, or both.
- **PS5 Dualsense adaptive trigger**: Changing the Dualsense controller triggers resistance.


## Installation
1. Navigate to the [GitHub release page](https://github.com/HongshuoFan/PLAY/releases).
2. Download the latest software package (currently available for macOS).
3. Extract the contents of the package.
4. Drag and drop the PLAY app into your Applications folder.

*Note*: If you encounter a warning about unidentified developers, refer to [this Apple support page](https://support.apple.com/en-gb/guide/mac-help/mh40616/13.0/mac/13.0) for assistance.

## Usage
1. Connect the controller to your computer via pairing or USB connection.
2. Launch the PLAY app.
3. Use the dropdown menu to select your controller.
4. Activate MIDI and/or OSC output as needed.

*Optional*: Toggle the controller's IMU features according to your preferences.

## Mapping Guide:

### Xbox Wireless Controller

Controller Input  |  MIDI Message | OSC Address     |
|-----------------|---------------|-----------------|
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

### PS5 Dualsense controller
*Coming soon*

### Nintendo Switch Joycons
*Coming soon*
 
## Contributing

Contributions to the PLAY project are welcome! If you encounter any issues or have ideas for improvements, please submit them as GitHub issues or create a pull request with your proposed changes.

## License

PLAY is licensed under the [MIT License](LICENSE). You are free to use and distribute the software in accordance with the terms of the license. If you use this in your project kindly give credit to the team.

## Credits 

Special thanks to [The Oxford Research Centre in the Humanities (HCP)](https://www.torch.ox.ac.uk/humanities-cultural-programme), Jesus College Oxford, and the [Royal Northern College of Music](https://www.rncm.ac.uk/) for their support and funding.


## Project Team
- Dr. Robert Laidlow: [robert.laidlow@oxford.ac.uk](mailto:robert.laidlow@oxford.ac.uk)
- Dr. Hongshuo Fan: [hongshuo.fan@rncm.ac.uk](mailto:hongshuo.fan@rncm.ac.uk)
- Dr. Bofan Ma: [bofan.ma@rncm.ac.uk](mailto:bofan.ma@rncm.ac.uk)
- Ellen Sargen: [ellensargen@gmail.com](mailto:ellensargen@gmail.com)

## References
- [JUCE Framework](https://github.com/juce-framework/JUCE)
- [JoyShockLibrary](https://github.com/JibbSmart/JoyShockLibrary)
- [DualSense Windows API](https://github.com/Ohjurot/DualSense-Windows)
- [DS4Windows](https://github.com/Ryochan7/DS4Windows)
- [Nintendo Switch Reverse Engineering](https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering)


