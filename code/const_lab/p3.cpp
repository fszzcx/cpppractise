int main() {
    int v = 5;
    const int* p = &v;
    *p = 1;
    return 0;
}
