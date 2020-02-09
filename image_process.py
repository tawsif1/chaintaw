import os 
import sys
import random 
from PIL import Image, ImageDraw
import cv2 
import serial 
import struct 
import time


#arduinoData = serial.Serial('COM3', 9600, timeout=1)

#def sendValues(position):
#    arduinoData.write(position)

cam = cv2.VideoCapture(0)

cv2.namedWindow("test")

img_counter = 0

while True:
    ret, frame = cam.read()
    cv2.imshow("test", frame)
    if not ret:
        break
    k = cv2.waitKey(1)

    if k%256 == 27:
        # ESC pressed
        print("Escape hit, closing...")
        break
    elif k%256 == 32:
        # SPACE pressed
        img_name = "opencv_frame_{}.png".format(img_counter)
        cv2.imwrite(img_name, frame)
        print("{} written!".format(img_name))
        img_counter += 1

cam.release()
img = cv2.imread(img_name,1)
im = Image.open (img_name)
isize = im.size
walnut = Image.open ('reference.png')
wsize = walnut.size
x0, y0 = wsize [0] // 2, wsize [1] // 2
pixel = walnut.getpixel ( (x0, y0) ) [:-1]
def diff (a, b):
    return sum ( (a - b) ** 2 for a, b in zip (a, b) )

best = (100000, 0, 0)
for x in range (isize [0] ):
    for y in range (isize [1] ):
        ipixel = im.getpixel ( (x, y) )
        d = diff (ipixel, pixel)
        if d < best [0]: best = (d, x, y)

draw = ImageDraw.Draw (im)
x, y = best [1:]
draw.rectangle ( (x - x0, y - y0, x + x0, y + y0), outline = 'red')
im.save ('out.png')
cv2.destroyAllWindows()


print(x)
print(y)

#arduinoData.write(225)

#sendValues(x)
#print(arduinoData.readline())
#sendValues(y)
#print(arduinoData.readline())