/*
 
 Ultimate Tic Tac Toe
 Using OpenGL
 by Yash Joshi
 24 March 2019
 
 */



#include <GLUT/glut.h>    // Header File For The GLUT Library
#include <OpenGL/gl.h>    // Header File For The OpenGL32 Library
#include <OpenGL/glu.h> 
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <time.h> 
int matrix[3][3][3][3],final[3][3];
int playerturn; 
bool gameover=false;
int result;
void myInit(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	gluOrtho2D(0,1200,0,1000);
}
void drawString (void * font, char *s, float x, float y){
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen (s); i++)
        glutBitmapCharacter (font, s[i]);
}
int glol=1,glok=1,gloi=1,gloj=1;
bool checkifdraw()
{
    int i, j;
    bool draw;
    for(i = 0; i <= 2; i++)
    {
        for(j = 0; j <= 2; j++)
        {
            if(final[i][j] == 0)
                return false;
        }
    }
    
    return true;
}
bool finalcheckifwin()
{
    int i, j;
    
    //check if there are horizontal win i.e if there is any row that has same value
    for(i = 0; i <= 2; i++)
    {
        for(j = 1; j <= 2; j++)
        {
            if(final[i][0] != 0 && final[i][0] == final[i][j])
            {
                if(j == 2)
                    return true;
            }
            else
                break;
        }
    }
    //check if there are vertical win i.e if there is any column that has same value
    for(i = 0; i <= 2; i++)
    {
        for(j = 1; j <= 2; j++)
        {
            if(final[0][i] != 0 && final[0][i] == final[j][i])
            {
                if(j == 2)
                    return true;
            }
            else
                break;
        }
    }   
    //check if there is any diagonal win i.e. if there is any diagonals that has same value
    for(i = 1; i <= 2; i++)
    {
        if(final[0][0] != 0 && final[0][0] == final[i][i])
        {
            if(i == 2)
                return true;
        }
        else
            break;
    }
    for(i = 1; i <= 2; i++)
    {
        if(final[2][0] != 0 && final[2][0] == final[2 - i][i])
        {
            if(i == 2)
                return true;
        }
        else
            break;
    }
}
bool checkifwin()
{
    int i, j;  
    //check if there are horizontal win i.e if there is any row that has same value
    for(i = 0; i <= 2; i++)
    {
        for(j = 1; j <= 2; j++)
        {
            if(matrix[gloi][gloj][i][0] != 0 && matrix[gloi][gloj][i][0] == matrix[gloi][gloj][i][j])
            {
                if(j == 2)
                    return true;
            }
            else
                break;
        }
    }  
    //check if there are vertical win i.e if there is any column that has same value
    for(i = 0; i <= 2; i++)
    {
        for(j = 1; j <= 2; j++)
        {
            if(matrix[gloi][gloj][0][i] != 0 && matrix[gloi][gloj][0][i] == matrix[gloi][gloj][j][i])
            {
                if(j == 2)
                    return true;
            }
            else
                break;
        }
    }    
    //check if there is any diagonal win i.e. if there is any diagonals that has same value
    for(i = 1; i <= 2; i++)
    {
        if(matrix[gloi][gloj][0][0] != 0 && matrix[gloi][gloj][0][0] == matrix[gloi][gloj][i][i])
        {
            if(i == 2)
                return true;
        }
        else
            break;
    }
    for(i = 1; i <= 2; i++)
    {
        if(matrix[gloi][gloj][2][0] != 0 && matrix[gloi][gloj][2][0] == matrix[gloi][gloj][2 - i][i])
        {
            if(i == 2)
                return true;
        }
        else
            break;
    }
    return false;
}
void sel(int k,int l)
{
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    //00
    glVertex2i(300,1000);
    glVertex2i(300,700);
    
    glVertex2i(10,700);
    glVertex2i(300,700);
    
    //01
    glVertex2i(300,1000);
    glVertex2i(300,700);
    
    glVertex2i(300,700);
    glVertex2i(600,700);

    glVertex2i(600,700);
    glVertex2i(600,1000);

    //02
    glVertex2i(600,1000);
    glVertex2i(600,700);
    
    glVertex2i(600,700);
    glVertex2i(900,700);

    //10
    glVertex2i(10,700);
    glVertex2i(300,700);
    
    glVertex2i(300,700);
    glVertex2i(300,400);
    
    glVertex2i(300,400);
    glVertex2i(10,400);

    //11

    glVertex2i(300,700);
    glVertex2i(300,400);
    glVertex2i(600,700);
    glVertex2i(300,700);
    glVertex2i(600,700);
    glVertex2i(600,400);
    glVertex2i(600,400);
    glVertex2i(300,400);

    //12
    glVertex2i(600,700);
    glVertex2i(900,700);
    glVertex2i(600,700);
    glVertex2i(600,400);
    glVertex2i(600,400);
    glVertex2i(900,400);

    //20
    glVertex2i(10,400);
    glVertex2i(300,400);
    glVertex2i(300,400);
    glVertex2i(300,100);

    //21
    glVertex2i(300,100);
    glVertex2i(300,400);
    glVertex2i(300,400);
    glVertex2i(600,400);
    glVertex2i(600,400);
    glVertex2i(600,100);

    //22
    glVertex2i(600,100);
    glVertex2i(600,400);
    glVertex2i(600,400);
    glVertex2i(900,400);

    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    if(k==0&&l==0)
    {
        glVertex2i(300,1000);
        glVertex2i(300,700);
        
        glVertex2i(10,700);
        glVertex2i(300,700);
    }

    else if(k==0&&l==1)
    {
        glVertex2i(300,1000);
        glVertex2i(300,700);
        
        glVertex2i(300,700);
        glVertex2i(600,700);

        glVertex2i(600,700);
        glVertex2i(600,1000);
    }
    else if(k==0&&l==2)
    {
        glVertex2i(600,1000);
        glVertex2i(600,700);
        
        glVertex2i(600,700);
        glVertex2i(900,700);
    }
    else if(k==1&&l==0)
    {
        glVertex2i(10,700);
        glVertex2i(300,700);
        
        glVertex2i(300,700);
        glVertex2i(300,400);
        
        glVertex2i(300,400);
        glVertex2i(10,400);
    }
    else if(k==1&&l==1)
    {
        glVertex2i(300,700);
        glVertex2i(300,400);
        glVertex2i(600,700);
        glVertex2i(300,700);
        glVertex2i(600,700);
        glVertex2i(600,400);
        glVertex2i(600,400);
        glVertex2i(300,400);
    }
    else if(k==1&&l==2)
    {
        glVertex2i(600,700);
        glVertex2i(900,700);
        glVertex2i(600,700);
        glVertex2i(600,400);
        glVertex2i(600,400);
        glVertex2i(900,400);
    }
    else if(k==2&&l==0)
    {
        glVertex2i(10,400);
        glVertex2i(300,400);
        glVertex2i(300,400);
        glVertex2i(300,100);
    }
    else if(k==2&&l==1)
    {
        glVertex2i(300,100);
        glVertex2i(300,400);
        glVertex2i(300,400);
        glVertex2i(600,400);
        glVertex2i(600,400);
    glVertex2i(600,100);
    }

    else if(k==2&&l==2)
    {
        glVertex2i(600,100);
        glVertex2i(600,400);
        glVertex2i(600,400);
        glVertex2i(900,400);
    }
    glEnd();
    glFlush();
    glColor3f(1,1,1);
}
void finalxo()
{
    int fact = 150;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
            {   
                //printf("f: %d",final[i][j]);
                if(final[i][j] == 1)
                {
                    glBegin(GL_LINES);
                    glVertex2f(900+50 + j * 100 - 25, 100 + (2-i) * 100 - 25 + fact);
                    glVertex2f(900+50 + j * 100 + 25, 100 + (2-i) * 100 + 25+ fact);
                    glVertex2f(900+50 + j * 100 - 25, 100 + (2-i) * 100 + 25+ fact);
                    glVertex2f(900+50 + j * 100 + 25, 100 + (2-i) * 100 - 25+ fact);
                    glEnd();
                }
                else if(final[i][j] == 2) //if it is 2 then draw o
                {
                    glBegin(GL_LINE_LOOP);
                    glVertex2f(900+50 + j * 100 - 25, 100 + (2-i) * 100 - 25+ fact);
                    glVertex2f(900+50 + j * 100 - 25, 100 + (2-i) * 100 + 25+ fact);
                    glVertex2f(900+50 + j * 100 + 25, 100 + (2-i) * 100 + 25+ fact);
                    glVertex2f(900+50 + j * 100 + 25, 100 + (2-i) * 100 - 25+ fact);
                    glEnd();
                }
                
            }
            //printf("\n");
    }  
    result = 0;     
}
void click(int button, int state, int x, int y)
{
    int i,j,k,l;
    //y=y+20;
    if(x<=900 && y<=728)
    {
    gloi=i = y/240;
    gloj=j= x/300;
    glok=k= (y - 240*i)/80;
    glol=l = (x-300*j)/100;
   //printf("x : %d y : %d \n",x,y);
    //printf(" %d  %d %d %d \n",i,j,k,l);
    if(gameover == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        
        if(playerturn == 1)
        {
            if(matrix[i][j][k][l] == 0)
            {
                matrix[i][j][k][l] = 1;
                playerturn = 2;
            }
        }
        else
        {
            if(matrix[i][j][k][l] == 0)
            {
                matrix[i][j][k][l] = 2;
                playerturn = 1;
            }
        }
    }
    
    }
    
}
void drawxo()
{
    //printf("drawxo\n");
    int fact = 50;
    for(int i = 0; i <= 2; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            for(int k = 0;k<=2;k++)
            {
                for(int l = 0;l<=2;l++)
                {
                    if(matrix[i][j][k][l] == 1) //if it is 1 then draw x
                    {
                        glBegin(GL_LINES);
                        glVertex2f(50 + l * 100 + j * 300 - 25,100 + (2-i) * 300 + (2-k) * 100 - 25 + fact);
                        glVertex2f(50 + l * 100 + j * 300 + 25,100 + (2-i) * 300 + (2-k) * 100 + 25+ fact);
                        glVertex2f(50 + l * 100 + j * 300 - 25, 100 + (2-i) * 300 + (2-k) * 100 + 25+ fact);
                        glVertex2f(50 + l * 100 + j * 300 + 25, 100 + (2-i) * 300 + (2-k) * 100 - 25+ fact);
                        glEnd();
                    }
                    else if(matrix[i][j][k][l] == 2) //if it is 2 then draw o
                    {
                        glBegin(GL_LINE_LOOP);
                        glVertex2f(50 + l * 100 + j * 300 - 25, 100 + (2-i) * 300 + (2-k) * 100 - 25+ fact);
                        glVertex2f(50 + l * 100 + j * 300 - 25,100 + (2-i) * 300 + (2-k) * 100 + 25+ fact);
                        glVertex2f(50 + l * 100 + j * 300 + 25, 100 + (2-i) * 300 + (2-k) * 100 + 25+ fact);
                        glVertex2f(50 + l * 100 + j * 300 + 25, 100 + (2-i) * 300 + (2-k) * 100 - 25+ fact);
                        glEnd();
                    }
                    
                }   
            }
        }
    }
}
void initgame()
{
    playerturn = 1;
    
    //clear the matrix
    for(int i = 0; i <= 2; i++)
        for(int j = 0; j <= 2; j++)
            for(int k=0;k<=2;k++)
                for(int l=0;l<=2;l++)
                    matrix[i][j][k][l] = 0;

    for(int i = 0;i<3;i++)
        for(int j = 0;j<3;j++)
            final[i][j]=0;   

    glol=1;glok=1;gloi=1;gloj=1;  
    gameover=false;                   
        
    
}

