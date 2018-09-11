# import modules
import cs50


# main
def main():
    # get height
    while True:
        print("Height: ", end="")
        h = cs50.get_int()
        if h <= 23 and h >= 0:
            break

    # print pyramid
    for b in range(1, h + 1):
        blocks = ("#" * b)
        spaces = (" " * (h - b))
        print("{}{}  {}{}".format(spaces, blocks, blocks, spaces))

    # done
    exit(0)


# redirect to main
if __name__ == "__main__":
    main()
