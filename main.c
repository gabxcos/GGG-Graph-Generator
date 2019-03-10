#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {

    
    FILE* f = fopen("strings.txt", "r");
    
    if (f == NULL){
        printf("Errore scrittura.");
        exit(1);
    }
    
    char readbuffer[3];
    int counter = 1;
    
    while(fgets(readbuffer, 3, f)){
        int i = atoi(readbuffer);
        
        int matrix[i][i];
        char linebuffer[i+2];
        
        for (int j = 0; j < i; j++){
            fgets(linebuffer, i+2, f);
            for (int k = 0; k < i; k++){
                matrix[j][k] = (int)(linebuffer[k]-'0');
            }
        }
        
        char filename[20];
        sprintf(filename, "results/%d.gfd", counter);
        
        FILE* graphfile = fopen(filename, "w");
        fprintf(graphfile, "directed\n%d", i);
        for (int x = 0; x < i; x++){
            for (int y = 0; y < i; y++){
                if (matrix[x][y]==1) fprintf(graphfile, "\n%d %d", x, y);
            }
        }
        fclose(graphfile);
        counter++;
    }
    
    return (EXIT_SUCCESS);
}

