// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main(void)
// {
// srand((unsigned int) time(NULL));
// //로또 6개의 각기 숫자
// int num = 0;

//   while(1)
//   {
//     int x = rand() % 45 + 1;
//     int y = rand() % 45 + 1;
//     if(y != x)
//     {
//       printf("%d ", x);
//       num++;
//     }  
//     else if( y == x) continue;
    
//     if(num == 6) break;
//   }
//   printf("\n");
//   return 0;
// }