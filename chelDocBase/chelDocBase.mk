##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelDocBase
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chel/source/chelDoc
ProjectPath            :=C:/Users/Chel/source/chelDoc/chelDocBase
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).dll
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="chelDocBase.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW_GCC_7.1/mingw32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)chelTypes $(LibrarySwitch)chelMath 
ArLibs                 :=  "chelTypes.dll" "chelMath.dll" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../chelTypes/Debug $(LibraryPathSwitch)../chelMath/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW_GCC_7.1/mingw32/bin/ar.exe rcu
CXX      := C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
CC       := C:/MinGW_GCC_7.1/mingw32/bin/gcc.exe
CXXFLAGS :=  -g  -std=c++1z  -fconcepts  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW_GCC_7.1/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/CDXML_CDXML.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(ObjectSuffix) $(IntermediateDirectory)/Task_CTask.cpp$(ObjectSuffix) $(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "C:\Users\Chel\source\chelDoc/.build-debug"
	@echo rebuilt > "C:\Users\Chel\source\chelDoc/.build-debug/chelDocBase"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/CDXML_CDXML.cpp$(ObjectSuffix): CDXML/CDXML.cpp $(IntermediateDirectory)/CDXML_CDXML.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelDocBase/CDXML/CDXML.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CDXML_CDXML.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CDXML_CDXML.cpp$(DependSuffix): CDXML/CDXML.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CDXML_CDXML.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CDXML_CDXML.cpp$(DependSuffix) -MM CDXML/CDXML.cpp

$(IntermediateDirectory)/CDXML_CDXML.cpp$(PreprocessSuffix): CDXML/CDXML.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CDXML_CDXML.cpp$(PreprocessSuffix) CDXML/CDXML.cpp

$(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(ObjectSuffix): ConsoleInterface/IConsole.cpp $(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelDocBase/ConsoleInterface/IConsole.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(DependSuffix): ConsoleInterface/IConsole.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(DependSuffix) -MM ConsoleInterface/IConsole.cpp

$(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(PreprocessSuffix): ConsoleInterface/IConsole.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleInterface_IConsole.cpp$(PreprocessSuffix) ConsoleInterface/IConsole.cpp

$(IntermediateDirectory)/Task_CTask.cpp$(ObjectSuffix): Task/CTask.cpp $(IntermediateDirectory)/Task_CTask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelDocBase/Task/CTask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Task_CTask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Task_CTask.cpp$(DependSuffix): Task/CTask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Task_CTask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Task_CTask.cpp$(DependSuffix) -MM Task/CTask.cpp

$(IntermediateDirectory)/Task_CTask.cpp$(PreprocessSuffix): Task/CTask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Task_CTask.cpp$(PreprocessSuffix) Task/CTask.cpp

$(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(ObjectSuffix): CFGLoader/NCFGLoad.cpp $(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelDocBase/CFGLoader/NCFGLoad.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(DependSuffix): CFGLoader/NCFGLoad.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(DependSuffix) -MM CFGLoader/NCFGLoad.cpp

$(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(PreprocessSuffix): CFGLoader/NCFGLoad.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CFGLoader_NCFGLoad.cpp$(PreprocessSuffix) CFGLoader/NCFGLoad.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


