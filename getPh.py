def getPhoneNumber(s):
    l=["zero","one","two","three","four","five","six","seven","eight","nine"]
    st=""
    s=s.split()
    i=0
    while i<len(s):
        j=i
        if s[j]=="double":
            st+=str(l.index(s[j+1]))
            st+=str(l.index(s[j+1]))
            i+=2
        elif s[j]=="triple":
            st+=str(l.index(s[j+1]))
            st+=str(l.index(s[j+1]))
            st+=str(l.index(s[j+1]))
            i+=2
        else:
            st+=str(l.index(s[j]))
            i+=1
        
        
       
    return(st)
if _name=='main_':
s=str(input(s)) 
print(getPhoneNumber(s))
