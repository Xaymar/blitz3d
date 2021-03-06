project(linker_lib)

add_library(${PROJECT_NAME} STATIC
	"dlltoexe.cpp"
	"dlltoexe.hpp"
	"image_util.cpp"
	"image_util.hpp"
	"linker.cpp"
	"linker.hpp"
)

target_link_libraries(${PROJECT_NAME}
	stdutil
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${PROJECT_SOURCE_DIR}
)

if (WIN32)
	target_compile_definitions(${PROJECT_NAME}
		PRIVATE
			_CRT_SECURE_NO_WARNINGS
			# windows.h
			WIN32_LEAN_AND_MEAN
			NOGPICAPMASKS
			NOVIRTUALKEYCODES
			NOWINMESSAGES
			NOWINSTYLES
			NOSYSMETRICS
			NOMENUS
			NOICONS
			NOKEYSTATES
			NOSYSCOMMANDS
			NORASTEROPS
			NOSHOWWINDOW
			NOATOM
			NOCLIPBOARD
			NOCOLOR
			NOCTLMGR
			NODRAWTEXT
			NOGDI
			NOKERNEL
			#NOUSER
			NONLS
			#NOMB
			NOMEMMGR
			NOMETAFILE
			NOMINMAX
			NOMSG
			NOOPENFILE
			NOSCROLL
			NOSERVICE
			NOSOUND
			NOTEXTMETRIC
			NOWH
			NOWINOFFSETS
			NOCOMM
			NOKANJI
			NOHELP
			NOPROFILER
			NODEFERWINDOWPOS
			NOMCX
			NOIME
			NOMDI
			NOINOUT
	)
endif()
