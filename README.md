# Verified List Inversion - Tortoise & Hare
![ACSL](https://img.shields.io/badge/Specification-ACSL-green)
![Frama-C](https://img.shields.io/badge/Verified%20with-Frama--C-orange)
![Prover](https://img.shields.io/badge/Prover-Alt--Ergo-orange)

## 🇫🇷 Version Française (english below)

Ce projet implémente et vérifie formellement un algorithme d'inversion de valeurs dans une liste chaînée en utilisant l'algorithme de  **Tortoise & Hare** (Tortue et lièvre).

###  Prérequis
* **Frama-C** : [Site officiel (frama-c.com)](https://frama-c.com/html/get-frama-c.html)
* **Alt-Ergo** : Prouveur SMT (souvent installé avec Frama-C via opam).

###  Utilisation

 Compiler et lancer le programme de test
```bash
make
./main
```

Lancer la vérification formelle (Frama-C/WP)
```bash
make proof
```

Nettoyer les fichiers temporaires
```bash
make clean
```

## 🇺🇸 English Version

###  Overview
This project implements and formally verifies a linked-list value-reversal algorithm using the **Tortoise & Hare** technique. The goal is to prove both memory safety and functional correctness.

###  Prerequisites
* **Frama-C**: [Get Frama-C](https://frama-c.com/html/get-frama-c.html)
* **Alt-Ergo / Z3**: SMT Solvers for WP.


### Commands
Compile
```bash
make        
```
Launch Frama-C/WP verification
```bash
make proof  
```
Cleanup
```bash
make clean  
```
