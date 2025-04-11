all: cmus/cmus

unexport MAKEFLAGS

cmus/cmus: configure_done
	(cd cmus && make)

configure_done: Makefile
	(cd cmus && \
	./configure prefix= \
	            CROSS=${CROSS_DEV_PREFIX} \
	            LDFLAGS="${LDLIBS} ${LDFLAGS}" \
	) && touch $@

.PHONY: fio/make_run
.NOTPARALLEL: fio/make_run configure_done
