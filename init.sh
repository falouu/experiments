#!/usr/bin/env bash

executable="linux_process_ids"

echo
echo ">>> Running <<<"
echo

echo ">> Executable: "
ls -l "${executable}"
echo

echo ">> Owner: "
id owner
echo

echo ">> Me: "
id
echo

bash