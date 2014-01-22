from __future__ import division
from pylab import *
import cv2

tilt_value = 340
zoom_value = -200
APPLY = True

Xin = Xout = 640
Yin = Yout = 480

def homography(tilt_value, y):
    """ Finds homography to warp the camera image to an "overhead" perspective.
        This assumes a webcam whose baseline is aligned with the top of the field of view,
        i.e. a tilted laptop screen with a built-in web cam looking just beyond the keyboard.
    """
    x = y * Xin/(1.0*Yin)
    xp = x
    yp = 2*y

    im2 = array([[xp,       0 ],
                [Xout-xp,    0 ],
                [xp,        Yout-yp],
                [Xout-xp,   Yout-yp]],
                dtype=np.float32)

    im1 = array([[Xin+tilt_value,       Yin],
                [-tilt_value,           Yin],
                [Xin,           0],
                [0,             0]],
                dtype=np.float32)

    h, mask = cv2.findHomography(im1, im2)
    return h

camera_port = 0
cameraCapture = cv2.VideoCapture(camera_port)

cv2.namedWindow("Camera", cv2.WINDOW_NORMAL)

while True:
    success, frame = cameraCapture.read()
    if APPLY:
        Yin, Xin, depth = frame.shape
        Xout, Yout = Xin, Yin
        h = homography(tilt_value, zoom_value)
        out = cv2.warpPerspective(frame, h, (Xout,Yout))
    else:
        out = frame[::-1,::-1,:] # flip the frame
        #out = frame
        pass
    cv2.imshow("Camera",out)

    k = cv2.waitKey(30)   # manually drive the OpenCV event loop
    if k != -1:
        print('Keycode:', k)
        if k == 65362:
            tilt_value -= 10 # tilt up
            print('up', tilt_value)
        elif k == 65364:
            tilt_value += 10 # tilt down
            print('down', tilt_value)
        elif k == 65361:
            zoom_value -= 10  # zoom in
            print('left', zoom_value)
        elif k == 65363:
            zoom_value += 10 # zoom out
            print('right', zoom_value)
        elif k == 116: #t
            APPLY = not APPLY
            print('toggle apply', APPLY)
        elif k in [27,  # esc
                   113, # q
                   ]:
            break
        if zoom_value > 0:
            zoom_value = 0

cameraCapture.release()
cv2.destroyWindow("Camera");
