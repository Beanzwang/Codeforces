#include<stdio.h>
#include<math.h>

int main() {
    double n, m, a;
    double h, w;
    // three inputs.
    scanf("%lf %lf %lf", &n, &m, &a);
    printf("%.0lf", ceil(n/a) * ceil(m/a));

    return 0;
}