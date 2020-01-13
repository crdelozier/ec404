#include <stdio.h>
#include <string.h>

struct midn{
  int alpha;
  char *name;
};

#define MAP_SIZE 31

int key_to_index(struct midn *mid){
    int index = mid->alpha; // (*mid).alpha;
    for(int c = 0; c < strlen(mid->name); c++){
        index += (int)mid->name[c];
    }
    return index % MAP_SIZE;
}

int grades[MAP_SIZE];

int main(){
    struct midn phil;
    phil.alpha = 215766;
    phil.name = "Phil";
    
    struct midn kira;
    kira.alpha = 213948;
    kira.name = "Kira";
    
    grades[key_to_index(&phil)] = 99;
    grades[key_to_index(&kira)] = 99;
    
    printf("%d,%d\n",grades[key_to_index(&phil)],grades[key_to_index(&kira)]);
    
    char bitmap[4];
    bitmap[0] = bitmap[0] | (1 << 7);  // Sets 7th bit
    
    if(bitmap[0] & (1 << 7)){ // if 7th bit is set
        printf("Bit is set\n");
    }else{
        printf("Bit is not set\n");
    }
    
    bitmap[0] = bitmap[0] & ~(1 << 7); // Clears 7th bit
    
    if(bitmap[0] & (1 << 7)){ // if 7th bit is set
        printf("Bit is set\n");
    }else{
        printf("Bit is not set\n");
    }
    
    return 0;
}
