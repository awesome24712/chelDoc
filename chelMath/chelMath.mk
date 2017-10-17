##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelMath
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chel/source/chelDoc
ProjectPath            :=C:/Users/Chel/source/chelDoc/chelMath
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chel
Date                   :=30/09/2017
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
ObjectsFileList        :="chelMath.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW_GCC_7.1/mingw32/bin/windres.exe
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
AR       := C:/MinGW_GCC_7.1/mingw32/bin/ar.exe rcu
CXX      := C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
CC       := C:/MinGW_GCC_7.1/mingw32/bin/gcc.exe
CXXFLAGS :=  -g  -std=c++14  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW_GCC_7.1/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/perfTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/Vector_Vector.cpp$(ObjectSuffix) $(IntermediateDirectory)/Vector_Vector2D.cpp$(ObjectSuffix) $(IntermediateDirectory)/BitBoard_BitBoard.cpp$(ObjectSuffix) $(IntermediateDirectory)/Coord_Coord2D.cpp$(ObjectSuffix) $(IntermediateDirectory)/Color_Color.cpp$(ObjectSuffix) $(IntermediateDirectory)/Rand_Rand.cpp$(ObjectSuffix) 



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
	@echo rebuilt > "C:\Users\Chel\source\chelDoc/.build-debug/chelMath"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/perfTest.cpp$(ObjectSuffix): perfTest.cpp $(IntermediateDirectory)/perfTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelMath/perfTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/perfTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/perfTest.cpp$(DependSuffix): perfTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/perfTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/perfTest.cpp$(DependSuffix) -MM perfTest.cpp

$(IntermediateDirectory)/perfTest.cpp$(PreprocessSuffix): perfTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/perfTest.cpp$(PreprocessSuffix) perfTest.cpp

$(IntermediateDirectory)/Vector_Vector.cpp$(ObjectSuffix): Vector/Vector.cpp $(IntermediateDirectory)/Vector_Vector.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelMath/Vector/Vector.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vector_Vector.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vector_Vector.cpp$(DependSuffix): Vector/Vector.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vector_Vector.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Vector_Vector.cpp$(DependSuffix) -MM Vector/Vector.cpp

$(IntermediateDirectory)/Vector_Vector.cpp$(PreprocessSuffix): Vector/Vector.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vector_Vector.cpp$(PreprocessSuffix) Vector/Vector.cpp

$(IntermediateDirectory)/Vector_Vector2D.cpp$(ObjectSuffix): Vector/Vector2D.cpp $(IntermediateDirectory)/Vector_Vector2D.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelMath/Vector/Vector2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vector_Vector2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vector_Vector2D.cpp$(DependSuffix): Vector/Vector2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vector_Vector2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Vector_Vector2D.cpp$(DependSuffix) -MM Vector/Vector2D.cpp

$(IntermediateDirectory)/Vector_Vector2D.cpp$(PreprocessSuffix): Vector/Vector2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vector_Vector2D.cpp$(PreprocessSuffix) Vector/Vector2D.cpp

$(IntermediateDirectory)/BitBoard_BitBoard.cpp$(ObjectSuffix): BitBoard/BitBoard.cpp $(IntermediateDirectory)/BitBoard_BitBoard.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelMath/BitBoard/BitBoard.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BitBoard_BitBoard.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BitBoard_BitBoard.cpp$(DependSuffix): BitBoard/BitBoard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BitBoard_BitBoard.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BitBoard_BitBoard.cpp$(DependSuffix) -MM BitBoard/BitBoard.cpp

$(IntermediateDirectory)/BitBoard_BitBoard.cpp$(PreprocessSuffix): BitBoard/BitBoard.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BitBoard_BitBoard.cpp$(PreprocessSuffix) BitBoard/BitBoard.cpp

$(IntermediateDirectory)/Coord_Coord2D.cpp$(ObjectSuffix): Coord/Coord2D.cpp $(IntermediateDirectory)/Coord_Coord2D.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelMath/Coord/Coord2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Coord_Coord2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Coord_Coord2D.cpp$(DependSuffix): Coord/Coord2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Coord_Coord2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Coord_Coord2D.cpp$(DependSuffix) -MM Coord/Coord2D.cpp

$(IntermediateDirectory)/Coord_Coord2D.cpp$(PreprocessSuffix): Coord/Coord2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Coord_Coord2D.cpp$(PreprocessSuffix) Coord/Coord2D.cpp

$(IntermediateDirectory)/Color_Color.cpp$(ObjectSuffix): Color/Color.cpp $(IntermediateDirectory)/Color_Color.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelMath/Color/Color.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Color_Color.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Color_Color.cpp$(DependSuffix): Color/Color.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Color_Color.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Color_Color.cpp$(DependSuffix) -MM Color/Color.cpp

$(IntermediateDirectory)/Color_Color.cpp$(PreprocessSuffix): Color/Color.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Color_Color.cpp$(PreprocessSuffix) Color/Color.cpp

$(IntermediateDirectory)/Rand_Rand.cpp$(ObjectSuffix): Rand/Rand.cpp $(IntermediateDirectory)/Rand_Rand.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelMath/Rand/Rand.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Rand_Rand.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Rand_Rand.cpp$(DependSuffix): Rand/Rand.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Rand_Rand.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Rand_Rand.cpp$(DependSuffix) -MM Rand/Rand.cpp

$(IntermediateDirectory)/Rand_Rand.cpp$(PreprocessSuffix): Rand/Rand.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Rand_Rand.cpp$(PreprocessSuffix) Rand/Rand.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


