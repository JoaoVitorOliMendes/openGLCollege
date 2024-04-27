# include <GL/glut.h>

int anguloSol = 2;
int anguloTerra = 2;
int anguloLua = 2;
float zoomFactor = 100.0f;
float translateAngle = 0.5f;
float translateY = 100.0f;

void desenha()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(anguloSol, 0, 1, 0);
	glTranslatef(0, 0, 0);
	glutWireSphere(30, 20, 20);

	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(100, 0, 0);
	glRotatef(anguloTerra, 0, 1, 0);
	glutWireSphere(15, 10, 10);

	glColor3f(1.0, 1.0, 1.0);
	glRotatef(anguloTerra, 0, 1, 0);
	glTranslatef(50, 0, 0);
	glutWireSphere(10, 10, 10);
	glPopMatrix();

	glPopMatrix();
	glFlush();
}

void animaSol(int x)
{
	anguloSol += 2;
	glutPostRedisplay();
	glutTimerFunc(50, animaSol, 5);
}

void animaTerra(int x) {
	anguloTerra += 2;
	glutPostRedisplay();
	glutTimerFunc(50, animaTerra, 5);
}

void animaLua(int x) {
	anguloLua += 2;
	glutPostRedisplay();
	glutTimerFunc(50, animaLua, 5);
}

void inicializa()
{
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	// define que irá manipular a matriz de projeção
	glLoadIdentity();
	// carrega a matriz limpa
	gluPerspective(120, 1, 10, 280);
	//ângulo de abertura horizontal,
	// proporção para a abertura vertical,
	// distância da câmera ao corte frontal,
	// distância da câmera ao corte traseiro.
	glMatrixMode(GL_MODELVIEW);
	// define que irá manipular a matriz de modelo
	glLoadIdentity();
	gluLookAt(0, 100, 100, 0, 0, 0, 0, 0.5, 0);
	//posição em x,y,z
	//para onde olha em x,y,z
	//rotação - para onde aponta x,y,z
	glEnable(GL_DEPTH_TEST);
}

void teclado(int key, int x, int y)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	switch (key) {
	case GLUT_KEY_PAGE_UP: // Tecla PageUp
    	zoomFactor *= 1.1f;
    	translateY *= 1.1f;
    	gluLookAt(0, translateY, zoomFactor, 0, 0, 0, 0, translateAngle, 0);
    	break;
	case GLUT_KEY_PAGE_DOWN: // Tecla PageUp
    	zoomFactor /= 1.1f;
    	translateY /= 1.1f;
    	gluLookAt(0, translateY, zoomFactor, 0, 0, 0, 0, translateAngle, 0);
    	break;
	case GLUT_KEY_UP: // Tecla PageUp
    	translateY *= 1.1f;
    	translateAngle += 0.1f;
    	gluLookAt(0, translateY, zoomFactor, 0, 0, 0, 0, translateAngle, 0);
    	break;
	case GLUT_KEY_DOWN: // Tecla PageUp
    	translateY /= 1.1f;
    	translateAngle -= 0.1f;
    	gluLookAt(0, translateY, zoomFactor, 0, 0, 0, 0, translateAngle, 0);
    	break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("3D");
	inicializa();
	animaSol(1);
	animaTerra(1);
	animaLua(1);
	glutDisplayFunc(desenha);
	glutSpecialFunc(teclado);
	glutMainLoop();
}
