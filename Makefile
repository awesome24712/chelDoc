.PHONY: clean All

All:
	@echo "----------Building project:[ chelMath - Debug ]----------"
	@cd "chelMath" && "$(MAKE)" -f  "chelMath.mk"
	@echo "----------Building project:[ chelTypes - Debug ]----------"
	@cd "chelTypes" && "$(MAKE)" -f  "chelTypes.mk"
	@echo "----------Building project:[ chelDocBase - Debug ]----------"
	@cd "chelDocBase" && "$(MAKE)" -f  "chelDocBase.mk"
	@echo "----------Building project:[ chelConsole - Debug ]----------"
	@cd "chelConsole" && "$(MAKE)" -f  "chelConsole.mk"
	@echo "----------Building project:[ chelProjectScanner - Debug ]----------"
	@cd "chelProjectScanner" && "$(MAKE)" -f  "chelProjectScanner.mk"
	@echo "----------Building project:[ chelInterpBase - Debug ]----------"
	@cd "chelInterpBase" && "$(MAKE)" -f  "chelInterpBase.mk"
	@echo "----------Building project:[ chelInterp - Debug ]----------"
	@cd "chelInterp" && "$(MAKE)" -f  "chelInterp.mk"
	@echo "----------Building project:[ chelWeb - Debug ]----------"
	@cd "chelWeb" && "$(MAKE)" -f  "chelWeb.mk"
	@echo "----------Building project:[ chelDoc - Debug ]----------"
	@cd "chelDoc" && "$(MAKE)" -f  "chelDoc.mk"
	@echo "----------Building project:[ chelTUI - Debug ]----------"
	@cd "chelTUI" && "$(MAKE)" -f  "chelTUI.mk"
clean:
	@echo "----------Cleaning project:[ chelMath - Debug ]----------"
	@cd "chelMath" && "$(MAKE)" -f  "chelMath.mk"  clean
	@echo "----------Cleaning project:[ chelTypes - Debug ]----------"
	@cd "chelTypes" && "$(MAKE)" -f  "chelTypes.mk"  clean
	@echo "----------Cleaning project:[ chelDocBase - Debug ]----------"
	@cd "chelDocBase" && "$(MAKE)" -f  "chelDocBase.mk"  clean
	@echo "----------Cleaning project:[ chelConsole - Debug ]----------"
	@cd "chelConsole" && "$(MAKE)" -f  "chelConsole.mk"  clean
	@echo "----------Cleaning project:[ chelProjectScanner - Debug ]----------"
	@cd "chelProjectScanner" && "$(MAKE)" -f  "chelProjectScanner.mk"  clean
	@echo "----------Cleaning project:[ chelInterpBase - Debug ]----------"
	@cd "chelInterpBase" && "$(MAKE)" -f  "chelInterpBase.mk"  clean
	@echo "----------Cleaning project:[ chelInterp - Debug ]----------"
	@cd "chelInterp" && "$(MAKE)" -f  "chelInterp.mk"  clean
	@echo "----------Cleaning project:[ chelWeb - Debug ]----------"
	@cd "chelWeb" && "$(MAKE)" -f  "chelWeb.mk"  clean
	@echo "----------Cleaning project:[ chelDoc - Debug ]----------"
	@cd "chelDoc" && "$(MAKE)" -f  "chelDoc.mk"  clean
	@echo "----------Cleaning project:[ chelTUI - Debug ]----------"
	@cd "chelTUI" && "$(MAKE)" -f  "chelTUI.mk" clean
