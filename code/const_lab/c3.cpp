int main() {
    int c = 13;
    int v = 5;
    int* const q = &v;
    q = &c;
    *q = 9;
    return 0;
}
