#include <iostream>
#include <conio.h>
using namespace std;
bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};              // idk
eDirection dir; // idk

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls"); // windows command to clear the screen.
    
   
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";

            else{                                                       //drawing of snake tail/body
             mbool print = false;                         //
                for(int k = 0; k < nTail; k++){             //
                    if(tailX[k] == j && tailY[k] == i){     //
                        cout<<"o";                          //
                        print = true;                       //snake body/tail,
                    }
                }
                if(!print)
                cout << " ";
            }
               

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout<<"Score : "<<score<<endl;
     
}
void Input()
{
    if (_kbhit()) //_kbhit() will check if any character on the keyboard is pressed, boolian type,
    {
        switch (_getch()) // will return the ASCII value of the chacracter that was pressed,
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int previousX = tailX[0];       //logic for the snake body/tail,
    int previousY = tailY[0];       //
    int previous2X, previous2Y;     //
    tailX[0] = x;                   //
    tailY[0] = y;                   //
    for(int i=1; i<nTail; i++){     //
        previous2X = tailX[i];      //
        previous2Y = tailY[i];      //
        tailX[i] = previousX;       //
        tailY[i] = previousY;       //
        previousX = previous2X;     //
        previousY = previous2Y;     //snake body/tail,
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default : 
        break;
    }
    if(x > width || x < 0 || y > height || y < 0)
        gameOver = true;
    if(x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;    //to increase the tail,
    }

}
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        // Sleep(10); slows the game a lil bit.
    }
    return 0;
}