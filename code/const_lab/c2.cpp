int main() {
    const int A = 78; int c = 13;
    const int* p = &A;
    *p = 1;
    p = &c;
    return 0;
}
