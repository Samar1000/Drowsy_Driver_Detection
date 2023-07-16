from __future__ import division
import dlib
import imutils 
from imutils import face_utils
import cv2
import numpy as np
from scipy.spatial import distance as dist
from threading import Thread
import threading
import pygame
import argparse

from gpiozero import Buzzer
from time import sleep
import serial

def start_sound2():
    pygame.mixer.init()
    pygame.mixer.music.load("Yawn.mp3")
    pygame.mixer.music.play()
    

def lip_distance(shape):
    top_lip = shape[50:53]
    top_lip = np.concatenate((top_lip, shape[61:64]))

    low_lip = shape[56:59]
    low_lip = np.concatenate((low_lip, shape[65:68]))

    top_mean = np.mean(top_lip, axis=0)
    low_mean = np.mean(low_lip, axis=0)

    distance = abs(top_mean[1] - low_mean[1])
    return distance
    


def pep():
        buzzer.on()
        sleep(1)
        buzzer.off()
        sleep(1)
        
def blue1():
     port="/dev/rfcomm0"
     bluetooth=serial.Serial(port, 9600)
     bluetooth.flushInput()
     for i in range(5):
         bluetooth.write(b"s"+str.encode(str(i)))
         input_data=bluetooth.readline()
         print(input_data.decode())
         time.sleep(0.1)
     bluetooth.close()
     
        
def blue2():
     print("Start")
     port="/dev/rfcomm0"
     bluetooth=serial.Serial(port, 9600)
     print("Connected")
     bluetooth.flushInput()
     for i in range(5):
         print("Ping")
         bluetooth.write(b"a"+str.encode(str(i)))
         input_data=bluetooth.readline()
         print(input_data.decode())
         time.sleep(0.1)
     bluetooth.close()
     print("Done")
                       

camera = cv2.VideoCapture(0)
s, img = camera.read()
if s:


    cv2.imwrite("belt.jpg",img)
    
#Slope of line
def Slope(a,b,c,d):
    return (d - b)/(c - a)


# Reading Image
beltframe = cv2.imread("belt.jpg")
#assert not isinstance(beltframe,type(None)), 'image not found'

# Resizing The Image
beltframe = imutils.resize(beltframe, height=800)

#Converting To GrayScale
beltgray = cv2.cvtColor(beltframe, cv2.COLOR_BGR2GRAY)

# No Belt Detected Yet
belt = False

# Bluring The Image For Smoothness
blur = cv2.blur(beltgray, (1, 1))

# Converting Image To Edges
edges = cv2.Canny(blur, 50, 400)


# Previous Line Slope
ps = 0

# Previous Line Co-ordinates
px1, py1, px2, py2 = 0, 0, 0, 0

# Extracting Lines
lines = cv2.HoughLinesP(edges, 1, np.pi/270, 30, maxLineGap = 20, minLineLength = 170)

# If "lines" Is Not Empty
if lines is not None:

    # Loop line by line
    for line in lines:

        # Co-ordinates Of Current Line
        x1, y1, x2, y2 = line[0]

        # Slope Of Current Line
        s = Slope(x1,y1,x2,y2)
        
        # If Current Line's Slope Is Greater Than 0.7 And Less Than 2
        if ((abs(s) > 0.7) and (abs (s) < 2)):

            # And Previous Line's Slope Is Within 0.7 To 2
            if((abs(ps) > 0.7) and (abs(ps) < 2)):

                # And Both The Lines Are Not Too Far From Each Other
                if(((abs(x1 - px1) > 5) and (abs(x2 - px2) > 5)) or ((abs(y1 - py1) > 5) and (abs(y2 - py2) > 5))):

                    # Plot The Lines On "beltframe"
                    cv2.line(beltframe, (x1, y1), (x2, y2), (0, 0, 255), 3)
                    cv2.line(beltframe, (px1, py1), (px2, py2), (0, 0, 255), 3)

                    # Belt Is Detected
                    print ("Belt Detected")
                    belt = True

                                             
                         
                         

        # Otherwise Current Slope Becomes Previous Slope (ps) And Current Line Becomes Previous Line (px1, py1, px2, py2)            
        ps = s
        px1, py1, px2, py2 = line[0]
        
                   
