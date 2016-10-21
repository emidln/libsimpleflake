#include <assert.h>
#include <bsd/stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/time.h>

#define SIMPLEFLAKE_EPOCH_MS 946702800000 /* 2000-01-01T00:00:00Z */
#define SIMPLEFLAKE_TIME_BITS 41
#define SIMPLEFLAKE_RANDOM_BITS 23

#define uint64_extract_bits(x, s, l) \
    (((x) & ((((uint64_t)1 << (l)) - (uint64_t)1) << (s))) >> (s))

extern uint64_t unix_epoch_ms(void);
extern uint64_t random_bits(int);
extern uint64_t simpleflake(void);
