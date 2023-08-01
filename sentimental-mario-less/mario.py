# The user's will input the height
while True:

    height = int(input("Height: "))
    if (height > 0) and (height < 9):
        break
# This code will form the Pyramid
for i in range(height):
    for x in range(height - i - 1):
        print(" ", end="")

    for j in range(i + 1):
        print("#", end="")
    print("\n", end="")