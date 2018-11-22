/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION 2.2.1 GCC V0.8
* LISTEP.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __LPOINT__
#define __LPOINT__


typedef struct EPOINT EPOINT; 

struct EPOINT {
  double x;
  double y;
  struct EPOINT * next;
};

typedef EPOINT * PLISTE;

#endif
