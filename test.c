#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE_NAME 50

typedef struct creepAttri{
  int isBuffed;
  int isGone;
} CreepAttri;

typedef struct creep{
  char name[SIZE_NAME];
  float health;
  float damage;
  int isRanged;
  int isDouble;
  CreepAttri creepAttri;
  int respawnTime;
} Creep;

typedef struct {
  Creep *redBuff;
  Creep *blueBuff;
  Creep *blueBuffGreenCamp;
  Creep *redBuffGreenCamp1;
  Creep *redBuffGreenCamp2;
  Creep *expCrab;
  Creep *goldCrab;
  Creep *litho;
} Jungle;

typedef struct hero {
  char name[SIZE_NAME];
  float health;
  float damage;
  float isRanged;
} Hero;

typedef struct itemAttri{
  int isMagic;
  int isPhysical;
  int isTrue;
  int isOneTime;
  int hasCoolDown;
} ItemAttri;

typedef struct item {
  char name[SIZE_NAME * 2];
  float damageCanDeal;
  int cooldown;
  ItemAttri itemAttri;
} Item;

typedef struct {
  Item *WarAxe;
  Item *clawsOfEte;
  Item *swordOfTheSevenSeas;
  Item *bowTheIrregular;
  Item *divineAegis;
} Items;

void createItemWithDamageAndCooldown(Item **newItem, char *name, float damageCanDeal, int cooldown, int isPhysical, int isTrue, int isOneTime, int hasCoolDown){
  
}

void createItemWithDamage(Item **newItem, char *name, float damageCanDeal) {}

void createCreep(Creep **newCreep, char *name, float health, float damage, int isRanged, int isDouble, int isBuffed, int isGone, int respawnTime){
  *newCreep = (Creep *) malloc(sizeof(Creep));

  if (*newCreep != NULL){
    strcpy((*newCreep)->name, name);
    (*newCreep)->health = health;
    (*newCreep)->damage = damage;
    (*newCreep)->isRanged = isRanged;
    (*newCreep)->isDouble = isDouble;
    (*newCreep)->creepAttri.isBuffed = isBuffed;
    (*newCreep)->creepAttri.isGone = isGone;
    (*newCreep)->respawnTime = respawnTime;
  }else{
    printf("Something bad happened!\n");
    return;
  }
}

void printCreep(const Creep *creep){
  printf("Creep name: %s\n", creep->name);
  printf("Creep health: %f\n", creep->health);
  printf("Creep damage: %f\n", creep->damage);
  printf("Creep isRanged: %d\n", creep->isRanged);
  printf("Creep isDouble: %d\n", creep->isDouble);
  printf("Creep isBuffed: %d\n", creep->creepAttri.isBuffed);
  printf("Creep isGone: %d\n", creep->creepAttri.isGone);
  printf("Creep respawnTime: %d\n", creep->respawnTime);
  printf("\n");
}

void printCreepsData(const Jungle *jungle){
  if(jungle == NULL) return;
  
  //Red Buff Area
  printf("Red Buff Area:\n");
  printCreep(jungle->redBuff);
  printCreep(jungle->redBuffGreenCamp1);
  printCreep(jungle->redBuffGreenCamp2);

  printf("Blue Buff Area:\n");
  //Blue Buff Area
  printCreep(jungle->blueBuff);
  printCreep(jungle->blueBuffGreenCamp);
  
  printf("Jungle Area:\n");
  //Lithowanderer
  printCreep(jungle->litho);
  //Gold Crab
  printCreep(jungle->goldCrab);
  //EXP Crab
  printCreep(jungle->expCrab);
}

void freeCreep(Creep **creep){
  if(creep != NULL && *creep != NULL){
    free(*creep);
    *creep = NULL;
  }
}

void createCreeps(Jungle *jungle){
  // void createCreep(Creep **newCreep, char *name, float health, float damage, int isRanged, int isDouble, int isBuffed, int isGone, int respawnTime){...}

  //Red Buff Area
  createCreep(&(jungle->redBuff), "Red Buff", 150000.00, 150.00, 0, 0, 0, 1, 1500);
  createCreep(&(jungle->redBuffGreenCamp1), "Golem", 120000.00, 100.00, 0, 0, 0, 0, 500);
  createCreep(&(jungle->redBuffGreenCamp2), "Spider", 120000.00, 120.00, 0, 1, 0, 0, 500);

  //Blue Buff Area
  createCreep(&(jungle->blueBuff), "Blue Buff", 150000.00, 125.00, 0, 1, 0, 1, 1500);
  createCreep(&(jungle->blueBuffGreenCamp), "Lizzard", 120000.00, 130.00, 1, 0, 1, 0, 500);

  //Jungle Area
  createCreep(&(jungle->litho), "Lithowanderer", 1500.00, 0.0, 0, 0, 0, 0, 60000);
  //Gold Area 
  createCreep(&(jungle->goldCrab), "Gold Crab", 1500.00, 100.00, 0, 0, 0, 0, 2000);
  //EXP Area
  createCreep(&(jungle->expCrab), "EXP Crab", 1500.00, 100.00, 0, 0, 0, 0, 2000);
}

void freeCreeps(Jungle *jungle){
  if(jungle == NULL) return;

  //void freeCreep(Jungle *jungle) {...}

  //Red Buff Area
  freeCreep(&(jungle->redBuff));
  freeCreep(&(jungle->redBuffGreenCamp1));
  freeCreep(&(jungle->redBuffGreenCamp2));
  
  //Blue Buff Area
  freeCreep(&(jungle->blueBuff));
  freeCreep(&(jungle->blueBuffGreenCamp));
  
  //Jungle Area
  freeCreep(&(jungle->litho));
  //Gold Area
  freeCreep(&(jungle->goldCrab));
  //EXP Area
  freeCreep(&(jungle->expCrab));

}

int main(){
  Jungle *jungle = (Jungle *) malloc(sizeof(Jungle));

  createCreeps(jungle);
  
  printCreepsData(jungle);

  freeCreeps(jungle);

  free(jungle);

  return 0;
}

