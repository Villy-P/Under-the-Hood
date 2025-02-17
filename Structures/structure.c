struct Unpacked {
    char a;
    int b;
};

struct Packed {
    char a;
    int b;
} __attribute__((packed));

int main() {
    struct Unpacked u = { 'A', 32 };
    struct Packed p = { 'B', 35 };
}