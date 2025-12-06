#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int NombredeCas;
    if (scanf("%d", &NombredeCas) != 1) return 0;

    while (NombredeCas--) {
        int TailleHistogramme;
        scanf("%d", &TailleHistogramme);

        vector<int> Liste;
        for (int i = 0; i < TailleHistogramme; i++) {
            int Mur;
            scanf("%d", &Mur);
            Liste.push_back(Mur);
        }

        int IndexSommetMax = 0;
        for (int i = 1; i < TailleHistogramme; i++) {
            if (Liste[i] > Liste[IndexSommetMax]) {
                IndexSommetMax = i;
            }
        }
        
        // 1. Les Champions
        int VolumeMax = 0, DebutVolume = 0, FinVolume = 0;
        int LargeurMax = 0, DebutLargeur = 0, FinLargeur = 0;
        int ProfondeurMax = 0, DebutProfondeur = 0, FinProfondeur = 0;

        // 2. Préparation
        int IndexMurReference = 0;
        int VolumeTemp = 0;
        int ProfondeurMaxTemp = 0;

        // 3. BOUCLE GAUCHE (0 -> Sommet)
        for (int i = 0; i <= IndexSommetMax; i++) {
            
            if (Liste[i] < Liste[IndexMurReference]) {
                VolumeTemp += (Liste[IndexMurReference] - Liste[i]);
                int ProfondeurActuelle = Liste[IndexMurReference] - Liste[i];
                if (ProfondeurActuelle > ProfondeurMaxTemp) {
                    ProfondeurMaxTemp = ProfondeurActuelle;
                }
            } else {
                if (VolumeTemp > 0) {
                    if (VolumeTemp > VolumeMax) {
                        VolumeMax = VolumeTemp;
                        DebutVolume = IndexMurReference;
                        FinVolume = i;
                    }
                    int LargeurActuelle = i - IndexMurReference - 1; 
                    if (LargeurActuelle > LargeurMax) {
                        LargeurMax = LargeurActuelle;
                        DebutLargeur = IndexMurReference;
                        FinLargeur = i;
                    }
                    if (ProfondeurMaxTemp > ProfondeurMax) {
                        ProfondeurMax = ProfondeurMaxTemp;
                        DebutProfondeur = IndexMurReference;
                        FinProfondeur = i;
                    }
                }
                // Reset pour le prochain lac
                IndexMurReference = i;
                VolumeTemp = 0;
                ProfondeurMaxTemp = 0;
            }
        } // <--- TRÈS IMPORTANT : On ferme la boucle GAUCHE ici !

        // --- RESET AVANT LA DROITE ---
        IndexMurReference = TailleHistogramme - 1; 
        VolumeTemp = 0;
        ProfondeurMaxTemp = 0;

        // 4. BOUCLE DROITE (Fin -> Sommet)
        for (int i = TailleHistogramme - 1; i >= IndexSommetMax; i--) { 
            
            if (Liste[i] < Liste[IndexMurReference]) {
                VolumeTemp += (Liste[IndexMurReference] - Liste[i]);
                int ProfondeurActuelle = Liste[IndexMurReference] - Liste[i];
                if (ProfondeurActuelle > ProfondeurMaxTemp) {
                    ProfondeurMaxTemp = ProfondeurActuelle;
                }
            } else {
                if (VolumeTemp > 0) {
                    if (VolumeTemp > VolumeMax) {
                        VolumeMax = VolumeTemp;
                        DebutVolume = i;                 // i est à gauche
                        FinVolume = IndexMurReference;   // Ref est à droite
                    }
                    int LargeurActuelle = IndexMurReference - i - 1;
                    if (LargeurActuelle > LargeurMax) {
                        LargeurMax = LargeurActuelle;
                        DebutLargeur = i;
                        FinLargeur = IndexMurReference;
                    }
                    if (ProfondeurMaxTemp > ProfondeurMax) {
                        ProfondeurMax = ProfondeurMaxTemp;
                        DebutProfondeur = i;
                        FinProfondeur = IndexMurReference;
                    }
                }
                IndexMurReference = i;
                VolumeTemp = 0;
                ProfondeurMaxTemp = 0;
            }
        } // Fin boucle Droite

        // 5. AFFICHAGE (LE JUDGE EN A BESOIN)
        if (VolumeMax == 0) {
            printf("0 0 0\n0 0 0\n0 0 0\n");
        } else {
            // On ajoute +1 aux indices car l'énoncé compte à partir de 1
            printf("%d %d %d\n", DebutVolume + 1, FinVolume + 1, VolumeMax);
            printf("%d %d %d\n", DebutLargeur + 1, FinLargeur + 1, LargeurMax);
            printf("%d %d %d\n", DebutProfondeur + 1, FinProfondeur + 1, ProfondeurMax);
        }

    } // Fin du While
    return 0;
}