/*
 *  vertex.h
 *  openFrameworks
 *
 *  Created by C. Anderson Miller on 4/10/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef VERTEX
#define VERTEX
 
 
 #include "ofMain.h"
 #include "math.h"
 #include "instructionList.h"
 
class vertex{

	public:
		vertex();
		vertex(float x, float y);
		~vertex();
		void setAnchor(vertex anchor);
		void rotate(vertex anchor, float theta);
		void rotate(float theta);
		void rotate(int time, float theta);
		void translate(float xAmt, float yAmt);
		void translate(int time, float xAmt, float yAmt);
		bool isMoving();
		float getX();
		vertex getAnchor();
		void setX(float x);
		float getY();
		void setY(float y);
		void draw();
		bool translating;
		bool rotating;
		
		private:
	
		float X;
		float Y;
		float AnchorX;
		float AnchorY;
		float targetXt;
		float targetYt;
		float startXt;
		float startYt;
		float startXr;
		float startYr;
		float targetTheta;
		int startTimet;
		int timeFramet;
		int startTimer;
		int timeFramer;
		instructionList list;
		void execute();


};

#endif