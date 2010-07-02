#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>

#define kWindowWidth 400
#define kWindowHeight 300

typedef GLfloat point[3]; 

point v[4] ={{0.0, 0.0, 1.0}, 
             {0.0, 0.942809, -0.333333}, 
             {-0.816497, -0.471405, -0.333333}, 
             {0.816497, -0.471405, -0.333333}};


GLvoid DrawGLScene(void);
void tetrahedron(void);
void triangle(point a, point b, point c);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(kWindowWidth, kWindowHeight);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("simple opengl example");

  glutDisplayFunc(DrawGLScene);

  glutMainLoop();
  return 0;
}

GLvoid DrawGLScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(1.0, 1.0, 1.0); 
  glLoadIdentity(); 

  tetrahedron(); 
  glutSwapBuffers();
}

void tetrahedron(void) 
{ 
  triangle(v[0], v[1], v[2]); 
  triangle(v[3], v[2], v[1]); 
  triangle(v[0], v[2], v[3]); 
} 

void triangle( point a, point b, point c) 
{ 
  glBegin(GL_LINE_LOOP);
    glVertex3fv(a); 
    glVertex3fv(b); 
    glVertex3fv(c); 
  glEnd(); 
}
