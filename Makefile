.PHONY: clean All

All:
	@echo "----------Building project:[ chelTypes - Debug ]----------"
	@cd "chelTypes" && "$(MAKE)" -f  "chelTypes.mk"
clean:
	@echo "----------Cleaning project:[ chelTypes - Debug ]----------"
	@cd "chelTypes" && "$(MAKE)" -f  "chelTypes.mk" clean
