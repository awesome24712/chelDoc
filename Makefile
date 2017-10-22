.PHONY: clean All

All:
	@echo "----------Building project:[ chelConsole - Debug ]----------"
	@cd "chelConsole" && "$(MAKE)" -f  "chelConsole.mk"
clean:
	@echo "----------Cleaning project:[ chelConsole - Debug ]----------"
	@cd "chelConsole" && "$(MAKE)" -f  "chelConsole.mk" clean
