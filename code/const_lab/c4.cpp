int main() {
    int v = 5;
    const int M = 10;
    const int* const r = &M;
    r = &v;
    *r = 1;
    return 0;
}
