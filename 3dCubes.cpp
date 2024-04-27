# include <GL/glut.h>

int angulo = 2;

void desenha()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glRotatef(angulo, -1, -1, -1);
    glColor3f(1.0, 0.0, 0.0);

        glPushMatrix();
            glTranslatef(0, 0, 0);
            glutWireCube(20);
        glPopMatrix();

       glPushMatrix();
            glTranslatef(30, 0, 0);
            glutWireCube(20);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-30, 0, 0);
            glutWireCube(20);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 30, 0);
            glutWireCube(20);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, -30, 0);
            glutWireCube(20);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0, 30);
            glutWireCube(20);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0, -30);
            glutWireCube(20);
        glPopMatrix();

    glPopMatrix();
    glFlush();
}

void anima(int x)
{
    angulo += 2;
    glutPostRedisplay();
    glutTimerFunc(10, anima, 1);
}

void inicializa()
{
    glClearColor(255, 255, 255, 1.0);
    glMatrixMode(GL_PROJECTION);
    // define que irá manipular a matriz de projeção
    glLoadIdentity();
    // carrega a matriz limpa
    gluPerspective(90, 1, 10, 280);
    //ângulo de abertura horizontal,
    // proporção para a abertura vertical,
    // distância da câmera ao corte frontal,
    // distância da câmera ao corte traseiro.
    glMatrixMode(GL_MODELVIEW);
    // define que irá manipular a matriz de modelo
    glLoadIdentity();
    gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
    //posição em x,y,z
    //para onde olha em x,y,z
    //rotação - para onde aponta x,y,z
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(400, 400);
    glutCreateWindow("3D");
    inicializa();
    anima(1);
    glutDisplayFunc(desenha);
    glutMainLoop();
}
