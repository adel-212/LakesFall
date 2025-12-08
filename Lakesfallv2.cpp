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

        // Recherche de lindex du sommet maximum
        int IndexSommetMax = 0;
        for (int i = 1; i < TailleHistogramme; i++) {
            if (Liste[i] > Liste[IndexSommetMax]) {
                IndexSommetMax = i;
            }
        }
        
        // initialisation des variable de résultat
        int VolumeMax = 0, DebutVolume = 0, FinVolume = 0;
        int LargeurMax = 0, DebutLargeur = 0, FinLargeur = 0;
        int ProfondeurMax = 0, DebutProfondeur = 0, FinProfondeur = 0;

        // initialisation des variables temporaire a 0
        int IndexMurReference = 0;
        int VolumeTemp = 0;
        int ProfondeurMaxTemp = 0;

        // boucle gauche du debut jusquau sommet Max
        for (int i = 0; i <= IndexSommetMax; i++) {
            
            // cas ou on est dans l'eau parce que cest plus petit que le mur de reference
            if (Liste[i] < Liste[IndexMurReference]) {
                VolumeTemp = VolumeTemp + (Liste[IndexMurReference] - Liste[i]);
                int ProfondeurActuelle = Liste[IndexMurReference] - Liste[i];
                if (ProfondeurActuelle > ProfondeurMaxTemp) {
                    ProfondeurMaxTemp = ProfondeurActuelle;
                }
            // cas ou le lac est fini parce que on a un mur plus grand ou egal au mur de reference
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
        } 

        //  Reset des variables pour commencer  la boucle droite a 0
        IndexMurReference = TailleHistogramme - 1; 
        VolumeTemp = 0;
        ProfondeurMaxTemp = 0;

        // boucle droite de la fin jusquau sommet Max
        for (int i = TailleHistogramme - 1; i >= IndexSommetMax; i--) { 
            
            if (Liste[i] < Liste[IndexMurReference]) {
                VolumeTemp = VolumeTemp + (Liste[IndexMurReference] - Liste[i]);
                int ProfondeurActuelle = Liste[IndexMurReference] - Liste[i];
                if (ProfondeurActuelle > ProfondeurMaxTemp) {
                    ProfondeurMaxTemp = ProfondeurActuelle;
                }
            } else {
                
                if (VolumeTemp > 0) {
                    if (VolumeTemp > VolumeMax || (VolumeTemp == VolumeMax && i < DebutVolume)) {
                        VolumeMax = VolumeTemp;
                        DebutVolume = i;                 
                        FinVolume = IndexMurReference;   
                    }
                  
                    int LargeurActuelle = IndexMurReference - i - 1;
                    if (LargeurActuelle > LargeurMax || (LargeurActuelle == LargeurMax && i < DebutLargeur)) {
                        LargeurMax = LargeurActuelle;
                        DebutLargeur = i;
                        FinLargeur = IndexMurReference;
                    }
                    if (ProfondeurMaxTemp > ProfondeurMax || (ProfondeurMaxTemp == ProfondeurMax && i < DebutProfondeur)) {
                        ProfondeurMax = ProfondeurMaxTemp;
                        DebutProfondeur = i;
                        FinProfondeur = IndexMurReference;
                    }
                }
                IndexMurReference = i;
                VolumeTemp = 0;
                ProfondeurMaxTemp = 0;
            }
        } 

        // Affichage des résultats
        if (VolumeMax == 0) {
            printf("0 0 0\n0 0 0\n0 0 0\n");
        } else {
            // +1 pour passer en base 1
            printf("%d %d %d\n", DebutVolume + 1, FinVolume + 1, VolumeMax);
            printf("%d %d %d\n", DebutLargeur + 1, FinLargeur + 1, LargeurMax);
            printf("%d %d %d\n", DebutProfondeur + 1, FinProfondeur + 1, ProfondeurMax);
        }
    } 
    return 0;
}