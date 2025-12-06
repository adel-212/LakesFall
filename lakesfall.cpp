#include stdio.h>
#include <vector>

using namespace std;

int main(){
    vector<int> Liste;
    int SommetTailleMax; 


    for(int i = 0; i < 100000; i++){
        int valeur;
        scanf("%d", &valeur);
        Liste.push_back(valeur);
    }

    SommetTailleMax = Liste[0];
    for(int i = 1; i < Liste.size(); i++){
        if(Liste[i] > SommetTailleMax){
            SommetTailleMax = Liste[i];
        }

    
    }