CC = g++
CXX = g++
CXXFLAGS = -std=c++17

SRCS = $(wildcard src/*.cpp)
OBJS = $(addprefix build/objects/,$(notdir $(SRCS:.cpp=.o)))
PDBS = $(addprefix build/pdbs/,$(notdir $(SRCS:.cpp=.pdb)))
LIBS = $(addprefix build/libs/,libapp.a)

build/app: $(OBJS) $(LIBS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $@ -Lbuild/libs -lapp

build/objects/%.o: src/%.cpp | build/objects
		$(CXX) $(CXXFLAGS) -c $< -o $@

build/pdbs/%.pdb: build/objects/%.o | build/pdbs
		$(CXX) $(CXXFLAGS) -g -o $@ -c $<

build/libs/libapp.a: $(OBJS) $(PDBS) | build/libs
		ar rcs $@ $(OBJS)

build/objects:
		mkdir -p $@

build/pdbs:
		mkdir -p $@

build/libs:
		mkdir -p $@

clean:
		rm -rf build