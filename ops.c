#include <string.h>
#include <math.h>

typedef struct{
        float x;
        float y;
        float z;
} Point;



void gen_grid(int size, Point grid[size][size][size]){

        for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                        for(int k=0; k<size; k++){
                                grid[i][j][k].x = i;
                                grid[i][j][k].y = j;
                                grid[i][j][k].z = k;
                                printf("(%d, %d, %d)", i, j, k);
                        printf("\n");
                        }
                printf("\n");
                }
        }
}

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
	float x;
	float y;
	float z;
} Point;



void gen_grid(int size, Point grid[size][size][size]){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				grid[i][j][k].x = i;
				grid[i][j][k].y = j;
				grid[i][j][k].z = k;
				printf("(%d, %d, %d)", i, j, k);
			printf("\n");
			}
		printf("\n");
		}
	}
}

void scale_grid(int size, int scale, Point grid[size][size][size], Point scaled_grid[size][size][size]){
	for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                        for(int k=0; k<size; k++){
				scaled_grid[i][j][k].x = grid[i][j][k].x * scale;
				scaled_grid[i][j][k].y = grid[i][j][k].y * scale;
				scaled_grid[i][j][k].z = grid[i][j][k].z * scale;
				printf("(%f, %f, %f)", scaled_grid[i][j][k].x, scaled_grid[i][j][k].y, scaled_grid[i][j][k].z);
			printf("\n");
			}
		printf("\n");
		}
	}
}

float M[3][3];
void set_matrix(int theta){
	M[0][0] = 1;
	M[0][1] = 0;
	M[0][2] = 0;

	M[1][0] = 0;
	M[1][1] = cos(theta);
	M[1][2] = -sin(theta);

	M[2][0] = 0;
	M[2][1] = sin(theta);
	M[2][2] = cos(theta);
}

void rotate_x(int size, int theta, Point grid[size][size][size], Point rotated_grid[size][size][size]){
	for(int i=0; i<size; i++){
               for(int j=0; j<size; j++){
                        for(int k=0; k<size; k++){
				rotated_grid[i][j][k].x = grid[i][j][k].x * M[0][0] +
							  grid[i][j][k].y * M[0][1] +
							  grid[i][j][k].z * M[0][2];

				rotated_grid[i][j][k].y = grid[i][j][k].x * M[1][0] +
                                                          grid[i][j][k].y * M[1][1] +
                                                          grid[i][j][k].z * M[1][2];
				
				rotated_grid[i][j][k].z = grid[i][j][k].x * M[2][0] +
                                                          grid[i][j][k].y * M[2][1] +
                                                          grid[i][j][k].z * M[2][2];
				printf("(%f, %f, %f)", rotated_grid[i][j][k].x, rotated_grid[i][j][k].y, rotated_grid[i][j][k].z);
			printf("\n");
			}
		printf("\n");
		}
	}
}
float T[4][4];
void set_transformer(int t1, int t2, int t3){
	float I[3][3];

        I[0][0] = 1;
       	I[0][1] = 0;
       	I[0][2] = 0;

       	I[1][0] = 0;
       	I[1][1] = 1;
       	I[1][2] = 0;

       	I[2][0] = 0;
       	I[2][1] = 0;
       	I[2][2] = 1;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			T[i][j] = I[i][j];
		}
	}

	T[0][3] = t1;
	T[1][3] = t2;
	T[2][3] = t3;
	
	T[3][0] = 0;
	T[3][1] = 0;
	T[3][2] = 0;
	T[3][3] = 1;
}

void transform_vector(int v1, int v2, int v3){

	float v[4];
	v[0] = v1;
	v[1] = v2;
	v[2] = v3;
	v[3] = 1;

	float new_v[4];
	
	new_v[0] = T[0][3] + v1;
	new_v[1] = T[1][3] + v2;
	new_v[2] = T[2][3] + v3;
	printf("%f %f %f", new_v[0], new_v[1], new_v[2]); 
}

float t[3];

void set_t(int t1, int t2, int t3){
	t[0] = t1;
        t[1] = t2;
        t[2] = t3;
}
float v[4];
void set_v(int v1, int v2, int v3){
        v[0] = v1;
        v[1] = v2;
        v[2] = v3;
        v[3] = 1;
}

int translate(int size, Point grid[size][size][size], Point translated_grid[size][size][size]){
	for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                        for(int k=0; k<size; k++){
				translated_grid[i][j][k].x = v[0] + grid[i][j][k].x;
				translated_grid[i][j][k].y = v[1] + grid[i][j][k].y;
				translated_grid[i][j][k].z = v[2] + grid[i][j][k].z;
                                printf("(%f, %f, %f)", translated_grid[i][j][k].x, translated_grid[i][j][k].y, translated_grid[i][j][k].z);
                        printf("\n");
                        }
                printf("\n");
                }
        }
}


int main(){

	int size;
	printf("enter size");	
	scanf("%d", &size);
	
	Point grid[size][size][size];
	gen_grid(size, grid);
	
	int scale;
	//printf("enter scale");
	//scanf("%d", &scale);
	Point scaled_grid[size][size][size];

	int theta;
	//printf("enter theta");
	//scanf("%d", &theta);

	Point rotated_grid[size][size][size];
	
	int v1;
	int v2;
	int v3;
	
	scanf("%d %d %d", &v1, &v2, &v3);
	Point translated_grid[size][size][size];	
		
	int t1;
        int t2;
        int t3;

	printf("input positions t1 t2 t3");
	scanf("%d %d %d", &t1, &t2, &t3);
	
	//set_matrix(theta);
	//scale_grid(size, scale, grid, scaled_grid);
	//rotate_x(size, theta, grid, rotated_grid);
	
	set_t(t1, t2, t3);
	set_transformer(t1, t2, t3);

	transform_vector(v1, v2, v3);
	//translate_vector(t1, t2, t3
	//translate(size, grid, translated_grid);
	return(0);
}
