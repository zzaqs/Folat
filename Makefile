FOLIPATH := /usr/local/bin/
FOLIDIR := /usr/local/bin/foli

.PHONY: all c i u

all: foli

foli: foli.c fmain.c finut.c
	gcc -O1 -Wall foli.c fmain.c finut.c -o foli

# clean
c:
	@echo "folmf [i]: Executing 'rm -f foli'."
	rm -f foli

# install
i:
	@echo "folmf [i]: Executing 'sudo cp foli $(FOLIPATH)'."
	sudo cp foli $(FOLIPATH)

# uninstall
u:
	@echo "folmf [i]: Executing 'sudo rm -f $(FOLIDIR)'."
	sudo rm -f $(FOLIDIR)
