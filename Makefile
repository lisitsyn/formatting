default:
	@(mkdir -p build; cd build; cmake ..; make)

test: default
	@(cd build; ctest -VV)

clean:
	@(rm -rf build/*)

.PHONY: test
