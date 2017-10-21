.PHONY: clean All

All:
	@echo "----------Building project:[ chelDocBase - Debug ]----------"
	@cd "chelDocBase" && "$(MAKE)" -f  "chelDocBase.mk"
clean:
	@echo "----------Cleaning project:[ chelDocBase - Debug ]----------"
	@cd "chelDocBase" && "$(MAKE)" -f  "chelDocBase.mk" clean
