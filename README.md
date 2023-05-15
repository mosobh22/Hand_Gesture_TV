# Hand_Gesture_TV
Machine Vision Project using python and Arduino UNO

## first Take the Raw Data 
in file sketch_jul16a i take the raw data from the tv remote controller to be able to controle the tv 
we saved the raw data in the irWaves.txt

## Second Detect Hand Move
in HandDetection.py i detect and track the hand move using mediapip Framework and detect wich fingers is open and where it's place on frame
for example if you open finger nail and move it to the right once it reach to the threshold that i put based on experiment the tv should move to the next channel
how the process execute after i detect the hand and check it's action i send a character to the Arduino by makeing connection between python and the Arduino on baudrate 9600
based on the character that i send the Arduino will send the Raw Data to preform that action relevant to that character for example if you open just the finger nail and the other finger close 
and move it to the right python code will send character 'a' to the Arduino so the Arduino will send the row data that response to get the next channel

## Third Send Row Data to TV
in file finalwork i save the row data in the code for each function it have specific row data for move to next channel , previous channel and so on 
when i send cahracter to this code to send row data this mean the user make a specific action with his hand 

## Hand Action and relevant function 

'i don't care about thumb state open or close it does'nt matter'

1- open the finger nail and close the other finger and move to the right of frame this mean move to next channel

2- open the finger nail and close the other finger and move to the left of frame this mean move to previous channel

3- open the finger nail , middle finger and close the other finger and move to the right of frame this mean Volume UP

4- open the finger nail , middle finger and close the other finger and move to the left of frame this mean Volume DOWN

5- close all finger this mean close tv if TV open else open TV if TV close
