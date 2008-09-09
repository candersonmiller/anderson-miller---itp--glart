/*
 *  vertex.cpp
 *  openFrameworks
 *
 *  Created by C. Anderson Miller on 4/10/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "vertex.h"
#include <iostream>
vertex::vertex(){
	X = 0.0f;
	Y = 0.0f;
	translating = false;
	rotating = false;
	startTimer = 0;
	startTimet = 0;
	timeFramet = 0;
	timeFramer = 0;
	
}

vertex::vertex(float x, float y){
	X = (float)x;
	Y = (float)y;
	translating = false;
	rotating = false;

	startTimer = 0;
	startTimet = 0;
	timeFramet = 0;
	timeFramer = 0;
}

vertex::~vertex(){
	X = 0;
	Y = 0;
	while(list.size() > 0){
		list.pop();
	}
}

float vertex::getX(){
	int curr = ofGetElapsedTimeMillis();
	if(translating || rotating){
		if(translating && rotating){
			if(curr < (timeFramet + startTimet) && curr < (timeFramer + startTimer)){
				float percentageT = (float)((float)(curr - startTimet)/(float)timeFramet);
				vertex anchor = vertex(AnchorX,AnchorY);
				anchor.translate(targetXt * percentageT,targetYt*percentageT);
				vertex temp = vertex((float)ceil(X + (targetXt * percentageT)),(float) ceil( Y + (targetYt * percentageT)));
				temp.setAnchor(anchor);
			
				//ofVertex((float)ceil(X + (targetXt * percentageT)),(float) ceil( Y + (targetYt * percentageT)));
				float percentageR = (float)((float)(curr - startTimer)/(float)timeFramer);
				temp.rotate(percentageR*targetTheta);
				return temp.getX();
			}
			if(curr >= (timeFramet + startTimet) ){
				translating = false;
				translate(targetXt,targetYt);
				vertex anchor = vertex(AnchorX, AnchorY);
				anchor.translate(targetXt,targetYt);
				setAnchor(anchor);
				execute();
			}
			
			if(	curr >= (timeFramer + startTimer) ){
				rotating = false;
				rotate(targetTheta);
				execute();
				return X;
			}
		}
		
		if(translating && !rotating){
			if(curr >= (timeFramet + startTimet) ){
				translating = false;
				translate(targetXt,targetYt);
				vertex anchor = vertex(AnchorX, AnchorY);
				anchor.translate(targetXt,targetYt);
				setAnchor(anchor);
				execute();
			}else{
				//printf("current time = %d percentage
				float percentage = (float)((float)(curr - startTimet)/(float)timeFramet);
				return ((float)ceil(X + (targetXt * percentage)));
			}
		}
		
		if(rotating && !translating){
			if(	curr >= (timeFramer + startTimer) ){
				rotating = false;
				rotate(targetTheta);
				execute();
				return X;
			}else{
				float percentage = (float)((float)(curr - startTimer)/(float)timeFramer);
				vertex temp(X,Y);
				temp.setAnchor(vertex(AnchorX,AnchorY));
				temp.rotate(percentage*targetTheta);
				return temp.getX();
			}
		}
	}else{
		return X;
	}

}

void vertex::setX(float x){
	X = x;
}

float vertex::getY(){
	int curr = ofGetElapsedTimeMillis();
	if(translating || rotating){
		if(translating && rotating){
			if(curr < (timeFramet + startTimet) && curr < (timeFramer + startTimer)){
				float percentageT = (float)((float)(curr - startTimet)/(float)timeFramet);
				vertex anchor = vertex(AnchorX,AnchorY);
				anchor.translate(targetXt * percentageT,targetYt*percentageT);
				vertex temp = vertex((float)ceil(X + (targetXt * percentageT)),(float) ceil( Y + (targetYt * percentageT)));
				temp.setAnchor(anchor);
			
				//ofVertex((float)ceil(X + (targetXt * percentageT)),(float) ceil( Y + (targetYt * percentageT)));
				float percentageR = (float)((float)(curr - startTimer)/(float)timeFramer);
				temp.rotate(percentageR*targetTheta);
				return temp.getY();
			}
			if(curr >= (timeFramet + startTimet) ){
				translating = false;
				translate(targetXt,targetYt);
				vertex anchor = vertex(AnchorX, AnchorY);
				anchor.translate(targetXt,targetYt);
				setAnchor(anchor);
				execute();
			}
			
			if(	curr >= (timeFramer + startTimer) ){
				rotating = false;
				rotate(targetTheta);
				execute();
				return Y;
			}
		}
		
		if(translating && !rotating){
			if(curr >= (timeFramet + startTimet) ){
				translating = false;
				translate(targetXt,targetYt);
				vertex anchor = vertex(AnchorX, AnchorY);
				anchor.translate(targetXt,targetYt);
				setAnchor(anchor);
				execute();
			}else{
				//printf("current time = %d percentage
				float percentage = (float)((float)(curr - startTimet)/(float)timeFramet);
				return ((float) ceil( Y + (targetYt * percentage)));
			}
		}
		
		if(rotating && !translating){
			if(	curr >= (timeFramer + startTimer) ){
				rotating = false;
				rotate(targetTheta);
				execute();
				return Y;
			}else{
				float percentage = (float)((float)(curr - startTimer)/(float)timeFramer);
				vertex temp(X,Y);
				temp.setAnchor(vertex(AnchorX,AnchorY));
				temp.rotate(percentage*targetTheta);
				return temp.getY();
			}
		}
	}else{
		return Y;
	}

}

void vertex::setY(float y){
	Y = y;
}

void vertex::draw(){

		//ofVertex(getX(),getY());
		glVertex2f(getX(),getY());
}


void vertex::translate(float xAmt, float yAmt){
	
	X = getX() + xAmt;
	Y = getY() + yAmt;
	//printf("new x: %f \t new y: %f\n",X,Y);
}

bool vertex::isMoving(){
	if(rotating || translating){
		return true;
	}else{
		return false;
	}
}

void vertex::translate(int time, float xAmt, float yAmt){
	//printf("\t\t\t\t%d\n",list.size());
	//printf("\t\t\t\t\t%d %d %f %f\n",list.getTime(), list.getType(), list.getXAmt(), list.getYAmt());
	if(!translating){
		translating = true;
		startXt = X;
		startYt = Y;
		targetXt = xAmt;
		targetYt = yAmt;
		startTimet = ofGetElapsedTimeMillis();
		timeFramet = time;
	}else{
		//printf("currently involved in %d %d %f %f\n",TRANSLATION,timeFramet, targetXt,targetYt);
		list.add(TRANSLATION,time,xAmt,yAmt);
		
		//printf("otherwise engaged\nlist size %d\n",list.size());
	}
	execute();
}




void vertex::rotate(int time, float theta){
	if(!rotating){
		rotating = true;
		startXr = X;
		startYr = Y;
		startTimer =  ofGetElapsedTimeMillis();
		timeFramer = time;
		targetTheta = theta;
	}else{
		//printf("currently involved in %d %d %f",ROTATION,timeFramer, targetTheta);
		//printf("\t\t\ %d\n",list.size());
		list.add(ROTATION,time,theta);
	}
}



void vertex::rotate(vertex anchor, float theta){
	AnchorX = anchor.getX();
	AnchorY = anchor.getY();
	float anchorX = AnchorX;
	float anchorY = AnchorY;
	float tempX = X - anchorX;
	float tempY = Y - anchorY;
	float finishedX = cos(theta)*tempX - sin(theta) * tempY;
	float finishedY = sin(theta)*tempX + cos(theta) * tempY;
	finishedX += anchorX;
	finishedY += anchorY;
	X = finishedX;
	Y = finishedY;
}

void vertex::setAnchor(vertex anchor){
	AnchorX = anchor.getX();
	AnchorY = anchor.getY();
}
void vertex::rotate(float theta){
	rotate(vertex(AnchorX,AnchorY),theta);
}

vertex vertex::getAnchor(){
	return vertex(AnchorX,AnchorY);
}

void vertex::execute(){
	
	int curr = ofGetElapsedTimeMillis();
	bool condition1 =   (curr >= (timeFramet + startTimet));
	bool condition2 = 	(curr >= (timeFramer + startTimer));
	if(list.size() > 0 && (condition1 && condition2) ){
		//printf("\t\texecute called\n");
		//printf("\t\t%d\n",list.size());
		int type = list.getTime();
		int time = list.getType();
		float d1 = list.getXAmt();
		float d2 = list.getYAmt();

		if(type == ROTATION){
			rotating = true;
			startXr = X;
			startYr = Y;
			startTimer =  ofGetElapsedTimeMillis();
			timeFramer = time;
			targetTheta = d1;
		}
		
		if(type == TRANSLATION){
			translating = true;
			startXt = X;
			startYt = Y;
			targetXt = d1;
			targetYt = d2;
			startTimet = ofGetElapsedTimeMillis();
			timeFramet = time;
		}
		list.pop();
	}
}