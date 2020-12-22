FROM gcc:10.2.0

WORKDIR /usr/src/app

COPY . .

RUN make

CMD [ "./main" ]
