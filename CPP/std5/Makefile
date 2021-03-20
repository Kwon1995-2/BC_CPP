#### By geodb
#

CC = gcc
CC_FLAG=-O2
LIBS = -pthread

#Object linkage definition

mysvr_obj = server.o

all : mysvr

mysvr : $(mysvr_obj)
	@echo Linking objects to tets
	$(CC) -o mysvr $(mysvr_obj) $(LIBS)

clean :
	@echo Cleaning intermediate files
	@rm -f $(mysvr_obj) 
