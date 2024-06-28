import cv2
import mediapipe as mp
import time
import HandTrackingModule as htm
import serial

arduinoData=serial.Serial('com11',115200) 

pTime = 0
cTime = 0
cap = cv2.VideoCapture(0)
detector = htm.handDetector()

cap.set(3,1280)
cap.set(4,720)

while True:
    success, img = cap.read()
    img = detector.findHands(img, draw=False)
    lmList = detector.findPosition(img, draw=False)
    fingerCount=[]
    if len(lmList) != 0:
        if lmList[4][1]>lmList[5][1]:
            fingerCount.append(1)
        else:
            fingerCount.append(0)

        if lmList[8][2]<lmList[6][2]:
            fingerCount.append(1)
        else:
            fingerCount.append(0)
            
        if lmList[12][2]<lmList[10][2]:
           fingerCount.append(1)
        else:
            fingerCount.append(0)
        
        if lmList[16][2]<lmList[14][2]:
           fingerCount.append(1)
        else:
            fingerCount.append(0)

        if lmList[20][2]<lmList[18][2]:
           fingerCount.append(1)
        else:
            fingerCount.append(0)

        print(fingerCount[:])
        no=fingerCount.count(1)
        print(no)
        
        cmd=str(no)
        cmd=cmd+'\r'
        print(cmd)
        arduinoData.write(cmd.encode())

    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime
    cv2.putText(img, str(int(fps)), (10, 70), cv2.FONT_HERSHEY_PLAIN, 3,(255, 0, 255), 3)
    cv2.imshow("Image", img)
    if cv2.waitKey(1) & 0xFF==ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
