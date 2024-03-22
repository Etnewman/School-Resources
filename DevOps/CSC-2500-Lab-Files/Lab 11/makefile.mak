PROG = craps
LIBSRCS = craps_game.cpp craps_helper.cpp craps_io.cpp craps.cpp
LIBOBJS = $(patsubst%.cpp,%.o,$(LIBSRCS))
HDRS = craps_const.h craps_game.h craps_helper.h craps_io.h
LIBCRAPS = craps
CXXFLAGS = -I./ -fpic
LDFLAGS = -L./

my_prog: $(LIBSRCS)
	g++ -o my_prog $(LIBOBJS)
