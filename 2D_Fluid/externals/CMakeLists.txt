## IMGUI
include_directories(imgui)
include_directories(imgui/examples)

set(IMGUI_HEADER
  imgui/imgui.h
  imgui/imconfig.h
  imgui/imgui_internal.h
  imgui/imstb_rectpack.h
  imgui/imstb_textedit.h
  imgui/imstb_truetype.h
)
set(IMGUI_SOURCE
  imgui/imgui.cpp
  imgui/imgui_demo.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_widgets.cpp
)

add_library(imgui STATIC
  ${IMGUI_HEADER}
  ${IMGUI_SOURCE}
)
