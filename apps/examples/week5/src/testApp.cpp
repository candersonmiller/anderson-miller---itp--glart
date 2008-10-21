#include "testApp.h"
#include <sstream>;

//--------------------------------------------------------------
void testApp::setup(){	 
	counter = 0;
	counter1 = 0;
	
	snapImage = 1000;
	myImage.allocate(1024, 768, OF_IMAGE_COLOR);

	//glEnable(GL_LIGHTING);

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
	glEnable(GL_DEPTH_TEST);
	
	glTranslated(700,300,-500);
	
	ofImage gold;
	gold.allocate(256, 256, OF_IMAGE_COLOR);
	gold.loadImage("gold2.jpg");

	unsigned char* data = gold.getPixels();
	ofTexture goldTexture;
	goldTexture.allocate(256, 256, GL_RGB);
	goldTexture.loadData(data, 256, 256, GL_RGB);
	
	//gold.setUseTexture(true);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(0,0,0);
		
		glTexCoord2f(256, 0);
		glVertex3f(100,0,0);
	
		glTexCoord2f(256, 256);
		glVertex3f(100,100,0);
	
		glTexCoord2f(0, 256);
		glVertex3f(0, 100, 0);
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
