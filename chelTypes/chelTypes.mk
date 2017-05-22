##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelTypes
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Awesome/chelDoc
ProjectPath            :=C:/Users/Awesome/chelDoc/chelTypes
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Awesome
Date                   :=19/05/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="chelTypes.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g  -std=c++14  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
WXWIN:=C:/wxWidgets
WXCFG:=gcc_dll/mswu
Objects0=$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix) $(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix) $(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "C:\Users\Awesome\chelDoc/.build-debug"
	@echo rebuilt > "C:\Users\Awesome\chelDoc/.build-debug/chelTypes"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix): String/String.cpp $(IntermediateDirectory)/String_String.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Awesome/chelDoc/chelTypes/String/String.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/String_String.cpp$(DependSuffix): String/String.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/String_String.cpp$(DependSuffix) -MM String/String.cpp

$(IntermediateDirectory)/String_String.cpp$(PreprocessSuffix): String/String.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/String_String.cpp$(PreprocessSuffix) String/String.cpp

$(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix): DebugTools/Assertions.cpp $(IntermediateDirectory)/DebugTools_Assertions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Awesome/chelDoc/chelTypes/DebugTools/Assertions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DebugTools_Assertions.cpp$(DependSuffix): DebugTools/Assertions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DebugTools_Assertions.cpp$(DependSuffix) -MM DebugTools/Assertions.cpp

$(IntermediateDirectory)/DebugTools_Assertions.cpp$(PreprocessSuffix): DebugTools/Assertions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DebugTools_Assertions.cpp$(PreprocessSuffix) DebugTools/Assertions.cpp

$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(ObjectSuffix): Templates/Fields/CBitfield.cpp $(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Awesome/chelDoc/chelTypes/Templates/Fields/CBitfield.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(DependSuffix): Templates/Fields/CBitfield.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(DependSuffix) -MM Templates/Fields/CBitfield.cpp

$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(PreprocessSuffix): Templates/Fields/CBitfield.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(PreprocessSuffix) Templates/Fields/CBitfield.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


