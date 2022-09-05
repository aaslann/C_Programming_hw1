#include <stdio.h>
#define line_num 4
int main() {

  double coorx, coory, sumx, sumy, sum2x, sum2y, coor2x, coor2y, avgx, avgy, avg2x, avg2y,x, y;
  float connecting_line, slope, midpoint_x, midpoint_y;
  for (int i = 0; i < line_num / 2; i++) {      
    scanf("%lf %lf", & coorx, & coory);     
    sumx += coorx;                                 //the entered x and y values are summed up
    sumy += coory;
  }
  avgx = sumx / (line_num / 2.0);                 //the average of values for class1 are calculated 
  avgy = sumy / (line_num / 2.0); 
  for (int j = line_num / 2; j < line_num; j++) {
    scanf("%lf %lf", & coor2x, & coor2y);             //the entered x and y values are summed up
    sum2x += coor2x;
    sum2y += coor2y;
  }
  avg2x = sum2x / (line_num / 2.0);
  avg2y = sum2y / (line_num / 2.0);      //the average of values for class2 are calculated

  midpoint_x = (avg2x + avgx) / 2;
  midpoint_y = (avg2y + avgy) / 2;		      // slope and midpoints are calculated 
  slope = ((avg2y - avgy) / (avg2x - avgx));
  if ((avg2x - avgx)==0)
  {
  	avg2x += 0.0001+avgx;
  }
  if (slope==0)                           // 0.0001 added to avoid indefinition  
  {
  	slope += 0.0001;
  }

  while(scanf("%lf %lf", & x, & y) != 0) {  //User enters something not expected program quits

      if (avg2y > avgy) {
      if ((-1 / slope) * (x - midpoint_x) < (y - midpoint_y)) {

        printf("class 2\n");
      } else if ((-1 / slope) * (x - midpoint_x) > (y - midpoint_y)) {
        printf("class 1\n");
      } else
        continue;              //testpoints are used to classify whether they are class1 or class2	 

    } else {
      if ((-1 / slope) * (x - midpoint_x) < (y - midpoint_y)) {
        printf("class 1\n");

      } else if ((-1 / slope) * (x - midpoint_x) > (y - midpoint_y)) {

        printf("class 2\n");
      } else
        continue;

    }

  }

  return 0;
}