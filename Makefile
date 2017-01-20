COMPILER=g++
ARGS=-Wall -O3
OUTFILE=bin/rlcs
SRCDIR=src
OBJDIR=obj

all: $(OUTFILE)

clean:
	rm $(OBJDIR)/* $(OUTFILE)

$(OUTFILE): $(OBJDIR)/main.o $(OBJDIR)/Crypto.o $(OBJDIR)/FILE_IO.o  $(OBJDIR)/FUSE_Bindings.o $(OBJDIR)/GDrive.o  $(OBJDIR)/Mega.o $(OBJDIR)/OneDrive.o $(OBJDIR)/Dropbox.o
	$(COMPILER) $(ARGS) -o $(OUTFILE) $(OBJDIR)/*.o

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(COMPILER) $(ARGS) -c -o $(OBJDIR)/main.o $(SRCDIR)/main.cpp

$(OBJDIR)/Crypto.o: $(SRCDIR)/Crypto.cpp
	$(COMPILER) $(ARGS) -c -o $(OBJDIR)/Crypto.o $(SRCDIR)/Crypto.cpp

$(OBJDIR)/FILE_IO.o: $(SRCDIR)/FILE_IO.cpp
	$(COMPILER) $(ARGS) -c -o $(OBJDIR)/FILE_IO.o $(SRCDIR)/FILE_IO.cpp

$(OBJDIR)/FUSE_Bindings.o: $(SRCDIR)/FUSE_Bindings.cpp
	$(COMPILER) $(ARGS) -c -o $(OBJDIR)/FUSE_Bindings.o $(SRCDIR)/FUSE_Bindings.cpp

$(OBJDIR)/GDrive.o: $(SRCDIR)/GDrive.cpp
	$(COMPILER) $(ARGS) -c -o $(OBJDIR)/GDrive.o $(SRCDIR)/GDrive.cpp

$(OBJDIR)/Mega.o: $(SRCDIR)/Mega.cpp
	$(COMPILER) $(ARGS) -c -o $(OBJDIR)/Mega.o $(SRCDIR)/Mega.cpp

$(OBJDIR)/OneDrive.o: $(SRCDIR)/OneDrive.cpp
	$(COMPILER) $(ARGS) -c -o $(OBJDIR)/OneDrive.o $(SRCDIR)/OneDrive.cpp

$(OBJDIR)/Dropbox.o: $(SRCDIR)/Dropbox.cpp
	$(COMPILER) $(ARGS) -c -o $(OBJDIR)/Dropbox.o $(SRCDIR)/Dropbox.cpp

