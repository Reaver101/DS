#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
// Define the structure for a hash table
struct HashTable
{
  int keys[SIZE];
  int occupied[SIZE];
};

//Funtion to initialize the hash table
void initialize(struct HashTable*table)
{
  for(int i=0; i< SIZE; i++)
  {
    table->keys[i] = -1;//-1 indicates an empty slot
    table->occupied[i]=0;// 0 indicates the slot is unoccupied
  }
}
//Hash function to calculate the index
int hash(int key){
  return key % SIZE;
}
//Function to insert a key value pair into the hash table
void insert(struct HashTable *table, int key){
  int index = hash(key);
  while(table->occupied[index]){
    printf("Collision Occured\n");
    index= (index +1)% SIZE;
  }
  table->keys[index]=key;
  table->occupied[index]=1;
  printf("Inserted value: %d, at index: %d\n",key,index);

}
int main()
{
  struct HashTable table;
  initialize(&table);
  //insert key pairs
  insert(&table, 10);
  insert(&table,22);
  insert(&table,34);
  insert(&table,45);
  insert(&table,20);
    return 0;
}