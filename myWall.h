#ifndef MYWALL_H
#define MYWALL_H

int myWallVertexCount = 24;

float myWallVertices[] = {
	

	//�ciana 2
	/*-1.0f,-1.0f, 1.0f,1.0f,
	1.0f, 1.0f, 1.0f,1.0f,
	1.0f,-1.0f, 1.0f,1.0f,

	-1.0f,-1.0f, 1.0f,1.0f,
	-1.0f, 1.0f, 1.0f,1.0f,
	1.0f, 1.0f, 1.0f,1.0f,*/


	//�ciana 3
	-1.0f,-1.0f,-1.0f,1.0f,
	1.0f,-1.0f, 1.0f,1.0f,
	1.0f,-1.0f,-1.0f,1.0f,

	-1.0f,-1.0f,-1.0f,1.0f,
	-1.0f,-1.0f, 1.0f,1.0f,
	1.0f,-1.0f, 1.0f,1.0f,

	//�ciana 4
	-1.0f, 1.0f, 1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,
	1.0f, 1.0f, 1.0f,1.0f,

	-1.0f, 1.0f, 1.0f,1.0f,
	-1.0f, 1.0f,-1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,

	//�ciana 5
	-1.0f,-1.0f,-1.0f,1.0f,
	-1.0f, 1.0f, 1.0f,1.0f,
	-1.0f,-1.0f, 1.0f,1.0f,

	-1.0f,-1.0f,-1.0f,1.0f,
	-1.0f, 1.0f,-1.0f,1.0f,
	-1.0f, 1.0f, 1.0f,1.0f,

	//�ciana 6
	1.0f,-1.0f, 1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,
	1.0f,-1.0f,-1.0f,1.0f,

	1.0f,-1.0f, 1.0f,1.0f,
	1.0f, 1.0f, 1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,




};

float myWallNormals[] = {
	////�ciana 2
	//0.0f, 0.0f, 1.0f,0.0f,
	//0.0f, 0.0f, 1.0f,0.0f,
	//0.0f, 0.0f, 1.0f,0.0f,

	//0.0f, 0.0f, 1.0f,0.0f,
	//0.0f, 0.0f, 1.0f,0.0f,
	//0.0f, 0.0f, 1.0f,0.0f,

	//�ciana 3
	0.0f,1.0f, 0.0f,0.0f,
	0.0f,1.0f, 0.0f,0.0f,
	0.0f,1.0f, 0.0f,0.0f,

	0.0f,1.0f, 0.0f,0.0f,
	0.0f,1.0f, 0.0f,0.0f,
	0.0f,1.0f, 0.0f,0.0f,

	//�ciana 4
	0.0f, -1.0f, 0.0f,0.0f,
	0.0f, -1.0f, 0.0f,0.0f,
	0.0f, -1.0f, 0.0f,0.0f,

	0.0f, -1.0f, 0.0f,0.0f,
	0.0f, -1.0f, 0.0f,0.0f,
	0.0f, -1.0f, 0.0f,0.0f,

	//�ciana 5
	1.0f, 0.0f, 0.0f,0.0f,
	1.0f, 0.0f, 0.0f,0.0f,
	1.0f, 0.0f, 0.0f,0.0f,

	1.0f, 0.0f, 0.0f,0.0f,
	1.0f, 0.0f, 0.0f,0.0f,
	1.0f, 0.0f, 0.0f,0.0f,

	//�ciana 6
	-1.0f, 0.0f, 0.0f,0.0f,
	-1.0f, 0.0f, 0.0f,0.0f,
	-1.0f, 0.0f, 0.0f,0.0f,

	-1.0f, 0.0f, 0.0f,0.0f,
	-1.0f, 0.0f, 0.0f,0.0f,
	-1.0f, 0.0f, 0.0f,0.0f,


};

float myWallTexCoords[] = {
	//�ciana 1


	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,
};

#endif

