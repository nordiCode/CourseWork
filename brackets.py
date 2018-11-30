
def bracket_check(line):
    brackets = []
    check = False
    for i in line:
        length = len(brackets)
        if i in '{[(':
            brackets.append(i)
        if i == ']':
            if brackets[length - 1] == '[':
                brackets.pop()
                print("--------Pair--------")
                check = True
            else:
                print("not ordered")
                return False
        elif i == '}':
            if brackets[length -1] == '{':
                brackets.pop()
                print("--------Pair--------")
                check = True
            else:
                print("not ordered")
                return False
        elif i == ')':
            if brackets[length -1] == '(':
                brackets.pop()
                print("--------Pair--------")
                check = True
            else:
                print("not ordered")
                return False
    return check


line = input()
check = bracket_check(line)
if check == True:
    print("The line was fine for brackets")
else:
    print("Brackets are out of wack")
print("This is the entered line:", line)
