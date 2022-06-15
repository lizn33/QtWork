CXX = g++

LDFLAGS = -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
		-Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
		-lhiredis -lpthread -ldl

GRPC_CPP_PLUGIN_PATH ?= `which grpc_cpp_plugin`

all: main grpcProto/grpcProto.pb.cc grpcProto/grpcProto.grpc.pb.cc 

main: main.o server.o rediscon.o grpcser.o log.o socket.o\
		grpcProto/grpcProto.pb.o grpcProto/grpcProto.grpc.pb.o
	$(CXX) $^ $(LDFLAGS) -o $@ 
	
%.pb.cc: %.proto
	protoc -I. --cpp_out=. $<

%.grpc.pb.cc: %.proto
	protoc -I. --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<

clean:
	rm -f *.o */*.o 
