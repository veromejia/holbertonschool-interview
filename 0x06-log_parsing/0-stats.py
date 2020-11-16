#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""

if __name__ == '__main__':
    import sys

    def print_statistics(codes, size):
        """function to print the metrics of a file"""
        print("File size: {}".format(size))
        for key in sorted(codes.keys()):
            if codes[key]:
                print("{}: {}".format(key, codes[key]))

    codes = {"200": 0, "301": 0, "400": 0, "401": 0,
             "403": 0, "404": 0, "405": 0, "500": 0}
    size = 0
    i = 0

    try:
        for line in sys.stdin:
            word = line.split()
            i += 1
            try:
                code = (word[7])
                line_size = word[8]
                size += int(line_size)

                if code in codes:
                    codes[code] += 1
            except:
                pass

            if i % 10 == 0:
                print_statistics(codes, size)
    except KeyboardInterrupt:
        pass
    finally:
        print_statistics(codes, size)
