# CMakeList.txt: projeto de CMake para D3DTutorial, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
add_executable (D3DTutorial "D3DTutorial.cpp" "D3DTutorial.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET D3DTutorial PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
