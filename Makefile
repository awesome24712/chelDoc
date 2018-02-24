.PHONY: clean All

All:
	@echo "----------Building project:[ chelGUI - Debug ]----------"
	@cd "chelGUI" && "$(MAKE)" -f  "chelGUI.mk"
clean:
	@echo "----------Cleaning project:[ chelGUI - Debug ]----------"
	@cd "chelGUI" && "$(MAKE)" -f  "chelGUI.mk" clean
