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
	setAnchor(vertex(X,Y));
}

vertex::vertex(float x, float y){
	X = (float)x;
	Y = (float)y;
	//setAnchor(vertex(X,Y));
}

vertex::~vertex(){
	X = 0;
	Y = 0;
}

float vertex::getX(){
	return X;
}

void vertex::setX(float x){
	X = x;
}

float vertex::getY(){
	return Y;
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
