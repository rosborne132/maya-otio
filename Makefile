OTIO_FILE := tests/example.otio
MAYA_FILE := tests/example.ma

all: clean build

clean:
	@echo "Cleaning up build..."
	rm -rf build

ifneq (,$(wildcard $(OTIO_FILE)))
	rm tests/example.otio
endif

ifneq (,$(wildcard $(MAYA_FILE)))
	rm tests/example.ma
endif

generate:
	@echo "Generating files..."
	cmake -H. -Bbuild -G Ninja

build:
	make generate
	@echo "Building project..."
	cmake --build build
