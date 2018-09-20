#!/usr/bin/env bash

set -o errexit -o pipefail

docker build --rm=false -t linux_process_ids .
docker run -it --rm linux_process_ids



echo


