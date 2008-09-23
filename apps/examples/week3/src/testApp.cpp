#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	counter = 0;
	counter2 = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	counter += 1;
	if(counter > 360){
		counter = 0;
	}
	counter2 += 0.0001;
	if(counter2 > 1){
		counter2 = 0;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	glTranslated(000,000, -1500);
	glPushMatrix();

	for(int j = 0; j < 5; j++){
		glTranslated(0,80,0);
		for(int i = 0; i < 10; i++){
			glRotated(cos(counter2 * pi) * 360, 1, 0.5, 0.5);
			glTranslated(80,0,0);
			flower(0,0);
		}
		glTranslated(-800,0,0);
	}



	//	glScaled(5,10,0);

//	glRotated(20.0, 0, 0, 1.0);
//	petal(0,0);
	//glRotated(95.0, 0, 0, 1.0);
	//petal(0,0);
	glPopMatrix();
	ofSetColor(0,0,0);
	ofDrawBitmapString("degrees   : " + ofToString(counter), 800, 630);
	ofDrawBitmapString("frame rate: "+ofToString(ofGetFrameRate(), 2), 800,650);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}

void testApp::petal(float startx, float starty){
	glPushMatrix();
	glScaled(6,12,0);
	glRotated(225,0,0,1);
	glColor3f(0,0.7,0.1);
	
	float centerX = startx + 10;
	float centerY = starty + 10;
	glBegin(GL_POLYGON);
		glVertex3f(startx,starty,0);
		glVertex3f(startx, starty + 10,0);
		glVertex3f(startx + 10, starty, 0);
	glEnd();
	
	glBegin(GL_POLYGON);
	for(float i = 0; i < (2 * pi); i += 0.25/pi){
		glVertex3f( centerX + (10 * cos(i)), centerY + (10 * sin(i)), 0);
	}
	glEnd();
	
	glPopMatrix();
}

void testApp::flower(float startx, float starty){
	glPushMatrix();
	glRotated(counter*2,0,0,1);
	glScaled(0.2,0.2,0);

	for(int i = 0; i < 6; i++){
		glRotated(60,0,0,1);
		petal(startx,starty);
	}
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	for(float i = 0; i < (2 * pi); i += 0.25/pi){
		glVertex3f( 0 + (90 * cos(i)), 0 + (90 * sin(i)), 0);
	}
	glEnd();
	glPopMatrix();
	
}