CC = zig cc
CXX = zig c++
CXXFLAGS = -std=c++17

SRCS = src/Square.cpp src/Circle.cpp src/main.cpp
OBJS = $(addprefix build/objects/,$(notdir $(SRCS:.cpp=.o)))
PDBS = $(addprefix build/pdbs/,$(notdir $(SRCS:.cpp=.pdb)))
LIBS = $(addprefix build/libs/,libapp.a)

build/app.exe: $(OBJS) $(LIBS)
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

win_clean:
		del /Q /F build\libs\* build\objects\* build\pdbs\* build\* *.o *.pdb *.a *.exe *.lib