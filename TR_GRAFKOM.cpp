#include <windows.h>
#include <stdlib.h>
#include <gl/glut.h>

void init(void);
void tampil(void);
void mouse ( int button , int state , int x , int y); //672018009 672018012 672018023
void ukuran (int , int);
void mouseMotion(int x , int y);
void keyboard(unsigned char, int x, int y);
int x;
float a;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth ;
int A =0;
int B =0;
int C =0;
float D =1;
float E =1;
float F =1;

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("3d");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(3.0f);
	glViewport(200, 100, 400, 350);
}
void bangkudepan()
{
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//depan bangku bawah
	glVertex3f(-20.7, 1.3, -25.0);
	glVertex3f(-20.7, 0.3, -21.0);
	glVertex3f(-15.3, 0.3, -21.0);
	glVertex3f(-15.3, 1.3, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//depan bangku atas
	glVertex3f(-20.7, 1.6, -25.0);
	glVertex3f(-20.7, 0.6, -21.0);
	glVertex3f(-15.3, 0.6, -21.0);
	glVertex3f(-15.3, 1.6, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//tutup depan
	glVertex3f(-20.7, 0.6, -21.0);
	glVertex3f(-20.7, 0.3, -21.0);
	glVertex3f(-15.3, 0.3, -21.0);
	glVertex3f(-15.3, 0.6, -21.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//tutup depan
	glVertex3f(-20.7, 1.6, -25.0);
	glVertex3f(-20.7, 1.3, -25.0);
	glVertex3f(-15.3, 1.3, -25.0);
	glVertex3f(-15.3, 1.6, -25.0);
	glEnd();
}
void bangkubkg()
{
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//belakang bangku
	glVertex3f(-20.7, 1.3, 25.0);
	glVertex3f(-20.7, 0.3, 21.0);
	glVertex3f(-15.3, 0.3, 21.0);
	glVertex3f(-15.3, 1.3, 25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//belakang bangku atas
	glVertex3f(-20.7, 1.6, 25.0);
	glVertex3f(-20.7, 0.6, 21.0);
	glVertex3f(-15.3, 0.6, 21.0);
	glVertex3f(-15.3, 1.6, 25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//belakang depan
	glVertex3f(-20.7, 0.6, 21.0);
	glVertex3f(-20.7, 0.3, 21.0);
	glVertex3f(-15.3, 0.3, 21.0);
	glVertex3f(-15.3, 0.6, 21.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//belakang depan
	glVertex3f(-20.7, 1.6, 25.0);
	glVertex3f(-20.7, 1.3, 25.0);
	glVertex3f(-15.3, 1.3, 25.0);
	glVertex3f(-15.3, 1.6, 25.0);
	glEnd();
}
void bangkukanan()
{
	glBegin(GL_POLYGON);//kanan bangku bawah
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(26.0, 0.5, -16.0);
	glVertex3f(26.0, 0.5, -6.0);
	glVertex3f(34.0, 4.0, -6.0);
	glVertex3f(34.0, 4.0, -16.0);
	glEnd();
	glBegin(GL_POLYGON);//kanan bangku atas
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(26.0, 0.5 + 0.3, -16.0);
	glVertex3f(26.0, 0.5 + 0.3, -6.0);
	glVertex3f(34.0, 4.0 + 0.3, -6.0);
	glVertex3f(34.0, 4.0 + 0.3, -16.0);
	glEnd();
	glBegin(GL_POLYGON);//kanan bangku tutup depan
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(26.0, 0.5, -16.0);
	glVertex3f(26.0, 0.5 + 0.3, -16.0);
	glVertex3f(26.0, 0.5 + 0.3, -6.0);
	glVertex3f(26.0, 0.5, -6.0);
	glEnd();
	glBegin(GL_POLYGON);//kanan bangku tutup belakang
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(34.0, 4.0, -6.0);
	glVertex3f(34.0, 4.0 + 0.3, -6.0);
	glVertex3f(34.0, 4.0 + 0.3, -16.0);
	glVertex3f(34.0, 4.0, -16.0);
	glEnd();
}
void bangkukiri()
{
	glBegin(GL_POLYGON);//kiri bangku
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-26.0, 0.5, -16.0);
	glVertex3f(-26.0, 0.5, -6.0);
	glVertex3f(-34.0, 4.0, -6.0);
	glVertex3f(-34.0, 4.0, -16.0);
	glEnd();
	glBegin(GL_POLYGON);//kanan bangku atas
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-26.0, 0.5 + 0.3, -16.0);
	glVertex3f(-26.0, 0.5 + 0.3, -6.0);
	glVertex3f(-34.0, 4.0 + 0.3, -6.0);
	glVertex3f(-34.0, 4.0 + 0.3, -16.0);
	glEnd();
	glBegin(GL_POLYGON);//kanan bangku tutup depan
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-26.0, 0.5, -16.0);
	glVertex3f(-26.0, 0.5 + 0.3, -16.0);
	glVertex3f(-26.0, 0.5 + 0.3, -6.0);
	glVertex3f(-26.0, 0.5, -6.0);
	glEnd();
	glBegin(GL_POLYGON);//kanan bangku tutup belakang
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-34.0, 4.0, -6.0);
	glVertex3f(-34.0, 4.0 + 0.3, -6.0);
	glVertex3f(-34.0, 4.0 + 0.3, -16.0);
	glVertex3f(-34.0, 4.0, -16.0);
	glEnd();
}
void bangkudpnlt2()
{
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//bangku depan-bawah
	glVertex3f(-20.7, 7.5, -37.0);
	glVertex3f(-20.7, 4.8, -31.0);
	glVertex3f(-14.2, 4.8, -31.0);
	glVertex3f(-14.2, 7.5, -37.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//bangku depan-atas
	glVertex3f(-20.7, 7.5 + 0.3, -37.0);
	glVertex3f(-20.7, 4.8 + 0.3, -31.0);
	glVertex3f(-14.2, 4.8 + 0.3, -31.0);
	glVertex3f(-14.2, 7.5 + 0.3, -37.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//tutup depan
	glVertex3f(-20.7, 4.8, -31.0);
	glVertex3f(-20.7, 4.8 + 0.3, -31.0);
	glVertex3f(-14.2, 4.8 + 0.3, -31.0);
	glVertex3f(-14.2, 4.8, -31.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//tutup belakang
	glVertex3f(-20.7, 7.5, -37.0);
	glVertex3f(-20.7, 7.5 + 0.3, -37.0);
	glVertex3f(-14.2, 7.5 + 0.3, -37.0);
	glVertex3f(-14.2, 7.5, -37.0);
	glEnd();
}
void bangkubkglt2()
{
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//bangku depan-bawah
	glVertex3f(-20.7, 7.5, 37.0);
	glVertex3f(-20.7, 4.8, 31.0);
	glVertex3f(-14.2, 4.8, 31.0);
	glVertex3f(-14.2, 7.5, 37.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//bangku depan-atas
	glVertex3f(-20.7, 7.5 + 0.3, 37.0);
	glVertex3f(-20.7, 4.8 + 0.3, 31.0);
	glVertex3f(-14.2, 4.8 + 0.3, 31.0);
	glVertex3f(-14.2, 7.5 + 0.3, 37.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//tutup depan
	glVertex3f(-20.7, 4.8, 31.0);
	glVertex3f(-20.7, 4.8 + 0.3, 31.0);
	glVertex3f(-14.2, 4.8 + 0.3, 31.0);
	glVertex3f(-14.2, 4.8, 31.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//tutup belakang
	glVertex3f(-20.7, 7.5, 37.0);
	glVertex3f(-20.7, 7.5 + 0.3, 37.0);
	glVertex3f(-14.2, 7.5 + 0.3, 37.0);
	glVertex3f(-14.2, 7.5, 37.0);
	glEnd();
}
void bangkukananlt2()
{
	glBegin(GL_POLYGON);//bangku kanan
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(39.0, 9.7, -14.0);
	glVertex3f(33.0, 6.7, -14.0);
	glVertex3f(33.0, 6.7, -22.0);
	glVertex3f(39.0, 9.7, -22.0);
	glEnd();
}
void bangkukirilt2()
{
	glBegin(GL_POLYGON);//bangku kanan
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-39.0, 9.7, -14.0);
	glVertex3f(-33.0, 6.7, -14.0);
	glVertex3f(-33.0, 6.7, -22.0);
	glVertex3f(-39.0, 9.7, -22.0);
	glEnd();
}
void bangkudpnlt3()
{
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//depan-atas
	glVertex3f(-20.5, 15.5, -43.0);
	glVertex3f(-20.5, 9.0, -36.0);
	glVertex3f(-15.5, 9.0, -36.0);
	glVertex3f(-15.5, 15.5, -43.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//depan-bawah
	glVertex3f(-20.5, 15.5  + 0.3, -43.0   + 0.3);
	glVertex3f(-20.5, 9.0  + 0.3, -36.0   + 0.3);
	glVertex3f(-15.5, 9.0  + 0.3, -36.0   + 0.3);
	glVertex3f(-15.5, 15.5  + 0.3, -43.0   + 0.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//tutup belakang
	glVertex3f(-20.5, 15.5, -43.0);
	glVertex3f(-20.5, 15.5  + 0.3, -43.0   + 0.3);
	glVertex3f(-15.5, 15.5  + 0.3, -43.0   + 0.3);
	glVertex3f(-15.5, 15.5, -43.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//depan-bawah
	glVertex3f(-20.5, 9.0, -36.0);
	glVertex3f(-20.5, 9.0  + 0.3, -36.0   + 0.3);
	glVertex3f(-15.5, 9.0  + 0.3, -36.0   + 0.3);
	glVertex3f(-15.5, 9.0, -36.0);
	glEnd();
}
void bangkubkglt3()
{
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//depan
	glVertex3f(-20.5, 15.5, 43.0);
	glVertex3f(-20.5, 9.0, 36.0);
	glVertex3f(-15.5, 9.0, 36.0);
	glVertex3f(-15.5, 15.5, 43.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//depan-bawah
	glVertex3f(-20.5, 15.5  + 0.3, 43.0   - 0.3);
	glVertex3f(-20.5, 9.0  + 0.3, 36.0   - 0.3);
	glVertex3f(-15.5, 9.0  + 0.3, 36.0   - 0.3);
	glVertex3f(-15.5, 15.5  + 0.3, 43.0   - 0.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//tutup belakang
	glVertex3f(-20.5, 15.5, 43.0);
	glVertex3f(-20.5, 15.5  + 0.3, 43.0   - 0.3);
	glVertex3f(-15.5, 15.5  + 0.3, 43.0   - 0.3);
	glVertex3f(-15.5, 15.5, 43.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//depan-bawah
	glVertex3f(-20.5, 9.0, 36.0);
	glVertex3f(-20.5, 9.0  + 0.3, 36.0   - 0.3);
	glVertex3f(-15.5, 9.0  + 0.3, 36.0   - 0.3);
	glVertex3f(-15.5, 9.0, 36.0);
	glEnd();
}
void chelsea()
{
	//HURUF CHELSEA
	glBegin(GL_LINE_STRIP);		//HURUF C
	glColor3f(1.0, 1.0, 1.0);	//HURUF C BAWAH
	glVertex3f(-19.7, 0.8 + 0.3, -21.7);
	glVertex3f(-19.7, 0.7 + 0.3, -21.7);
	glVertex3f(-16.3, 0.7 + 0.3, -21.7);
	glVertex3f(-16.3, 0.8 + 0.3, -21.7);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF C ATAS
	glVertex3f(-19.7, 1.2 + 0.3, -24.0);
	glVertex3f(-19.7, 1.3 + 0.3, -24.0);
	glVertex3f(-16.3, 1.3 + 0.3, -24.0);
	glVertex3f(-16.3, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF C ATAS BAWAH
	glVertex3f(-19.7, 1.2 + 0.3, -24.0);
	glVertex3f(-19.7, 0.7 + 0.3, -21.7);
	glVertex3f(-19.6, 0.7 + 0.3, -21.7);
	glVertex3f(-19.6, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	//HURUF H
	glColor3f(1.0, 1.0, 1.0);	//HURUF H KANAN
	glVertex3f(-10.4, 1.2 + 0.3, -24.0);
	glVertex3f(-10.4, 0.7 + 0.3, -21.7);
	glVertex3f(-10.3, 0.7 + 0.3, -21.7);
	glVertex3f(-10.3, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF H TENGAH
	glVertex3f(-13.7, 0.9 + 0.3, -22.8);
	glVertex3f(-13.7, 1.0 + 0.3, -22.8);
	glVertex3f(-10.3, 1.0 + 0.3, -22.8);
	glVertex3f(-10.3, 0.9 + 0.3, -22.8);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF H KIRI
	glVertex3f(-13.7, 1.2 + 0.3, -24.0);
	glVertex3f(-13.7, 0.7 + 0.3, -21.7);
	glVertex3f(-13.6, 0.7 + 0.3, -21.7);
	glVertex3f(-13.6, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);		//HURUF E 1
	glColor3f(1.0, 1.0, 1.0);	//HURUF E TENGAH
	glVertex3f(-7.7, 1.0 + 0.3, -22.8);
	glVertex3f(-7.7, 0.9 + 0.3, -22.8);
	glVertex3f(-4.3, 0.9 + 0.3, -22.8);
	glVertex3f(-4.3, 1.0 + 0.3, -22.8);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	
	glColor3f(1.0, 1.0, 1.0);	//HURUF E BAWAH
	glVertex3f(-7.7, 0.8 + 0.3, -21.7);
	glVertex3f(-7.7, 0.7 + 0.3, -21.7);
	glVertex3f(-4.3, 0.7 + 0.3, -21.7);
	glVertex3f(-4.3, 0.8 + 0.3, -21.7);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF E ATAS
	glVertex3f(-7.7, 1.2 + 0.3, -24.0);
	glVertex3f(-7.7, 1.3 + 0.3, -24.0);
	glVertex3f(-4.3, 1.3 + 0.3, -24.0);
	glVertex3f(-4.3, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF E KIRI
	glVertex3f(-7.7, 1.2 + 0.3, -24.0);
	glVertex3f(-7.7, 0.7 + 0.3, -21.7);
	glVertex3f(-7.6, 0.7 + 0.3, -21.7);
	glVertex3f(-7.6, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);		//HURUF L
	glColor3f(1.0, 1.0, 1.0);	//HURUF L KIRI
	glVertex3f(-1.7, 1.2 + 0.3, -24.0);
	glVertex3f(-1.7, 0.7 + 0.3, -21.7);
	glVertex3f(-1.6, 0.7 + 0.3, -21.7);
	glVertex3f(-1.6, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	
	glColor3f(1.0, 1.0, 1.0);	//HURUF L BAWAH
	glVertex3f(-1.7, 0.8 + 0.3, -21.7);
	glVertex3f(-1.7, 0.7 + 0.3, -21.7);
	glVertex3f(1.8, 0.7 + 0.3, -21.7);
	glVertex3f(1.8, 0.8 + 0.3, -21.7);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF S ATAS
	glVertex3f(4.4, 1.2 + 0.3, -24.0);
	glVertex3f(4.4, 1.3 + 0.3, -24.0);
	glVertex3f(7.5, 1.3 + 0.3, -24.0);
	glVertex3f(7.5, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	
	glColor3f(1.0, 1.0, 1.0);	//HURUF S KIRI
	glVertex3f(4.4, 1.2 + 0.3, -24.0);
	glVertex3f(4.4, 0.9 + 0.3, -22.8);
	glVertex3f(4.5, 0.9 + 0.3, -22.8);
	glVertex3f(4.5, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	
	glColor3f(1.0, 1.0, 1.0);	//HURUF S TENGAH
	glVertex3f(7.5, 1.0 + 0.3, -22.8);
	glVertex3f(7.5, 0.9 + 0.3, -22.8);
	glVertex3f(4.4, 0.9 + 0.3, -22.8);
	glVertex3f(4.4, 1.0 + 0.3, -22.8);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	
	glColor3f(1.0, 1.0, 1.0);	//HURUF S KANAN
	glVertex3f(7.5, 0.6 + 0.3, -21.7);
	glVertex3f(7.5, 0.9 + 0.3, -22.8);
	glVertex3f(7.6, 0.9 + 0.3, -22.8);
	glVertex3f(7.6, 0.6 + 0.3, -21.7);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	
	glColor3f(1.0, 1.0, 1.0);	//HURUF S BAWAH
	glVertex3f(7.5, 0.6 + 0.3, -21.7);
	glVertex3f(7.5, 0.5 + 0.3, -21.7);
	glVertex3f(4.4, 0.5 + 0.3, -21.7);
	glVertex3f(4.4, 0.6 + 0.3, -21.7);
	glEnd();
	
	glBegin(GL_LINE_STRIP);		//HURUF E 2
	glColor3f(1.0, 1.0, 1.0);	//HURUF E TENGAH
	glVertex3f(13.5, 1.0 + 0.3, -22.8);
	glVertex3f(13.5, 0.9 + 0.3, -22.8);
	glVertex3f(10.4, 0.9 + 0.3, -22.8);
	glVertex3f(10.4, 1.0 + 0.3, -22.8);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	
	glColor3f(1.0, 1.0, 1.0);	//HURUF E BAWAH
	glVertex3f(13.5, 0.8 + 0.3, -21.7);
	glVertex3f(13.5, 0.7 + 0.3, -21.7);
	glVertex3f(10.4, 0.7 + 0.3, -21.7);
	glVertex3f(10.4, 0.8 + 0.3, -21.7);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF E ATAS
	glVertex3f(13.5, 1.2 + 0.3, -24.0);
	glVertex3f(13.5, 1.3 + 0.3, -24.0);
	glVertex3f(10.4, 1.3 + 0.3, -24.0);
	glVertex3f(10.4, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF E KIRI
	glVertex3f(10.4, 1.2 + 0.3, -24.0);
	glVertex3f(10.4, 0.7 + 0.3, -21.7);
	glVertex3f(10.5, 0.7 + 0.3, -21.7);
	glVertex3f(10.5, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);		//HURUF A
	glColor3f(1.0, 1.0, 1.0);	//HURUF A KIRI
	glVertex3f(16.4, 1.2 + 0.3, -24.0);
	glVertex3f(16.4, 0.7 + 0.3, -21.7);
	glVertex3f(16.5, 0.7 + 0.3, -21.7);
	glVertex3f(16.5, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF A KANAN
	glVertex3f(19.5, 1.2 + 0.3, -24.0);
	glVertex3f(19.5, 0.7 + 0.3, -21.7);
	glVertex3f(19.6, 0.7 + 0.3, -21.7);
	glVertex3f(19.6, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);	//HURUF A ATAS
	glVertex3f(19.5, 1.2 + 0.3, -24.0);
	glVertex3f(19.5, 1.3 + 0.3, -24.0);
	glVertex3f(16.4, 1.3 + 0.3, -24.0);
	glVertex3f(16.4, 1.2 + 0.3, -24.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);	
	glColor3f(1.0, 1.0, 1.0);	//HURUF A TENGAH
	glVertex3f(19.5, 1.0 + 0.3, -22.8);
	glVertex3f(19.5, 0.9 + 0.3, -22.8);
	glVertex3f(16.4, 0.9 + 0.3, -22.8);
	glVertex3f(16.4, 1.0 + 0.3, -22.8);
	glEnd();
}
void tv()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 14.0, -22.0);
	glVertex3f(-25.0, 14.0, -17.0);
	glVertex3f(-25.0, 10.0, -17.0);
	glVertex3f(-20.0, 10.0, -22.0);
	glEnd();	

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-20.0, 13.5, -21.9);
	glVertex3f(-25.0, 13.5, -16.9);
	glVertex3f(-25.0, 10.5, -16.9);
	glVertex3f(-20.0, 10.5, -21.9);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 14.0, 22.0);
	glVertex3f(25.0, 14.0, 17.0);
	glVertex3f(25.0, 10.0, 17.0);
	glVertex3f(20.0, 10.0, 22.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(20.0, 13.5, 21.9);
	glVertex3f(25.0, 13.5, 16.9);
	glVertex3f(25.0, 10.5, 16.9);
	glVertex3f(20.0, 10.5, 21.9);
	glEnd();
}
void lapangan()
{
	//GARISSSSSSSSSSSSSSSS START
	glBegin(GL_LINE_LOOP);//kotak luar
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 0.3, 15.0);
	glVertex3f(-20.0, 0.3, -15.0);
	glVertex3f(20.0, 0.3, -15.0);
	glVertex3f(20.0, 0.3, 15.0);
	glEnd();
	glBegin(GL_LINE_LOOP);//tiang bendera corner
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 0.3, 15.0);
	glVertex3f(-20.0, 3.3, 15.0);
	glEnd();
	glBegin(GL_POLYGON);//bendera corner
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-20.0, 3.3, 15.0);
	glVertex3f(-18.5, 2.0, 15.0);
	glVertex3f(-20.0, 2.0, 15.0);
	glEnd();
	glBegin(GL_LINE_LOOP);//tiang bendera corner
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 0.3, -15.0);
	glVertex3f(-20.0, 3.3, -15.0);
	glEnd();
	glBegin(GL_POLYGON);//bendera corner
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-20.0, 3.3, -15.0);
	glVertex3f(-18.5, 2.0, -15.0);
	glVertex3f(-20.0, 2.0, -15.0);
	glEnd();
	glBegin(GL_LINE_LOOP);//tiang bendera corner
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 0.3, -15.0);
	glVertex3f(20.0, 3.3, -15.0);
	glEnd();
	glBegin(GL_POLYGON);//bendera corner
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(20.0, 3.3, -15.0);
	glVertex3f(18.5, 2.0, -15.0);
	glVertex3f(20.0, 2.0, -15.0);
	glEnd();
	glBegin(GL_LINE_LOOP);//tiang bendera corner
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 0.3, 15.0);
	glVertex3f(20.0, 3.3, 15.0);
	glEnd();
	glBegin(GL_POLYGON);//bendera corner
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(20.0, 3.3, 15.0);
	glVertex3f(18.5, 2.0, 15.0);
	glVertex3f(20.0, 2.0, 15.0);
	glEnd();
	glBegin(GL_LINE_LOOP);//kotak dalem
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, 0.3, 5.0);
	glVertex3f(-5.0, 0.3, -5.0);
	glVertex3f(5.0, 0.3, -5.0);
	glVertex3f(5.0, 0.3, 5.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);//garis tengah
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, 0.3, -15.0);
	glVertex3f(0.0, 0.3, 15.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);//kotak pinalti kiri
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 0.3, -8.0);
	glVertex3f(-13.0, 0.3, -8.0);
	glVertex3f(-13.0, 0.3, 8.0);
	glVertex3f(-20.0, 0.3, 8.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);//kotak pinalti kanan
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 0.3, -8.0);
	glVertex3f(13.0, 0.3, -8.0);
	glVertex3f(13.0, 0.3, 8.0);
	glVertex3f(20.0, 0.3, 8.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);//corner kiri1
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 0.3, -12.0);
	glVertex3f(-17.0, 0.3, -12.0);
	glVertex3f(-17.0, 0.3, -15.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);//corner kiri2
	glVertex3f(-20.0, 0.3, 12.0);
	glVertex3f(-17.0, 0.3, 12.0);
	glVertex3f(-17.0, 0.3, 15.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);//corner kanan1
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(17.0, 0.3, -15.0);
	glVertex3f(17.0, 0.3, -12.0);
	glVertex3f(20.0, 0.3, -12.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);//corner kanan2
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 0.3, 12.0);
	glVertex3f(17.0, 0.3, 12.0);
	glVertex3f(17.0, 0.3, 15.0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);//kotak penalti kecil depan kanan
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(13.0, 0.3, -2.0);
	glVertex3f(10.0, 0.3, -2.0);
	glVertex3f(10.0, 0.3, 2.0);
	glVertex3f(13.0, 0.3, 2.0);
	glEnd();

	glBegin(GL_LINE_STRIP);//kotak penalti kecil depan kiri
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-13.0, 0.3, -2.0);
	glVertex3f(-10.0, 0.3, -2.0);
	glVertex3f(-10.0, 0.3, 2.0);
	glVertex3f(-13.0, 0.3, 2.0);
	glEnd();
	//END
	
	//FIELD START     
	glBegin(GL_POLYGON);//Lapangan dasar paling luar
	glColor3f(0.2, 0.8, 0.1);
	glVertex3f(-25.0, -0.15, 17.0);
	glVertex3f(-25.0, -0.15, -17.0);
	glVertex3f(-22.0, -0.15, -20.0);
	glVertex3f(22.0, -0.15, -20.0);
	glVertex3f(25.0, -0.15, -17.0);
	glVertex3f(25.0, -0.15, 17.0);
	glVertex3f(22.0, -0.15, 20.0);
	glVertex3f(-22.0, -0.15, 20.0);
	glEnd();
	                                                    
	glBegin(GL_POLYGON);//Lapangan dasar
	glColor3f(0.2, 0.6, 0.1);
	glVertex3f(-22.0, -0.1, 17.0);
	glVertex3f(-22.0, -0.1, -17.0);
	glVertex3f(22.0, -0.1, -17.0);
	glVertex3f(22.0, -0.1, 17.0);
	glEnd();
	
	glBegin(GL_POLYGON);//Lapangan dalam
	glColor3f(0.2, 0.8, 0.1);
	glVertex3f(-20.0, 0.0, 15.0);
	glVertex3f(-20.0, 0.0, -15.0);
	glVertex3f(20.0, 0.0, -15.0);
	glVertex3f(20.0, 0.0, 15.0);
	glEnd();
	
	glBegin(GL_POLYGON);//Belang rumput
	glColor3f(0.2, 0.6, 0.1);
	glVertex3f(-20.0, 0.1, 15.0);
	glVertex3f(-20.0, 0.1, 10.0);
	glVertex3f(20.0, 0.1, 10.0);
	glVertex3f(20.0, 0.1, 15.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.6, 0.1);
	glVertex3f(-20.0, 0.1, 5.0);
	glVertex3f(-20.0, 0.1, 0.0);
	glVertex3f(20.0, 0.1, 0.0);
	glVertex3f(20.0, 0.1, 5.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.6, 0.1);
	glVertex3f(-20.0, 0.1, -5.0);
	glVertex3f(-20.0, 0.1, -10.0);
	glVertex3f(20.0, 0.1, -10.0);
	glVertex3f(20.0, 0.1, -5.0);
	glEnd();
	//END
		
	for(a = 0; a < 2.5; a+=0.5) //jaring gawang kiri-kiri
	{
		glPushMatrix();
   	  	glTranslatef(0.0 - a, 0.0, 0.0);
		glBegin(GL_LINE_STRIP);//gawang pinalti kiti kiri-kanan-atas
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-18.0, 0.3, -5.0);
		glVertex3f(-18.0, 3.3, -5.0);
		glVertex3f(-18.0, 3.3, 5.0);
		glVertex3f(-18.0, 0.3, 5.0);
		glEnd();
		glPopMatrix();
	}

	 
	for(a = 0; a < 3; a+=0.5) //jaring gawang kiri-kiri
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0 - a, 0.0);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-18.0, 3.0, -5.0);
		glVertex3f(-20.0, 3.0, -5.0);
		glEnd();
		glPopMatrix();
	}
	
	for(a = 0; a < 3; a+=0.5) //jaring gawang kiri-kanan
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0 - a, 0.0);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-18.0, 3.0, 5.0);
		glVertex3f(-20.0, 3.0, 5.0);
		glEnd();
		glPopMatrix();
	}
	
	for(a = 0; a < 10; a+=0.5) //jaring gawang kiri-atas
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0, 0.0 - a);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-18.0, 3.3, 4.5);
		glVertex3f(-20.0, 3.3, 4.5);
		glEnd();
		glPopMatrix();
	}
	
	for(a = 0; a < 10; a+=0.5) //jaring gawang kiri-belakang horizontal
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0, 0.0 - a);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-20.0, 0.3, 4.5);
		glVertex3f(-20.0, 3.3, 4.5);
		glEnd();
		glPopMatrix();
	}
	
	for(a = 0; a < 3; a+=0.5) //jaring gawang kiri-belakang vertikal
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0 - a, 0.0);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-20.0, 3.0, 5.0);
		glVertex3f(-20.0, 3.0, -5.0);
		glEnd();
		glPopMatrix();
	}
	for(a = 0; a < 2.5; a+=0.5) //jaring gawang kiri-kiri
	{
		glPushMatrix();
   	  	glTranslatef(0.0 + a, 0.0, 0.0);
		glBegin(GL_LINE_STRIP);//gawang pinalti kiti kiri-kanan-atas
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(18.0, 0.3, -5.0);
		glVertex3f(18.0, 3.3, -5.0);
		glVertex3f(18.0, 3.3, 5.0);
		glVertex3f(18.0, 0.3, 5.0);
		glEnd();
		glPopMatrix();
	}
	for(a = 0; a < 3; a+=0.5) //jaring gawang kanan-kiri
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0 - a, 0.0);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(18.0, 3.0, -5.0);
		glVertex3f(20.0, 3.0, -5.0);
		glEnd();
		glPopMatrix();
	}
	
	for(a = 0; a < 3; a+=0.5) //jaring gawang kanan-kanan
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0 - a, 0.0);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(18.0, 3.0, 5.0);
		glVertex3f(20.0, 3.0, 5.0);
		glEnd();
		glPopMatrix();
	}
	
	for(a = 0; a < 10; a+=0.5) //jaring gawang kanan-atas
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0, 0.0 - a);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(18.0, 3.3, 4.5);
		glVertex3f(20.0, 3.3, 4.5);
		glEnd();
		glPopMatrix();
	}
	
	for(a = 0; a < 10; a+=0.5) //jaring gawang kanan-belakang horizontal
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0, 0.0 - a);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(20.0, 0.3, 4.5);
		glVertex3f(20.0, 3.3, 4.5);
		glEnd();
		glPopMatrix();
	}
	
	for(a = 0; a < 3; a+=0.5) //jaring gawang kanan-belakang vertikal
	{
		glPushMatrix();
   	  	glTranslatef(0.0, 0.0 - a, 0.0);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(20.0, 3.0, 5.0);
		glVertex3f(20.0, 3.0, -5.0);
		glEnd();
		glPopMatrix();
	}
    //END
    
    glBegin(GL_POLYGON);//Sponsor dasar abu abu
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-22.0, -0.1, 15.0);
    glVertex3f(-22.0, -0.1, -15.0);
    glVertex3f(-22.0, 2.0, -15.0);
    glVertex3f(-22.0, 2.0, 15.0);
    glEnd();

    glBegin(GL_POLYGON);//Sponsor dasar abu abu
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(22.0, -0.1, 15.0);
    glVertex3f(22.0, -0.1, -15.0);
    glVertex3f(22.0, 2.0, -15.0);
    glVertex3f(22.0, 2.0, 15.0);
    glEnd();

    glBegin(GL_POLYGON);//Sponsor dalam kiri abu abu
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-20.0, 0.0,-17.0);
    glVertex3f(-20.0, 2.0, -17.0);
    glVertex3f(20.0, 2.0, -17.0);
    glVertex3f(20.0, 0.0, -17.0);
    glEnd();

    glBegin(GL_POLYGON);//Sponsor dalam kanan abu abu
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-20.0, 0.0,17.0);
    glVertex3f(-20.0, 2.0,17.0);
    glVertex3f(20.0, 2.0,17.0);
    glVertex3f(20.0, 0.0,17.0);
    glEnd();
    //END
}
void tribunlt1()
{
		//LANDASAN MIRING TRIBUN
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//kiri-depan
	glVertex3f(-22.0, 4.0, -30.0);
	glVertex3f(-30.0, 4.0, -30.0);
	glVertex3f(-22.0, -0.15, -20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//sekat kiri-depan
	glVertex3f(-22.0, 4.0, -30.0);
	glVertex3f(-22.0, 4.0, -32.0);
	glVertex3f(-22.0, 3.0, -32.0);
	glVertex3f(-22.0, -0.15, -20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//depan
	glVertex3f(-22.0, 3.0, -32.0);
	glVertex3f(-22.0, -0.15, -20.0);
	glVertex3f(22.0, -0.15, -20.0);
	glVertex3f(22.0, 3.0, -32.0);
	glEnd();
	for(a = 0; a <= 36; a+= 6)
	{
		glPushMatrix();
   		glTranslatef(0.0 + a, 0.0, 0.0);
   		bangkudepan();
		glPopMatrix();
	}
	glPushMatrix();
	bangkudepan();
	glTranslatef(0.0, 1.5, -6.0);
 	for(a = 0; a <= 36; a+= 6)
	{
		glPushMatrix();
   		glTranslatef(0.0 + a, 0.0, 0.0);
   		bangkudepan();
		glPopMatrix();
	}
	glPopMatrix();
	chelsea();
	glPushMatrix();
	glTranslatef(0.0, 1.5, -6.0);
	chelsea();
	glPopMatrix();
	
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//sekat depan-kanan
	glVertex3f(22.0, 4.0, -30.0);
	glVertex3f(22.0, 4.0, -32.0);
	glVertex3f(22.0, 3.0, -32.0);
	glVertex3f(22.0, -0.15, -20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//depan-kanan1
	glVertex3f(22.0, 4.0, -30.0);
	glVertex3f(30.0, 4.0, -30.0);
	glVertex3f(22.0, -0.15, -20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//depan-kanan2
	glVertex3f(30.0, 4.0, -30.0);
	glVertex3f(22.0, -0.15, -20.0);
	glVertex3f(25.0, -0.15, -17.0);
	glVertex3f(35.0, 4.0, -25.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//bangku depan-kanan segitiga1
	glVertex3f(23.0, 4.0, -29.0);
	glVertex3f(29.0, 4.0, -29.0);
	glVertex3f(23.0, 0.5, -21.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku depan-kanan segiempat
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(25.5, 0.5, -17.5);
	glVertex3f(34.0, 4.0, -24.0);
	glVertex3f(30.0, 4.0, -28.0);
	glVertex3f(23.0, 0.5, -20.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku depan-kanan segitiga2
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(26.0, 0.5, -17.0);
	glVertex3f(34.0, 4.0, -23.0);
	glVertex3f(34.0, 4.0, -17.0);
	glEnd();
	
	glBegin(GL_POLYGON);//kanan
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(35.0, 4.0, 25.0);
	glVertex3f(25.0, -0.15, 17.0);
	glVertex3f(25.0, -0.15, -17.0);
	glVertex3f(35.0, 4.0, -25.0);
	glEnd();
	
	for(a = 0; a <= 22; a+= 11)
	{
		glPushMatrix();
   		glTranslatef(0.0, 0.0, 0.0 + a);
   		bangkukanan();
		glPopMatrix();
	}
	glBegin(GL_POLYGON);//bangku kanan-belakang segitiga1
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(26.0, 0.5, 17.0);
	glVertex3f(34.0, 4.0, 23.0);
	glVertex3f(34.0, 4.0, 17.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku kanan-belakang segiempat
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(25.5, 0.5, 17.5);
	glVertex3f(34.0, 4.0, 24.0);
	glVertex3f(30.0, 4.0, 28.0);
	glVertex3f(23.0, 0.5, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//bangku kanan-belakang segitiga2
	glVertex3f(23.0, 4.0, 29.0);
	glVertex3f(29.0, 4.0, 29.0);
	glVertex3f(23.0, 0.5, 21.0);
	glEnd();
	
	glBegin(GL_POLYGON);//kanan-belakang
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(25.0, -0.15, 17.0);
	glVertex3f(35.0, 4.0, 25.0);
	glVertex3f(30.0, 4.0, 30.0);
	glVertex3f(22.0, -0.15, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//belakang-kanan
	glVertex3f(22.0, 4.0, 30.0);
	glVertex3f(30.0, 4.0, 30.0);
	glVertex3f(22.0, -0.15, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//sekat kanan-belakang
	glVertex3f(22.0, 4.0, 30.0);
	glVertex3f(22.0, 4.0, 32.0);
	glVertex3f(22.0, 3.0, 32.0);
	glVertex3f(22.0, -0.15, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//belakang
	glVertex3f(-22.0, 3.0, 32.0);
	glVertex3f(-22.0, -0.15, 20.0);
	glVertex3f(22.0, -0.15, 20.0);
	glVertex3f(22.0, 3.0, 32.0);
	glEnd();
	bangkubkg();
	for(a = 0; a <= 36; a+= 6)
	{
		glPushMatrix();
   		glTranslatef(0.0 + a, 0.0, 0.0);
   		bangkubkg();
		glPopMatrix();
	}
	glPushMatrix();
	glTranslatef(0.0, 1.5, 6.0);
 	for(a = 0; a <= 36; a+= 6)
	{
		glPushMatrix();
   		glTranslatef(0.0 + a, 0.0, 0.0);
   		bangkubkg();
		glPopMatrix();
	}
	glPopMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//sekat kiri-belakang
	glVertex3f(-22.0, 4.0, 30.0);
	glVertex3f(-22.0, 4.0, 32.0);
	glVertex3f(-22.0, 3.0, 32.0);
	glVertex3f(-22.0, -0.15, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//belakang-kiri
	glVertex3f(-22.0, 4.0, 30.0);
	glVertex3f(-30.0, 4.0, 30.0);
	glVertex3f(-22.0, -0.15, 20.0);
	glEnd();
	glBegin(GL_POLYGON);//belakang-kiri
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(-22.0, -0.15, 20.0);
	glVertex3f(-30.0, 4.0, 30.0);
	glVertex3f(-35.0, 4.0, 25.0);
	glVertex3f(-25.0, -0.15, 17.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//bangku belakang-kiri segitiga1
	glVertex3f(-23.0, 4.0, -29.0);
	glVertex3f(-29.0, 4.0, -29.0);
	glVertex3f(-23.0, 0.5, -21.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku belakang-kiri segiempat
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-25.5, 0.5, -17.5);
	glVertex3f(-34.0, 4.0, -24.0);
	glVertex3f(-30.0, 4.0, -28.0);
	glVertex3f(-23.0, 0.5, -20.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku belakang-kiri segitiga2
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-26.0, 0.5, -17.0);
	glVertex3f(-34.0, 4.0, -23.0);
	glVertex3f(-34.0, 4.0, -17.0);
	glEnd();
	
	glBegin(GL_POLYGON);//kiri
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(-35.0, 4.0, 25.0);
	glVertex3f(-25.0, -0.15, 17.0);
	glVertex3f(-25.0, -0.15, -17.0);
	glVertex3f(-35.0, 4.0, -25.0);
	glEnd();
	
	for(a = 0; a <= 22; a+= 11)
	{
		glPushMatrix();
   		glTranslatef(0.0, 0.0, 0.0 + a);
   		bangkukiri();
		glPopMatrix();
	}
	glBegin(GL_POLYGON);//bangku belakang-kiri segitiga1
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-26.0, 0.5, 17.0);
	glVertex3f(-34.0, 4.0, 23.0);
	glVertex3f(-34.0, 4.0, 17.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku belakang-kiri segiempat
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-25.5, 0.5, 17.5);
	glVertex3f(-34.0, 4.0, 24.0);
	glVertex3f(-30.0, 4.0, 28.0);
	glVertex3f(-23.0, 0.5, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);//bangku belakang-kiri segitiga2
	glVertex3f(-23.0, 4.0, 29.0);
	glVertex3f(-29.0, 4.0, 29.0);
	glVertex3f(-23.0, 0.5, 21.0);
	glEnd();
	
	glBegin(GL_POLYGON);//kiri-atas
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(-25.0, -0.15, -17.0);
	glVertex3f(-35.0, 4.0, -25.0);
	glVertex3f(-30.0, 4.0, -30.0);
	glVertex3f(-22.0, -0.15, -20.0);
	glEnd();
	//END
}
void tribunlt2()
{
	//LANDASAN MIRING TRIBUN 2
	glBegin(GL_POLYGON);//sekat kiri-depan
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-22.0, 6.0, -28.0);
	glVertex3f(-22.0, 3.0, -28.0);
	glVertex3f(-22.0, 3.0, -30.0);
	glVertex3f(-22.0, 8.0, -38.0);
	glVertex3f(-22.0, 10.0, -38.0);
	glVertex3f(-22.0, 10.0, -36.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//depan
	glVertex3f(-22.0, 8.0, -38.0);
	glVertex3f(-22.0, 4.0, -30.0);
	glVertex3f(22.0, 4.0, -30.0);
	glVertex3f(22.0, 8.0, -38.0);
	glEnd();
	
	for(a = 0; a <= 35; a+= 7)
	{
		glPushMatrix();
   		glTranslatef(0.0 + a, 0.0, 0.0);
   		bangkudpnlt2();
		glPopMatrix();
	}
	
	glBegin(GL_POLYGON);//sekat depan-kanan
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(22.0, 6.0, -28.0);
	glVertex3f(22.0, 3.0, -28.0);
	glVertex3f(22.0, 3.0, -30.0);
	glVertex3f(22.0, 8.0, -38.0);
	glVertex3f(22.0, 10.0, -38.0);
	glVertex3f(22.0, 10.0, -36.0);
	glEnd();
	glBegin(GL_POLYGON);//depan-kanan
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(28.0, 6.0, -28.0);
	glVertex3f(34.0, 10.0, -36.0);
	glVertex3f(22.0, 10.0, -36.0);
	glVertex3f(22.0, 6.0, -28.0);
	glEnd();
	
	glBegin(GL_POLYGON);//bangku depan-kanan segiempat1
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(28.5, 6.7, -29.0);
	glVertex3f(33.0, 9.7, -35.0);
	glVertex3f(23.0, 9.7, -35.0);
	glVertex3f(23.0, 6.7, -29.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//depan-kanan
	glVertex3f(28.0, 6.0, -28.0);
	glVertex3f(34.0, 10.0, -36.0);
	glVertex3f(40.0, 10.0, -29.0);
	glVertex3f(32.0, 6.0, -23.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);// bangku depan-kanan segiempat2
	glVertex3f(29.3, 6.5, -28.0);
	glVertex3f(34.0, 10.0, -34.3);
	glVertex3f(38.5, 10.0, -29.0);
	glVertex3f(32.5, 6.5, -24.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku depan kanan segitiga
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(39.0, 9.7, -23.0);
	glVertex3f(33.0, 6.7, -23.0);
	glVertex3f(39.0, 9.7, -27.5);
	glEnd();
	
	glBegin(GL_POLYGON);//kanan
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(40.0, 10.0, 29.0);
	glVertex3f(32.0, 6.0, 23.0);
	glVertex3f(32.0, 6.0, -23.0);
	glVertex3f(40.0, 10.0, -29.0);
	glEnd();
	
	for(a = 0; a <= 36; a+= 9)
	{
		glPushMatrix();
   		glTranslatef(0.0, 0.0, 0.0 + a);
   		bangkukananlt2();
		glPopMatrix();
	}
	glBegin(GL_POLYGON);//bangku kanan-belakang segitiga
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(39.0, 9.7, 23.0);
	glVertex3f(33.0, 6.7, 23.0);
	glVertex3f(39.0, 9.7, 27.5);
	glEnd();
	
	glBegin(GL_POLYGON);//kanan-belakang
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(40.0, 10.0, 29.0);
	glVertex3f(32.0, 6.0, 23.0);
	glVertex3f(28.0, 6.0, 28.0);
	glVertex3f(34.0, 10.0, 36.0);
	glEnd();
	
	glBegin(GL_POLYGON);//bangku depan kanan segitiga
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(39.0, 9.7, 23.0);
	glVertex3f(33.0, 6.7, 23.0);
	glVertex3f(39.0, 9.7, 27.5);
	glEnd();
	
	glBegin(GL_POLYGON);//kanan-belakang
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(28.0, 6.0, 28.0);
	glVertex3f(34.0, 10.0, 36.0);
	glVertex3f(22.0, 10.0, 36.0);
	glVertex3f(22.0, 6.0, 28.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);// bangku depan-kanan segiempat1
	glVertex3f(29.3, 6.5, 28.0);
	glVertex3f(34.0, 10.0, 34.3);
	glVertex3f(38.5, 10.0, 29.0);
	glVertex3f(32.5, 6.5, 24.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku depan-kanan segiempat2
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(28.5, 6.7, 29.0);
	glVertex3f(33.0, 9.7, 35.0);
	glVertex3f(23.0, 9.7, 35.0);
	glVertex3f(23.0, 6.7, 29.0);
	glEnd();
	glBegin(GL_POLYGON);//sekat kanan-belakang
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(22.0, 6.0, 28.0);
	glVertex3f(22.0, 3.0, 28.0);
	glVertex3f(22.0, 3.0, 30.0);
	glVertex3f(22.0, 8.0, 38.0);
	glVertex3f(22.0, 10.0, 38.0);
	glVertex3f(22.0, 10.0, 36.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//belakang
	glVertex3f(-22.0, 8.0, 38.0);
	glVertex3f(-22.0, 4.0, 30.0);
	glVertex3f(22.0, 4.0, 30.0);
	glVertex3f(22.0, 8.0, 38.0);
	glEnd();
	
	for(a = 0; a <= 35; a+= 7)
	{
		glPushMatrix();
   		glTranslatef(0.0 + a, 0.0, 0.0);
   		bangkubkglt2();
		glPopMatrix();
	}
	
	glBegin(GL_POLYGON);//sekat kiri-belakang
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-22.0, 6.0, 28.0);
	glVertex3f(-22.0, 3.0, 28.0);
	glVertex3f(-22.0, 3.0, 30.0);
	glVertex3f(-22.0, 8.0, 38.0);
	glVertex3f(-22.0, 10.0, 38.0);
	glVertex3f(-22.0, 10.0, 36.0);
	glEnd();
	glBegin(GL_POLYGON);//kiri-belakang
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(-28.0, 6.0, 28.0);
	glVertex3f(-34.0, 10.0, 36.0);
	glVertex3f(-22.0, 10.0, 36.0);
	glVertex3f(-22.0, 6.0, 28.0);
	glEnd();
	
	glBegin(GL_POLYGON);//bangku depan kanan segitiga
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-39.0, 9.7, 23.0);
	glVertex3f(-33.0, 6.7, 23.0);
	glVertex3f(-39.0, 9.7, 27.5);
	glEnd();	
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//belakang-kiri
	glVertex3f(-34.0, 10.0, 36.0);
	glVertex3f(-28.0, 6.0, 28.0);
	glVertex3f(-32.0, 6.0, 23.0);
	glVertex3f(-40.0, 10.0, 29.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);// bangku depan-kanan segiempat1
	glVertex3f(-29.3, 6.5, 28.0);
	glVertex3f(-34.0, 10.0, 34.3);
	glVertex3f(-38.5, 10.0, 29.0);
	glVertex3f(-32.5, 6.5, 24.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku depan-kanan segiempat2
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-28.5, 6.7, 29.0);
	glVertex3f(-33.0, 9.7, 35.0);
	glVertex3f(-23.0, 9.7, 35.0);
	glVertex3f(-23.0, 6.7, 29.0);
	glEnd();
	
	glBegin(GL_POLYGON);//kiri
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(-40.0, 10.0, 29.0);
	glVertex3f(-32.0, 6.0, 23.0);
	glVertex3f(-32.0, 6.0, -23.0);
	glVertex3f(-40.0, 10.0, -29.0);
	glEnd();
	
	for(a = 0; a <= 36; a+= 9)
	{
		glPushMatrix();
   		glTranslatef(0.0, 0.0, 0.0 + a);
   		bangkukirilt2();
		glPopMatrix();
	}
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.8);// bangku kiri-depan segiempat1
	glVertex3f(-29.3, 6.5, -28.0);
	glVertex3f(-34.0, 10.0, -34.3);
	glVertex3f(-38.5, 10.0, -29.0);
	glVertex3f(-32.5, 6.5, -24.0);
	glEnd();
	glBegin(GL_POLYGON);//bangku kiri-depan segitiga
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-39.0, 9.7, -23.0);
	glVertex3f(-33.0, 6.7, -23.0);
	glVertex3f(-39.0, 9.7, -27.5);
	glEnd();
	
	glBegin(GL_POLYGON);//kiri-depan
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(-32.0, 6.0, -23.0);
	glVertex3f(-40.0, 10.0, -29.0);
	glVertex3f(-34.0, 10.0, -36.0);
	glVertex3f(-28.0, 6.0, -28.0);
	glEnd();
	
	glBegin(GL_POLYGON);//bangku kiri-depan segiempat2
	glColor3f(0.3, 0.2, 0.8);
	glVertex3f(-28.5, 6.7, -29.0);
	glVertex3f(-33.0, 9.7, -35.0);
	glVertex3f(-23.0, 9.7, -35.0);
	glVertex3f(-23.0, 6.7, -29.0);
	glEnd();
	
	glBegin(GL_POLYGON);//kiri-depan
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(-28.0, 6.0, -28.0);
	glVertex3f(-34.0, 10.0, -36.0);
	glVertex3f(-22.0, 10.0, -36.0);
	glVertex3f(-22.0, 6.0, -28.0);
	glEnd();
	//END
}
void tribunlt3()
{
	//LANDASAN MIRING TRIBUN 3
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//depan
	glVertex3f(-22.0, 16.0, -44.0);
	glVertex3f(-22.0, 8.0, -35.0);
	glVertex3f(22.0, 8.0, -35.0);
	glVertex3f(22.0, 16.0, -44.0);
	glEnd();
	
	//bangkudepan
	for(a = 0; a <= 36; a+= 6)
	{
		glPushMatrix();
   		glTranslatef(0.0 + a, 0.0, 0.0);
   		bangkudpnlt3();
		glPopMatrix();
	}
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);//belakang
	glVertex3f(-22.0, 16.0, 44.0);
	glVertex3f(-22.0, 8.0, 35.0);
	glVertex3f(22.0, 8.0, 35.0);
	glVertex3f(22.0, 16.0, 44.0);
	glEnd();
	
	//bangkubelakang
	for(a = 0; a <= 36; a+= 6)
	{
		glPushMatrix();
   		glTranslatef(0.0 + a, 0.0, 0.0);
   		bangkubkglt3();
		glPopMatrix();
	}
	//END
}
void temboktribun()
{
	//TEMBOK ATAS LANDASAN MIRING
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//kiri-depan2
	glVertex3f(-30.0, 4.0, -30.0);
	glVertex3f(-30.0, 7.0, -30.0);
	glVertex3f(-22.0, 7.0, -30.0);
	glVertex3f(-22.0, 4.0, -30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//depan1
	glVertex3f(-22.0, 3.0, -32.0);
	glVertex3f(-22.0, 4.0, -32.0);
	glVertex3f(22.0, 4.0, -32.0);
	glVertex3f(22.0, 3.0, -32.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//depan2
	glVertex3f(-22.0, 8.0, -38.0);
	glVertex3f(-22.0, 10.0, -38.0);
	glVertex3f(22.0, 10.0, -38.0);
	glVertex3f(22.0, 8.0, -38.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//depan-kanan1
	glVertex3f(30.0, 4.0, -30.0);
	glVertex3f(30.0, 7.0, -30.0);
	glVertex3f(22.0, 7.0, -30.0);
	glVertex3f(22.0, 4.0, -30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//depan-kanan2
	glVertex3f(30.0, 4.0, -30.0);
	glVertex3f(30.0, 7.0, -30.0);
	glVertex3f(35.0, 7.0, -25.0);
	glVertex3f(35.0, 4.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);//kanan
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(35.0, 4.0, 25.0);
	glVertex3f(35.0, 7.0, 25.0);
	glVertex3f(35.0, 7.0, -25.0);
	glVertex3f(35.0, 4.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//kanan-belakang1
	glVertex3f(30.0, 4.0, 30.0);
	glVertex3f(30.0, 7.0, 30.0);
	glVertex3f(22.0, 7.0, 30.0);
	glVertex3f(22.0, 4.0, 30.0);
	glEnd();
	glBegin(GL_POLYGON);//kanan-belakang2
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(35.0, 7.0, 25.0);
	glVertex3f(35.0, 4.0, 25.0);
	glVertex3f(30.0, 4.0, 30.0);
	glVertex3f(30.0, 7.0, 30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//belakang1
	glVertex3f(-22.0, 3.0, 32.0);
	glVertex3f(-22.0, 4.0, 32.0);
	glVertex3f(22.0, 4.0, 32.0);
	glVertex3f(22.0, 3.0, 32.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//belakang2
	glVertex3f(-22.0, 8.0, 38.0);
	glVertex3f(-22.0, 10.0, 38.0);
	glVertex3f(22.0, 10.0, 38.0);
	glVertex3f(22.0, 8.0, 38.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);//kiri-belakang1
	glVertex3f(-30.0, 4.0, 30.0);
	glVertex3f(-30.0, 7.0, 30.0);
	glVertex3f(-22.0, 7.0, 30.0);
	glVertex3f(-22.0, 4.0, 30.0);
	glEnd();
	glBegin(GL_POLYGON);//kiri-belakang2
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-30.0, 7.0, 30.0);
	glVertex3f(-30.0, 4.0, 30.0);
	glVertex3f(-35.0, 4.0, 25.0);
	glVertex3f(-35.0, 7.0, 25.0);
	glEnd();
	glBegin(GL_POLYGON);//kiri
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-35.0, 4.0, 25.0);
	glVertex3f(-35.0, 7.0, 25.0);
	glVertex3f(-35.0, 7.0, -25.0);
	glVertex3f(-35.0, 4.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);//kiri-depan1
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-35.0, 7.0, -25.0);
	glVertex3f(-35.0, 4.0, -25.0);
	glVertex3f(-30.0, 4.0, -30.0);
	glVertex3f(-30.0, 7.0, -30.0);
	glEnd();
}
void atap()
{
	//ATAP KANAN
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(25.0, 12.0, -17.0);
	glVertex3f(22.0, 12.0, -20.0);
	glVertex3f(22.0, 12.0, -36.0);
	glVertex3f(34.0, 12.0, -36.0);
	glVertex3f(40.0, 12.0, -29.0);
	glVertex3f(40.0, 12.0, -17.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(25.0, 12.0, 17.0);
	glVertex3f(22.0, 12.0, 20.0);
	glVertex3f(22.0, 12.0, 36.0);
	glVertex3f(34.0, 12.0, 36.0);
	glVertex3f(40.0, 12.0, 29.0);
	glVertex3f(40.0, 12.0, 17.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(40.0, 12.0, -17.0);
	glVertex3f(25.0, 12.0, -17.0);
	glVertex3f(25.0, 12.0, 17.0);
	glVertex3f(40.0, 12.0, 17.0);
	glEnd();
	//ATAP KIRI
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-25.0, 12.0, -17.0);
	glVertex3f(-22.0, 12.0, -20.0);
	glVertex3f(-22.0, 12.0, -36.0);
	glVertex3f(-34.0, 12.0, -36.0);
	glVertex3f(-40.0, 12.0, -29.0);
	glVertex3f(-40.0, 12.0, -17.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-25.0, 12.0, 17.0);
	glVertex3f(-22.0, 12.0, 20.0);
	glVertex3f(-22.0, 12.0, 36.0);
	glVertex3f(-34.0, 12.0, 36.0);
	glVertex3f(-40.0, 12.0, 29.0);
	glVertex3f(-40.0, 12.0, 17.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-40.0, 12.0, -17.0);
	glVertex3f(-25.0, 12.0, -17.0);
	glVertex3f(-25.0, 12.0, 17.0);
	glVertex3f(-40.0, 12.0, 17.0);
	glEnd();
	//ATAP DEPAN
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-22.0, 16.0, -44.0);
	glVertex3f(22.0, 16.0, -44.0);
	glVertex3f(22.0, 22.0, -25.0);
	glVertex3f(-22.0, 22.0, -25.0);
	glEnd();
	//ATAP Belakang
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-22.0, 16.0, 44.0);
	glVertex3f(22.0, 16.0, 44.0);
	glVertex3f(22.0, 22.0, 25.0);
	glVertex3f(-22.0, 22.0, 25.0);
	glEnd();
}
void tembokluar()
{
	//TEMBOK LUAR
	glBegin(GL_POLYGON);//Depan Pinggir Kiri
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-22.0, 16.0, -44.0);
	glVertex3f(-22.0, -2.0, -44.0);
	glVertex3f(-22.0, -2.0, -36.0);
	glVertex3f(-22.0, 12.0, -36.0);
	glVertex3f(-22.0, 22.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);//Depan
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-22.0, 16.0, -44.0);
	glVertex3f(-22.0, -2.0, -44.0);
	glVertex3f(22.0, -2.0, -44.0);
	glVertex3f(22.0, 16.0, -44.0);
	glEnd();
	glBegin(GL_POLYGON);//Depan Pinggir Kanan
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(22.0, 16.0, -44.0);
	glVertex3f(22.0, -2.0, -44.0);
	glVertex3f(22.0, -2.0, -36.0);
	glVertex3f(22.0, 12.0, -36.0);
	glVertex3f(22.0, 22.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);//Depan-Kanan
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(22.0, 12.0, -36.0);
	glVertex3f(34.0, 12.0, -36.0);
	glVertex3f(34.0, -2.0, -36.0);
	glVertex3f(22.0, -2.0, -36.0);
	glEnd();
	glBegin(GL_POLYGON);//Depan-Kanan Pojok
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(34.0, 12.0, -36.0);
	glVertex3f(40.0, 12.0, -29.0);
	glVertex3f(40.0, -2.0, -29.0);
	glVertex3f(34.0, -2.0, -36.0);
	glEnd();
	glBegin(GL_POLYGON);//Kanan
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(40.0, -2.0, -29.0);
	glVertex3f(40.0, 12.0, -29.0);
	glVertex3f(40.0, 12.0, 29.0);
	glVertex3f(40.0, -2.0, 29.0);
	glEnd();
	glBegin(GL_POLYGON);//Kanan-Belakang Pojok
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(34.0, 12.0, 36.0);
	glVertex3f(40.0, 12.0, 29.0);
	glVertex3f(40.0, -2.0, 29.0);
	glVertex3f(34.0, -2.0, 36.0);
	glEnd();
	glBegin(GL_POLYGON);//Kanan-Belakang
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(22.0, 12.0, 36.0);
	glVertex3f(34.0, 12.0, 36.0);
	glVertex3f(34.0, -2.0, 36.0);
	glVertex3f(22.0, -2.0, 36.0);
	glEnd();
	glBegin(GL_POLYGON);//Belakang Pinggir Kiri
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-22.0, 16.0, 44.0);
	glVertex3f(-22.0, -2.0, 44.0);
	glVertex3f(-22.0, -2.0, 36.0);
	glVertex3f(-22.0, 12.0, 36.0);
	glVertex3f(-22.0, 22.0, 25.0);
	glEnd();
	glBegin(GL_POLYGON);//Belakang
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-22.0, 16.0, 44.0);
	glVertex3f(-22.0, -2.0, 44.0);
	glVertex3f(22.0, -2.0, 44.0);
	glVertex3f(22.0, 16.0, 44.0);
	glEnd();
	glBegin(GL_POLYGON);//Belakang Pinggir Kanan
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(22.0, 16.0, 44.0);
	glVertex3f(22.0, -2.0, 44.0);
	glVertex3f(22.0, -2.0, 36.0);
	glVertex3f(22.0, 12.0, 36.0);
	glVertex3f(22.0, 22.0, 25.0);
	glEnd();
	glBegin(GL_POLYGON);//Belakang-Kiri Pojok
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-34.0, 12.0, 36.0);
	glVertex3f(-40.0, 12.0, 29.0);
	glVertex3f(-40.0, -2.0, 29.0);
	glVertex3f(-34.0, -2.0, 36.0);
	glEnd();
	glBegin(GL_POLYGON);//Belakang-Kiri
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-22.0, 12.0, 36.0);
	glVertex3f(-34.0, 12.0, 36.0);
	glVertex3f(-34.0, -2.0, 36.0);
	glVertex3f(-22.0, -2.0, 36.0);
	glEnd();
	glBegin(GL_POLYGON);//Kiri
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-40.0, -2.0, -29.0);
	glVertex3f(-40.0, 12.0, -29.0);
	glVertex3f(-40.0, 12.0, 29.0);
	glVertex3f(-40.0, -2.0, 29.0);
	glEnd();
	glBegin(GL_POLYGON);//Kiri-Depan Pojok
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-34.0, 12.0, -36.0);
	glVertex3f(-40.0, 12.0, -29.0);
	glVertex3f(-40.0, -2.0, -29.0);
	glVertex3f(-34.0, -2.0, -36.0);
	glEnd();
	glBegin(GL_POLYGON);//Kiri-Depan
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-22.0, 12.0, -36.0);
	glVertex3f(-34.0, 12.0, -36.0);
	glVertex3f(-34.0, -2.0, -36.0);
	glVertex3f(-22.0, -2.0, -36.0);
	glEnd();
	glBegin(GL_POLYGON);//Pondasi
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-50.0, -2.0, -50.0);
	glVertex3f(50.0, -2.0, -50.0);
	glVertex3f(50.0, -2.0, 50.0);
	glVertex3f(-50.0, -2.0, 50.0);
	glEnd();
	//END TEMBOK
}
void tampil(void)
{
	
	if (is_depth)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glTranslatef(A,B,C);
	glScalef(D,E,F);
	glPushMatrix();
	tv();
	lapangan();
	tribunlt1();
	tribunlt2();
	temboktribun();
	atap();
	tembokluar();
	tribunlt3();

	glPopMatrix();
	glutSwapBuffers();
}
void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
        }
        else
        mouseDown = false;
}
void mouseMotion(int x, int y)
{
	if (mouseDown)
	
		{
			yrot = x - xdiff;	
			xrot = y + ydiff;
			
			glutPostRedisplay();
		}
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'w' || key == 'W')C+=2;
    	else if(key == 's' || key == 'S')C-=2;
    	else if(key == 'a' || key == 'A')A-=2;
    	else if(key == 'd' || key == 'D')A+=2;
    	else if(key == 't' || key == 'T')B+=2;
    	else if(key == 'g' || key == 'G')B-=3;
    	else if(key == 'Z' || key == 'z')D = D * 2,E = E * 2, F = F * 2;
        else if(key == 'X' || key == 'x')D = D * 1/2,E = E * 1/2, F = F * 1/2;
        else if(key == 'c' || key == 'C')
        {
		if (is_depth)
            {
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
        }

}
void ukuran(int lebar, int tinggi)
{

	if(tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0, lebar/tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -100.0);
	glMatrixMode(GL_MODELVIEW);
}

