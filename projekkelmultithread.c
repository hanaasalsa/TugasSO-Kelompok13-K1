#include<stdio.h>
#include<pthread.h>

int arr[100];
int temp, i, n, sum;
float average;

void *avg(){
  sum = 0;
  
  //Menghitung nilai rata-rata
  for(i=0; i<n; i++){
    sum = sum + arr[i];
  }
  average = sum / n;
  
  printf("The average value is %.0f\n", average);
}

void *min(){
  temp = arr[0];
  
  // Menghitung nilai minimum
  for(i=1; i<n; i++){
    if(temp > arr[i]){
      temp = arr[i];
    }
  }
  
  printf("The minimum value is %d\n", temp);
}

void *max(){
  temp = arr[0];
  
  // Menghitung nilai maksimum
  for(i=1; i<n; i++){
    if(temp < arr[i]){
      temp = arr[i];
    }
  }
  
  printf("The maximum value is %d\n", temp);
}

int main(){
  // Input banyaknya bilangan
  printf("Enter your number : ");
  scanf("%d", &n);
  
  // Memasukkan bilangan yang akan dihitung ke dalam arr[]
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  pthread_t t1, t2, t3;
  
  pthread_create(&t1, NULL, avg, NULL);
  pthread_join(t1, NULL);
  
  pthread_create(&t2, NULL, min, NULL);
  pthread_join(t2, NULL);
  
  pthread_create(&t3, NULL, max, NULL);
  pthread_join(t3, NULL);
  
  return 0;
} 
