cmake_minimum_required (VERSION 3.12)


add_custom_target(fonts)

set(DESTINATION ../app/src/fonts)

function(add_font_target PATH NAME STYLE SIZES)

	foreach(SIZE ${SIZES})
		set(FONT_TARGET font_${NAME}_${STYLE}_${SIZE})
		add_custom_target(${FONT_TARGET}
			COMMAND lv_font_conv --bpp=8 --size=${SIZE}
			--output=${DESTINATION}/${NAME}_${STYLE}_${SIZE}.c
			--format=lvgl
			--font=${PATH} --range=0x20-0x7F
			WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
			)

		add_dependencies(fonts ${FONT_TARGET})
	endforeach()

endfunction()

function(add_font_symbol_target PATH NAME STYLE SIZES)

	set(FONT_AWESOME_PATH "fontawesome-free-5.15.4-desktop/otfs")
	set(FONT_AWESOME_SOLID "Font Awesome 5 Free-Solid-900.otf")
	set(FONT_AWESOME_REGULAR "Font Awesome 5 Free-Regular-400.otf")
	set(FONT_AWESOME_BRANDS "Font Awesome 5 Brands-Regular-400.otf")


	 #0xf8a2 -- newline?
	set(SOLID_ICONS 0xf00b,0xf00c,0xf00d,0xf011,0xf013,0xf015)
	set(SOLID_ICONS ${SOLID_ICONS},0xf019,0xf01c,0xf021,0xf304,0xf04b,0xf04c)
	set(SOLID_ICONS ${SOLID_ICONS},0xf04d,0xf052,0xf053,0xf054,0xf067,0xf068)
	set(SOLID_ICONS ${SOLID_ICONS},0xf06e,0xf070,0xf071,0xf077,0xf078,0xf079)
	set(SOLID_ICONS ${SOLID_ICONS},0xf07b,0xf093,0xf0c4,0xf0c5,0xf0c7,0xf0c9)
	set(SOLID_ICONS ${SOLID_ICONS},0xf0e7,0xf0ea,0xf11c,0xf15b,0xf1eb,0xf240)
	set(SOLID_ICONS ${SOLID_ICONS},0xf241,0xf242,0xf243,0xf244,0xf2ed,0xf1fe)
	set(SOLID_ICONS ${SOLID_ICONS},0xf55a,0xf7c2,0xf060,0xf061,0xf062,0xf1de)
	set(SOLID_ICONS ${SOLID_ICONS},0xf063,0xf110,0xf0ad,0xf12d,0xf080,0xf129)
	set(SOLID_ICONS ${SOLID_ICONS},0xf201,0xf200,0xf017,0xf15c,0xf1c9,0xf1c5)
	set(SOLID_ICONS ${SOLID_ICONS},0xf573,0xf07c,0xf0c2,0xf381,0xf382,0xf83e)
	set(SOLID_ICONS ${SOLID_ICONS},0xf01e,0xf552,0xf084,0xf035,0xf009,0xf121)
	set(SOLID_ICONS ${SOLID_ICONS},0xf2db,0xf538,0xf185,0xf362,0xf35d,0xf128)
	set(SOLID_ICONS ${SOLID_ICONS},0xf12a,0xf567,0xf11a,0xf5a5,0xf5a4,0xf556)
	set(SOLID_ICONS ${SOLID_ICONS},0xf118,0xf5b8,0xf4da,0xf599,0xf59a,0xf59b)
	set(SOLID_ICONS ${SOLID_ICONS},0xf59c,0xf5b3,0xf5b4,0xf550,0xf002,0xf519)
	set(SOLID_ICONS ${SOLID_ICONS},0xf188,0xf023,0xf3c1,0xf09c,0xf007,0xf0c0)
	set(SOLID_ICONS ${SOLID_ICONS},0xf120)

	set(BRANDS_ICONS 0xf287)


	foreach(SIZE ${SIZES})
		set(FONT_TARGET font_${NAME}_${STYLE}_${SIZE})
		add_custom_target(${FONT_TARGET}
			COMMAND lv_font_conv --bpp=8 --size=${SIZE}
			--output=${DESTINATION}/${NAME}_${STYLE}_${SIZE}.c
			--format=lvgl
			--font=${PATH} --range=0x20-0x7F
			--font=${FONT_AWESOME_PATH}/${FONT_AWESOME_SOLID} --range=${SOLID_ICONS}
			--font=${FONT_AWESOME_PATH}/${FONT_AWESOME_BRANDS} --range=${BRANDS_ICONS}
			WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
			)

		add_dependencies(fonts ${FONT_TARGET})
	endforeach()

endfunction()

set(SIZES 8 12 16 20 24 28 44 56 72)

add_font_target(SourceCode/SourceCodePro-Black.ttf sourcecode r "${SIZES}")
add_font_symbol_target(Montserrat/Montserrat-Regular.ttf montserrat r "${SIZES}")
add_font_target(Montserrat/Montserrat-Light.ttf montserrat l "${SIZES}")
add_font_target(Montserrat/Montserrat-Italic.ttf montserrat i "${SIZES}")
add_font_symbol_target(Montserrat/Montserrat-SemiBold.ttf montserrat sb "${SIZES}")

