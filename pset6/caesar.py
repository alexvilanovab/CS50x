# import modules
import sys
import cs50


# main
def main():
    # ensure right usage
    if len(sys.argv) != 2:
        print("Usage: python caesar.py k")
        exit(1)

    # get k
    k = int(sys.argv[1])

    # get plain text
    print("plaintext:  ", end="")
    p = cs50.get_string()

    # print cipher text
    print("ciphertext: ", end="")
    for i in range(len(p)):
        c = p[i]
        if c.isalpha():
            if c.isupper():
                print("{}".format(chr((ord(c) - 65 + k) % 26 + 65)), end="")
            else:
                print("{}".format(chr((ord(c) - 97 + k) % 26 + 97)), end="")
        else:
            print("{}".format(c), end="")
    print()

    # done
    exit(0)


# redirect to main
if __name__ == "__main__":
    main()
