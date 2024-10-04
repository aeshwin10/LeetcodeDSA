import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    result = employees.head(3)
    return employees.iloc[:3, :]
    