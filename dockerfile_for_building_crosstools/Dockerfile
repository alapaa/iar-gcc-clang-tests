FROM gcc:latest
RUN apt update && \
    apt install -y build-essential flex bison texinfo help2man gawk libtool-bin
RUN mkdir /usr/src/crosstools
RUN mkdir /usr/src/crosstools-build
RUN mkdir /usr/local/crosstools
COPY crosstool-ng-1.28.0_rc1.tar.xz /usr/src/crosstools
WORKDIR /usr/src/crosstools
RUN tar xf crosstool-ng-1.28.0_rc1.tar.xz
WORKDIR crosstool-ng-1.28.0_rc1
RUN ./configure --prefix=/usr/local/crosstool
RUN make
RUN make install
ENV PATH="${PATH}:/usr/local/crosstool/bin"
RUN useradd -ms /bin/bash myuser
USER myuser
CMD bash
