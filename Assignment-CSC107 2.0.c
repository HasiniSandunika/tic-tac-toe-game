#include<stdio.h>
#include<stdlib.h>
#include<conio.h>//system("cls"); function contains in this library

int const LINES=3;

void readUserChoice(char *mark);//decides who will play first
void defineArray(char characters[][LINES]);//initializes the array
void readUserCharacter(char *player);//decides the character(X/O) that player wishes to use
void displayTable(char characters[][LINES]);//displays the board
char readUserMovement(char player,char characters[][LINES]);//gets user movement
char checkTable(char characters[][LINES]);//checks the winner(computer or player)
void definePointsArray(int points[][LINES]);//defines the array that contains points of each cell
char checkDraw(char characters[][LINES]);//checks whether the game is draw or not
void decideComputerMovement(char characters[][LINES],char computer,char player,int points[][LINES]);//gets computer movement
//calculate the points of each line in the characters array
int calculatePointsColumn1(char characters[][LINES],char computer,char player);
int calculatePointsColumn2(char characters[][LINES],char computer,char player);
int calculatePointsColumn3(char characters[][LINES],char computer,char player);
int calculatePointsRow1(char characters[][LINES],char computer,char player);
int calculatePointsRow2(char characters[][LINES],char computer,char player);
int calculatePointsRow3(char characters[][LINES],char computer,char player);
int calculatePointsDiagonal1(char characters[][LINES],char computer,char player);
int calculatePointsDiagonal2(char characters[][LINES],char computer,char player);

int main(){

  char characters1[LINES][LINES];
  int points1[LINES][LINES];
  char draw1, computer1, player1, mark1, value1, symbol1, decide;

  system("COLOR 79");
  printf("\n\n                                           This is the Tic-Tac-Toe game\n");
  printf("                                          ______________________________\n");
  printf("  You can play the game with the computer\n");
  do{
    readUserChoice(&mark1);
    if(mark1=='Y'){
    defineArray(characters1);
    displayTable(characters1);
    printf("  This is the structure of the table\n");
        readUserCharacter(&player1);
        if((player1=='X')||(player1=='O')){
            if(player1=='X'){
                computer1='O';
            }
            else{
                computer1='X';
            }
        definePointsArray(points1);
       do{
            symbol1=readUserMovement(player1,characters1);
            value1=checkTable(characters1);
            draw1=checkDraw(characters1);
            definePointsArray(points1);
       if((value1=='n')&&(symbol1=='d')&&(draw1!='l')){
                decideComputerMovement(characters1,computer1,player1,points1);
                value1=checkTable(characters1);
                system("cls");//use to clear the screen
                displayTable(characters1);
            }
       }while((value1=='n')&&(draw1!='l'));
       printf("  The final result is\n");
       displayTable(characters1);
         if(value1==player1)
            printf("  You won the game\n");
         else
            if(value1==computer1)
               printf("  Computer won the game\n");
            else
                printf("  Draw\n");
        }
        else{
            printf("  Invalid character,use only X or O,try again!\n");
        }
    }
    else{
    if(mark1=='N'){
         defineArray(characters1);
         displayTable(characters1);
         printf("  This is the structure of the table\n");
         readUserCharacter(&player1);
        if((player1=='X')||(player1=='O')){
            if(player1=='X'){
                computer1='O';
            }
            else{
                computer1='X';
            }
       do{
            printf("  Gets computer movement\n");
            definePointsArray(points1);
            decideComputerMovement(characters1,computer1,player1,points1);
            value1=checkTable(characters1);
            draw1=checkDraw(characters1);
            system("cls");
            displayTable(characters1);
            if((value1=='n')&&(draw1!='l')){
                symbol1=readUserMovement(player1,characters1);
                if(symbol1!='d'){
                     while(symbol1!='d'){
                     symbol1=readUserMovement(player1,characters1);
                     }
         }
                value1=checkTable(characters1);
                displayTable(characters1);
            }
       }while((value1=='n')&&(draw1!='l'));
       printf("  The final result is\n");
       displayTable(characters1);
       if(value1==player1)
            printf("  You won the game\n");
         else
            if(value1==computer1)
               printf("  Computer won the game\n");
            else
                printf("  Draw\n");
        }
        else{
            printf("  Invalid character,use only X or O,try again!\n");
         }
    }
    else{
        printf("  Invalid character,use only Y or N,try again!\n");
     }
    }
   printf("  Do you want to repeat the game\?(Enter 'Y' if yes otherwise press any key to exit):");
   scanf(" %c",&decide);
   }while(decide=='Y');
   return 0;
}

