#include "libsimpleflake.h"

uint64_t unix_epoch_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64_t)tv.tv_sec * 1000 +
        (uint64_t)tv.tv_usec / 1000;
}

uint64_t random_bits(int n)
{
    assert(SIMPLEFLAKE_RANDOM_BITS <= 32);
    assert(n <= 32);
    int r = n % 8;
    uint32_t random = arc4random();
    return uint64_extract_bits(random, ((r == 0) ? 0: (8 - r)), n);
}

uint64_t simpleflake()
{
    uint64_t ts = unix_epoch_ms() - SIMPLEFLAKE_EPOCH_MS;
    uint64_t random = random_bits(SIMPLEFLAKE_RANDOM_BITS);
    return (ts << SIMPLEFLAKE_RANDOM_BITS) + random;
}
