# Palm Pro Wearable Keyboard
The Palm Pro is a small wearable keyboard intended to be used for navigation control and keyboard input for smartglasses. It is designed to be an ideal keyboard for multitasking (walking, running, socializing, etc...)

More info on this project can be found [on the Palm Pro's website](https://www.parallelinnov.com/palm-pro-wearable-keyboard/). I will post a link to the CAD files to 3D print once their design is stable. 

## How it works
The microcontroller I'm using is an Adafruit feather 32u4 because it is relatively small, has on-board BLE, and on-board battery management. For the keyboard, there are 6 keys that you press in the palm of your hand. I call it a 3D-keyboard because how hard you press on a key will determine which character you choose. There are 6 keys, and 5 layers on each key. You control the space and shift keys with your thumb. They are arranged in a way that it re-uses your finger memory from typing on a qwerty keyboard, as the keys are spanned in the same approximate location if you were to fit a qwerty keyboard in the same area. You learn how deep you need to press for each character by feeling for the simulated bump feeling (vibration motor) that happens at each layer as you press down. It takes a bit of learning, but not as much as with a chorded keyboard.

Each key uses a force sensitive resistor to measure the force (Interlink Electronics FSR 400). The force-sensitive resistors will be programmed similar to a potentiometer, each having its own 2K ohm pull-down resistor to ground. On the keyboard, the FSRs and the vibration motor connections will be soldered directly to a polymer FFC breakout with solder joints. The flexible flat cable will then run to the Adafruit Feather in the electronics housing located on the back of the hand.

[Wiring diagram](https://i.imgur.com/adfmHOk.png)

## The code

The current sketch just measures a single FSR and provides a tactile 'bump' feeling when you pass over any of the 5 layers. This was to test for layer distinguishability and to dial in the force points. I used an Arduino nano clone to test it, because I don't want to solder anything to my Adafruit Feather yet. The feedback from pressing the key feels really neat. 

![Testing the FSRs](https://i.imgur.com/VURApk9.png)
 
 There's still a lot to do. I need to find an appropriate module for keyboard control that will work alongside the vibration motor code. If anybody has any suggestions or wants to contribute in any way, I'd very much appreciate it. 
