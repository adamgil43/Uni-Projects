#A function that recursively reverses a string.
def rev(s):
    if s == "":
        return s
    else:
        return s[-1] + rev(s[:-1])
    
def reverseList(s):
    split = s.split();
    reverse = []
    reverse = split[::-1]
    newWord = " ".join(reverse);
    return newWord

def main():
    strWord = input("Please enter a sentence \n")
    newWord = rev(strWord)
    reverse = reverseList(newWord)
    print(reverse)
