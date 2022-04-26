def getPhoneNumber(s):
    l=["zero","one","two","three","four","five","six","seven","eight","nine"]
    st=""
    s=s.split()
    for c in s:
        st+=str(l.index(c))
    return(st)

if __name__ == '__main__':
    s = str(input())
    print(getPhoneNumber(s))
   
   
   
