#include<stdio.h>
#include<math.h>
#define max 10
typedef struct rectangle
{
    float coordinates[6];
    float sides[3];
    float area;
} rect;

int input(int n, rect r[])
{
    int i, j;
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 6; j++){
            scanf ("%f", &r[i].coordinates[j]);
        }
    }
    return n;
}
float find_max (float a, float b, float c)
{
    float m;
    if (a >= b && a>=c)
        m=a;

    if (b>=a && b>=c)
        m=b;

    if (c>=a && c>=b)
        m=c;

    return m;
}

float compute (rect rs)
{
    rs.sides[0] =sqrt (pow (rs.coordinates[2] - rs.coordinates[0], 2) + pow (rs.coordinates[3] - rs.coordinates[1], 2));
    rs.sides[1] =sqrt (pow (rs.coordinates[5] - rs.coordinates[3], 2) + pow (rs.coordinates[4] - rs.coordinates[2], 2));
    rs.sides[2] =sqrt (pow (rs.coordinates[4] - rs.coordinates[0], 2) + pow (rs.coordinates[5] - rs.coordinates[1], 2));
    if (rs.sides[0] == find_max (rs.sides[0], rs.sides[1], rs.sides[2]))
    rs.area = rs.sides[1] * rs.sides[2];
    else if (rs.sides[1] == find_max (rs.sides[0], rs.sides[1], rs.sides[2]))
    rs.area = rs.sides[0] * rs.sides[2];
    else if (rs.sides[2] == find_max (rs.sides[0], rs.sides[1], rs.sides[2]))
    rs.area = rs.sides[0] * rs.sides[1];
    return rs.area;
}
void output (rect ro)
{
     printf("Area of rectangle with vertices (%.1f,%.1f), (%.1f,%.1f), (%.1f,%.1f) is %.2f\n",
     ro.coordinates[0], ro.coordinates[1], ro.coordinates[2], ro.coordinates[3], ro.coordinates[4],
     ro.coordinates[5], ro.area);
}

int main ()
{
    int n, i;
    rect rm[max];
    n = input(n, rm);
    for (i = 0; i < n; i++)
    {
        rm[i].area = compute (rm[i]);
        output(rm[i]);
    }
    return 0;
}
