#include <GL/glut.h>
#include <iostream>
using namespace std;

float zoomFactor = 1.0f;
float translateX = 0.1f;
float translateY = 0.1f;

void desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//apaga o fundo da janela
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(-0.8, 0.8);
	glVertex2f(0.8, 0.8);
	glVertex2f(0.8, -0.8);
	glVertex2f(-0.8, -0.8);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.6, -0.6);
	glVertex2f(0.0, 0.6);
	glVertex2f(0.6, -0.6);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, -0.4);
	glVertex2f(0.0, -0.3);
	glVertex2f(0.6, -0.4);
	glVertex2f(0.6, -0.6);
	glVertex2f(-0.6, -0.6);
	glEnd();
	//encerra o desenho
	glFlush();
	//finaliza todos os desenhos
}

void inicializa(void)
{
	glClearColor(0, 0, 0, 1);
	//define a cor para o buffer de limpeza da janela (R,G,B, alpha)
	gluOrtho2D(1, 1, 1, 1);
}

//void teclado(int key, int x, int y)
//{
//	float a = 1.0f;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (key == GLUT_KEY_PAGE_UP)
//	{
//    	gluOrtho2D(x-2, x+2, x-2, x+2);
//	}
//	else if (key == GLUT_KEY_PAGE_DOWN)
//	{
//    	gluOrtho2D(1, 1, 1, 1);
//	}
//	else if (key == GLUT_KEY_LEFT)
//	{
//    	gluOrtho2D(1, 1, 1, 1);
//	}
//	else if (key == GLUT_KEY_RIGHT)
//	{
//    	gluOrtho2D(1, 1, 1, 1);
//	}
//	else if (key == GLUT_KEY_UP)
//	{
//    	gluOrtho2D(1, 1, 1, 1);
//	}
//	else if (key == GLUT_KEY_DOWN)
//	{
//    	gluOrtho2D(1, 1, 1, 1);
//	}
//	glutPostRedisplay();
//}
void teclado(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_PAGE_UP: // Tecla PageUp
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluOrtho2D(-2 * zoomFactor, 2 * zoomFactor, -2 * zoomFactor, 2 * zoomFactor);
    	zoomFactor *= 1.1; // Ajuste o fator de zoom para a próxima vez
    	glutPostRedisplay();
    	break;
	case GLUT_KEY_PAGE_DOWN: // Tecla PageDown
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluOrtho2D(-2 * zoomFactor, 2 * zoomFactor, -2 * zoomFactor, 2 * zoomFactor);
    	zoomFactor /= 1.1; // Ajuste o fator de zoom para a próxima vez
    	glutPostRedisplay();
    	break;
	case GLUT_KEY_UP: // Tecla Up - mover para cima
    	glTranslatef(0, translateY, 0);
    	glutPostRedisplay();
    	break;
	case GLUT_KEY_DOWN: // Tecla Down - mover para baixo
    	glTranslatef(0, -1*translateY, 0);
    	glutPostRedisplay();
    	break;
	case GLUT_KEY_LEFT: // Tecla Left - mover para esquerda
    	glTranslatef(-1*translateX, 0, 0);
    	glutPostRedisplay();
    	break;
	case GLUT_KEY_RIGHT: // Tecla Right - mover para direita
    	glTranslatef(translateX, 0, 0);
    	glutPostRedisplay();
    	break;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	//define o tamanho da janeja (largura e altura) em pixels
	glutInitWindowPosition(0, 0);
	//define a posição da janela (x e Y)
	glutCreateWindow("Desenho da Linha");
	//Cria janela do tamanho e posição definidos
	inicializa();
	glutDisplayFunc(desenha);
	glutSpecialFunc(teclado);
	glutMainLoop();
}
