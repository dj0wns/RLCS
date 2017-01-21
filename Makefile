COMPILER=g++
ARGS=-Wall -O3  -D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26 `pkg-config fuse --cflags` -std=c++11
LINKARGS=-Wall -O3 -lcurl `pkg-config fuse --libs` -std=c++11
OUTFILE=bin/rlcs
SRCDIR=src
OBJDIR=obj

all: $(OUTFILE)

clean:
	rm $(OBJDIR)/* $(OUTFILE)

$(OUTFILE): $(OBJDIR)/main.o $(OBJDIR)/Crypto.o $(OBJDIR)/FILE_IO.o  $(OBJDIR)/FUSE_Bindings.o $(OBJDIR)/FUSE_Definitions.o $(OBJDIR)/GDrive.o $(OBJDIR)/Cloud_Storage_Base_Class.o $(OBJDIR)/Mega.o $(OBJDIR)/OneDrive.o $(OBJDIR)/Dropbox.o
	$(COMPILER) $(OBJDIR)/*.o $(LINKARGS) -o $(OUTFILE)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(COMPILER) $(SRCDIR)/main.cpp $(ARGS) -c -o $(OBJDIR)/main.o

$(OBJDIR)/Crypto.o: $(SRCDIR)/Crypto.cpp
	$(COMPILER) $(SRCDIR)/Crypto.cpp $(ARGS) -c -o $(OBJDIR)/Crypto.o

$(OBJDIR)/FILE_IO.o: $(SRCDIR)/FILE_IO.cpp
	$(COMPILER) $(SRCDIR)/FILE_IO.cpp $(ARGS) -c -o $(OBJDIR)/FILE_IO.o

$(OBJDIR)/FUSE_Bindings.o: $(SRCDIR)/FUSE_Bindings.cpp
	$(COMPILER) $(SRCDIR)/FUSE_Bindings.cpp $(ARGS) -c -o $(OBJDIR)/FUSE_Bindings.o

$(OBJDIR)/FUSE_Definitions.o: $(SRCDIR)/FUSE_Definitions.cpp
	$(COMPILER) $(SRCDIR)/FUSE_Definitions.cpp $(ARGS) -c -o $(OBJDIR)/FUSE_Definitions.o

$(OBJDIR)/Cloud_Storage_Base_Class.o: $(SRCDIR)/Cloud_Storage_Base_Class.cpp
	$(COMPILER) $(SRCDIR)/Cloud_Storage_Base_Class.cpp $(ARGS) -c -o $(OBJDIR)/Cloud_Storage_Base_Class.o

$(OBJDIR)/GDrive.o: $(SRCDIR)/GDrive.cpp
	$(COMPILER) $(SRCDIR)/GDrive.cpp $(ARGS) -c -o $(OBJDIR)/GDrive.o

$(OBJDIR)/Mega.o: $(SRCDIR)/Mega.cpp
	$(COMPILER) $(SRCDIR)/Mega.cpp $(ARGS) -c -o $(OBJDIR)/Mega.o

$(OBJDIR)/OneDrive.o: $(SRCDIR)/OneDrive.cpp
	$(COMPILER) $(SRCDIR)/OneDrive.cpp $(ARGS) -c -o $(OBJDIR)/OneDrive.o

$(OBJDIR)/Dropbox.o: $(SRCDIR)/Dropbox.cpp
	$(COMPILER) $(SRCDIR)/Dropbox.cpp $(ARGS) -c -o $(OBJDIR)/Dropbox.o

