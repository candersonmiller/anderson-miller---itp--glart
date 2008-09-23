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
		void petal(float startx, float starty);
	void flower(float startx, float starty);
	private:
		float counter;
		float counter2;
	float rotation;
};

#endif
	