void readUserChoice(char *mark){//decides who will play first

    printf("  Do you like to be the first player(Y/N,only capital):");
    scanf(" %c" ,mark);
}

void readUserCharacter(char *player1){//decides the character(X/O) that player wishes to use

    printf("  Enter the character that you wish to use(X/O,only capital):");
    scanf(" %c" ,player1);
}

void displayTable(char characters[][LINES]){//displays the board

    int rows, colums;

    printf("\n  __________________\n");
    for(rows=0;rows<LINES;rows++){
        for(colums=0;colums<LINES;colums++){
            printf("    |%c",characters[rows][colums]);
        }
    printf("\n  __________________\n");
    }
}

char readUserMovement(char player,char characters[][LINES]){//gets user movement

    int place;
    char symbol;

    printf("  Input the number that you want to place your character:");
    scanf("%d",&place);
    switch(place){
    case 1:
        if((characters[0][0]!='X')&&(characters[0][0]!='O')){
           characters[0][0]=player;
           symbol='d';//returns if the computer can implement the character
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';//returns if the computer cannot implement the character
            }
            break;
    case 2:
        if((characters[0][1]!='X')&&(characters[0][1]!='O')){
           characters[0][1]=player;
           symbol='d';
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';
            }
            break;
    case 3:
        if((characters[0][2]!='X')&&(characters[0][2]!='O')){
           characters[0][2]=player;
           symbol='d';
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';
            }
            break;
    case 4:
        if((characters[1][0]!='X')&&(characters[1][0]!='O')){
           characters[1][0]=player;
           symbol='d';
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';
            }
            break;
    case 5:
        if((characters[1][1]!='X')&&(characters[1][1]!='O')){
           characters[1][1]=player;
           symbol='d';
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';
            }
            break;
    case 6:
        if((characters[1][2]!='X')&&(characters[1][2]!='O')){
           characters[1][2]=player;
           symbol='d';
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';
            }
            break;
    case 7:
        if((characters[2][0]!='X')&&(characters[2][0]!='O')){
           characters[2][0]=player;
           symbol='d';
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';
            }
            break;
    case 8:
        if((characters[2][1]!='X')&&(characters[2][1]!='O')){
           characters[2][1]=player;
           symbol='d';
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';
            }
            break;
    case 9:
        if((characters[2][2]!='X')&&(characters[2][2]!='O')){
           characters[2][2]=player;
           symbol='d';
           }
        else{
            printf("  Invalid selection,you or computer have already selected this number,try again!\n");
            symbol='k';
            }
            break;
    default:

            printf("  Invalid number,try again!\n");
            symbol='k';
            break;
    }
    return symbol;
}

