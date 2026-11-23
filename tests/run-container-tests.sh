#!/bin/sh
set -eu
export LC_ALL=C
workdir=$(mktemp -d)
trap 'rm -rf "$workdir"' EXIT
cp -R /src/main.c /src/system /src/tests "$workdir"
cd "$workdir"

gcc --coverage -O0 -g -Wall -Wextra -Werror -Itests/fakes -Dmain=firmware_main -c main.c -o firmware.o
gcc --coverage -O0 -g -Wall -Wextra -Werror -Wno-unknown-pragmas -Itests/fakes -c system/system.c -o system.o
gcc --coverage -O0 -g -Wall -Wextra -Werror -Itests/fakes -c system/controllers/dma/dma.c -o dma.o
gcc --coverage -Wall -Wextra -Werror -I. -Itests/fakes tests/test_initialization.c \
  firmware.o system.o dma.o -o test_initialization
./test_initialization

for unit in firmware system dma; do
  report=$(gcov -b "$unit.gcno")
  printf '%s\n' "$report"
  line_percent=$(printf '%s\n' "$report" | awk -F '[:%]' '/^Lines executed:/{print $2; exit}')
  awk -v coverage="$line_percent" 'BEGIN { exit !(coverage ~ /^[0-9.]+$/ && coverage >= 95) }'
done
