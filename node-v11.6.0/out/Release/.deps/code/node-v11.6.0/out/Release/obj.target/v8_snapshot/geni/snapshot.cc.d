cmd_/code/node-v11.6.0/out/Release/obj.target/v8_snapshot/geni/snapshot.cc := LD_LIBRARY_PATH=/code/node-v11.6.0/out/Release/lib.host:/code/node-v11.6.0/out/Release/lib.target:$$LD_LIBRARY_PATH; export LD_LIBRARY_PATH; cd ../deps/v8/gypfiles; mkdir -p /code/node-v11.6.0/out/Release/obj.target/v8_snapshot/geni; "/code/node-v11.6.0/out/Release/mksnapshot" --turbo_instruction_scheduling --startup_src "/code/node-v11.6.0/out/Release/obj.target/v8_snapshot/geni/snapshot.cc"
