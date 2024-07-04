#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int emtiazpl1(int map[8][8], int x, int y){
    return map[x][y];
}
int emtiazpl2(int map[8][8], int x, int y){
    return map[x][y];
}


int showMap(int show[8][8], int map[8][8], int x, int y){
    system("clear");
    
    
    
    
    for (int a = 0; a < 8; a++){
        printf("  %d", a);
    }
    
    printf("\n"); 
      
    for (int i = 0; i < 8; i++){
        printf("%d", i);
        for (int j = 0; j < 8; j++){
            
            if (show[j][i] == 1){
                if ((map[j][i]) >= 100){
                    printf("[!]");
                    
                    
                    
                }else{
                    printf("[%d]", map[j][i]);
                    
                    
                }
            }else{
                printf("[ ]");
                
            }
        }
        
        printf("\n");
        //printf("-------------------------");
        //printf("\n");
    }
    printf("-------------------------");
    printf("\n");
    return map[x][y];
    
    
}
int checkgame(int show[8][8], int map[8][8], int bomb){
    
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (show[j][i] == 1){
                if (map[j][i] >= 100){
                    bomb ++;
                }
            }
        }
    }
    return bomb;
    
}




void checkBomb(int map[8][8], int x, int y){
    map[x][y] = 100;
    if (x - 1 >= 0){
        map[x-1][y]++;
        if (y - 1 >= 0){
            map[x-1][y-1]++;
        }
        if (y + 1 < 8){
            map[x-1][y+1]++;
        }
    }
    if (x + 1 < 8){
        map[x+1][y]++;
        if(y - 1 >= 0){
            map[x+1][y-1]++;
        }
        if (y + 1 < 8){
            map[x+1][y+1]++;
        }
    }
    if (y - 1 >= 0){
        map[x][y-1]++;
    }
    if (y + 1 < 8){
        map[x][y+1]++;
    }
    

}

int my_select(int show[8][8], int map[8][8], int x, int y){
    
    if (x<0 || y<0 || x>=8 || y>=8){
        return 0;
    }
    if (show[x][y] == 1){
        return 0;
    }
    show[x][y] = 1;
    if (map[x][y] == 0){
        
        my_select(show, map, x+1, y);
        my_select(show, map, x-1, y);
        my_select(show, map, x, y+1);
        my_select(show, map, x, y-1);
        my_select(show, map, x+1, y+1);
        my_select(show, map, x+1, y-1);
        my_select(show, map, x-1, y+1);
        my_select(show, map, x-1, y-1);
    }    
    
}



int main(){
    int map[8][8] = {0};
    int show[8][8] = {0};
    int bombCount = 15;
    int tpl = 2;
    char name1[100];
    char name2[100];
    int emtiaz1 = 0, emtiaz2 = 0;
    int win1 = 0, win2 = 0;
    int lvl1 = 0, lvl2 = 0;
    char a[10000];
    srand(time(NULL));
    for (int i = 0; i < bombCount; i++){
        int x = rand()%8;
        int y = rand()%8;
        if (map[x][y] < 100){
            checkBomb(map, x, y);
        }else{
            i--;
        }
    }
    printf("player 1 : ");
    scanf("%s", name1);
    printf("player 2 : ");
    scanf("%s", name2);
    showMap(show, map, 0, 0);
    int pl1 = 0, pl2 = 0;
    

    while (1){
        int x, y;
        
        int res = checkgame(show, map, 0);
        if (res == 15){
            printf("<Game Over>\n");
            if (emtiaz1 > emtiaz2){
                printf("emtiaz %s = %d\n", name1, emtiaz1);
                printf("emtiaz %s = %d\n", name2, emtiaz2);
                printf("%s is the winner\n", name1);
                win1 ++;
            }else if (emtiaz1 == emtiaz2){
                printf("Equal\n");
            }else{
                printf("emtiaz %s = %d\n", name2, emtiaz2);
                printf("emtiaz %s = %d\n", name1, emtiaz1);
                printf("%s is the winner\n", name2);
                win2 ++;
            }
            
            printf("-------------------------");
            break;
        }
        
        
        
        if (tpl % 2 == 0){   
            printf("%s ==> EMTIAZ = %d\n", name1, emtiaz1);
            printf("-------------------------\n");
            
        }else{
            printf("%s ==> EMTIAZ = %d\n", name2, emtiaz2);
            printf("-------------------------\n");
            
        }
        
        //printf("-------------------------");
        printf("\n");
        printf("enter X : ");
        scanf("%d", &x);
        printf("enter Y : ");
        scanf("%d", &y);

        my_select(show, map, x, y);
        showMap(show, map, x, y);
        

        if (showMap(show, map, x, y) == 0 || showMap(show, map, x, y) < 100){
            tpl ++;
        }
        int w = emtiazpl1(map, x, y);
        int z = emtiazpl2(map, x, y);
        if (tpl % 2 == 0){
            if (w >= 100){
                emtiaz1 ++;
            }
        }else{
            if (z >= 100){
                emtiaz2 ++;
            }
        }
         
    }
    
    


    return 0;
}