char checkTable(char characters[][LINES]){//checks the winner(computer or player)

    char value;

    if((characters[0][0]==characters[0][1])&&(characters[0][0]==characters[0][2])&&(characters[0][1]==characters[0][2]))
        value=characters[0][0];
    else
        if((characters[1][0]==characters[1][1])&&(characters[1][0]==characters[1][2])&&(characters[1][1]==characters[1][2]))
        value=characters[1][0];
    else
        if((characters[2][0]==characters[2][1])&&(characters[2][0]==characters[2][2])&&(characters[2][1]==characters[2][2]))
        value=characters[2][0];
    else
        if((characters[0][0]==characters[1][0])&&(characters[0][0]==characters[2][0])&&(characters[1][0]==characters[2][0]))
        value=characters[0][0];
    else
        if((characters[0][1]==characters[1][1])&&(characters[0][1]==characters[2][1])&&(characters[1][1]==characters[2][1]))
        value=characters[0][1];
    else
        if((characters[0][2]==characters[1][2])&&(characters[0][2]==characters[2][2])&&(characters[1][2]==characters[2][2]))
        value=characters[0][2];
    else
        if((characters[0][0]==characters[1][1])&&(characters[0][0]==characters[2][2])&&(characters[1][1]==characters[2][2]))
        value=characters[0][0];
    else
        if((characters[2][0]==characters[1][1])&&(characters[2][0]==characters[0][2])&&(characters[1][1]==characters[0][2]))
        value=characters[2][0];
    else
        value='n';//'n' defines there is no winner
    return value;
 }

 void defineArray(char characters[][LINES]){//initializes the array

    characters[0][0]='1';
    characters[0][1]='2';
    characters[0][2]='3';
    characters[1][0]='4';
    characters[1][1]='5';
    characters[1][2]='6';
    characters[2][0]='7';
    characters[2][1]='8';
    characters[2][2]='9';
 }

char checkDraw(char characters[][LINES]){//checks whether the game is draw or not

    int rows, colums, value=0;
    char draw;

    for(rows=0;rows<LINES;rows++){
        for(colums=0;colums<LINES;colums++){
            if((characters[rows][colums]=='X')||(characters[rows][colums]=='O')){
               value=value+1;
            }
            else{
                value=value+0;
            }
        }
    }
    if(value==9)
        draw='l';//returns if the game is draw
    else
        draw='m';//returns if the game is not draw
    return draw;
}


void definePointsArray(int points[][LINES]){//defines the array that contains points of each cell

     int rows, colums;

    for(rows=0;rows<LINES;rows++){
        for(colums=0;colums<LINES;colums++){
            points[rows][colums]=-2;

        }
    }
}

void decideComputerMovement(char characters[][LINES],char computer,char player,int points[][LINES]){//gets computer movement

          int point1=0, point2=0, point3=0, point4=0;

    if((characters[0][0]!='X')&&(characters[0][0]!='O')){
        point1=calculatePointsColumn1(characters,player,computer);
        point2=calculatePointsRow1(characters,player,computer);
        point3=calculatePointsDiagonal1(characters,player,computer);
        points[0][0]=point1+point2+point3;
  }
        point1=0;//reusing above defined variables
        point2=0;
    if((characters[0][1]!='X')&&(characters[0][1]!='O')){
        point1=calculatePointsColumn2(characters,player,computer);
        point2=calculatePointsRow1(characters,player,computer);
        points[0][1]=point1+point2;
  }
        point1=0;
        point2=0;
        point3=0;
     if((characters[0][2]!='X')&&(characters[0][2]!='O')){
        point1=calculatePointsColumn3(characters,player,computer);
        point2=calculatePointsRow1(characters,player,computer);
        point3=calculatePointsDiagonal2(characters,player,computer);
        points[0][2]=point1+point2+point3;
  }
        point1=0;
        point2=0;
    if((characters[1][0]!='X')&&(characters[1][0]!='O')){
        point1=calculatePointsColumn1(characters,player,computer);
        point2=calculatePointsRow2(characters,player,computer);
        points[1][0]=point1+point2;
  }
        point1=0;
        point2=0;
        point3=0;
        point4=0;
     if((characters[1][1]!='X')&&(characters[1][1]!='O')){
        point1=calculatePointsColumn2(characters,player,computer);
        point2=calculatePointsRow2(characters,player,computer);
        point3=calculatePointsDiagonal1(characters,player,computer);
        point4=calculatePointsDiagonal2(characters,player,computer);
        points[1][1]=point1+point2+point3+point4;
  }
        point1=0;
        point2=0;
     if((characters[1][2]!='X')&&(characters[1][2]!='O')){
        point1=calculatePointsColumn3(characters,player,computer);
        point2=calculatePointsRow2(characters,player,computer);
        points[1][2]=point1+point2;
  }
        point1=0;
        point2=0;
        point3=0;
     if((characters[2][0]!='X')&&(characters[2][0]!='O')){
        point1=calculatePointsColumn1(characters,player,computer);
        point2=calculatePointsRow3(characters,player,computer);
        point3=calculatePointsDiagonal2(characters,player,computer);
        points[2][0]=point1+point2+point3;
  }
        point1=0;
        point2=0;
     if((characters[2][1]!='X')&&(characters[2][1]!='O')){
        point1=calculatePointsColumn2(characters,player,computer);
        point2=calculatePointsRow3(characters,player,computer);
        points[2][1]=point1+point2;
  }
        point1=0;
        point2=0;
        point3=0;
     if((characters[2][2]!='X')&&(characters[2][2]!='O')){
        point1=calculatePointsColumn3(characters,player,computer);
        point2=calculatePointsRow3(characters,player,computer);
        point3=calculatePointsDiagonal1(characters,player,computer);
        points[2][2]=point1+point2+point3;
  }
        point3=0;//reusing above defined variables
        point4=0;
   for (point1=0;point1<LINES; point1++){//finds the maximum number in the array
        for (point2=0;point2<LINES;point2++){
           if(points[point1][point2]> points[0][0]){
            points[0][0]=points[point1][point2];
            point3=point1;
            point4=point2;
            }
        }
     }
      characters[point3][point4]=computer;
}
//calculate the points of each line in the characters array
int calculatePointsColumn1(char characters[][LINES],char player,char computer){

       int countsComputer=0,countsPlayer=0;
       int cells;

        for(cells=0;cells<LINES;cells++){
            if(characters[cells][0]==player){
                countsPlayer=countsPlayer+1;
            }
            if(characters[cells][0]==computer){
                countsComputer=countsComputer+1;
            }
        }
       int marksForLines;
         if((countsComputer==1)&&(countsPlayer==1)){
            marksForLines=0;
        }
        else{
            if(countsPlayer==2)
                marksForLines=1000;
            else
                if(countsComputer==2)
                  marksForLines=100;
                else
                    if(countsPlayer==1)
                      marksForLines=10;
                    else
                        if(countsComputer==1)
                          marksForLines=9;
                        else
                          marksForLines=1;
        }
        return marksForLines;
}

