.PHONY: clean All

All:
	@echo "----------Building project:[ consoleTest - Debug ]----------"
	@cd "consoleTest" && "$(MAKE)" -f  "consoleTest.mk"
clean:
	@echo "----------Cleaning project:[ consoleTest - Debug ]----------"
	@cd "consoleTest" && "$(MAKE)" -f  "consoleTest.mk" clean
