LBITS := $(shell getconf LONG_BIT)
PTHREAD_PATH=
ifeq ($(LBITS),64)
	PTHREAD_PATH=/usr/lib/x86_64-linux-gnu
else
	PTHREAD_PATH=/usr/lib/i386-linux-gnu
endif
#-GCC-------------------------------------------------
GCC=gcc
GCC_FLAGS=-Wall -Wextra -O3
GCC_LIBS=-lgenerics
GCC_STATIC_LIBS=$(PTHREAD_PATH)/libpthread.a /usr/lib/libgenerics.a
GCC_SHARED_LIBS=$(PTHREAD_PATH)/libpthread.so /usr/lib/libgenerics.so

#-VARIABLE--------------------------------------------
SRC_PATH=src
HEADER_PATH=include
BUILD_PATH=build

SOURCES=$(wildcard $(SRC_PATH)/*.c)
HEADERS=$(wildcard $(HEADER_PATH)/*.h)

OBJ_PATH=$(BUILD_PATH)/obj
TK_OBJ=$(OBJ_PATH)/tk.o

# libs
LIB_STATIC_PATH=$(BUILD_PATH)/lib/static
LIB_STATIC=$(LIB_STATIC_PATH)/libtk.a

LIB_SHARED_PATH=$(BUILD_PATH)/lib/shared
LIB_SHARED=$(LIB_SHARED_PATH)/libtk.so

# install
INSTALL_HEADER_PATH=/usr/include/tk.h
INSTALL_STATIC_PATH=/usr/lib/libtk.a
INSTALL_SHARED_PATH=/usr/lib/libtk.so

# doc
DOC_PATH=doc
DOX_LATEX=$(DOC_PATH)/doxygen/latex
DOX=$(DOX_LATEX) $(DOC_PATH)/html $(DOC_PATH)/man

#-OBJ-------------------------------------------------

all: $(TK_OBJ)

$(BUILD_PATH):
	[ -d $(BUILD_PATH) ] || mkdir -p $(BUILD_PATH)

$(OBJ_PATH): $(BUILD_PATH)
	[ -d $(OBJ_PATH) ] || mkdir -p $(OBJ_PATH)

$(TK_OBJ): $(OBJ_PATH) $(SOURCES) $(HEADERS)
	$(GCC) -c -o $(TK_OBJ) $(SOURCES) -I $(HEADER_PATH) $(GCC_FLAGS) $(GCC_LIBS)

#-LIBRARIES-------------------------------------------

$(LIB_STATIC_PATH):
	[ -d $(LIB_STATIC_PATH) ] || mkdir -p $(LIB_STATIC_PATH)

$(LIB_SHARED_PATH):
	[ -d $(LIB_SHARED_PATH) ] || mkdir -p $(LIB_SHARED_PATH)

$(LIB_STATIC): $(LIB_STATIC_PATH) $(TK_OBJ)
	ar -cvq $(LIB_STATIC) $(TK_OBJ) $(GCC_STATIC_LIBS)

$(LIB_SHARED): $(LIB_SHARED_PATH) $(TK_OBJ)
	$(GCC) -fPIC -c $(SOURCES) -I $(HEADER_PATH) $(GCC_FLAGS) $(GCC_LIBS)
	mv *.o $(LIB_SHARED_PATH)
	$(GCC) -shared -Wl,-soname,libtk.so -o $(LIB_SHARED) $(LIB_SHARED_PATH)/*.o $(GCC_SHARED_LIBS)

#-INSTALLATION----------------------------------------
install: $(HEADERS) $(LIB_STATIC) $(LIB_SHARED)
	cp $(HEADERS) $(INSTALL_HEADER_PATH)
	cp $(LIB_STATIC) $(INSTALL_STATIC_PATH)
	cp $(LIB_SHARED) $(INSTALL_SHARED_PATH)

uninstall:
	rm $(INSTALL_HEADER_PATH)
	rm $(INSTALL_STATIC_PATH)
	rm $(INSTALL_SHARED_PATH)

#-DOC-------------------------------------------------
$(DOX): .dox $(SOURCES) $(HEADERS)
	doxygen .dox

$(DOC_PATH)/dox.pdf: $(DOX_LATEX)
	make -C $(DOX_LATEX)
	cp $(DOX_LATEX)/refman.pdf $(DOC_PATH)/doc.pdf
