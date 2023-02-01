#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

int dt0(int t, double p, double h, int s, int w);

char dt1a(float pl, float pw, float sl, float sw);
char dt1b(float pl, float pw, float sl, float sw);

double dt2a(double x1, double x2, double x3, int x4, int x5);
double dt2b(double x1, double x2, double x3, int x4, int x5);

double dt3a(int b1, double r1, double r2, int c1, int c2);
double dt3b(int b1, double r1, double r2, int c1, int c2);

#endif /* _UTIL_H_ */
