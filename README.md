# Algorithmes de tri en C

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/1/19/C_Logo.png" alt="Langage C" width="120">
</p>

<p align="center">
  <em>Étude comparative • Performances • Visualisation avec GNUplot</em>
</p>

<hr>

## Description

> Étude comparative de différents algorithmes de tri implémentés en langage **C**, avec analyse de leurs performances et visualisation des résultats à l’aide de **GNUplot**.

<hr>

## Structure du projet

```
algorithmes-tri-c/
├── Makefile                  # Compilation automatique (mingw32-make)
├── README.md
│
├── includes/                 # En-têtes (.h)
│   ├── benchmark.h
│   ├── data_generator.h
│   ├── data_loader.h
│   └── sorting/
│       └── insertion_sort.h
│
├── src/                      # Code source (.c)
│   ├── main.c                # Point d'entrée
│   ├── benchmark/
│   │   └── benchmark.c       # Mesures de performance
│   ├── data/
│   │   ├── data_generator.c  # Génération des jeux de données
│   │   └── data_loader.c     # Lecture des fichiers de données
│   └── sorting/
│       └── insertion_sort.c  # Tri par insertion
│
├── data/
│   ├── input/random/         # Données générées (ignorées par git)
│   └── raw/
│
├── results/
│   ├── graphs/               # Graphiques (PNG, SVG)
│   └── reports/              # Rapports CSV
│
├── gnuplot/                  # Scripts GNUplot
├── docs/                     # Documentation
└── tests/                    # Tests
```

### Rôles des modules

| Module | Rôle |
|---|---|
| `main.c` | Initialise les tailles, génère les données, lance les benchmarks |
| `data_generator` | Écrit les fichiers de nombres aléatoires |
| `data_loader` | Lit les fichiers en mémoire (avec validation) |
| `insertion_sort` | Trie un tableau d'entiers |
| `benchmark` | Orchestre le chargement + tri de chaque jeu de données |

### Flux d'exécution

```
main()
 ├── generate_random_datasets()  → data/input/random/*.txt
 └── run_all_benchmarks()
      └── run_benchmark()
           ├── load_data()       ← fichier .txt
           └── insertion_sort()  → tri en mémoire
```

<hr>
