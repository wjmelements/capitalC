#include "capitalC.h"
int main() {
    pid_t pid = Fork();
    if (pid) {
        // parent
        return 0;
    } else {
        // child
        return -1;
    }
    return 0;
}
