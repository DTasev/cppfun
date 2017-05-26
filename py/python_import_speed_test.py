import time


def main():
    t = None
    sumx = 0
    runs = 10
    print("starting..")
    for x in xrange(0, runs):
        t = time.time()

        import tomopy
        import tomopy.prep
        import tomopy.recon
        import tomopy.misc
        import tomopy.io

        v = time.time() - t

        sumx += v
        print(v)
        print(sumx)

    print("Average:", sumx / runs)

main()
