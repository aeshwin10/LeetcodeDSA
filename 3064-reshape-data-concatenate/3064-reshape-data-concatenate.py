import pandas as pd

def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    DataFrame = [df1, df2]
    return pd.concat(DataFrame)