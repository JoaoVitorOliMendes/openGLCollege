# include <GL/glut.h>
# include<math.h>

float anguloCubo = 2.0f;
float translateSphere = 0.1f;
float deslocaz = 200.0f;
float deslocay = 0.0f;
float deslocax = 0.0f;
bool animar = true;

void desenha()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(-50, 0, 0);
    glRotatef(anguloCubo, 0, 1, 0);
    glutWireCube(30);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(50, 0, 0);
    glRotatef(anguloCubo * -1.0f, 0, 1, 0);
    glutWireCube(30);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0, sin(translateSphere) * 100, 0);
    glutWireSphere(15, 12, 12);
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

void anima(int x)
{
    if (animar) {
        anguloCubo += 2;
        translateSphere = translateSphere + 0.1f;
        glutPostRedisplay();
        glutTimerFunc(50, anima, 1);
    }
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
    gluLookAt(deslocax, deslocay, deslocaz, deslocax, deslocay, 0, 0, 1, 0);
    //posição em x,y,z
    //para onde olha em x,y,z
    //rotação - para onde aponta x,y,z
    glEnable(GL_DEPTH_TEST);
}

void teclado(int key, int x, int y)
{
    if (key == GLUT_KEY_PAGE_UP)//VERIFICA SE A TECLA PRESSIONADA FOI A UP
    {
        deslocaz -= 10.0f; // DIMINUI O TAMANHO DA JANELA DE SELECAO (ZOOM IN)
    }
    if (key == GLUT_KEY_PAGE_DOWN) //VERIFICA SE A TECLA PRESSIONADA FOI A DOWN
    {
        deslocaz += 10.0f; // AUMENTA O TAMANHO DA JANELA DE SELECAO (ZOOM OUT)
    }
    if (key == GLUT_KEY_UP)//VERIFICA SE A TECLA PRESSIONADA FOI A UP
    {
        deslocay += 10.0f; // DIMINUI O TAMANHO DA JANELA DE SELECAO (ZOOM IN)
    }
    if (key == GLUT_KEY_DOWN) //VERIFICA SE A TECLA PRESSIONADA FOI A DOWN
    {
        deslocay -= 10.0f; // AUMENTA O TAMANHO DA JANELA DE SELECAO (ZOOM OUT)
    }
    if (key == GLUT_KEY_LEFT)//VERIFICA SE A TECLA PRESSIONADA FOI A UP
    {
        deslocax += 10.0f; // DIMINUI O TAMANHO DA JANELA DE SELECAO (ZOOM IN)
    }
    if (key == GLUT_KEY_RIGHT) //VERIFICA SE A TECLA PRESSIONADA FOI A DOWN
    {
        deslocax -= 10.0f; // AUMENTA O TAMANHO DA JANELA DE SELECAO (ZOOM OUT)
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //OBSERVADOR EM 0,0 DE FRENTE PARA O OBJETO
    gluLookAt(deslocax, deslocay, deslocaz, deslocax, deslocay, 0, 0, 1, 0);
    glutPostRedisplay();   //REDESENHA
}

void tecladoNormal(unsigned char key, int x, int y) {
    if (key == 'a')
    {
        animar = false;
    }
    if (key == 'd')
    {
        animar = true;
        anima(1);
    }
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
    glutSpecialFunc(teclado);
    glutKeyboardFunc(tecladoNormal);
    glutMainLoop();
}
