import org.lwjgl.opengl.*;
import org.lwjgl.util.glu.*;
import org.lwjgl.input.Keyboard;

/**
 * GLART_2_geometry.java
 *
 * demonstrate six types of geometry using glBegin()...glEnd()
 *
 */
public class GLART_1_geometry {
    private boolean done = false;
    private final String windowTitle = "Basic OpenGL App";
    private DisplayMode displayMode;

    /**
     * Main function just creates and runs the application.
     */
    public static void main(String args[]) {
    	GLART_1_geometry app = new GLART_1_geometry();
        app.run();
    }

    /**
     * Initialize the app, then sit in a render loop until done==true.
     */
    public void run() {
        try {
            init();
            while (!done) {
                mainloop();
                render();
                Display.update();
            }
            cleanup();
        }
        catch (Exception e) {
            e.printStackTrace();
            System.exit(0);
        }
    }

    /**
     * Initialize the environment
     * @throws Exception
     */
    private void init() throws Exception {
        initDisplay();
        initGL();
    }

    /**
     * Create an OpenGL display, in this case a fullscreen window.
     * @throws Exception
     */
    private void initDisplay() throws Exception {
        // get all possible display resolutions
        DisplayMode d[] = Display.getAvailableDisplayModes();
        // find a resolution we like
        for (int i = 0; i < d.length; i++) {
            if (d[i].getWidth() == 800
                && d[i].getHeight() == 600
                && d[i].getBitsPerPixel() == 32) {
                displayMode = d[i];
                break;
            }
        }
        // set the display to the resolution we picked
        Display.setDisplayMode(displayMode);
        Display.setTitle(windowTitle);
        // set fullscreen off
        Display.setFullscreen(false);
        // create the window
        Display.create();
    }

    /**
     * Initialize OpenGL
     *
     */
    private void initGL() {
        // Select the Projection Matrix (controls perspective)
        GL11.glMatrixMode(GL11.GL_PROJECTION);
        GL11.glLoadIdentity();    // Reset The Projection Matrix

        // Define perspective
        GLU.gluPerspective(
            45.0f,        // Field Of View
            (float)displayMode.getWidth() / (float)displayMode.getHeight(), // aspect ratio
            0.1f,         // near Z clipping plane
            100.0f);      // far Z clipping plane

        // Select The Modelview Matrix (controls model orientation)
        GL11.glMatrixMode(GL11.GL_MODELVIEW);
    }

    /**
     * Handle keyboard input.  Just check for escape key or user
     * clicking to close the window.
     */
    private void mainloop() {
        if(Keyboard.isKeyDown(Keyboard.KEY_ESCAPE)) {   // Escape is pressed
            done = true;
        }
        if(Display.isCloseRequested()) {                // Window is closed
            done = true;
        }
    }

    /**
     * Render the scene.
     */
    private void render() {
    	// Clear screen and depth buffer
    	GL11.glClear(GL11.GL_COLOR_BUFFER_BIT | GL11.GL_DEPTH_BUFFER_BIT);

    	// Select The Modelview Matrix (controls model orientation)
    	GL11.glMatrixMode(GL11.GL_MODELVIEW);

    	// Reset the Modelview matrix
    	// this resets the coordinate system to center of screen
    	GL11.glLoadIdentity();

    	// Where is the 'eye'
    	GLU.gluLookAt(
    			0f, 0f, 10f,    // eye position
    			0f, 0f, 0f,     // target to look at
    			0f, 1f, 0f);    // which way is up

    	// draw one point upper left
    	GL11.glBegin(GL11.GL_POINTS);
    	{
    		GL11.glVertex3f( -3f, 1f, 0f);    // point
    	}
    	GL11.glEnd();

    	// draw a line upper center
    	GL11.glBegin(GL11.GL_LINES);
    	{
    		GL11.glVertex3f( 0f, 1f, 0f);   // start point
    		GL11.glVertex3f( 1f, 2f, 0f);   // end point
    	}
    	GL11.glEnd();

    	// draw a long line upper center
    	GL11.glBegin(GL11.GL_LINE_STRIP);
    	{
    		GL11.glVertex3f( 3f, 1f, 0f);  // start point
    		GL11.glVertex3f( 4f, 1f, 0f);  // next point
    		GL11.glVertex3f( 5f, 2f, 0f);  // next point
    		GL11.glVertex3f( 4f, 3f, 0f);  // next point ...
    	}
    	GL11.glEnd();

    	// draw a blue triangle lower left
    	GL11.glColor3f(.5f, .5f, .9f);  // color will affect all the following verts
    	GL11.glBegin(GL11.GL_TRIANGLES);
    	{
    		GL11.glVertex3f( -3f,   -1f, 0f);   // top
    		GL11.glVertex3f( -3.5f, -2f, 0f);   // lower left
    		GL11.glVertex3f( -2.5f, -2f, 0f);   // lower right
    	}
    	GL11.glEnd();

    	// draw a violet square lower center
    	GL11.glColor3f(.8f, .5f, 1f);
    	GL11.glBegin(GL11.GL_QUADS);
    	{
    		GL11.glVertex3f( 0f, -1f, 0f);    // top left
    		GL11.glVertex3f( 0f, -2f, 0f);    // lower left
    		GL11.glVertex3f( 1f, -2f, 0f);    // lower right
    		GL11.glVertex3f( 1f, -1f, 0f);    // top right
    	}
    	GL11.glEnd();

    	// draw a polygon lower right
    	GL11.glBegin(GL11.GL_POLYGON);
    	{
    		GL11.glColor3f(.8f, .3f, .2f);       // color
    		GL11.glVertex3f( 3f, -1f, 0f);
    		GL11.glVertex3f( 2.5f, -1.5f, 0f);

    		GL11.glColor3f(1f, .3f, .0f);        // color
    		GL11.glVertex3f( 2.3f, -2f, 0f);
    		GL11.glVertex3f( 2.1f, -2.5f, 0f);

    		GL11.glColor3f(0f, 0f, .5f);         // color
    		GL11.glVertex3f(  4.5f, -2.5f, 0f);

    		GL11.glColor3f(1f, 1f, 0f);          // color
    		GL11.glVertex3f(  5f, -1.5f, 0f);
    	}
    	GL11.glEnd();

        // reset vertex color to white
    	GL11.glColor3f(1f, 1f, 1f);
    }

    /**
     * Cleanup all the resources.
     *
     */
    private void cleanup() {
        Display.destroy();
    }
}


