#!/usr/bin/env bash

set -eo pipefail

extension="dat"

for file in data/*."$extension"; do
    filename="${file%.*}"
    truncate -s 0 real_ans.ans

    ./../../build/matrix < $file -l > real_ans.ans

    first_line=$(head -n 1 "$filename".ans)
    second_line=$(head -n 1 real_ans.ans)

    if [ "$first_line" == "$second_line" ]; then
        echo "Test $file passed"
    else
        echo "Test $file failed"
        exit 0
    fi

done

rm -rf real_ans.ans

