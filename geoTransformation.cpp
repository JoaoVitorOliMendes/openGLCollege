#include <GL/glut.h>

float limite = 1;
float deslocaX = 0;
float deslocaY = 0;

void desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity;

	glPushMatrix();

	glTranslatef(0.3, 0.0, 0.0);
	glRotatef(45, 0, 0, 1);

	glClear(GL_COLOR_BUFFER_BIT);
	//apaga o fundo da janela
	glColor3f(1, 0, 0);

	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5, 0.2);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.4, -0.5);
	glVertex2f(0.4, -0.4);
	glVertex2f(-0.4, -0.4);
	glVertex2f(-0.4, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	glColor3f(0, 1, 0);

	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.1, 0.5);
	glVertex2f(0.1, 0.5);
	glVertex2f(0.1, -0.2);
	glVertex2f(-0.1, -0.2);
	glEnd();

	glColor3f(0, 0, 1);

	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.1, 0.7);
	glVertex2f(0.1, 0.7);
	glVertex2f(0.1, 0);
	glVertex2f(-0.1, 0);
	glEnd();

	glFlush();
	//finaliza todos os desenhos
}

void inicializa(void)
{
	glClearColor(1, 1, 1, 1);
	//define a cor para o buffer de limpeza da janela (R,G,B, alpha)
	gluOrtho2D(-limite, limite, -limite, limite);
}

void teclado(int key, int x, int y)
{
	if (key == GLUT_KEY_PAGE_UP)
	{
    	limite -= 0.1;
	}
	if (key == GLUT_KEY_PAGE_DOWN)
	{
    	limite += 0.1;
	}
	if (key == GLUT_KEY_LEFT)
	{
    	deslocaX -= 0.1;
	}
	if (key == GLUT_KEY_RIGHT)
	{
    	deslocaX += 0.1;
	}
	if (key == GLUT_KEY_UP)
	{
    	deslocaY += 0.1;
	}
	if (key == GLUT_KEY_DOWN)
	{
    	deslocaY -= 0.1;
	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-limite + deslocaX, limite + deslocaX, -limite + deslocaY, limite + deslocaY);
	glutPostRedisplay();
}

int main(int argc, char** argv)
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
