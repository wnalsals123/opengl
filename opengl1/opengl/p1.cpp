#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<gl/glut.h>

GLint mx, my;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		//�÷����ۿ� �ʱ�ȭ ���� ����
	glViewport(mx, my, 500, 500);
	glColor3f(1, 0, 0); 				//������
	glBegin(GL_POLYGON);				//�����׸���
	glVertex3f(-0.1, -0.1, 0.0);		//���ϴ� ��ǥ
	glVertex3f(0.1, -0.1, 0.0);			//���ϴ� ��ǥ
	glVertex3f(0.1, 0.1, 0.0);			//���� ��ǥ
	glVertex3f(-0.1, 0.1, 0.0);			//�»�� ��ǥ	  
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
	glClearColor(0, 0, 0, 1.0);//������
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutPassiveMotionFunc(MyMouseMove);
	glutMainLoop();
	return 0;
}