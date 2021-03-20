// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main(void)
// {
//   srand((unsigned int)time(NULL));
//   int n[6] = {0};
//   //int* p = n;
// //값 입력받기
//   for(int i =0; i<6;i++)
//   {
//     n[i] = rand() % 45 + 1;
//   }
// //같은 값 걸러내기
//   // for(int i =0;i<6;i++){
//   //   for(int j = 0;j<6;j++){
//   //     if(i==j){j++;}
//   //       while(1){
//   //         if(n[i] == n[j]){
//   //         n[j] = rand() % 8 + 1;}
//   //         if(n[i] != n[j])j++;
//   //         if(i==j)j++;
//   //         if(j == 6)break;
//   //         else continue;
//   //       }
//   //     }
//   //   }

// //같은 값 걸러내기2
// for(int i = 0; i<6;i++)
// {
//   for(int j = 0; j<6;j++)
//   {
//     if(i==j)j++;
//     while(1)
//     {
//       if(n[i] == n[j]){
//           n[j] = rand() % 45 + 1;}
//       if(n[i] != n[j])break;
//     }
//   }
// }
// //sorting
//   for(int i =0;i<6;i++){
//     for(int j = i+1;j<6;j++){
//       if(n[i]>n[j]){
//         int temp = n[i];
//         n[i] = n[j];
//         n[j] = temp;
//       }
//     }
//   }
// //출력
//   for(int i =0; i<6;i++){
//     printf("%d ",n[i]);
//   }
// }