#include <stdio.h>
#include <stdlib.h>

typedef struct HefniArrayImplementation {
  int size;
  int capacity;
  int *data;

} Harray;

Harray *array_new(int capacity);
int array_get(Harray *arr, int i);
int array_size(Harray *arr);
void array_push(Harray *arr, int val);
void array_set(Harray *arr, int i, int val);
void array_free(Harray *arr);
void array_print(Harray *arr, int all);

int main() {
  Harray *arr = array_new(2);
  array_push(arr, 21);
  array_push(arr, 22);
  array_push(arr, 23);
  array_print(arr, 1);
  array_push(arr, 24);
  array_push(arr, 25);
  array_print(arr, 1);
  for(int i =0; i < 1000000000; i++)
  {
    array_push(arr, i);
  }
  array_print(arr, 0);
  array_free(arr);

}
Harray *array_new(int capacity) {
  Harray *arr = malloc(sizeof(Harray));
  arr->capacity = capacity;
  arr->size = 0;
  arr->data = (int *)malloc(arr->capacity * sizeof(int));
  return arr;
}

void array_push(Harray *arr, int val) {
  if (arr->size == arr->capacity) {
    int new_capacity = 2 * arr->capacity;
    arr->data = (int *)realloc(arr->data, sizeof(int) * new_capacity);
    arr->capacity = new_capacity;
  }
  arr->data[arr->size] = val;
  arr->size++;
}

int array_get(Harray *arr, int i) {
  if (i < 0 || i >= arr->capacity) {
    printf("Error: index out of range \n");
    return 0;
  }
  return arr->data[i];
}

void array_set(Harray *arr, int i, int val) {
  if (i < 0 || i >= arr->capacity) {
    printf("Error: index out of range \n");
  }
  arr->data[i] = val;
}

int array_size(Harray *arr) { return arr->size; }

void array_free(Harray *arr) {
  free(arr->data);
  free(arr);
}


void array_print(Harray *arr, int all)
{
  printf("\n========================= Array Print =========================\n");
  printf("Array Size: %d\n", arr->size);
  printf("Array Capacity: %d\n", arr->capacity);
  if(all)
  {
    printf("Array Data: ");
    for(int i =0; i < arr->size; i++)
    {
      printf(" %d", arr->data[i]);
    }
    printf("\n");
  }
}
