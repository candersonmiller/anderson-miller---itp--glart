#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	center = vertex(300,300);
	top = vertex(center.getX(),center.getY());
	top.translate(0,200);
	top.setAnchor(center);
	counter = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	printf("Center X: %f  Y: %f\n",center.getX(), center.getY());
}

//--------------------------------------------------------------
void testApp::draw(){	
	
	//counter cleanup
	counter += 0.01;
	if(counter > pi * 2){
		counter = 0;
	}
	
	center = vertex(300,300);
	center.setAnchor(vertex(300,300));
	
	
	glColor3f(1.0f, 1.0f, 1.0f);
	float radius = -200;
	
	float angle = pi / 3;
	
	for(int i = 0; i < 4; i++){
		glBegin(GL_POLYGON);
		vertex tempCenter = vertex(center.getX(),center.getY());
		tempCenter.setAnchor(center);
		tempCenter.translate(100 * sin(counter), 100 * sin(counter/2));
		tempCenter.rotate((2*pi)-counter);
			for(int j = 0; j < 200; j++){
				vertex p1 = vertex(tempCenter.getX(), tempCenter.getY());
				p1.setAnchor(tempCenter);
				p1.translate(0,radius);
				p1.rotate(((j*angle + (angle * i) )/200) + counter);
				glVertex2f(p1.getX(), p1.getY());
			}

		glVertex2f(tempCenter.getX(),tempCenter.getY());
		glEnd();
	}
	
	
		center = vertex(600,300);
	
		glBegin(GL_POLYGON);
		for(int j = 0; j < 200; j++){
			vertex p1 = vertex(center.getX(), center.getY());
			p1.setAnchor(center);
			p1.translate(0,50 * sin(counter));
			p1.rotate( (j * 2 *  pi)/200);
			glVertex2f(p1.getX(), p1.getY());
		}
		

		glEnd();
							
	//
	glFlush();
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
