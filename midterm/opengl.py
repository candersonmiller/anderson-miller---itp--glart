#!/usr/bin/env python

from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import random
import sys
import math
from numpy import *


counter = 0
cloudsize = 15
xrand = [cloudsize]
yrand = [cloudsize]
zrand = [cloudsize]

period = 10

for i in range(0, cloudsize):
	xrand.append(0)
	yrand.append(0)
	zrand.append(0)

#from http://www.fundza.com/c4serious/noise/perlin/perlin.html
p = (
151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,
30,69,142,8,99,37,240,21,10,23,190,6,148,247,120,234,75,0,26,197,
62,94,252,219,203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,
125,136,171,168,68,175,74,165,71,134,139,48,27,166,77,146,158,231,
83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,102,
143,54,65,25,63,161,1,216,80,73,209,76,132,187,208,89,18,169,200,
196,135,130,116,188,159,86,164,100,109,198,173,186,3,64,52,217,226,
250,124,123,5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,
58,17,182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,
221,153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,113,
224,232,178,185,112,104,218,246,97,228,251,34,242,193,238,210,144,
12,191,179,162,241,81,51,145,235,249,14,239,107,49,192,214,31,181,
199,106,157,184,84,204,176,115,121,50,45,127,4,150,254,138,236,
205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180,
151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,
30,69,142,8,99,37,240,21,10,23,190,6,148,247,120,234,75,0,26,197,
62,94,252,219,203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,
125,136,171,168,68,175,74,165,71,134,139,48,27,166,77,146,158,231,
83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,102,
143,54,65,25,63,161,1,216,80,73,209,76,132,187,208,89,18,169,200,
196,135,130,116,188,159,86,164,100,109,198,173,186,3,64,52,217,226,
250,124,123,5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,
58,17,182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,
221,153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,113,
224,232,178,185,112,104,218,246,97,228,251,34,242,193,238,210,144,
12,191,179,162,241,81,51,145,235,249,14,239,107,49,192,214,31,181,
199,106,157,184,84,204,176,115,121,50,45,127,4,150,254,138,236,
205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180)
def lerp(t, a, b):
    return a + t * (b - a)
  
def fade(t):
    return t * t * t * (t * (t * 6 - 15) + 10)
  
def grad(hash, x, y, z):
    h = hash & 15
    if h < 8:
        u = x
    else:
        u = y
    if h < 4:
        v = y
    elif h == 12 or h == 14:
        v = x
    else:
        v = z
    if h & 1 != 0:
        u = -u
    if h & 2 != 0:
        v = -v
    return u + v
  
def pnoise(x, y, z):
    global p
    X = int(math.floor(x)) & 255
    Y = int(math.floor(y)) & 255
    Z = int(math.floor(z)) & 255
    x -= math.floor(x)
    y -= math.floor(y)
    z -= math.floor(z)
    
    u = fade(x)
    v = fade(y)
    w = fade(z)
    
    A =  p[X] + Y
    AA = p[A] + Z
    AB = p[A + 1] + Z
    B =  p[X + 1] + Y
    BA = p[B] + Z
    BB = p[B + 1] + Z
    
    pAA = p[AA]
    pAB = p[AB]
    pBA = p[BA]
    pBB = p[BB]
    pAA1 = p[AA + 1]
    pBA1 = p[BA + 1]
    pAB1 = p[AB + 1]
    pBB1 = p[BB + 1]
    
    gradAA =  grad(pAA, x,   y,   z)
    gradBA =  grad(pBA, x-1, y,   z)
    gradAB =  grad(pAB, x,   y-1, z)
    gradBB =  grad(pBB, x-1, y-1, z)
    gradAA1 = grad(pAA1,x,   y,   z-1)
    gradBA1 = grad(pBA1,x-1, y,   z-1)
    gradAB1 = grad(pAB1,x,   y-1, z-1)
    gradBB1 = grad(pBB1,x-1, y-1, z-1)
    return lerp(w, 
    lerp(v, lerp(u, gradAA, gradBA), lerp(u, gradAB, gradBB)),
    lerp(v, lerp(u, gradAA1,gradBA1),lerp(u, gradAB1,gradBB1)))    


# Some api in the chain is translating the keystrokes to this octal string
# so instead of saying: ESCAPE = 27, we use the following.
ESCAPE = '\033'

# Number of the glut window.
window = 0

# Rotation angle for the triangle. 
rtri = 0.0

# Rotation angle for the quadrilateral.
rquad = 0.0


def drawSphere():
	#glPushMatrix()
	glColor3f(1,1,1)
	s1color = ( 1.0, 1.0, 1.0, 1.0 )
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, s1color)
	glMaterialf(GL_FRONT, GL_SHININESS, 1)
	glutSolidSphere(0.6,100,100)
	#glPopMatrix()
	
	
