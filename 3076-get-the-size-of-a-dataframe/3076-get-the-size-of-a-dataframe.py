import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    #Method 1
    ans = list(players.shape)
    #return ans

    #Method 3
    rows = len(players.axes[0])
    cols = len(players.axes[1])
    return [rows, cols]



    