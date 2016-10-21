import ctypes

csf = ctypes.CDLL('./libsimpleflake.so')

def pretty_timeit(func_str, setup_str):
    import timeit
    v = timeit.timeit(func_str, setup=setup_str)
    ns = v * 1000 * 1000 * 1000
    print "Total (1,000,000 runs, best of 3): %s" % str(v)
    print str(ns / 1000000), "ns per loop"

if __name__ == '__main__':
    pretty_timeit("csf.simpleflake()", "from __main__ import csf")
    pretty_timeit("simpleflake()", "from simpleflake import simpleflake")