# A general OpenGL initialization function.  Sets all of the initial parameters. 
def InitGL(Width, Height):				# We call this right after our OpenGL window is created.
    glClearColor(0.0, 0.0, 0.0, 0.0)	# This Will Clear The Background Color To Black
    glClearDepth(1.0)					# Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS)				# The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST)				# Enables Depth Testing
    glEnable(GL_LIGHTING)
    glShadeModel(GL_SMOOTH)				# Enables Smooth Color Shading
	
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()					# Reset The Projection Matrix
										# Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0, float(Width)/float(Height), 0.1, 100.0)

    glMatrixMode(GL_MODELVIEW)

# The function called when our window is resized (which shouldn't happen if you enable fullscreen, below)
def ReSizeGLScene(Width, Height):
    if Height == 0:						# Prevent A Divide By Zero If The Window Is Too Small 
	    Height = 1

    glViewport(0, 0, Width, Height)		# Reset The Current Viewport And Perspective Transformation
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(45.0, float(Width)/float(Height), 0.1, 100.0)
    glMatrixMode(GL_MODELVIEW)

# The main drawing function. 
def DrawGLScene():
	global counter
	global xrand
	global yrand
	global zrand
	global cloudsize
	global period
	
	#print counter
	#clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	
	
	glLoadIdentity()
	
	
	glPushMatrix() #Push
	
	glTranslated(5, 4, -2)
	ambient = (1.0, 1.0, 1.0)
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient)
	
	glPopMatrix() #Pop
	
	
	
	glPushMatrix()  #Push
	
	glTranslated(3, -3, 0)
	position = (0, 0,-1, 1)
	specularLight = (1, 1, 1, 1)
	glLightfv(GL_LIGHT0, GL_POSITION, position)
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight)
	
	glPopMatrix() #Pop
	
	#glEnable(GL_LIGHT1)
	glEnable(GL_LIGHT0)

	
	glLoadIdentity()			

	floatingpt = float(float(counter) / float(period))
	
	#print "%.2f" % floatingpt
	glTranslate(-4, 0, 0) #jokey coming off screen effect
	glTranslatef(floatingpt * 10 , 0, 0) #flyin' by
	glTranslatef(-1.5,0.0,-6.0)				
	if( counter > period or counter == 0):
		for i in range(0, cloudsize):
			xrand[i] = random.uniform(-0.5, 0.5)
			yrand[i] = random.uniform(-0.5, 0.5)
			zrand[i] = random.uniform(-0.5, 0.5)
		#delay(1)
		counter = 1
	else:
		counter = counter + 0.03

	
	for x in range(0,cloudsize):
		glPushMatrix()  #Push
		glTranslatef(xrand[x],yrand[x],zrand[x])
		drawSphere()
		glPopMatrix()   #Pop


	glutSwapBuffers()

# The function called whenever a key is pressed. Note the use of Python tuples to pass in: (key, x, y)  
def keyPressed(*args):
	# If escape is pressed, kill everything.
    if args[0] == ESCAPE:
	    glutDestroyWindow(window)
	    sys.exit()

def main():
	global counter
	global window

	glutInit(sys.argv)
	counter = 0
	# Select type of Display mode:   
	#  Double buffer 
	#  RGBA color
	# Alpha components supported 
	# Depth buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH)
	
	# get a 640 x 480 window 
	glutInitWindowSize(640, 480)
	
	# the window starts at the upper left corner of the screen 
	glutInitWindowPosition(0, 0)
	
	# Okay, like the C version we retain the window id to use when closing, but for those of you new
	# to Python (like myself), remember this assignment would make the variable local and not global
	# if it weren't for the global declaration at the start of main.
	window = glutCreateWindow("Midterm Prototype")

   	# Register the drawing function with glut, BUT in Python land, at least using PyOpenGL, we need to
	# set the function pointer and invoke a function to actually register the callback, otherwise it
	# would be very much like the C version of the code.	
	glutDisplayFunc(DrawGLScene)
	#glutDisplayFunc()
	
	# Uncomment this line to get full screen.
	# glutFullScreen()

	# When we are doing nothing, redraw the scene.
	glutIdleFunc(DrawGLScene)
		
	# Register the function called when our window is resized.
	glutReshapeFunc(ReSizeGLScene)
	
	
	# Register the function called when the keyboard is pressed.  
	glutKeyboardFunc(keyPressed)
	
	# Initialize our window. 
	InitGL(640, 480)

	
# Print message to console, and kick off the main to get it rolling.
print "Hit ESC key to quit."

if __name__ == '__main__':
	try:
		GLU_VERSION_1_2
	except:
		print "Need GLU 1.2 to run this demo"
		sys.exit(1)
	main()
	glutMainLoop()
    	
