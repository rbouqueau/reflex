BIN?=bin

$(BIN)/reflex.exe: $(BIN)/main.o $(BIN)/object1.o $(BIN)/object2.o $(BIN)/registry.o

$(BIN)/%.exe:
	@mkdir -p $(dir $@)
	$(CXX) -o "$@" $^ $(LDFLAGS)

$(BIN)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) "$<" -c $(CFLAGS) -o "$(BIN)/$*.deps" -MM -MT "$(BIN)/$*.o"
	$(CXX) "$<" -c $(CFLAGS) -o "$@" 

clean:
	rm -rf $(BIN)
	mkdir $(BIN)
