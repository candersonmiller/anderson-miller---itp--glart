#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofAddons.h"
#include "math.h"

class testApp : public ofSimpleApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
	private: 
		float vert[3][2];
		float rgb[3];
		int lastColor;	
		bool up;
		float counter;
		
};

#endif
	
