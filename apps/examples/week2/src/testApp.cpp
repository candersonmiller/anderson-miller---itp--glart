#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	counter = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	counter += 0.5;
	if(counter > 360){
		counter = 0;
	}
}

//--------------------------------------------------------------
void testApp::draw(){	
	//glMatrixMode(GL_PROJECTION);
	//Mars
	glLoadIdentity();
	glTranslated(400,400,-100);
	glColor3f(0.7, 0.2 ,0);
	glRotatef(counter, -0.3f, 1.0f, 0);
	glTranslated(400,0, -100);
	glutSolidSphere(50,100,100);
	
	//Sun
	glLoadIdentity();
	glColor3f(0.9,0.9,0.00);
	glTranslated(400,400,-300);
	glRotatef(counter, 0.0f,1.0f,0.0f);
	glutSolidSphere(200,50,50);
	

	
	
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
