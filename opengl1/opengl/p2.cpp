#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<gl/glut.h>

void MyTimer();
void MyTimer2();

GLfloat Delta = 0.0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		//컬러버퍼에 초기화 색을 가함
	glBegin(GL_POLYGON);				//도형그리기
	glColor3f(1, 0, 0); 				//도형색
	glVertex3f(-0.1, -0.1 + Delta, 0.0);		//좌하단 좌표
	glVertex3f(0.1, -0.1 + Delta, 0.0);			//우하단 좌표
	glVertex3f(0.1, 0.1 + Delta, 0.0);			//우상단 좌표
	glVertex3f(-0.1, 0.1 + Delta, 0.0);			//좌상단 좌표	  
	glEnd();
	glutSwapBuffers();
}

void MyTimer() {
	if (Delta > 1.0)
		glutIdleFunc(MyTimer2);
	Delta = Delta + 0.01;
	glutPostRedisplay();
}


void MyTimer2() {
	if(Delta < -1.0)
		glutIdleFunc(MyTimer);
	Delta = Delta - 0.01;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("OpenGL Report2");
	glClearColor(0, 0, 0, 1.0);//바탕색
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyTimer);
	glutMainLoop();
	return 0;
}