#include <stdio.h>
#include <stdbool.h>


bool segmentCode[10][7] = {
 //  a  b  c  d  e  f  g  .
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1},  // 9
};

static void print_two_segs(bool seg_a, bool seg_b, int horizontal_len, int vertical_len) {
  if(!seg_a && !seg_b) return;
  for(int i = 0; i < vertical_len; i++) {
    seg_b && printf("**");
    for (int j = 0 ; j <= horizontal_len; j++) {
      (seg_a || seg_b) &&  printf(" ");
    }
        
    seg_a && printf("**");
    (seg_a || seg_b) && printf("\n");
  }

}

static void print_one_seg(bool seg, int horizontal_len) {
  if(!seg) return;
  printf("  ");
  for(int i = 0; i < horizontal_len; i++){
    printf("*");
  }
  printf("  ");
  printf("\n");
  printf("  ");
  for(int i = 0; i < horizontal_len; i++){
    printf("*");
  }
  printf("  ");
  printf("\n");

}



static void print_seven_segment(int i, int horizontal_len, int vertical_len) { 
  print_one_seg(segmentCode[i][0], horizontal_len);
  print_two_segs(segmentCode[i][1], segmentCode[i][5],horizontal_len ,vertical_len);
  print_one_seg(segmentCode[i][6], horizontal_len);
  print_two_segs(segmentCode[i][2], segmentCode[i][3],horizontal_len, vertical_len);
  print_one_seg(segmentCode[i][4], horizontal_len);
}

int main() {
  int horizontal;
  int vertical;
  printf("This is a 7-segment display! Press \"Enter\" after providing any number in keyboard.\n");
  bool hasError = false;
  do {
      if(hasError) {
        printf("The length is not acceptable.\n");
      }
      printf("Please enter the length of horizontal segments (from 3 to 40): ");
      bool input = scanf("%d", &horizontal); 
      hasError = ((horizontal < 3) || (horizontal > 40)) && (input);
  } while(hasError);
  
  do {
      if(hasError) {
        printf("The length is not acceptable.\n");
      }
      printf("Now, enter the length of vertical segments (from 3 to 40): ");
      bool input = scanf("%d", &vertical); 
      hasError = ((vertical < 3) || (vertical > 40) || (vertical > 2 * horizontal) || (vertical < horizontal / 2)) && (input);
  } while(hasError);
  int integer;

  while(true) {
    do {
      if(hasError) {
        printf("Error: invalid input.\n");
      }
      printf("Enter a positive integer (from 0 to 9): ");
      bool input = scanf("%d", &integer); 
      hasError = (integer < 0 || integer > 9) && (input);
    } while(hasError);
    print_seven_segment(integer, horizontal, vertical);
  }
  
  
  return 0;
}
