#============================================================
# Path of Build Product
#============================================================
BINDIR		:= $(TOPDIR)/build
OBJ_DIR		:= $(BINDIR)/obj/$(TARGET)
DEF_DIR		:= $(BINDIR)/dep/$(TARGET)
EXE_DIR		:= $(BINDIR)/exe
LIB_DIR		:= $(BINDIR)/lib
MAP_DIR		:= $(BINDIR)/map
ASM_DIR		:= $(BINDIR)/asm


#============================================================
# Path of Include directoies
#============================================================
INC_PATH	:= Include


#============================================================
# Path of Source lists
#============================================================
CSRCS		:= Source/main.c
CSRCS		:= Source/bignum_conv.c


#============================================================
# Path of Libraries
#============================================================
LIB_PATH	:=

#============================================================
# Name of Libraries
#============================================================
LIB_NAME	:=

#============================================================
# Convert Object & Denpendency file lists from Source Lists
# Add compiler option(-L, -l)
# (Must be Located at last line)
#============================================================
OBJS		:= $(addprefix $(OBJ_DIR)/, $(CSRCS:.c=.o))
OBJS		+= $(addprefix $(OBJ_DIR)/, $(CXXSRCS:.cpp=.o))
DEPS		:= $(addprefix $(DEF_DIR)/, $(CSRCS:.c=.d))
DEPS		+= $(addprefix $(DEF_DIR)/, $(CXXSRCS:.cpp=.d))
LIBS		:= $(addprefix -l, $(LIB_NAME))
LIB_DIR		:= $(addprefix -L , $(LIB_PATH))
INCS		:= $(addprefix -I , $(INC_PATH))