int calculatePointsColumn2(char characters[][LINES],char player,char computer){

    int countsComputer=0,countsPlayer=0;
       int cells;

        for(cells=0;cells<LINES;cells++){
            if(characters[cells][1]==player){
                countsPlayer=countsPlayer+1;
            }
            if(characters[cells][1]==computer){
                countsComputer=countsComputer+1;
            }
        }
       int marksForLines;
         if((countsComputer==1)&&(countsPlayer==1)){
            marksForLines=0;
        }
        else{
            if(countsPlayer==2)
                marksForLines=1000;
            else
                if(countsComputer==2)
                  marksForLines=100;
                else
                    if(countsPlayer==1)
                      marksForLines=10;
                    else
                        if(countsComputer==1)
                          marksForLines=9;
                        else
                          marksForLines=1;
        }
        return marksForLines;
}

int calculatePointsColumn3(char characters[][LINES],char player,char computer){

    int countsComputer=0,countsPlayer=0;
       int cells;

        for(cells=0;cells<LINES;cells++){
            if(characters[cells][2]==player){
                countsPlayer=countsPlayer+1;
            }
            if(characters[cells][2]==computer){
                countsComputer=countsComputer+1;
            }
        }
       int marksForLines;
         if((countsComputer==1)&&(countsPlayer==1)){
            marksForLines=0;
        }
        else{
            if(countsPlayer==2)
                marksForLines=1000;
            else
                if(countsComputer==2)
                  marksForLines=100;
                else
                    if(countsPlayer==1)
                      marksForLines=10;
                    else
                        if(countsComputer==1)
                          marksForLines=9;
                        else
                          marksForLines=1;
        }
        return marksForLines;
}

