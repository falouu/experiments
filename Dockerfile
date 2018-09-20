FROM ubuntu:16.04

WORKDIR /workdir

RUN useradd -ms /bin/bash owner
RUN useradd -ms /bin/bash caller

ADD init.sh .
RUN chmod +x init.sh
ADD cmake-build-debug/linux_process_ids .

USER root
RUN chown owner:owner linux_process_ids

USER owner
RUN chmod 4701 linux_process_ids


USER caller
CMD bash init.sh