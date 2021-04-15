#include <stdio.h>
#include <string.h>

struct worker
{
    char name[100];
    int minutes;
    float hours;
    float hw;
    float finalpay;
};
typedef struct worker work;

work input_one()
{
    work wo;
    scanf("%s %f", &wo.name, &wo.hw);

    return wo;
}

int find_index(int n, work wi[n], char name[])
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(name, wi[i].name))
            return i;
    }

    return 0;
}

void input_n(int n, work winp[n])
{
    for (int i = 0; i < n; i++)
        winp[i] = input_one();
}

void input_timecards(int n, work wcard[n])
{
    int x, min, index;
    char name[100];

    scanf("%d", &x);

    for (int i = 0; i < x; i++)
    {
        scanf("%s", &name);
        index = find_index(n, wcard, name);
        scanf("%d", &min);
        wcard[index].minutes += min;
    }
}

float compute_hours(float minutes)
{
    return minutes/60;
}

void compute_one(work *wcomp)
{
    wcomp->hours = compute_hours(wcomp->minutes);

    if (wcomp->hours <= 40.00)
        wcomp->finalpay = wcomp->hw * wcomp->hours;
    else
        wcomp->finalpay = (wcomp->hw * 40.00) + (1.5 * (wcomp->hw * (wcomp->hours - 40.00)));
}

void compute_n(int n, work wc[n])
{
    for (int i = 0; i < n; i++)
        compute_one(&wc[i]);
}

void output_one_work(work wd)
{
    printf("%s: %.2f hours, $%.2f\n", wd.name, wd.hours, wd.finalpay);
}

void output_n_works(int n, work wdn[n])
{
    for (int i = 0; i < n; i++)
        output_one_work(wdn[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    work wm[n];
    input_n(n, wm);
    input_timecards(n, wm);
    compute_n(n, wm);
    output_n_works(n, wm);

    return 0;
}
