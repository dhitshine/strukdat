/*
 Source: Kalicharan, Advanced Topics in C, p.48 no.8
 */

#include <stdio.h>

typedef struct {
  int hour, minute;
} Time;

int diff(Time t1, Time t2) {
  int t1mnt = 60 * t1.hour + t1.minute;
  int t2mnt = 60 * t2.hour + t2.minute;
  if(t2mnt < t1mnt) {
    return 1440 + t2mnt - t1mnt;
  }
  return t2mnt - t1mnt;
}

int main() {
  Time t1 = {23, 50};
  Time t2 = {0, 10};
  int res = diff(t1, t2);
  printf("%d", res);
  return 0;
}

