#include <stdio.h>
#include <math.h>

int main() {
    float x = 0.1, hx = 0.6;
    float y = 1.0, hy = 0.7;

    for (float i = x; i <= 1.0; i += hx) {
        for (float j = y; j <= 2.0; j += hy) {
            
            double V;
            
            if ((i + j) <= 2.0) {
                double v1 = pow(fabs(sin(i)), j);
                double v2 = pow(j + i, 1.0 / 5.0);
                V = fmax(v1, v2);
            } else {
                V = (i * i) + (j * j);
            }
            
            printf("x = %.2f, y = %.2f, V = %.4f\n", i, j, V);
        }
    }

    return 0;
}
