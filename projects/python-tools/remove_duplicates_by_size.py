import os


def get_directory_location() -> str:
    return "/Users/kk/git/"


def remove_duplicates():
    d = get_directory_location()
    if not os.path.isdir(d):
        print("not exactly a directory {} exiting .. ".format(d))
        return

    print("looking inside {}".format(d))

    size_name_hash = {}

    def peek():
        for path, subdirs, files in os.walk(d):
            for name in files:
                file = os.path.join(path, name)
                size = os.path.getsize(file)
                print("file {} size {}".format(file, size))
                if size not in size_name_hash:
                    size_name_hash[size] = []
                size_name_hash[size].append(file)

        for k in size_name_hash:
            for f in size_name_hash[k]:
                print(" size {} file {}".format(k, f))

    peek()

    return


if __name__ == "__main__":
    remove_duplicates()
