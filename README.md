# ESP8266 Plane Controller Using BLYNK
This repo contains the code for the ESP8266 microcontroller to be used as both a computer and reciever for the plane dogfight competition at the College of dupage. This code is made to work with the blynk app through a personal hotspot or Wifi of ones choosing. Extendability was kept in mind for the code so that participants can edit it to accomodate their plane design and control.

## Hardware and Software Used
- ESP8266
- 4 9g Servos
- 1 2200kv motor
- 20A motor ESC
- Plane Frame
- 3 AA battery pack
- Arduino IDE
- Blynk app

## Instructions

#### Downloads
1. Download the github repository.

2. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software) in accordance with your OS and architecture.

3. If you have an apple laptop or a windows system where the driver doesn't imediatelly install when you connect the board, download and install the following [driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).

#### Library Setup
4. Open the IDE and in the top left corner, click Arduino -> Prefrences. In the prefrences window navigate to `Additional Boards Manager URLs:` and paste in the corresponding link to your board:
- ESP8266: http://arduino.esp8266.com/stable/package_esp8266com_index.json

5. Go to Sketch -> Include Library -> Manage Libraries. Search `Blynk` and click on install repeatedly until the error message stops appearing and the library is downloaded.

6. Go to Sketch -> Include Library -> Add ZIP Library. Find the folder for this repository you downloaded on step 1, open it and select the `ESP8266WIFI` folder and press ok. Make sure the IDE installs it.

7. Go to Tools -> Board: -> Boards Manager. Search `esp8266` and click on install repeatedly until the error message stops appearing and the Package is downloaded.

#### App Setup
8. In the Blynk app, make a new device by clicking on the nut icon in the top right and clicking on the devices tab. Add a new device, name it whatever you prefer, select the corresponding board `nodeMCU`, and choose the connection type to be wifi.

9. Select joystick and place it on the very top left of the screen
- Click on it and under the output section, select the green box to the left with `[0]` on its left and on the left column select `virtual` and on the right select `V1` then press ok. Select the box immediately to the right of the green box and type in `0` and the other to the very right of the screen `180`. Repeat this exact process to the 3 boxes below  but select `Virtual` --> `V2` instead of `Virtual` --> `V1`. Once you have finished you can press ok on the very top right.
    
10. Select another joystick and place it on the very bottom left.
- Repeat the same steps you took for the top left joystick for this except make the green box with `[0]` to the left of it `Virtual` --> `V3` and the blue box with `[1]` to the left of it `Virtual` --> `V4`.
    
11. Place two vertical sliders on the very top right parallel to eachother
- Click on the slider to the left and under the output section, select the green box to the left with `[0]` on its left and on the left column select `virtual` and on the right select `V5` then press ok. Select the box immediately to the right of the green box and type in `0` and the other to the very right of the screen `10`. Repeat the same process with the slider in the very top right corner and select `V6` instead. Once you have finished you can press ok on the very top right.
   
12. Place another two vertical sliders parallel to eachother on the very bottom right
- Repeat the same steps as for the previous sliders but select `V7` and `V8` instead in the same order so that the `V8` slider is on the very bottom right. 
  
10. When the board is connected to your hotspot you can go back to this app and press the play button on the top right to start the controls.

#### Code Setup
11. Copy the `auth token` and paste it in replacing the `customAuthenticator`.

12. Replace the `ssid` with the exact name of your mobile hotspot and change the `password` to your mobile hotspot password.

13. Go to Tools -> Board: and scroll on the list until you find and select the apropriate board `NodeMCU 1.0 (ESP-12E Module)`.

14. Go to Tools -> Port and select the port that shows up when you plug the `esp8266` into the computer.

15. Click on the checkmark on the very top left of the IDE and see if the program can compile "the progress bar on the bottom right completes and the text says the program compiled properly and took ...% amound of memory"

16. If step 15 occured properly, you can make sure the `esp8266` is connected and if so, press the arrow button to the right of the checkmark and let the program upload to the `esp8266`.

17. Once it has uploaded, select the magnifying glass button on the top right and wait for the `Serial Monitor` to open. On the bottom right make sure `9600 baud` is selected and then on your `esp8266` press the `RST` button and look to see if the `esp8266` can properly connect to your phones hotspot and then the `BLYNK` server.

18. Congratulations, your new phone RC plane controller now works and can replace any $150 radio controller you would normally have to buy to pilot a RC plane!

## Authors
Nikita Lukhanin - [nikilukhan](https://github.com/nikilukhan)
