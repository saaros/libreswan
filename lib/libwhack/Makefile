# Libreswan library
# Copyright (C) 1998-2001  Henry Spencer.
# Copyright (C) 2003, 2004 Xelerance Corporation
# Copyright (C) 2012-2013 Paul Wouters <paul@libreswan.org>
# 
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.



LIBRESWANSRCDIR?=$(shell cd ../..; pwd)

include ${LIBRESWANSRCDIR}/Makefile.inc
include ${LIBRESWANSRCDIR}/Makefile.ver

MANDIR=$(MANTREE)/man3

SRCS=whacklib.c aliascomp.c

OBJS=${SRCS:.c=.o} 

KLIPSD=${LIBRESWANSRCDIR}/linux/include
KLIPSSRCDIR=${LIBRESWANSRCDIR}/linux/net/ipsec
MANSRCDIR=${LIBRESWANSRCDIR}/lib/libswan

VPATH+= ${KLIPSSRCDIR}

LIB=libwhack.a

# Original flags
INCLUDES=-I. -I${KLIPSSRCDIR} -I${KLIPSD} -I${LIBRESWANSRCDIR}
INCLUDES+=-I${LIBRESWANSRCDIR}/include 

CFLAGS+=${PORTINCLUDE} ${INCLUDES} 
CFLAGS+= $(USERCOMPILE) $(NSSFLAGS)
CFLAGS+= ${WERROR}

ifeq ($(USE_LABELED_IPSEC),true)
CFLAGS+= -DHAVE_LABELED_IPSEC
endif

ifeq ($(USE_DNSSEC),true)
CFLAGS+= -DDNSSEC
endif

ARFLAGS=crvs
MANS=

.PHONY:	all install clean l t lt tar check checkprograms

# we can't do tests with two conditions, but we can concatenate the strings
SHOULDWERESTART=${USE_OBJDIR}$(wildcard whacklib.c)
ifeq ($(SHOULDWERESTART),truewhacklib.c)
all programs clean install:
	cd ${LIBRESWANSRCDIR} && cd ${OBJDIRTOP}/lib/libwhack && make $@
else
all:	$(LIB) ${LIBL}
programs: $(LIB) ${LIBL}
clean:	cleanall
install: doinstall

endif

doinstall:
	@mkdir -p $(MANDIR)
	@for f in $(MANS) ; \
	do \
		$(INSTALL) $(INSTMANFLAGS) $(MANSRCDIR)/$$f $(MANDIR)/ipsec_$$f || exit 1 ; \
	done
	@$(LIBRESWANSRCDIR)/packaging/utils/manlink $(foreach man, $(MANS), ${MANSRCDIR}/$(man)) | \
	while read from to; \
	do \
		ln -s -f ipsec_$$from $(MANDIR)/$$to; \
	done


install_file_list:
	@for f in $(MANS) ; \
	do \
		echo $(MANDIR)/ipsec_$$f;\
	done;
	@$(LIBRESWANSRCDIR)/packaging/utils/manlink $(foreach man, $(MANS), ${MANSRCDIR}/$(man)) | \
	while read from to; \
	do \
		echo $(MANDIR)/$$to; \
	done

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $(LIB) $(OBJS)

$(OBJS):	$(HDRS)

cleanall:
	rm -rf ${OBJS} $(LIB) Makefile.depend

# Gather dependencies caused by explicit #includes within .c files
Makefile.depend: $(SRCS) $(LIBRESWANSRCDIR)/lib/libwhack/Makefile
	@(ls $(wildcard $(addprefix $(LIBRESWANSRCDIR)/lib/libwhack/,$(SRCS))) | grep '\.c' | xargs $(CC) -MM ${PORTINCLUDE} ${INCLUDES} ${ALLFLAGS} ) >Makefile.depend

-include Makefile.depend



