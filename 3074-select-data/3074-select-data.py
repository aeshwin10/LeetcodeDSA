import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    #Boolean Series where each entry is True if the corresponding student_id is 101, and False otherwise. This is called a Boolean mask.
    #return students.loc[students['student_id']==101, ["name", "age"]]
    return students.loc[students['student_id']==101, "name":]