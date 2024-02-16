
TARGET = openlands

CC ?= gcc
SRC_DIR := src
OBJ_DIR := build
GSRC_DIR := $(SRC_DIR)/generated
RES_DIR := res

RES_FILES := $(shell find $(RES_DIR) -type f)
GSRC_FILES := $(patsubst $(RES_DIR)/%,$(GSRC_DIR)/res_%.c,$(RES_FILES))
SRC_FILES := $(shell find $(SRC_DIR) -type f -name "*.c" -not -path "$(GSRC_DIR)*")
C_FILES := $(SRC_FILES) $(GSRC_FILES) 

OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES))
DEP_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.d,$(C_FILES))

SRC_SDIRS := $(shell find $(SRC_DIR) -type d -not -path "$(GSRC_DIR)*")
OBJ_SDIRS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC_SDIRS)) 
OBJ_SDIRS += $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(GSRC_DIR))

EXTRA_DIRS := $(OBJ_SDIRS) $(GSRC_DIR)

.PHONY: clean all

CFLAGS += -Wall -Wextra -pedantic -std=c11 -O3
LDFLAGS += -lraylib

all: $(TARGET)

$(TARGET): $(EXTRA_DIRS) $(C_FILES) $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -MD $(CFLAGS) -c $< -o $@

$(GSRC_DIR)/res_%.c: $(RES_DIR)/%
	python3 tools/embed.py $< $@ $(RES_DIR)

$(EXTRA_DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(GSRC_DIR)

-include $(DEP_FILES)
