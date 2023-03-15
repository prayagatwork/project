#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];

int main(){
    char done;
    printf("this is X-O game against computer \n");

    done=' ';
    init_matrix();

    do{
        disp_matrix();
        get_player_move();
        done=check();
        if(done!= ' '){
            break;
        }
        get_computer_move();
        done=check();
    }
        while(done==' ');
        if(done=='X'){
            printf("you won\n");
        }else{
            printf("computer won\n");
        }
        disp_matrix();
    
    return 0;
}

// 1
void init_matrix(void){
    int i,j;
    for(int i=0;i<3;i++){
        for(j=0;j<3;j++){
            matrix[i][j] =' ';

        }
    }
}

// 2
void disp_matrix(void){
     
     int t;

     for(t=0;t<3;t++){
        printf("%c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);

        if(t!=2){
            printf("\n---|---|---\n");
        }
        printf("\n");
     }
}

// 3
void get_player_move(void){
    int x,y;
    printf("enter the coordinates for move\n");
    scanf("%d%*c%d", &x,&y);
    x--;y--;

    if(matrix[x][y]!= ' '){
        printf("invalid move\n");
        get_player_move();
    }
    else{
        matrix[x][y] = 'X';
    }
}

// 4
void get_computer_move(void){
    int i,j;
    for(int i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(matrix[i][j]==' '){
                break;
            }
            if(matrix[i][j]==' '){
                break;
            }
        }
        if(i*j==9){
            printf("draw\n");
            exit(0);
        }else{
            matrix[i][j]= 'O';
        }
    }
}