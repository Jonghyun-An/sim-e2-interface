# ASN.1 library linkage regression

After building `e2sim_shared` and, with `DEV_PKG=1`, `e2sim_static`, compile
`check_asn1_linkage.c` against each library. The program references the public
E2AP PDU descriptor and releases a PDU through the ASN.1 runtime. A missing
ASN.1 object set causes a link failure before the program can run.

For example, from `e2sim`, with libraries in `build`:

```sh
cc -Iasn1c tests/check_asn1_linkage.c -Lbuild \
  -Wl,-rpath,"$PWD/build" -le2sim_shared -lsctp -lstdc++ -pthread \
  -o build/check-asn1-shared
build/check-asn1-shared
cc -Iasn1c tests/check_asn1_linkage.c build/libe2sim.a \
  -lsctp -lstdc++ -pthread -o build/check-asn1-static
build/check-asn1-static
```

This checks the library's exported codec dependencies; it does not connect to a RIC.
