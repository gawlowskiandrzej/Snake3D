#ifndef MYFLOOR_H
#define MYFLOOR_H

int myFloorVertexCount = 6;

float myFloorVertices[] = {
	//�ciana 1
	1.0f,-1.0f,-1.0f,1.0f,
	-1.0f, 1.0f,-1.0f,1.0f,
	-1.0f,-1.0f,-1.0f,1.0f,

	1.0f,-1.0f,-1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,
	-1.0f, 1.0f,-1.0f,1.0f,

	////�ciana 2
	//-1.0f,-1.0f, 1.0f,1.0f,
	//1.0f, 1.0f, 1.0f,1.0f,
	//1.0f,-1.0f, 1.0f,1.0f,

	//-1.0f,-1.0f, 1.0f,1.0f,
	//-1.0f, 1.0f, 1.0f,1.0f,
	//1.0f, 1.0f, 1.0f,1.0f,


	////�ciana 3
	//-1.0f,-1.0f,-1.0f,1.0f,
	//1.0f,-1.0f, 1.0f,1.0f,
	//1.0f,-1.0f,-1.0f,1.0f,

	//-1.0f,-1.0f,-1.0f,1.0f,
	//-1.0f,-1.0f, 1.0f,1.0f,
	//1.0f,-1.0f, 1.0f,1.0f,

	////�ciana 4
	//-1.0f, 1.0f, 1.0f,1.0f,
	//1.0f, 1.0f,-1.0f,1.0f,
	//1.0f, 1.0f, 1.0f,1.0f,

	//-1.0f, 1.0f, 1.0f,1.0f,
	//-1.0f, 1.0f,-1.0f,1.0f,
	//1.0f, 1.0f,-1.0f,1.0f,

	////�ciana 5
	//-1.0f,-1.0f,-1.0f,1.0f,
	//-1.0f, 1.0f, 1.0f,1.0f,
	//-1.0f,-1.0f, 1.0f,1.0f,

	//-1.0f,-1.0f,-1.0f,1.0f,
	//-1.0f, 1.0f,-1.0f,1.0f,
	//-1.0f, 1.0f, 1.0f,1.0f,

	////�ciana 6
	//1.0f,-1.0f, 1.0f,1.0f,
	//1.0f, 1.0f,-1.0f,1.0f,
	//1.0f,-1.0f,-1.0f,1.0f,

	//1.0f,-1.0f, 1.0f,1.0f,
	//1.0f, 1.0f, 1.0f,1.0f,
	//1.0f, 1.0f,-1.0f,1.0f,
};


float myFloorNormals[] = {
	//�ciana 1
	0.0f, 0.0f,-1.0f,0.0f,
	0.0f, 0.0f,-1.0f,0.0f,
	0.0f, 0.0f,-1.0f,0.0f,

	0.0f, 0.0f,-1.0f,0.0f,
	0.0f, 0.0f,-1.0f,0.0f,
	0.0f, 0.0f,-1.0f,0.0f,

};

float myFloorVertexNormals[] = {
	//�ciana 1
	1.0f,-1.0f,-1.0f,0.0f,
	-1.0f, 1.0f,-1.0f,0.0f,
	-1.0f,-1.0f,-1.0f,0.0f,

	1.0f,-1.0f,-1.0f,0.0f,
	1.0f, 1.0f,-1.0f,0.0f,
	-1.0f, 1.0f,-1.0f,0.0f,

};

float myFloorTexCoords[] = {
	//�ciana 1
	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,
};


#endif // MYFLOOR_H_INCLUDED



