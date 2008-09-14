#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	counter = 0;
	counter1 = 0;
	glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void testApp::update(){
	counter += 0.25;
	if(counter > 360){
		counter = 0;
	}
	
	counter1 += 0.5;
	if(counter1 > 360){
		counter1 = 0;
	}
	 
}

//--------------------------------------------------------------
void testApp::draw(){	
	glMatrixMode(GL_PROJECTION);
	
	
	glTranslated(700,-300,-500); //origin point
	
	
	//Sun
	glPushMatrix();
	glTranslated(-225,0,0);
	glRotatef(counter,0,1,0);
	glColor3f(0.9,0.9,0.00);
	//glutSolidSphere(150,50,50);	
	glutSolidCube(150);
	
	//Mars
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.7, 0.2 ,0);
	glRotatef(counter, -0.3f, 1.0f,0);
	glTranslated(100,100,0); //away from "origin"
	//glutSolidSphere(50,50,50);
	glRotatef(counter,0,1,0);
	glutSolidCube(50);
	
	//Mars Moon
	glPushMatrix();
	glTranslated(-60,0,0);
	glRotatef(counter1, 0.1f, 1.0f, 0);
	glColor3f(1.0, 1.0,1.0);
	//glutSolidSphere(10,50,50);
	glRotatef(counter,0,1,0);
	glutSolidCube(10);
	
	
	glPopMatrix();
	glPopMatrix();
	glColor3f(0,0.6,0);
	glTranslated(-200,0,0);
	glRotatef(counter1 , 0.0f, 1.0f, 0.0f);
	glTranslated(-400,-20,0);
	//glutSolidSphere(60,50,50);
	glRotatef(counter,0,1,0);
	glutSolidCube(60);

	/*glLoadIdentity();
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
	glutSolidSphere(200,50,50);*/
	

	
	
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
