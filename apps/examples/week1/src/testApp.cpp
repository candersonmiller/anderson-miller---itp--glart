#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	 
	vert[0][0] = 200;
	vert[0][1] = 125;
	
	vert[1][0] = 100;
	vert[1][1] = 375;
	
	vert[2][0] = 300;
	vert[2][1] = 375;
	
	for(int i = 0; i < 3; i++){
		rgb[i] = 0.5f;
	}
	lastColor = 0;
	up = true;
	counter = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	
	if(lastColor < 3){
		lastColor += 1;
	}else{
		lastColor = 0;
	}
	
	if(rgb[0] < 0.98 && rgb[1] < 0.98 && rgb[2] < 0.98 && up){
		rgb[lastColor] += 0.001;
	}else{
		//up = false;
		for(int p = 0; p < 3; p++){
			rgb[p] = 0;
		}
	}
	
		
	
}

//--------------------------------------------------------------
void testApp::draw(){
	counter += 0.001;

	if(counter > 180){
		counter = 0;
	}
	
	float x = 0;
	float y = 0;
	
	
	for(int k = -1; k < 4; k += 1){
		glColor3f(rgb[0],rgb[1],rgb[2]);
		glBegin(GL_POLYGON);
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 2; j++){
				if(j == 0){
					x = vert[i][j];
				}else{
					y = vert[i][j];
					x = x + (250 * k);
					x = x + (  100 * sin(counter) );
					y = y + ( 100 * sin(counter * 10) );

					//y = y + (y * 1.6);
					glVertex2f(x,y);
				}
			}
		}
		glEnd();
	}

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
