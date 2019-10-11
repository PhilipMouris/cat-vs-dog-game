// Includes
#include <math.h>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <glut.h>

// Methods Signatures
void Display();
void drawCat();
void drawDog();
void drawScene();
int* bezier(float t, int* p0, int* p1, int* p2, int* p3);
void drawBezierCurve();
void fire(unsigned char key, int x, int y);
void switchTurn();
void drawPowerBars();
void toggleRelease();
void release(unsigned char key, int x, int y);
void drawProjectile();
void animate();
void animateProjectile();
void animateBackground();
void handleProjectile();
void drawHealthBars();
void animateAnimal();
void drawWall();

// Global Variables
float sceneTranslation = 0;
float sceneTranslationFactor = 0.01;
int turn = 1;
int p0[2] = { 100,90 };
int p1[2] = { 100,90 };
int p2[2] = { 100,90 };
int p3[2] = { 100,90 };
float catPowerBar = 0;
float dogPowerBar = 0;
int releaseFlag = -1;
float projectileAnimation = 0;
float projectileTranslation[2] = { 100,90 };
float projectilePosition[2] = { 100,90 };
float catHealth = 1;
float dogHealth = 1;
float dogTranslation = 0;
float catTranslation = 0;
float animalTranslationFactor = 0.1;
int dogTranslationFlag = 0;
int catTranslationFlag = 0;
int upDownFlag = 1;

//PlaySound(TEXT("maybe-next-time.wav"), NULL, SND_ASYNC | SND_FILENAME);
void main(int argc, char** argr) {
	glutInit(&argc, argr);
	
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("Cats vs Dogs");
	glutDisplayFunc(Display);
	glutIdleFunc(animate);
	glutKeyboardFunc(fire);
	glutKeyboardUpFunc(release);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	gluOrtho2D(0.0, 600, 0.0, 500);

	glutMainLoop();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawScene();
	drawCat();
	drawDog();
	drawBezierCurve();
	drawPowerBars();
	drawHealthBars();
	if (releaseFlag == 1) {
		drawProjectile();
	}
	drawWall();
	glFlush();
}

