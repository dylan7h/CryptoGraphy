export TARGET	:= CryptoGraphy
export TOPDIR	:= $(PWD)

all:
	@$(MAKE) -C $(TARGET) --no-print-directory

clean:
	@$(MAKE) -C $(TARGET) clean --no-print-directory

distclean:
	rm -rf build/*

run:
	@$(MAKE) -C $(TARGET) run --no-print-directory
	
info:
	@$(MAKE) -C $(TARGET) info --no-print-directory
	