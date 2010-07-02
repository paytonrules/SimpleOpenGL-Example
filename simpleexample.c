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
void drawCircles(void);
void tetrahedron(void);
void triangle(point a, point b, point c);

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

  drawCircles(); 
  
  glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h)
{
  GLfloat nRange = 100.0f;

  // Prevent a divide by zero
  if(h == 0)
    h = 1;

  // Change the viewport each time the window is resized
  // otherwise the image can be distorted.
  // You do not have to match the window size - that's just simple.
  glViewport(0, 0, w, h);

  // Reset coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Establish clipping volume (left, right, bottom, top, near, far)
  if (w <= h) 
    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2.0f, nRange*2.0f);
  else 
    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2.0f, nRange*2.0f);

  //gluPerspective(60.0f, w/h, 1.0, 400.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void drawCircles(void)
{
  glColor3ub(255, 0, 0);
  glutSolidSphere(10.0f, 15, 15);
  glPushMatrix();

  glTranslatef(20.0f, 0.0f, -40.0f);
  glColor3ub(255, 255, 0);
  glutSolidSphere(10.0f, 15, 15);
  glPopMatrix();
}
