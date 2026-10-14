/* Minimal syscalls for ARM GCC */
int _write(int file, char *ptr, int len) {
    (void)file; (void)ptr;
    return len;
}
int _read(int file, char *ptr, int len) {
    (void)file; (void)ptr; (void)len;
    return 0;
}
int _close(int file) { (void)file; return -1; }
int _lseek(int file, int ptr, int dir) { (void)file; (void)ptr; (void)dir; return 0; }
int _fstat(int file, void *st) { (void)file; (void)st; return -1; }
int _isatty(int file) { (void)file; return 1; }
void _exit(int status) { while(1); }
