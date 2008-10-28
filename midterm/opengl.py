#!/usr/bin/env python

from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import random
import os
import sys
import math
import Image
from numpy import *
from pnoise import pnoise


####### To Do:
#  		(done) Commit to Git Repository
#  		Tweak Lighting
#		Tweak Colors
#		Sun (done, tweaking)
#       Image file for frame (xcode working)
#		Basic Rotation (done)
#       Green Grass (as per Tom's suggestion)
#       (done) sinewave()
imagecounter = 1000
counter = 0
cloudsize = 16
xrand = [cloudsize]
yrand = [cloudsize]
zrand = [cloudsize]
period = 20

for i in range(0, cloudsize):
	xrand.append(0)
	yrand.append(0)
	zrand.append(0)


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
	glMaterialf(GL_FRONT, GL_SHININESS, 0.2)
	glutSolidSphere(0.6,100,100)
	#glPopMatrix()
	
	
# A general OpenGL initialization function.  Sets all of the initial parameters. 
def InitGL(Width, Height):				# We call this right after our OpenGL window is created.
    glClearColor(0.539, 0.777, 0.957, 1.0)	# This Will Clear The Background Color To Black
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
	global imagecounter
	global counter
	global xrand 	#array containing positions of all spheres (x values)
	global yrand	#array containing positions of all spheres (y values)
	global zrand	#array containing positions of all spheres (z values)
	global cloudsize
	global period
	
	#print counter
	#clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	
	
	glLoadIdentity()
	
	
	#ambient scene light
	glPushMatrix() #Push
	glTranslated(5, 4, 4)
	ambient = (0.55, 0.55, 0.55)
	#ambient = (0.3, 0.3, 0.3)
	#ambient = (0.1, 0.1, 0.1)
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient)
	glPopMatrix() #Pop
	
	
	
	#sunlight
	sun = 0  # 1 for on, 0 for off
	if(sun):
		glPushMatrix()
		glTranslatef(-5, 3, -10)
		glColor3f(255, 249, 78)
		s1color = ( 1.0, 0.93, 0.27, 1.0 )
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, s1color)
		glMaterialf(GL_FRONT, GL_SHININESS, 1)
		glutSolidSphere(1,100,100)
		glPopMatrix()
	
	
	position = (-5, 1,-10, 1)
	specularLight = (1.0, 1.0, 1.0, 1.0)
	glLightfv(GL_LIGHT1, GL_POSITION, position)
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight)


	#fill light
	position1 = (3, -3,5, 1)
	specularLight1 = (0.539, 0.777, 0.957, 0.2)
	glLightfv(GL_LIGHT2, GL_POSITION, position1)
	glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight1)




	glEnable(GL_LIGHT0)
	#glEnable(GL_LIGHT1)
	glEnable(GL_LIGHT2)
	
	glLoadIdentity()			


	glPushMatrix()
	glTranslatef(0,-27,-12)
	glColor3f(0,1,0)
	s1color = ( 0.0, 1.0, 0.0, 1.0 )
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, s1color)
	glMaterialf(GL_FRONT, GL_SHININESS, 0.2)
	glutSolidSphere(24,100,100)
	glPopMatrix()



	floatingpt = float(float(counter) / float(period))
	
	#print "%.2f" % floatingpt
	glTranslate(-4.5, 0, 0) #jokey coming off screen effect
	glTranslatef(floatingpt * 12 , math.sin((xrand[0] + floatingpt)*5) * 1, 0) #flyin' by
	glTranslatef(-1.5,0.0,-6.0)				
	if( counter > period or counter == 0):   #time to make a new cloud
		#this is how you make a new cloud
		for i in range(0, cloudsize):
			xrand[i] = random.uniform(-.5, .5)
			yrand[i] = random.uniform(-.5, .5)
			zrand[i] = random.uniform(-.5, .5)
			
		#delay(1)
		counter = 1
	else:
		counter = counter + 0.03
	

	##this is how we draw clouds
	glPushMatrix() #push
	glRotatef(20 * floatingpt, 1.0, 0.5, 0.0)
	
	for x in range(0,cloudsize):
		glPushMatrix()  #Push
		glTranslatef(xrand[x],yrand[x],zrand[x])
		drawSphere()
		glPopMatrix()   #Pop
	glPopMatrix() #pop


	write = 0
	imagecounter = imagecounter + 1
	#print imagecounter
	if(write and imagecounter > 1120):
		size = 640, 480
		tempimage = Image.new('RGB', size, (0,0,0))
		print "reading pixels"
		pixels = glReadPixels(0, 0, 640, 480, GL_RGB, GL_FLOAT)
		print "done reading pixels"
		#print pixels[0][0][0]
		#print pixels[0][0][1]
		#print pixels[0][0][2]
		
		print "writing pixels to file"
		pix = tempimage.load()
		for x in range(640):
			for y in range(480):
				pix[x,y] = (int(pixels[x][y][0] * 255),int(pixels[x][y][1] * 255),int(pixels[x][y][2] * 255))
		
		towrite = Image.new('RGB', size)
		towrite.putdata(pix)
		print "done writing pixels"
		outfile = 'frame00%d.jpg' % imagecounter

		towrite.save(outfile, "JPEG")
		print "done saving"
	

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
	glutFullScreen()

	# When we are doing nothing, redraw the scene.
	glutIdleFunc(DrawGLScene)
		
	# Register the function called when our window is resized.
	glutReshapeFunc(ReSizeGLScene)
	
	
	# Register the function called when the keyboard is pressed.  
	glutKeyboardFunc(keyPressed)
	
	# Initialize our window. 
	InitGL(320, 240)

	
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
    	
