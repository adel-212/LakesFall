#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t); // On lit le nombre de cas

    while (t--) { // Pour chaque cas de test...
        int n;
        scanf("%d", &n); // On lit la taille de CET histogramme

        vector<int> Liste;
        // ... ICI : Boucle pour lire les 'n' hauteurs et les mettre dans Liste ...
        for (int i = 0; i < n; i++) {
            int h;
            scanf("%d", &h);
            Liste.push_back(h);
        }

        // ... ICI : Recherche de l'INDEX du maximum ...
        int IndexSommetMax = 0;
        // ... ta boucle for qui cherche le max ...
        for (int i = 1; i < n; i++) {
            if (Liste[i] > Liste[IndexSommetMax]) {
                IndexSommetMax = i;
            }
        }
        
        // C'est ici qu'on mettra la logique des Lacs (Gauche et Droite) plus tard
        
        // À la fin de chaque cas, on affiche le résultat (0 0 0 pour l'instant)
    }
    return 0;
}