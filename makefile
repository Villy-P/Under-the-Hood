.ONESHELL:

reset:
	rmdir build
	mkdir build
	cd build
	cmake -GNinja ..

run-hashmap:
	ninja -C build
ifeq ($(OS),Windows_NT)
	.\bin\HASHMAP.exe
else
	./bin/HASHMAP.exe
endif