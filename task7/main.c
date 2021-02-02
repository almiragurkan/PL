#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Skater{
  char name[95];
  char surname[95];
  double refereeScores[6];
  double keepingAverage;
};



double calculateScore(const struct Skater* member){
    double score = 0;
    int count = 0;
    for (int i=0; i<6; i++){
        count++;
        score += member->refereeScores[i];

    }
    return score / count;
}

int loadSkaters(Skater** memberp){
    FILE *filep;
    char text[60];
    FILE *filep = fopen(skaters.txt,"r");
    for(int i=0; i<6;i++){

    }



}
int main(void) {

  printf("Winner of the Skating Championship is:")
}
