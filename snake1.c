#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define cols 80
#define rows 20

char board[cols*rows];
int isGameover=0;
int snakeX=5;
int snakeY=5;

void fill_board(){
    int x,y;

    for(y=0;y<rows; y++){
        for(x=0;x<cols;x++){
            if(x==0||y==0 || x==cols-1 || y==rows-1){
               board[y*cols + x]= '#';}
               else { board[y*cols + x]= ' ';}
            
        }

    }
}

void clear_screen(){
    //windows
    system("cls");
    //linux
    //system("clear");
}

void print_board(){
    int x,y;
    clear_screen();
    for(y=0;y<rows; y++){
        for(x=0;x<cols;x++){
            putch(board[y*cols + x]);
        }
            putch('\n');
    }
}

#define len 256
struct snakepart{
    int x,y;

};
struct Snake {
    int length;
    struct snakepart part[len];
};

struct Snake snake;


void draw_snake(){
    // board[snakeY*cols + snakeX]='@';
    int i;

    for(i=snake.length;i>0;i--){
        board[snake.part[i].y*cols + snake.part[i].x]='o';
    }
     board[snake.part[0].y*cols + snake.part[0].x]='O';
}


void move_snake(int deltaX,int deltaY){

snake.part[0].x=deltaX;
snake.part[0].y=deltaY;

}

void read_key(){
    int ch=getch();
    
    switch(ch){
         case '8': move_snake( 0, -1); break;
         case '4': move_snake( -1, 0); break;
         case '6': move_snake( 1,  0); break;
         case '2': move_snake( 0,  1); break;
         
    }
}



int main(int argc,char **argv){

    snake.length=1;
    snake.part[0].x=5;
    snake.part[0].y=5;
    
    while(!isGameover){
fill_board();
draw_snake();
print_board();
read_key();
    }
    return 0;

}