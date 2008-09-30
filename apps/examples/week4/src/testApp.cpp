#include "testApp.h"
#include <sstream>;

//--------------------------------------------------------------
void testApp::setup(){	 
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_COLOR_MATERIAL);

	GLfloat global_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	counter = 0;
	snapImage = 1000;
	myImage.allocate(1024, 768, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void testApp::update(){
	if(counter < 360){
		counter += 0.2;
	}else{
		counter = 0;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	glTranslated(500, 400, -200);

	GLfloat ambient[] = { 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glPushMatrix();
	glRotated(counter, 0.0, 1.0, 0.0);
	glRotated(sin(((2*pi)/360)*counter) * 360, 0.0, 0, 1.0);
	glTranslated(300, -30, 0);
	GLfloat position[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glPopMatrix();
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	
	glPushMatrix();
	glColor3f(0.7, 0.7,0);
	float mcolor[] = { 0.5f, 0.0f, 0.5f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mcolor);
	glMaterialf(GL_FRONT, GL_AMBIENT, 0.0f);
	glMaterialf(GL_FRONT, GL_DIFFUSE, 1.0f);
	glMaterialf(GL_FRONT, GL_SHININESS, 1.0f);
	glMaterialf(GL_FRONT, GL_SPECULAR, 1.0f);
	glMaterialf(GL_FRONT, GL_EMISSION, 1.0f);
	glutSolidSphere(150,50,50);
	
	glPopMatrix();
	glRotated(counter, 0.0, 1.0, 0.0);
	glRotated(sin(((2*pi)/360)*counter) * 360, 0.0, 0, 1.0);
	glTranslated(300, -30, 0);
	glColor3f(0.0, 0, 0.0);
	float scolor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, scolor);
	glMaterialf(GL_FRONT, GL_EMISSION, 1.0f);
	
	glutSolidSphere(20, 50, 50);
	
	

	
//	myImage.grabScreen(0,0,1024,768);
//	stringstream buff;
//	snapImage++;
//	buff << "/Users/andersonmiller/Documents/glart/apps/examples/week4/data/partOfTheScreen_"<< snapImage << ".png";
//	string file;
//	buff >> file;
//	myImage.saveImage(file);

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
