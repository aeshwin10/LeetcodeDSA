class Solution:
    def romanToInt(self, s: str) -> int:
        
        romans=['I','V','X','L','C','D','M']
        values=[1,5,10,50,100,500,1000]
        suma=0
        skip=False


        for i in range(len(s)):
            if skip==True:
                skip=False
                continue
            else:
                #print(i+1,len(s))
                a=romans.index(s[i])
                #if i+1<=len(s):
                if i==len(s)-1:
                    suma+=values[a]
                    break
                #print("s of i is:",s[i],s[i+1])
                
                #print('a:',a)
                b=romans.index(s[i+1])
                if a<b:
                    suma+=values[b]-values[a]
                    skip=True
                else:
                    suma+=values[a]
        return (suma)


