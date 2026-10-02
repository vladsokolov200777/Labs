#include <stdio.h>
#include <math.h>

int main() {
    float hx = 0.6, hy = 0.7;
    float x0 = 0.1, x1 = 1.0;
    float y0 = 1.0, y1 = 2.0;

    for (float x = x0; x <= x1; x += hx) {
        for (float y = y0; y <= y1; y += hy) {
            printf("x = %f; y = %f; ", x, y);
            if (x + y <= 2.0) {
                float v1 = pow(sin(x), y);
                float v2 = pow(y + x, 1.0/3.0);
                if (v1 > v2) {
                    printf("V = %f\n", v1);
                } else {
                    printf("V = %f\n", v2);
                }
            } else {
                printf("V = %f\n", x*x + y*y);
            }
        }
    }
    return 0;
}
