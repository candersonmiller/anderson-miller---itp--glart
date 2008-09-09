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
 
class vertex{

	public:
		vertex();
		vertex(float x, float y);
		~vertex();
		void setAnchor(vertex anchor);
		void rotate(vertex anchor, float theta);
		void rotate(float theta);
		void translate(float xAmt, float yAmt);
		float getX();
		vertex getAnchor();
		void setX(float x);
		float getY();
		void setY(float y);
		void draw();

		
		private:
	
		float X;
		float Y;
		float AnchorX;
		float AnchorY;
		float targetTheta;



};

#endif