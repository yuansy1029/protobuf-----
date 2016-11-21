LIBDIR=/usr/local/lib

CXXFLAGS=-g -Wall -O0 -pthread
LDFLAGS=-lprotobuf -lz -lpthread -Wl,-rpath -Wl,$(LIBDIR)

BINARIES=codec_test
TARGETS=$(BINARIES)

# comment out following line if you have boost installed
TARGETS=codec_test

all: $(TARGETS)

whole: $(BINARIES)

codec_test: query.pb.h query.pb.cc codec.h codec_test.cc


$(BINARIES):
	g++ $(CXXFLAGS) $(filter %.cc,$^) -o $@ $(LDFLAGS)

query.pb.h query.pb.cc: query.proto
	protoc --cpp_out . $<

test: codec_test
	./codec_test

clean:
	rm -f query.pb.*
	rm -f $(BINARIES)

