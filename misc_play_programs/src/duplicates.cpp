#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <string_view>
#include <unordered_map>

static std::string filename;

void exit_if(int argc, const char **argv) {
    if (argc != 2) {
        exit(0);
    }
    filename = std::string(argv[1]);
}

size_t hits = 0;
std::unordered_map<size_t, std::string_view> meta;
void hash_and_store(char *data, std::size_t size) {
    auto sv = std::string_view(data, size);
    size_t hval = std::hash<std::string_view>()(sv);
    if (meta.find(hval) != meta.end()) {
        hits++;
    } else {
        meta.insert(std::pair<size_t, std::string_view>(hval, sv));
    }
}

void dump_meta() {
    std::cout << std::setw(64) << filename << std::setw(16) << " Meta Size "
              << meta.size() << std::setw(16) << " Hits " << hits << "\n";
}

int main(int argc, char const *argv[]) {
    exit_if(argc, argv);
    std::ifstream ifs(filename, std::fstream::binary);
    if (not ifs) {
        std::cout << "unable to open file " << filename << "\n";
        std::exit(0);
    }

    int size = 1024 << 1;
    char *b = new char[size];
    int iterations = 1;
    do {
        ifs.read(b, size);
        hash_and_store(b, size);
        ++iterations;
    } while (ifs);
    hash_and_store(b, size);

    dump_meta();
    return 0;
}