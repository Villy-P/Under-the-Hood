.ONESHELL:

reset:
	rmdir build
	mkdir build
	cd build
	cmake -GNinja ..

run-hashmap:
	ninja -C build
ifeq ($(OS),Windows_NT)
	.\HASHMAP.exe
else
	./HASHMAP.exe
endif