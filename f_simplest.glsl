#version 330

uniform sampler2D tex;

out vec4 pixelColor; //Zmienna wyjsciowa fragment shadera. Zapisuje sie do niej ostateczny (prawie) kolor piksela

in vec4 n;
in vec4 l1;
in vec4 l2;
in vec4 l3;
in vec4 v;
in vec2 iTexCoord0;

void main(void) {

    // Znormalizowane interpolowane wektory
    vec4 ml1 = normalize(l1);
    vec4 ml2 = normalize(l2);
    vec4 ml3 = normalize(l3);
    vec4 mn = normalize(n);
    vec4 mv = normalize(v);

    // Wektory odbite
    vec4 mr1 = reflect(-ml1, mn);
    vec4 mr2 = reflect(-ml2, mn);
    vec4 mr3 = reflect(-ml3, mn);

    // Parametry powierzchni
    vec4 kd = texture(tex, iTexCoord0);

    // Obliczenie modelu oœwietlenia dla pierwszego Ÿród³a œwiat³a
    float nl1 = clamp(dot(mn, ml1), 0, 1);
    float rv1 = pow(clamp(dot(mr1, mv), 0, 1), 25);

    // Obliczenie modelu oœwietlenia dla drugiego Ÿród³a œwiat³a
    float nl2 = clamp(dot(mn, ml2), 0, 1);
    float rv2 = pow(clamp(dot(mr2, mv), 0, 1), 25);

    float nl3 = clamp(dot(mn, ml3), 0, 1);
    float rv3 = pow(clamp(dot(mr3, mv), 0, 1), 25);

    // £¹czenie oœwietlenia z obu Ÿróde³
    vec3 diffuse = (kd.rgb * (nl1 + nl2 + nl3) )/ 2;
    // Tu mo¿na dodaæ równie¿ spekularne oœwietlenie, jeœli jest potrzebne
    pixelColor = vec4(diffuse, kd.a);
}