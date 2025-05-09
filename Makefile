build:
	@CGO_ENABLED=0 $(shell go env GOPATH)/bin/gobind -lang=go,objc -outdir=./target/ios -tags="no_cgo,ios,ios_simulator,no_libproc,ios_cpu" ./clash
	@CGO_ENABLED=0 $(shell go env GOPATH)/bin/gobind -lang=go,java -outdir=./target/android -tags="no_cgo,android,no_libproc" ./clash
