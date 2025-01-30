import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    animalsCopy = animals[["name", "weight"]]

    heavyAnimals = animalsCopy[animalsCopy["weight"]>100]

    heavyAnimals = heavyAnimals.sort_values(by = 'weight', ascending = False)[["name"]]
    return heavyAnimals