int calculatePointsRow1(char characters[][LINES],char player,char computer){
    int countsComputer=0, countsPlayer=0;
    int cells;
    for(cells=0;cells<LINES;cells++){
            if(characters[0][cells]==player){
                countsPlayer=countsPlayer+1;
            }
            if(characters[0][cells]==computer){
                countsComputer=countsComputer+1;
            }
        }
        int marksForLines;
        if((countsComputer==1)&&(countsPlayer==1)){
            marksForLines=0;
        }
        else{
            if(countsPlayer==2)
                marksForLines=1000;
            else
                if(countsComputer==2)
                  marksForLines=100;
                else
                    if(countsPlayer==1)
                      marksForLines=10;
                    else
                        if(countsComputer==1)
                          marksForLines=9;
                        else
                          marksForLines=1;
        }
        return marksForLines;
 }

 int calculatePointsRow2(char characters[][LINES],char player,char computer){
    int countsComputer=0, countsPlayer=0;
    int cells;
    for(cells=0;cells<LINES;cells++){
            if(characters[1][cells]==player){
                countsPlayer=countsPlayer+1;
            }
            if(characters[1][cells]==computer){
                countsComputer=countsComputer+1;
            }
        }
        int marksForLines;
        if((countsComputer==1)&&(countsPlayer==1)){
            marksForLines=0;
        }
        else{
            if(countsPlayer==2)
                marksForLines=1000;
            else
                if(countsComputer==2)
                  marksForLines=100;
                else
                    if(countsPlayer==1)
                      marksForLines=10;
                    else
                        if(countsComputer==1)
                          marksForLines=9;
                        else
                          marksForLines=1;
        }
        return marksForLines;
 }

 int calculatePointsRow3(char characters[][LINES],char player,char computer){
    int countsComputer=0, countsPlayer=0;
    int cells;
    for(cells=0;cells<LINES;cells++){
            if(characters[2][cells]==player){
                countsPlayer=countsPlayer+1;
            }
            if(characters[2][cells]==computer){
                countsComputer=countsComputer+1;
            }
        }
        int marksForLines;
        if((countsComputer==1)&&(countsPlayer==1)){
            marksForLines=0;
        }
        else{
            if(countsPlayer==2)
                marksForLines=1000;
            else
                if(countsComputer==2)
                  marksForLines=100;
                else
                    if(countsPlayer==1)
                      marksForLines=10;
                    else
                        if(countsComputer==1)
                          marksForLines=9;
                        else
                          marksForLines=1;
        }
        return marksForLines;
 }

 int calculatePointsDiagonal1(char characters[][LINES],char player,char computer){

    int cells1=0, cells=0, countsComputer=0, countsPlayer=0;
    int marksForLines;

     while((cells1<LINES)&&(cells<LINES)){
         if(characters[cells1][cells]==player){
                countsPlayer=countsPlayer+1;
            }
         if(characters[cells1][cells]==computer){
                countsComputer=countsComputer+1;
            }
        cells1++;
        cells++;
     }
    if((countsComputer==1)&&(countsPlayer==1)){
            marksForLines=0;
        }
        else{
            if(countsPlayer==2)
                marksForLines=1000;
            else
                if(countsComputer==2)
                  marksForLines=100;
                else
                    if(countsPlayer==1)
                      marksForLines=10;
                    else
                        if(countsComputer==1)
                          marksForLines=9;
                        else
                          marksForLines=1;
        }
        return marksForLines;
}

int calculatePointsDiagonal2(char characters[][LINES],char player,char computer){

    int cells1=0, cells=2, countsComputer=0, countsPlayer=0;
    int marksForLines;

     while((cells1<LINES)&&(cells>=0)){
         if(characters[cells1][cells]==player){
                countsPlayer=countsPlayer+1;
            }
         if(characters[cells1][cells]==computer){
                countsComputer=countsComputer+1;
            }
        cells1++;
        cells--;
     }
    if((countsComputer==1)&&(countsPlayer==1)){
            marksForLines=0;
        }
        else{
            if(countsPlayer==2)
                marksForLines=1000;
            else
                if(countsComputer==2)
                  marksForLines=100;
                else
                    if(countsPlayer==1)
                      marksForLines=10;
                    else
                        if(countsComputer==1)
                          marksForLines=9;
                        else
                          marksForLines=1;
        }
        return marksForLines;
}
//end of the program







