#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	center = vertex(300,300);
}

//--------------------------------------------------------------
void testApp::update(){
	printf("X: %f  Y: %f",center.getX(), center.getY());
}

//--------------------------------------------------------------
void testApp::draw(){
	glBegin(GL_POLYGON);					
	glColor3f(0.0f, 0.2f, 1.0f);
	
	glEnd();						
	
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
