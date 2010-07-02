#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_X 100
#define WINDOW_Y 100

typedef GLfloat point[3]; 

point v[4] ={{0.0, 0.0, 1.0}, 
             {0.0, 0.942809, -0.333333}, 
             {-0.816497, -0.471405, -0.333333}, 
             {0.816497, -0.471405, -0.333333}};

void DrawGLScene(void);
void ChangeSize(GLsizei w, GLsizei h);
void drawSquareTunnel(void);
void tetrahedron(void);
void triangle(point a, point b, point c);
void drawTunnel(void);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(WINDOW_X, WINDOW_Y);
  glutCreateWindow("simple opengl example");

  glutDisplayFunc(DrawGLScene);
  // NEW
  glutReshapeFunc(ChangeSize);

  glutMainLoop();
  return 0;
}

void DrawGLScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

  glTranslatef(0.0f, 0.0f, -100.0f);

  drawSquareTunnel(); 
  
  glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h)
{
  GLfloat nRange = 120.0f;
  // Prevent a divide by zero
  if(h == 0)
    h = 1;

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

  // Reset coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Establish clipping volume (left, right, bottom, top, near, far)
  if (w <= h) 
    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2.0f, nRange*2.0f);
  else 
    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2.0f, nRange*2.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void drawSquareTunnel(void)
{
  // Clear the window with current clearing color
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glTranslatef(0.0f, 0.0f, -100.0f);

  glPushMatrix();
  glTranslatef(60.0f, 0.0f, 0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);
  drawTunnel();
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 1.0f);
  glTranslatef(-60.0f, 10.0f, 0.0f);
  glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
  drawTunnel();
  glPopMatrix();
}

void drawTunnel(void)
{
  float fZ,bZ;
  fZ = 100.0f;
  bZ = -100.0f;

  // Front Face ///////////////////////////////////
  glBegin(GL_QUADS);
    // Pointing straight out Z
    glNormal3f(0.0f, 0.0f, 1.0f);	

    // Left Panel
    glVertex3f(-50.0f, 50.0f, fZ);
    glVertex3f(-50.0f, -50.0f, fZ);
    glVertex3f(-35.0f, -50.0f, fZ);
    glVertex3f(-35.0f,50.0f,fZ);

    // Right Panel
    glVertex3f(50.0f, 50.0f, fZ);
    glVertex3f(35.0f, 50.0f, fZ);
    glVertex3f(35.0f, -50.0f, fZ);
    glVertex3f(50.0f,-50.0f,fZ);

    // Top Panel
    glVertex3f(-35.0f, 50.0f, fZ);
    glVertex3f(-35.0f, 35.0f, fZ);
    glVertex3f(35.0f, 35.0f, fZ);
    glVertex3f(35.0f, 50.0f,fZ);

    // Bottom Panel
    glVertex3f(-35.0f, -35.0f, fZ);
    glVertex3f(-35.0f, -50.0f, fZ);
    glVertex3f(35.0f, -50.0f, fZ);
    glVertex3f(35.0f, -35.0f,fZ);

    // Top length section ////////////////////////////
    // Normal points up Y axis
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0f, 50.0f, fZ);
    glVertex3f(50.0f, 50.0f, fZ);
    glVertex3f(50.0f, 50.0f, bZ);
    glVertex3f(-50.0f,50.0f,bZ);
		
    // Bottom section
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-50.0f, -50.0f, fZ);
    glVertex3f(-50.0f, -50.0f, bZ);
    glVertex3f(50.0f, -50.0f, bZ);
    glVertex3f(50.0f, -50.0f, fZ);

    // Left section
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 50.0f, fZ);
    glVertex3f(50.0f, -50.0f, fZ);
    glVertex3f(50.0f, -50.0f, bZ);
    glVertex3f(50.0f, 50.0f, bZ);

    // Right Section
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-50.0f, 50.0f, fZ);
    glVertex3f(-50.0f, 50.0f, bZ);
    glVertex3f(-50.0f, -50.0f, bZ);
    glVertex3f(-50.0f, -50.0f, fZ);
  glEnd();

  glFrontFace(GL_CW);		// clock-wise polygons face out

  glBegin(GL_QUADS);
    // Back section
    // Pointing straight out Z
    glNormal3f(0.0f, 0.0f, -1.0f);	
    
    // Left Panel
    glVertex3f(-50.0f, 50.0f, bZ);
    glVertex3f(-50.0f, -50.0f, bZ);
    glVertex3f(-35.0f, -50.0f, bZ);
    glVertex3f(-35.0f,50.0f,bZ);
    
    // Right Panel
    glVertex3f(50.0f, 50.0f, bZ);
    glVertex3f(35.0f, 50.0f, bZ);
    glVertex3f(35.0f, -50.0f, bZ);
    glVertex3f(50.0f,-50.0f,bZ);
    
    // Top Panel
    glVertex3f(-35.0f, 50.0f, bZ);
    glVertex3f(-35.0f, 35.0f, bZ);
    glVertex3f(35.0f, 35.0f, bZ);
    glVertex3f(35.0f, 50.0f,bZ);
    
    // Bottom Panel
    glVertex3f(-35.0f, -35.0f, bZ);
    glVertex3f(-35.0f, -50.0f, bZ);
    glVertex3f(35.0f, -50.0f, bZ);
    glVertex3f(35.0f, -35.0f,bZ);
    
    // Insides /////////////////////////////
    glColor3f(0.75f, 0.75f, 0.75f);
    
    // Normal points up Y axis
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-35.0f, 35.0f, fZ);
    glVertex3f(35.0f, 35.0f, fZ);
    glVertex3f(35.0f, 35.0f, bZ);
    glVertex3f(-35.0f,35.0f,bZ);
    
    // Bottom section
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-35.0f, -35.0f, fZ);
    glVertex3f(-35.0f, -35.0f, bZ);
    glVertex3f(35.0f, -35.0f, bZ);
    glVertex3f(35.0f, -35.0f, fZ);
    
    // Left section
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-35.0f, 35.0f, fZ);
    glVertex3f(-35.0f, 35.0f, bZ);
    glVertex3f(-35.0f, -35.0f, bZ);
    glVertex3f(-35.0f, -35.0f, fZ);
    
    // Right Section
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(35.0f, 35.0f, fZ);
    glVertex3f(35.0f, -35.0f, fZ);
    glVertex3f(35.0f, -35.0f, bZ);
    glVertex3f(35.0f, 35.0f, bZ);
  glEnd();
}
