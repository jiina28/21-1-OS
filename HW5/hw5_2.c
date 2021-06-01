#include <stdio.h>
#include <malloc.h>

typedef struct {
	int dim;
	float *data;
} DynamicVector;

// define a new type 'Vector' by aliasing DynamicVector
typedef DynamicVector Vector;


DynamicVector* AllocVector(int dim);
void DeleteVector(DynamicVector *vec);

void FillVector(Vector *vec, int dim, int dir);

float GetVectorData(Vector *vec, int idx);
void SetVectorData(Vector *vec, int idx, float v);

void DisplayVector(Vector *vec);

float DotProduct(Vector *vec1, Vector *vec2);


int main()
{
	Vector *vec1 = AllocVector(10);
	Vector *vec2 = AllocVector(10);

	FillVector(vec1, 10, 0);
	printf("vec1 = ");
	DisplayVector(vec1);

	FillVector(vec2, 10, 1);
	printf("vec2 = ");
	DisplayVector(vec2);

	printf("DotProduct(vec1, vec2) = %f\n", DotProduct(vec1, vec2));

	DeleteVector(vec1);
	DeleteVector(vec2);

	return 0;
}

DynamicVector* AllocVector(int dim)
{
	DynamicVector *vec = NULL;

	vec = (DynamicVector*)malloc(sizeof(DynamicVector));
	if(vec==NULL) {
		printf("malloc error\n");
		return NULL;
	}
	vec->data = (float*)malloc(dim*sizeof(float));
	if(vec->data == NULL) {
		printf("malloc error\n");
		free(vec);
		return NULL;
	}
	vec->dim = dim;
	return vec;
}

void DeleteVector(DynamicVector *vec)
{
	if(vec == NULL)
		return;

	free(vec->data);
	free(vec);
}

void FillVector(Vector *vec, int dim, int dir)
{
	vec->dim = dim;

	for(int i=0;i<vec->dim;i++) {
		if(dir==0)
			vec->data[i] = i+1.0;
		else
			vec->data[i] = vec->dim-i;
	}
}

float GetVectorData(Vector *vec, int idx)
{
	return vec->data[idx];
}

void SetVectorData(Vector *vec, int idx, float v)
{
	vec->data[idx] = v;
}

float DotProduct(Vector *vec1, Vector *vec2)
{
	if(vec1->dim != vec2->dim){
		printf("Error! vec1->dim = %d, vec2->dim = %d\n", vec1->dim, vec2->dim);
		return 0.F;
	}

	float dot = 0.F;
	for(int i=0;i<vec1->dim;i++)
		dot += vec1->data[i] * vec2->data[i];
	return dot;
}

void DisplayVector(Vector *vec)
{
	for(int i = 0; i < vec->dim; i++)
		printf("%.3f ", vec->data[i]);

	printf("(dim = %d)\n", vec->dim);
}