if belt == False:
    print("No Seatbelt detected")
    blue1()
    exit()


buzzer = Buzzer(17)


def resize(img, width=None, height=None, interpolation=cv2.INTER_AREA):
    global ratio
    w, h = img.shape
    if width is None and height is None:
        return img
    elif width is None:
        ratio = height / h
        width = int(w * ratio)
        resized = cv2.resize(img, (height, width), interpolation)
        return resized
    else:
        ratio = width / w
        height = int(h * ratio)
        resized = cv2.resize(img, (height, width), interpolation)
        return resized
######
def shape_to_np(shape, dtype="int"):
    coords = np.zeros((68, 2), dtype=dtype)
    for i in range(36,68):
        coords[i] = (shape.part(i).x, shape.part(i).y)
    return coords
def eye_aspect_ratio(eye):
    A = dist.euclidean(eye[1], eye[5])
    B = dist.euclidean(eye[2], eye[4])
 
	# compute the euclidean distance between the horizontal
	# eye landmark (x, y)-coordinates
    C = dist.euclidean(eye[0], eye[3])
   
	# compute the eye aspect ratio
    ear = (A + B) / (2.0 * C)
 
	# return the eye aspect ratio
    return ear
alarm=False
YAWN_THRESH = 12

predictor_path = 'shape_predictor_68_face_landmarks.dat_2'

detector = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

predictor = dlib.shape_predictor(predictor_path)
(lStart, lEnd) = face_utils.FACIAL_LANDMARKS_IDXS["left_eye"]
(rStart, rEnd) = face_utils.FACIAL_LANDMARKS_IDXS["right_eye"]
total=0
while True:
    ret, frame = camera.read()
    if ret == False:
        print('Failed to capture frame from camera. Check camera index in cv2.VideoCapture(0) \n')
        break

    frame_grey = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
#     frame_resized = imutils.resize(frame, width=120)
    frame_resized = resize(frame_grey, width=120)
    dets = detector.detectMultiScale(frame_resized,scaleFactor=1.1,
                    minNeighbors=5, minSize=(30, 30),
                    flags=cv2.CASCADE_SCALE_IMAGE)
        

# Ask the detector to find the bounding boxes of each face. The 1 in the
# second argument indicates that we should upsample the image 1 time. This
# will make everything bigger and allow us to detect more faces.
    
    
    if len(dets) > 0:
        for (x, y, w, h) in dets:
            d = dlib.rectangle(int(x), int(y), int(x + w),int(y + h))
            shape = predictor(frame_resized, d)
#             shape = face_utils.shape_to_np(shape)
            shape = shape_to_np(shape)
            leftEye= shape[lStart:lEnd]
            rightEye= shape[rStart:rEnd]
            leftEAR= eye_aspect_ratio(leftEye)
            rightEAR = eye_aspect_ratio(rightEye)
            ear = (leftEAR + rightEAR) / 2.0
            distance = lip_distance(shape)
            leftEyeHull = cv2.convexHull(leftEye)
            rightEyeHull = cv2.convexHull(rightEye)
            cv2.drawContours(frame, [leftEyeHull], -1, (0, 255, 0), 1)
            cv2.drawContours(frame, [rightEyeHull], -1, (0, 255, 0), 1)
            lip = shape[48:60]
            cv2.drawContours(frame, [lip], -1, (0, 255, 0), 1)
            if (distance > YAWN_THRESH):
                cv2.putText(frame, "Yawn Alert", (10, 30),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
                alarm=True
                t=threading.Thread(target=start_sound2)
                t.start()
                t.setDaemon=True
            else:
                alarm=False
                
            
            
            if ear>.25:
                #print (ear)
                total=0

                
            else:
                total+=1
                if total>9:
                    
                    t = Thread(target = pep,args=())
                    t.deamon = True
                    t.start()  
                        

                    
                    cv2.putText(frame, "drowsiness detect" ,(250, 30),cv2.FONT_HERSHEY_SIMPLEX, 1.7, (0, 0, 0), 4)
                    
                    if total>16:
                           blue2()

                    
                    
                    
            for (x, y) in shape:
                 cv2.circle(frame, (int(x/ratio), int(y/ratio)), 3, (255, 255, 255), -1)
    cv2.imshow("image", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        camera.release()
        break
