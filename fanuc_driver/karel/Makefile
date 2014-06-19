
CC=ktrans.exe
SUPPORT_VER?=V7.70-1
CFLAGS=/ver $(SUPPORT_VER)

SRCS=\
	libind_hdr.kl \
	libind_log.kl \
	libind_mth.kl \
	libind_pkt.kl \
	libind_rs.kl  \
	libssock.kl   \
	ros_relay.kl  \
	ros_state.kl

OBJS=$(SRCS:.kl=.pc)

.PHONY: clean

all: $(OBJS)

clean:
	@rm -f $(OBJS)

%.pc: %.kl
	@echo ">>> Building $^"
	@$(CC) $^ $(CFLAGS)
	@echo ""
