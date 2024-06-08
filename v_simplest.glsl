#version 330

//Zmienne jednorodne
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;

//Atrybuty
in vec4 vertex; //wspolrzedne wierzcholka w przestrzeni modelu
in vec4 normal; //wektor normalny w przestrzeni modelu
in vec2 texCoord;

//Zmienne interpolowane
out vec4 l1;
out vec4 l2;
out vec4 l3;
out vec4 n;
out vec4 v;
out vec2 iTexCoord0;

void main(void) {
    vec4 lp1 = vec4(0, 0, -20, 20); // pierwsze źródło światła
    vec4 lp2 = vec4(2.8, -2.8, -2, 1f);  // drugie źródło światła
    vec4 lp3 = vec4(-2.8, 2.8, -2, 1f);  // drugie źródło światła

    l1 = normalize(lp1 - M * vertex); // wektor do pierwszego światła w przestrzeni oka
    l2 = normalize(lp2 - M * vertex); // wektor do drugiego światła w przestrzeni oka
    l3 = normalize(lp3 - M * vertex); // wektor do drugiego światła w przestrzeni oka

    n = normalize(M * normal); // wektor normalny w przestrzeni oka
    iTexCoord0 = texCoord;

    gl_Position = P * V * M * vertex;
}
