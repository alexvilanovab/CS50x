# import modules
import cs50


# main
def main():
    # get dollars
    while True:
        print("O hai! How much change is owed?")
        d = cs50.get_float()
        if d > 0:
            break

    # get cents
    c = int(d * 100)

    # init coins
    coins = 0

    # calculate...
    coins += c // 25
    c %= 25
    coins += c // 10
    c %= 10
    coins += c // 5
    c %= 5
    coins += c

    # print results
    print("{}".format(coins))

    # done
    exit(0)


# redirect to main
if __name__ == "__main__":
    main()
