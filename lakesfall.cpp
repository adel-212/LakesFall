#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int NombredeCas;
    scanf("%d", &NombredeCas); // On lit le nombre de cas

    while (NombredeCas--) {
        int TailleHistogramme;
        scanf("%d", &TailleHistogramme); // On lit la taille de  cet histogramme

        // on dermine la liste des hauteurs des murs
        vector<int> Liste;
        for (int i = 0; i < TailleHistogramme; i++) {
            int Mur;
            scanf("%d", &Mur);
            Liste.push_back(Mur);
        }

        // on determine l'index du sommet le plus haut
        int IndexSommetMax = 0;
        for (int i = 1; i < TailleHistogramme; i++) {
            if (Liste[i] > Liste[IndexSommetMax]) {
                IndexSommetMax = i;
            }
        }
        
        // 1. Les Champions (Valeurs + Indices)
        int VolumeMax = 0, DebutVolume = 0, FinVolume = 0;
        int LargeurMax = 0, DebutLargeur = 0, FinLargeur = 0;
        int ProfondeurMax = 0, DebutProfondeur = 0, FinProfondeur = 0;

        // 2. Préparation de la marche (Le cahier de brouillon)
        int IndexMurReference = 0; // On commence avec le premier mur comme référence
        int VolumeTemp = 0;     // Volume du lac en cours
        int ProfondeurMaxTemp = 0; // Profondeur max du lac en cours

        // 3. La Marche vers le Sommet
        for (int i = 0; i <= IndexSommetMax; i++) {
            
            // CAS 1 : On est dans l'eau ? (Mur actuel < Mur de Référence)
            if (Liste[i] < Liste[IndexMurReference]) {
                // ... A TOI DE CODER :
                // Ajoute de l'eau au VolumeTemp
                VolumeTemp = VolumeTemp + (Liste[IndexMurReference] - Liste[i]);
                // Calcule la profondeur ici (MurRef - MurActuel)
                int ProfondeurActuelle = Liste[IndexMurReference] - Liste[i];
                // Si cette profondeur est plus grande que ProfondeurMaxTemp, on la met à
                if (ProfondeurActuelle > ProfondeurMaxTemp) {
                    ProfondeurMaxTemp = ProfondeurActuelle;
                }
            } 
            
            // CAS 2 : Le lac est fini (Mur actuel >= Mur de Référence)
            else {
                // On vérifie qu'on a bien traversé de l'eau
                if (VolumeTemp > 0) {
                    
                    // 1. Est-ce le plus VOLUMINEUX ?
                    if (VolumeTemp > VolumeMax) {
                        // ... met à jour VolumeMax, DebutVolume, FinVolume  ...
                        VolumeMax = VolumeTemp;
                        DebutVolume = IndexMurReference;
                        FinVolume = i;
        
                    }

                    // 2. Est-ce le plus LARGE ? 
                    // Rappel : Largeur = i - IndexMurReference - 1
                    int LargeurActuelle = i - IndexMurReference - 1; 
                    if (LargeurActuelle > LargeurMax) {
                        // ... met à jour LargMax ...
                        // Attention aux indices : Debut = IndexMurReference, Fin = i
                        LargeurMax = LargeurActuelle;
                        DebutLargeur = IndexMurReference;
                        FinLargeur = i;
                    }

                    // 3. Est-ce le plus PROFOND ?
                    if (ProfondeurMaxTemp > ProfondeurMax) {
                        // ... met à jour ProfMax ...
                        ProfondeurMax = ProfondeurMaxTemp;
                        DebutProfondeur = IndexMurReference;
                        FinProfondeur = i;
                    }
                }

                // --- RESET ---
                IndexMurReference = i;
                VolumeTemp = 0;
                ProfondeurMaxTemp = 0;
            }

        // --- RESET DES VARIABLES TEMPORAIRES AVANT D'ATTAQUER LA DROITE ---
        IndexMurReference = TailleHistogramme - 1; // On part du tout dernier mur
        VolumeTemp = 0;
        ProfondeurMaxTemp = 0;

        // BOUCLE DE DROITE (De la fin vers le Sommet)
        for (int i = TailleHistogramme - 1; i >= IndexSommetMax; i--) { // Attention au i--
            
            // CAS 1 : On est dans l'eau ? (Mur actuel < Mur de Référence)
            if (Liste[i] < Liste[IndexMurReference]) {
                // ... C'est exactement pareil que la gauche .
                VolumeTemp = VolumeTemp + (Liste[IndexMurReference] - Liste[i]);
                int ProfondeurActuelle = Liste[IndexMurReference] - Liste[i];
                if (ProfondeurActuelle > ProfondeurMaxTemp) {
                    ProfondeurMaxTemp = ProfondeurActuelle;
                }
                
            } 
            
            // CAS 2 : Fin du lac
            else {
                if (VolumeTemp > 0) {
                    
                    // 1. Est-ce le plus VOLUMINEUX ?
                    if (VolumeTemp > VolumeMax) {
                        VolumeMax = VolumeTemp;
                        DebutVolume = i;                 // <--- ATTENTION : i est à gauche
                        FinVolume = IndexMurReference;   // <--- ATTENTION : Ref est à droite
                    }

                    // ... PAREIL POUR LARGEUR ET PROFONDEUR ...
                    int LargeurActuelle = IndexMurReference - i - 1;
                    if (LargeurActuelle > LargeurMax) {
                        LargeurMax = LargeurActuelle;
                        DebutLargeur = i;                 // ... Pense bien à inverser i et Index
                        FinLargeur = IndexMurReference;   // ... Pense bien à inverser i et Index
                    }
                    // ... Pense bien à inverser i et IndexMurReference pour les indices ...
                    if (ProfondeurMaxTemp > ProfondeurMax) {
                        ProfondeurMax = ProfondeurMaxTemp;
                        DebutProfondeur = i;                 // ... Pense bien à inverser i et Index
                        FinProfondeur = IndexMurReference;   // ... Pense bien à inverser i et Index
                    }

                }

                // RESET
                IndexMurReference = i;
                VolumeTemp = 0;
                ProfondeurMaxTemp = 0;
            }
        
        }

        }
        
    return 0;
    }
