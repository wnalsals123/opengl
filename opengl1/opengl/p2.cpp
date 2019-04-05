#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<gl/glut.h>

void MyTimer();
void MyTimer2();

GLfloat Delta = 0.0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		//�÷����ۿ� �ʱ�ȭ ���� ����
	glBegin(GL_POLYGON);				//�����׸���
	glColor3f(1, 0, 0); 				//������
	glVertex3f(-0.1, -0.1 + Delta, 0.0);		//���ϴ� ��ǥ
	glVertex3f(0.1, -0.1 + Delta, 0.0);			//���ϴ� ��ǥ
	glVertex3f(0.1, 0.1 + Delta, 0.0);			//���� ��ǥ
	glVertex3f(-0.1, 0.1 + Delta, 0.0);			//�»�� ��ǥ	  
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
	glClearColor(0, 0, 0, 1.0);//������
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyTimer);
	glutMainLoop();
	return 0;
}