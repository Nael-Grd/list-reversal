# Verified List Inversion - Tortoise & Hare
![C](https://img.shields.io/badge/Language-C-blue.svg)
![ACSL](https://img.shields.io/badge/Specification-ACSL-blueviolet)
![Frama-C](https://img.shields.io/badge/Verified%20with-Frama--C-blue)
![Prover](https://img.shields.io/badge/Prover-Alt--Ergo-orange)

## 🇫🇷 Version Française (english bellow)

Ce projet implémente et vérifie formellement un algorithme d'inversion de valeurs dans une liste chaînée en utilisant l'algorithme de  **Tortoise & Hare** (Tortue et lièvre).

###  Prérequis
* **Frama-C** : [Site officiel (frama-c.com)](https://frama-c.com/html/get-frama-c.html)
* **Alt-Ergo** : Prouveur SMT (souvent installé avec Frama-C via opam).
* **GCC & Make** : Pour la compilation et l'exécution classique.

###  Utilisation

```bash
# Compiler et lancer le programme de test
make
./main

# Lancer la vérification formelle (Frama-C/WP)
make proof

# Nettoyer les fichiers temporaires
make clean
```

## 🇺🇸 English Version

###  Overview
This project implements and formally verifies a linked-list value-reversal algorithm using the **Tortoise & Hare** technique. The goal is to prove both memory safety and functional correctness.

###  Prerequisites
* **Frama-C**: [Get Frama-C](https://frama-c.com/html/get-frama-c.html)
* **Alt-Ergo / Z3**: SMT Solvers for WP.
* **GCC & Make**: For standard build.

### Commands
```bash
make        # Compile 
make proof  # Launch Frama-C/WP verification
make clean  # Cleanup
```