void drawCat() {
	glPushMatrix();
	glTranslated(0.0f, catTranslation, 0.0f);
	glColor3f(0.96, 0.68, 0.26);
	glBegin(GL_POLYGON);
		glVertex3f(50.0f, 50.0f, 0.0f);
		glVertex3f(85.0f, 43.0f, 0.0f);
		glVertex3f(120.0f, 50.0f, 0.0f);
		glVertex3f(120.0f, 70.0f, 0.0f);
		glVertex3f(85.0f, 78.0f, 0.0f);
		glVertex3f(50.0f, 70.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(52.0f, 50.0f, 0.0f);
		glVertex3f(60.0f, 50.0f, 0.0f);
		glVertex3f(60.0f, 30.0f, 0.0f);
		glVertex3f(52.0f, 30.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(110.0f, 50.0f, 0.0f);
		glVertex3f(118.0f, 50.0f, 0.0f);
		glVertex3f(118.0f, 30.0f, 0.0f);
		glVertex3f(110.0f, 30.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(110.0f, 70.0f, 0.0f);
		glVertex3f(115.0f, 85.0f, 0.0f);
		glVertex3f(120.0f, 70.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(108.0f, 80.0f, 0.0f);
		glVertex3f(122.0f, 80.0f, 0.0f);
		glVertex3f(122.0f, 100.0f, 0.0f);
		glVertex3f(108.0f, 100.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(108.0f, 100.0f, 0.0f);
		glVertex3f(115.0f, 100.0f, 0.0f);
		glVertex3f(111.5f, 107.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(115.0f, 100.0f, 0.0f);
		glVertex3f(122.0f, 100.0f, 0.0f);
		glVertex3f(118.5f, 107.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(50.0f, 64.0f, 0.0f);
		glVertex3f(20.0f, 54.0f, 0.0f);
	glEnd();
	glColor3f(0, 0, 0);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex3f(119.0f, 95.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex3f(122.0f, 87.0f, 0.0f);
		glVertex3f(117.0f, 84.0f, 0.0f);
		glVertex3f(112.0f, 87.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void drawDog() {
	glPushMatrix();
	glTranslated(0.0f, dogTranslation, 0.0f);
	glColor3f(0.79, 0.36, 0.05);
	glBegin(GL_POLYGON);
		glVertex3f(550.0f, 50.0f, 0.0f);
		glVertex3f(515.0f, 43.0f, 0.0f);
		glVertex3f(480.0f, 50.0f, 0.0f);
		glVertex3f(480.0f, 70.0f, 0.0f);
		glVertex3f(515.0f, 78.0f, 0.0f);
		glVertex3f(550.0f, 70.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(548.0f, 50.0f, 0.0f);
		glVertex3f(540.0f, 50.0f, 0.0f);
		glVertex3f(540.0f, 30.0f, 0.0f);
		glVertex3f(548.0f, 30.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(490.0f, 50.0f, 0.0f);
		glVertex3f(482.0f, 50.0f, 0.0f);
		glVertex3f(482.0f, 30.0f, 0.0f);
		glVertex3f(490.0f, 30.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(490.0f, 70.0f, 0.0f);
		glVertex3f(485.0f, 85.0f, 0.0f);
		glVertex3f(480.0f, 70.0f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(492.0f, 80.0f, 0.0f);
		glVertex3f(460.0f, 80.0f, 0.0f);
		glVertex3f(460.0f, 90.0f, 0.0f);
		glVertex3f(478.0f, 100.0f, 0.0f);
		glVertex3f(492.0f, 100.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(550.0f, 64.0f, 0.0f);
		glVertex3f(580.0f, 54.0f, 0.0f);
	glEnd();
	glColor3f(0, 0, 0);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex3f(479.0f, 95.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex3f(460.0f, 87.0f, 0.0f);
		glVertex3f(466.0f, 84.0f, 0.0f);
		glVertex3f(472.0f, 87.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex3f(492.0f, 100.0f, 0.0f);
		glVertex3f(492.0f, 85.0f, 0.0f);
		glVertex3f(485.0f, 85.0f, 0.0f);
		glVertex3f(485.0f, 100.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void drawScene() {
	glColor3f(0.35f, 0.68f, 0.01f);
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(600.0f, 0.0f, 0.0f);
		glVertex3f(600.0f, 350.0f, 0.0f);
		glVertex3f(0.0f, 350.0f, 0.0f);
	glEnd();
	glColor3f(0.0f, 0.93f, 0.87f);
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 350.0f, 0.0f);
		glVertex3f(600.0f, 350.0f, 0.0f);
		glVertex3f(600.0f, 500.0f, 0.0f);
		glVertex3f(0.0f, 500.0f, 0.0f);
	glEnd();
	glPushMatrix();
	glTranslated(sceneTranslation, 0, 0);
	glColor3f(0.44f, 0.20f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(50.0f, 300.0f, 0.0f);
		glVertex3f(100.0f, 300.0f, 0.0f);
		glVertex3f(90.0f, 360.0f, 0.0f);
		glVertex3f(60.0f, 360.0f, 0.0f);
	glEnd();
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex3f(40.0f, 360.0f, 0.0f);
		glVertex3f(110.0f, 360.0f, 0.0f);
		glVertex3f(115.0f, 385.0f, 0.0f);
		glVertex3f(110.0f, 410.0f, 0.0f);
		glVertex3f(40.0f, 410.0f, 0.0f);
		glVertex3f(35.0f, 385.0f, 0.0f);
	glEnd();
	glColor3f(1.0f, 0.89f, 0.42f);
	glBegin(GL_POLYGON);
		glVertex3f(150.0f, 320.0f, 0.0f);
		glVertex3f(220.0f, 320.0f, 0.0f);
		glVertex3f(220.0f, 370.0f, 0.0f);
		glVertex3f(185.0f, 390.0f, 0.0f);
		glVertex3f(150.0f, 370.0f, 0.0f);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
		glVertex3f(170.0f, 320.0f, 0.0f);
		glVertex3f(170.0f, 340.0f, 0.0f);
		glVertex3f(190.0f, 340.0f, 0.0f);
		glVertex3f(190.0f, 320.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(200.0f, 350.0f, 0.0f);
		glVertex3f(210.0f, 350.0f, 0.0f);
		glVertex3f(210.0f, 360.0f, 0.0f);
		glVertex3f(200.0f, 360.0f, 0.0f);
	glEnd();
	glColor3f(1.0f, 0.89f, 0.42f);
	glBegin(GL_POLYGON);
		glVertex3f(300.0f, 320.0f, 0.0f);
		glVertex3f(400.0f, 320.0f, 0.0f);
		glVertex3f(400.0f, 370.0f, 0.0f);
		glVertex3f(300.0f, 370.0f, 0.0f);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
		glVertex3f(315.0f, 350.0f, 0.0f);
		glVertex3f(325.0f, 350.0f, 0.0f);
		glVertex3f(325.0f, 360.0f, 0.0f);
		glVertex3f(315.0f, 360.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(335.0f, 350.0f, 0.0f);
		glVertex3f(345.0f, 350.0f, 0.0f);
		glVertex3f(345.0f, 360.0f, 0.0f);
		glVertex3f(335.0f, 360.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(355.0f, 350.0f, 0.0f);
		glVertex3f(365.0f, 350.0f, 0.0f);
		glVertex3f(365.0f, 360.0f, 0.0f);
		glVertex3f(355.0f, 360.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(375.0f, 350.0f, 0.0f);
		glVertex3f(385.0f, 350.0f, 0.0f);
		glVertex3f(385.0f, 360.0f, 0.0f);
		glVertex3f(375.0f, 360.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex3f(335.0f, 320.0f, 0.0f);
		glVertex3f(335.0f, 340.0f, 0.0f);
		glVertex3f(365.0f, 340.0f, 0.0f);
		glVertex3f(365.0f, 320.0f, 0.0f);
	glEnd();
	glColor3f(0.44f, 0.20f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex3f(450.0f, 350.0f, 0.0f);
		glVertex3f(600.0f, 350.0f, 0.0f);
		glVertex3f(550.0f, 450.0f, 0.0f);
		glVertex3f(500.0f, 450.0f, 0.0f);
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(500.0f, 450.0f, 0.0f);
		glVertex3f(550.0f, 450.0f, 0.0f);
		glVertex3f(525.0f, 490.0f, 0.0f);
	glEnd();
	glPushMatrix();
	glTranslated(90.0f, 10.0f, 0.0f);
	glColor3f(0.44f, 0.20f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(60.0f, 225.0f, 0.0f);
		glVertex3f(60.0f, 275.0f, 0.0f);
		glVertex3f(80.0f, 275.0f, 0.0f);
		glVertex3f(80.0f, 225.0f, 0.0f);
		glVertex3f(85.0f, 225.0f, 0.0f);
		glVertex3f(85.0f, 275.0f, 0.0f);
		glVertex3f(105.0f, 275.0f, 0.0f);
		glVertex3f(105.0f, 225.0f, 0.0f);
		glVertex3f(110.0f, 225.0f, 0.0f);
		glVertex3f(110.0f, 275.0f, 0.0f);
		glVertex3f(130.0f, 275.0f, 0.0f);
		glVertex3f(130.0f, 225.0f, 0.0f);
		glVertex3f(135.0f, 225.0f, 0.0f);
		glVertex3f(135.0f, 275.0f, 0.0f);
		glVertex3f(155.0f, 275.0f, 0.0f);
		glVertex3f(155.0f, 225.0f, 0.0f);
		glVertex3f(160.0f, 225.0f, 0.0f);
		glVertex3f(160.0f, 275.0f, 0.0f);
		glVertex3f(180.0f, 275.0f, 0.0f);
		glVertex3f(180.0f, 225.0f, 0.0f);
		glVertex3f(185.0f, 225.0f, 0.0f);
		glVertex3f(185.0f, 275.0f, 0.0f);
		glVertex3f(205.0f, 275.0f, 0.0f);
		glVertex3f(205.0f, 225.0f, 0.0f);
		glVertex3f(210.0f, 225.0f, 0.0f);
		glVertex3f(210.0f, 275.0f, 0.0f);
		glVertex3f(230.0f, 275.0f, 0.0f);
		glVertex3f(230.0f, 225.0f, 0.0f);
		glVertex3f(235.0f, 225.0f, 0.0f);
		glVertex3f(235.0f, 275.0f, 0.0f);
		glVertex3f(255.0f, 275.0f, 0.0f);
		glVertex3f(255.0f, 225.0f, 0.0f);
		glVertex3f(260.0f, 225.0f, 0.0f);
		glVertex3f(260.0f, 275.0f, 0.0f);
		glVertex3f(280.0f, 275.0f, 0.0f);
		glVertex3f(280.0f, 225.0f, 0.0f);
		glVertex3f(285.0f, 225.0f, 0.0f);
		glVertex3f(285.0f, 275.0f, 0.0f);
		glVertex3f(305.0f, 275.0f, 0.0f);
		glVertex3f(305.0f, 225.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(60.0f, 277.0f, 0.0f);
		glVertex3f(70.0f, 287.0f, 0.0f);
		glVertex3f(80.0f, 277.0f, 0.0f);
		glVertex3f(85.0f, 277.0f, 0.0f);
		glVertex3f(95.0f, 287.0f, 0.0f);
		glVertex3f(105.0f, 277.0f, 0.0f);
		glVertex3f(110.0f, 277.0f, 0.0f);
		glVertex3f(120.0f, 287.0f, 0.0f);
		glVertex3f(130.0f, 277.0f, 0.0f);
		glVertex3f(135.0f, 277.0f, 0.0f);
		glVertex3f(145.0f, 287.0f, 0.0f);
		glVertex3f(155.0f, 277.0f, 0.0f);
		glVertex3f(160.0f, 277.0f, 0.0f);
		glVertex3f(170.0f, 287.0f, 0.0f);
		glVertex3f(180.0f, 277.0f, 0.0f);
		glVertex3f(185.0f, 277.0f, 0.0f);
		glVertex3f(195.0f, 287.0f, 0.0f);
		glVertex3f(205.0f, 277.0f, 0.0f);
		glVertex3f(210.0f, 277.0f, 0.0f);
		glVertex3f(220.0f, 287.0f, 0.0f);
		glVertex3f(230.0f, 277.0f, 0.0f);
		glVertex3f(235.0f, 277.0f, 0.0f);
		glVertex3f(245.0f, 287.0f, 0.0f);
		glVertex3f(255.0f, 277.0f, 0.0f);
		glVertex3f(260.0f, 277.0f, 0.0f);
		glVertex3f(270.0f, 287.0f, 0.0f);
		glVertex3f(280.0f, 277.0f, 0.0f);
		glVertex3f(285.0f, 277.0f, 0.0f);
		glVertex3f(295.0f, 287.0f, 0.0f);
		glVertex3f(305.0f, 277.0f, 0.0f);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}

int* bezier(float t, int* p0, int* p1, int* p2, int* p3)
{
	int res[2];
		res[0] = pow((1 - t), 3) * p0[0] + 3 * t * pow((1 - t), 2) * p1[0] + 3 * pow(t, 2) * (1 - t) * p2[0] + pow(t, 3) * p3[0];
		res[1] = pow((1 - t), 3) * p0[1] + 3 * t * pow((1 - t), 2) * p1[1] + 3 * pow(t, 2) * (1 - t) * p2[1] + pow(t, 3) * p3[1];
	return res;
}

void drawBezierCurve() {
	glPointSize(2);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (float t = 0; t < 1; t += 0.001)
	{
		int* p = bezier(t, p0, p1, p2, p3);
		glVertex3f(p[0], p[1], 0);
	}
	glEnd();
}

void fire(unsigned char key, int x, int y) {
	if (key == ' ' && p1[1] < 400) {
		p1[0] += 2 * turn;
		p1[1] += 3;
		p2[0] += 4 * turn;
		p2[1] += 3;
		p3[0] += 6 * turn;
		if (turn == 1)
			catPowerBar = (p1[1] - 90) / 310.0;
		else
			dogPowerBar = (p1[1] - 90) / 310.0;
	}
	glutPostRedisplay();
}

void switchTurn() {
	if (turn == 1) {
		turn = -1;
		p0[0] = 500;
		p0[1] = 90;
		p1[0] = 500;
		p1[1] = 90;
		p2[0] = 500;
		p2[1] = 90;
		p3[0] = 500;
		p3[1] = 90;
		catPowerBar = 0;
		projectileTranslation[0] = 500;
		projectileTranslation[1] = 90;
		projectilePosition[0] = 500;
		projectilePosition[1] = 90;
	}
	else {
		turn = 1;
		p0[0] = 100;
		p0[1] = 90;
		p1[0] = 100;
		p1[1] = 90;
		p2[0] = 100;
		p2[1] = 90;
		p3[0] = 100;
		p3[1] = 90;
		dogPowerBar = 0;
		projectileTranslation[0] = 100;
		projectileTranslation[1] = 90;
		projectilePosition[0] = 100;
		projectilePosition[1] = 90;
	}
	toggleRelease();
	projectileAnimation = 0;
}

void drawPowerBars() {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(133.0f, 30.0f, 0.0f);
		glVertex3f(143.0f, 30.0f, 0.0f);
		glVertex3f(143.0f, 100.0f, 0.0f);
		glVertex3f(133.0f, 100.0f, 0.0f);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(133.0f, 30.0f, 0.0f);
		glVertex3f(143.0f, 30.0f, 0.0f);
		glVertex3f(143.0f, catPowerBar * 70 + 30.0f, 0.0f);
		glVertex3f(133.0f, catPowerBar * 70 + 30.0f, 0.0f);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(449.0f, 30.0f, 0.0f);
		glVertex3f(439.0f, 30.0f, 0.0f);
		glVertex3f(439.0f, 100.0f, 0.0f);
		glVertex3f(449.0f, 100.0f, 0.0f);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(449.0f, 30.0f, 0.0f);
		glVertex3f(439.0f, 30.0f, 0.0f);
		glVertex3f(439.0f, dogPowerBar * 70 + 30.0f, 0.0f);
		glVertex3f(449.0f, dogPowerBar * 70 + 30.0f, 0.0f);
	glEnd();
}

void toggleRelease() {
	releaseFlag *= -1;
}

void release(unsigned char key, int x, int y) {
	if (key == ' ')
		toggleRelease();
}

void drawProjectile() {
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslated(projectileTranslation[0]-projectilePosition[0], projectileTranslation[1]-projectilePosition[1], 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(projectilePosition[0] - 10, projectilePosition[1] - 20, 0.0f);
		glVertex3f(projectilePosition[0] + 10, projectilePosition[1] - 20, 0.0f);
		glVertex3f(projectilePosition[0] + 10, projectilePosition[1] + 20, 0.0f);
		glVertex3f(projectilePosition[0] - 10, projectilePosition[1] + 20, 0.0f);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(projectilePosition[0] - 2, projectilePosition[1] - 10, 0.0f);
		glVertex3f(projectilePosition[0] + 2, projectilePosition[1] - 10, 0.0f);
		glVertex3f(projectilePosition[0] + 2, projectilePosition[1] - 5, 0.0f);
		glVertex3f(projectilePosition[0] - 2, projectilePosition[1] - 5, 0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(projectilePosition[0] - 2, projectilePosition[1] + 10, 0.0f);
		glVertex3f(projectilePosition[0] + 2, projectilePosition[1] + 10, 0.0f);
		glVertex3f(projectilePosition[0] + 2, projectilePosition[1] + 5, 0.0f);
		glVertex3f(projectilePosition[0] - 2, projectilePosition[1] + 5, 0.0f);
	glEnd();
	glPopMatrix();
}

void animate() {
	animateProjectile();
	animateBackground();
	handleProjectile();
	animateAnimal();
	glutPostRedisplay();
}

void animateBackground() {
	if (sceneTranslation > 50 || sceneTranslation < -50)
		sceneTranslationFactor *= -1;
	sceneTranslation += sceneTranslationFactor;
}

void animateProjectile() {
	if (releaseFlag == 1 && projectileAnimation < 1) {
		int* p = bezier(projectileAnimation, p0, p1, p2, p3);
		projectileTranslation[0] = p[0];
		projectileTranslation[1] = p[1];
		projectileAnimation += 0.001;
	}
}

void animateAnimal() {
	if (dogTranslationFlag == 1) {
		if (upDownFlag == 1 && dogTranslation < 20)
			dogTranslation += animalTranslationFactor;
		if (upDownFlag == 1 && dogTranslation >= 20) {
			upDownFlag = 0;
			dogTranslation -= animalTranslationFactor;
		}
		if (upDownFlag == 0 && dogTranslation > 0)
			dogTranslation -= animalTranslationFactor;
		if (upDownFlag == 0 && dogTranslation <= 0) {
			upDownFlag = 1;
			dogTranslationFlag = 0;
			dogTranslation = 0;
		}
	}
	if (catTranslationFlag == 1) {
		if (upDownFlag == 1 && catTranslation < 20)
			catTranslation += animalTranslationFactor;
		if (upDownFlag == 1 && catTranslation >= 20) {
			upDownFlag = 0;
			catTranslation -= animalTranslationFactor;
		}
		if (upDownFlag == 0 && catTranslation > 0)
			catTranslation -= animalTranslationFactor;
		if (upDownFlag == 0 && catTranslation <= 0) {
			upDownFlag = 1;
			catTranslationFlag = 0;
			catTranslation = 0;
		}
	}
}

void handleProjectile() {
	if (projectileTranslation[0] >= 290 && projectileTranslation[0] <= 310 && projectileTranslation[1] <= 220)
		switchTurn();
	if (projectileAnimation >= 1) {
		if (turn == 1 && projectileTranslation[0] >= 460 && projectileTranslation[0] <= 550 && projectileTranslation[1] <= 100)
		{
			dogHealth -= 0.20;
			dogTranslationFlag = 1;
		}
		if (turn == -1 && projectileTranslation[0] <= 122 && projectileTranslation[0] >= 50 && projectileTranslation[1] <= 100)
		{
			catHealth -= 0.20;
			catTranslationFlag = 1;
		}
		switchTurn();
	}
}

void drawHealthBars() {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(50.0f, 10.0f, 0.0f);
		glVertex3f(120.0f, 10.0f, 0.0f);
		glVertex3f(120.0f, 20.0f, 0.0f);
		glVertex3f(50.0f, 20.0f, 0.0f);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
		glVertex3f(50.0f, 10.0f, 0.0f);
		glVertex3f(catHealth * 70 + 50.0f, 10.0f, 0.0f);
		glVertex3f(catHealth * 70 + 50.0f, 20.0f, 0.0f);
		glVertex3f(50.0f, 20.0f, 0.0f);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(480.0f, 10.0f, 0.0f);
		glVertex3f(550.0f, 10.0f, 0.0f);
		glVertex3f(550.0f, 20.0f, 0.0f);
		glVertex3f(480.0f, 20.0f, 0.0f);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
		glVertex3f(550.0f, 10.0f, 0.0f);
		glVertex3f(550.0f - dogHealth * 70, 10.0f, 0.0f);
		glVertex3f(550.0f - dogHealth * 70, 20.0f, 0.0f);
		glVertex3f(550.0f, 20.0f, 0.0f);
	glEnd();
}

void drawWall() {
	glColor3f(0.52, 0.15, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(290.0f, 0.0f, 0.0f);
		glVertex3f(310.0f, 0.0f, 0.0f);
		glVertex3f(310.0f, 220.0f, 0.0f);
		glVertex3f(290.0f, 220.0f, 0.0f);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(290.0f, 40.0f, 0.0f);
		glVertex3f(310.0f, 40.0f, 0.0f);
		glVertex3f(290.0f, 80.0f, 0.0f);
		glVertex3f(310.0f, 80.0f, 0.0f);
		glVertex3f(290.0f, 120.0f, 0.0f);
		glVertex3f(310.0f, 120.0f, 0.0f);
		glVertex3f(290.0f, 160.0f, 0.0f);
		glVertex3f(310.0f, 160.0f, 0.0f);
		glVertex3f(290.0f, 200.0f, 0.0f);
		glVertex3f(310.0f, 200.0f, 0.0f);
	glEnd();
}