##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelTUI
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chel/source/chelDoc
ProjectPath            :=C:/Users/Chel/source/chelDoc/chelTUI
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chel
Date                   :=22/10/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW_GCC_7.1/mingw32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="chelTUI.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW_GCC_7.1/mingw32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)chelTypes $(LibrarySwitch)chelMath $(LibrarySwitch)chelDocBase $(LibrarySwitch)chelInterpBase $(LibrarySwitch)chelConsole $(LibrarySwitch)chelProjectScanner $(LibrarySwitch)chelWeb $(LibrarySwitch)chelInterp $(LibrarySwitch)chelDoc 
ArLibs                 :=  "chelTypes.dll" "chelMath.dll" "chelDocBase.dll" "chelInterpBase.dll" "chelConsole.dll" "chelProjectScanner.dll" "chelWeb.dll" "chelInterp.dll" "chelDoc.dll" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../chelTypes/Debug $(LibraryPathSwitch)../chelMath/Debug $(LibraryPathSwitch)../chelDocBase/Debug $(LibraryPathSwitch)../chelInterpBase/Debug $(LibraryPathSwitch)../chelConsole/Debug $(LibraryPathSwitch)../chelProjectScanner/Debug $(LibraryPathSwitch)../chelWeb/Debug $(LibraryPathSwitch)../chelInterp/Debug $(LibraryPathSwitch)../chelDoc/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW_GCC_7.1/mingw32/bin/ar.exe rcu
CXX      := C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
CC       := C:/MinGW_GCC_7.1/mingw32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall -std=c++1z  -fconcepts  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW_GCC_7.1/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d "..\.build-debug\chelMath" "..\.build-debug\chelTypes" "..\.build-debug\chelDocBase" "..\.build-debug\chelConsole" "..\.build-debug\chelProjectScanner" "..\.build-debug\chelInterpBase" "..\.build-debug\chelInterp" "..\.build-debug\chelWeb" "..\.build-debug\chelDoc" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

"..\.build-debug\chelMath":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelMath"


"..\.build-debug\chelTypes":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelTypes"


"..\.build-debug\chelDocBase":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelDocBase"


"..\.build-debug\chelConsole":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelConsole"


"..\.build-debug\chelProjectScanner":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelProjectScanner"


"..\.build-debug\chelInterpBase":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelInterpBase"


"..\.build-debug\chelInterp":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelInterp"


"..\.build-debug\chelWeb":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelWeb"


"..\.build-debug\chelDoc":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\chelDoc"




MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTUI/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


