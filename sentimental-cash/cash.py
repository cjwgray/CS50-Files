from cs50 import get_float
while True:
    i = 0
    coins = 0
    # The user's will input the what change is due, and the user's input will convert to a float.
    i = get_float("The amount of change due: ")

    # The cents varible is store with i to multiple it by 100 and then round it out.
    cents = round(i * 100)

    # If the user inputs less then 0 the condition will break.
    if cents < 0:
        break

    # quarters, dimes, nickels, and pennies varibles.
    quarters = 25
    dimes = 10
    nickels = 5
    pennies = 1

    # Cents will loop still the condition is greater than each varible.
    while cents >= quarters:
        cents = cents - quarters
        coins += 1
    while cents >= dimes:
        cents = cents - dimes
        coins += 1
    while cents >= nickels:
        cents = cents - nickels
        coins += 1
    while cents >= pennies:
        cents = cents - pennies
        coins += 1

    # This will print the amount of coins that is due back.
    print("You get", coins, "coins back")
    break