void drawlines()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
   int y=100;

    // vertical lines
    glVertex2f(100, 0+y);
    glVertex2f(100, 900+y);

    glVertex2f(200, 0+y);
    glVertex2f(200, 900+y);
    
    
    glVertex2f(300, 0+y);
    glVertex2f(300, 900+y);
    
    glVertex2f(400, 0+y);
    glVertex2f(400, 900+y);

    glVertex2f(500, 0+y);
    glVertex2f(500, 900+y);

    glVertex2f(600, 0+y);
    glVertex2f(600, 900+y);

    glVertex2f(700, 0+y);
    glVertex2f(700, 900+y);

    glVertex2f(800, 0+y);
    glVertex2f(800, 900+y);
    
    
    //horizontal lines

    glVertex2f(10, 50+50+y);
    glVertex2f(900, 50+50+y);

    glVertex2f(10, 150+50+y);
    glVertex2f(900, 150+50+y);

    glVertex2f(10, 250+50+y);
    glVertex2f(900, 250+50+y);

    glVertex2f(10, 350+50+y);
    glVertex2f(900, 350+50+y);

    glVertex2f(10, 450+50+y);
    glVertex2f(900, 450+50+y);

    glVertex2f(10, 550+50+y);
    glVertex2f(900, 550+50+y);

    glVertex2f(10, 650+50+y);
    glVertex2f(900, 650+50+y);

    glVertex2f(10, 750+50+y);
    glVertex2f(900, 750+50+y);

    glColor3f(0.0,0.0,1.0);

    glVertex2f(900+5, 250+50);
    glVertex2f(1200-5, 250+50);

    glVertex2f(900+5, 350+50);
    glVertex2f(1200-5, 350+50);
    
    glVertex2f(1100, 200+5);
    glVertex2f(1100, 500-5);

    glVertex2f(1000, 200+5);
    glVertex2f(1000, 500-5);

    glEnd();
}
void KeyPress(unsigned char key, int x, int y ){
    switch(key){
        case 'y':
            if(gameover == true)
            {
                gameover = false;
                initgame();
            }
            break;
        case 'n':
            if(gameover == true)
                exit(0);
            break;
        case 27:
            exit(0);
            
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(playerturn == 1)
        drawString(GLUT_BITMAP_HELVETICA_18, "X turn", 950, 800);
    else
        drawString(GLUT_BITMAP_HELVETICA_18, "O turn", 950, 800);
    
    drawlines();
        glColor3f(1, 1, 1);

    drawString(GLUT_BITMAP_HELVETICA_18, "Final : ", 1000, 550);

    drawxo();
    finalxo();
    sel(glok,glol); 
      
    if(finalcheckifwin() == true)
    {
        //the player who made the previous move is the winner
        if(playerturn == 1)
        {
            gameover = true;
            result = 2; //player2 wins
        }
        else
        {
            gameover = true;
            result = 1; //player1 wins
        }
    }
    else if(checkifdraw() == true)
    {
        gameover = true;
        result = 0;
    }
    if(gameover == true)
    {
        drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 950, 650);
        
        if(result == 0)
            drawString(GLUT_BITMAP_HELVETICA_18, "Its a draw", 950 ,700);
        
        if(result == 1)
            drawString(GLUT_BITMAP_HELVETICA_18, "X wins", 950, 700);
        
        if(result == 2)
            drawString(GLUT_BITMAP_HELVETICA_18, "O wins", 950, 700);
        
        drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to continue (y/n)", 950 ,600);
    } 
    glFlush();

    if(checkifwin() == true)
    {
        //the player who made the previous move is the winner
        if(playerturn == 1)
        {
            //game = true;
            //result = 2; //player2 wins
            if(final[gloi][gloj]==0)
                final[gloi][gloj]=2;
        }
        else
        {
            //game = true;
            //result = 1; //player1 wins
            if(final[gloi][gloj]==0)
                final[gloi][gloj]=1;
        }
    }
    
    

    
}
void reshape(int x, int y)
{
        glutReshapeWindow( 1200, 1000);

}
int main(int argc, char **argv)
{
	
	
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1200,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Ultimate Tic Tac Toe");
	myInit();
    glutReshapeFunc(reshape);


	glutDisplayFunc(display);
    glutKeyboardFunc(KeyPress);
    glutMouseFunc(click);
    glutIdleFunc(display);
	glutMainLoop();
}
