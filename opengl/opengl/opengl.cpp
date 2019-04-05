#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<gl/glut.h>
 
GLint mx, my;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		//컬러버퍼에 초기화 색을 가함
	glViewport(mx, my, 500, 500);
	glColor3f(1, 0, 0); 				//도형색
	glBegin(GL_POLYGON);				//도형그리기
	glVertex3f(-0.1, -0.1, 0.0);		//좌하단 좌표
	glVertex3f(0.1, -0.1, 0.0);			//우하단 좌표
	glVertex3f(0.1, 0.1, 0.0);			//우상단 좌표
	glVertex3f(-0.1, 0.1, 0.0);			//좌상단 좌표	  
	glEnd();
	glFlush();
}

void MyMouseMove(GLint x, GLint y) {
	mx = x;
	my = 500 - y;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Report1");
	glClearColor(0, 0, 0, 1.0);//바탕색
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutPassiveMotionFunc(MyMouseMove);
	glutMainLoop();
	return 0;
}