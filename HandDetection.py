# -*- coding: utf-8 -*-
"""
Created on Fri Apr 15 16:13:31 2022

@author: Mohamed Sobh
"""

import mediapipe as mp
import serial 
import cv2 as cv 
import time 

mp_drawing = mp.solutions.drawing_utils
mp_hand = mp.solutions.hands
ArduinoData = serial.Serial('com5',9600)  
ArduinoData.timeout = 1



cap = cv.VideoCapture(0)
cap.set(3, 1280)
cap.set(4, 720)

finger_points = [8,12,16,20]


with mp_hand.Hands(max_num_hands=1,min_detection_confidence=0.9,min_tracking_confidence=0.5) as hands:
    while cap.isOpened():
        ret,fram = cap.read()
        #detection 
        image = cv.cvtColor(fram, cv.COLOR_BGR2RGB) 
      
        #fileb the image 
        
        image = cv.flip(image , 1)
        h,w,c = image.shape;
        #print(w)
        #print(h)
        #image.flags.writeable = False
        results = hands.process(image)
        #image.flags.writeable = True
        image = cv.cvtColor(image,cv.COLOR_RGB2BGR)
        
        #print(results)
        
        if results.multi_hand_landmarks:
            for num ,hand in enumerate(results.multi_hand_landmarks):
                landmarklist = []
                
                for Id , pos in enumerate(hand.landmark):
                    landmarklist.append(pos)
                    
                
                stat = []
                for point in finger_points:
                    x , y= (int)(landmarklist[point].x * w), (int)(landmarklist[point].y * h)
                    
                    if(landmarklist[point].y > landmarklist[point-3].y):
                        stat.append(True)
                    else:
                        stat.append(False)
                     
                        
                    cv.circle(image, (x,y), 20, (255,0,0),cv.FILLED)
                
                if all(stat):
                    ArduinoData.write(b'o')
                    cntl=3
                if stat[1] == 1 and stat[2] == 1 and stat[3] == 1 and stat[0]==0 :
                    #print(landmarklist[8].x)
                    check = (int)(landmarklist[8].x * w)
                    #print(check)
                    if (check >= 550):
                        #cnt = 1
                        #print("move to next channel")
                        # to send massege to the arduino to display a function
                        ArduinoData.write(b'a')
                        cnt=1;
                        
                        
                    elif (check <= 400):
                        #cnt = 2
                        #print("get the previous channel")
                        ArduinoData.write(b'b')
                        cnt2 = 1
                        
                elif stat[1] == 0 and stat[2] == 1 and stat[3] == 1 and stat[0]==0 :
                    #print(landmarklist[8].x)
                    check = (int)(landmarklist[8].x * w)
                    check2 = (int)(landmarklist[12].x*w)
                    #print(check)
                    if (check >= 850 and check2 >= 900):
                        #cnt = 1
                        #print("volum up")
                        # to send massege to the arduino to display a function
                        ArduinoData.write(b'c')
                        cnt23=1
                        #print(ArduinoData.readline().decode('ascii'))
                        
                    elif (check <= 400 and check2 <= 400):
                        #cnt = 2
                        
                        # to send massege to the arduino to display a function
                        ArduinoData.write(b'd')
                        cnt34243=1
                        #print(ArduinoData.readline().decode('ascii'))
                        
                
                mp_drawing.draw_landmarks(image, hand , mp_hand.HAND_CONNECTIONS,
                                          mp_drawing.DrawingSpec(color=(0,0,255),thickness = 2,circle_radius=4),
                                          mp_drawing.DrawingSpec(color=(0,255,0),thickness = 1,circle_radius=2)
                                          )
                time.sleep(0.009)
       
            
        
        cv.imshow("hand traking", image)
        #print(image)
        
        
        if cv.waitKey(10) & 0xFF == ord('q'):
            break
    
    
    
cap.release()
cv.destroyAllWindows()
ArduinoData.close()