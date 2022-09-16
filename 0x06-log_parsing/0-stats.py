#!/usr/bin/python3
'''
Script that reads stdin line by line and computes metrics:

    Input format: <IP Address> - [<date>]
    "GET /projects/260 HTTP/1.1" <status code> <file size>
    (if the format is not this one, the line must be skipped)
    After every 10 lines and/or a keyboard interruption (CTRL + C),
    print these statistics from the beginning:
        Total file size: File size: <total size>
        Where <total size> is the sum of all previous <file size>
        (see input format above)
        Number of lines by status code:
            possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
            if a status code doesn’t appear or is not an integer,
            don’t print anything for this status code
            format: <status code>: <number>
            status codes should be printed in ascending order
Warning: In this sample, you will have random value
- it’s normal to not have the same output as this one.
'''

import sys


if __name__ == "__main__":
    st_code = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0}
    count = 1
    file_size = 0

    def read_data(line):
        '''Function that parse, read and save data'''
        try:
            split_line = line.split()
            status_code = split_line[-2]
            if status_code in st_code.keys():
                st_code[status_code] += 1
            return int(split_line[-1])
        except Exception:
            return 0

    def status():
        '''Function that prints the status'''
        print("File size: {}".format(file_size))
        for key in sorted(st_code.keys()):
            if st_code[key]:
                print("{}: {}".format(key, st_code[key]))

    try:
        for line in sys.stdin:
            file_size += read_data(line)
            if count % 10 == 0:
                status()
            count += 1
    except KeyboardInterrupt:
        status()
        raise
    status()
