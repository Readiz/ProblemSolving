val = -1
for i in range(3):
    tmp = input()
    if tmp == "Fizz" or tmp == "Buzz" or tmp == "FizzBuzz":
        val = val + 1
        continue
    else:
        val = int(tmp)
val = val + 1
if val % 5 == 0 and val % 3 == 0:
    print("FizzBuzz")
elif val % 3 == 0:
    print("Fizz")
elif val % 5 == 0:
    print("Buzz")
else:
    print(val)
