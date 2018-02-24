##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelTester
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chel/source/chelDoc
ProjectPath            :=C:/Users/Chel/source/chelDoc/chelTester
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chel
Date                   :=22/02/2018
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
ObjectsFileList        :="chelTester.txt"
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
CXXFLAGS :=  -g  -fconcepts  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g  $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW_GCC_7.1/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/CTestCase.cpp$(ObjectSuffix) $(IntermediateDirectory)/Commands.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(ObjectSuffix) $(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(ObjectSuffix) 



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
	@echo rebuilt > "C:\Users\Chel\source\chelDoc/.build-debug/chelTester"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/CTestCase.cpp$(ObjectSuffix): CTestCase.cpp $(IntermediateDirectory)/CTestCase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/CTestCase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CTestCase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CTestCase.cpp$(DependSuffix): CTestCase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CTestCase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CTestCase.cpp$(DependSuffix) -MM CTestCase.cpp

$(IntermediateDirectory)/CTestCase.cpp$(PreprocessSuffix): CTestCase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CTestCase.cpp$(PreprocessSuffix) CTestCase.cpp

$(IntermediateDirectory)/Commands.cpp$(ObjectSuffix): Commands.cpp $(IntermediateDirectory)/Commands.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/Commands.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Commands.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Commands.cpp$(DependSuffix): Commands.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Commands.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Commands.cpp$(DependSuffix) -MM Commands.cpp

$(IntermediateDirectory)/Commands.cpp$(PreprocessSuffix): Commands.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Commands.cpp$(PreprocessSuffix) Commands.cpp

$(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(ObjectSuffix): Test/Test_CUrDblLkLst.cpp $(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/Test/Test_CUrDblLkLst.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(DependSuffix): Test/Test_CUrDblLkLst.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(DependSuffix) -MM Test/Test_CUrDblLkLst.cpp

$(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(PreprocessSuffix): Test/Test_CUrDblLkLst.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_Test_CUrDblLkLst.cpp$(PreprocessSuffix) Test/Test_CUrDblLkLst.cpp

$(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(ObjectSuffix): Init/chelTesterInitialize.cpp $(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/Init/chelTesterInitialize.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(DependSuffix): Init/chelTesterInitialize.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(DependSuffix) -MM Init/chelTesterInitialize.cpp

$(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(PreprocessSuffix): Init/chelTesterInitialize.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Init_chelTesterInitialize.cpp$(PreprocessSuffix) Init/chelTesterInitialize.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


