#include "libsimpleflake.h"
#include <inttypes.h>

int main(int argc, char **argv)
{
    printf("%" PRIu64 "\n", simpleflake());
    exit(0);
}
