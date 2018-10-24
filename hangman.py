from random import randint

filename = "words.txt"

try:
    content = [line.rstrip("\n").lower() for line in open(filename)]
    size = len(content)
    num = randint(0,size)
    #print(size, num)

    word = content[num]
    wordl = list(word)
    #print("The word to guess", word)
    #print(list(word))

except Exception as e:
    print("Couldn't find the file")

#Counts how many wrong
wrong_count = 0

hangman = list("HANGMAN")
show_guess = []
for i in range(0, len(word)):
    show_guess.append("*")
str1 = ""

while str1 != word and wrong_count != 7:
    if wrong_count >=1:
        print("\n")
        print("####################")
        print("How you are hanging!")
        for c in range(0,wrong_count):
            print(hangman[c],end="")
        print("\n")
    guess = str(input("Guess a letter: ")).lower()
    if guess in wordl:
        for x in range(0,len(word)):
            if guess == wordl[x]:
                show_guess[x]= guess
    else:
        print("\n")
        print("Another letter for you")
        wrong_count +=1
    str1 = ''.join(show_guess)
    print("\n")
    print("#####################")
    print("Currently have: ", end = "")
    print(str1)

if wrong_count == 7:

    print("-----------------------------------------")
    print("----------------HANGMAN------------------")
    print("-----------------------------------------")
    print("You were looking for: ",word)
else:
    print("-----------------------------------------")
    print("----------------WINNER-------------------")
    print("-----------------------------------------")
