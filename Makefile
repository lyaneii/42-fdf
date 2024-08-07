NAME = fdf
CFLAGS = -Wall -Wextra -Werror
LINKS = -Lget_next_line -lgnl -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
INCLUDES = -I./include -I./minilibx-linux -I./get_next_line -I./libft

SRC = main.c
SRC_COORD_OPS = normalise_coords.c append_coordinate.c clear_coordinates.c get_coordinate_color.c last_coordinate.c new_coordinate.c next_column_coordinate.c next_row_coordinate.c
SRC_ROW_OPS = append_row.c last_row.c new_row.c clear_rows.c
SRC_PARSER = parse_input.c
SRC_MAP = create_map.c initialise_map.c map_from_file.c
SRC_DRAW = draw_bounds.c display_transform_info.c connect_points.c determine_direction.c draw_direction_east.c draw_direction_north.c draw_line.c draw_map.c
SRC_DRAW_HELPERS = fdf_itoa.c fdf_dtoa.c rgb_add.c get_rgb_diff.c get_rgb_slope.c ft_abs_double.c get_diff.c get_slope.c is_in_frame.c put_pixel_to_img.c new_projected_coordinate.c
SRC_TRANSFORM = apply_transforms.c change_perspective.c reset_transforms.c rotate_object.c scale_object.c translate_object.c
SRC_TRANSFORM_HELPERS = degrees_to_radians.c dot_product.c new_vector.c vector_multiply.c
SRC_MATRICES = isometric_matrix.c orthogonal_matrix.c perspective_matrix.c rotate_x_matrix.c rotate_y_matrix.c rotate_z_matrix.c
SRC_HOOK = key_hook.c mouse_hook.c
SRC_DESTROY = destroy.c

DIR_SRC = src
DIR_PARSER = parser
DIR_COORD_OPS = coord_operations
DIR_ROW_OPS = row_operations
DIR_MAP = map
DIR_DRAW = draw
DIR_DRAW_HELPERS = draw_helpers
DIR_TRANSFORM = transform
DIR_TRANSFORM_HELPERS = transform_helpers
DIR_MATRICES = matrices
DIR_HOOK = hook
DIR_DESTROY = destroy

SRC_COORD_OPS := ${addprefix ${DIR_PARSER}/${DIR_COORD_OPS}/, ${SRC_COORD_OPS}}
SRC_ROW_OPS := ${addprefix ${DIR_PARSER}/${DIR_ROW_OPS}/, ${SRC_ROW_OPS}}
SRC_PARSER := ${addprefix ${DIR_PARSER}/, ${SRC_PARSER}}
SRC_MAP := ${addprefix ${DIR_MAP}/, ${SRC_MAP}}
SRC_DRAW := ${addprefix ${DIR_DRAW}/, ${SRC_DRAW}}
SRC_DRAW_HELPERS := ${addprefix ${DIR_DRAW}/${DIR_DRAW_HELPERS}/, ${SRC_DRAW_HELPERS}}
SRC_TRANSFORM := ${addprefix ${DIR_TRANSFORM}/, ${SRC_TRANSFORM}}
SRC_TRANSFORM_HELPERS := ${addprefix ${DIR_TRANSFORM}/${DIR_TRANSFORM_HELPERS}/, ${SRC_TRANSFORM_HELPERS}}
SRC_MATRICES := ${addprefix ${DIR_TRANSFORM}/${DIR_MATRICES}/, ${SRC_MATRICES}}
SRC_HOOK := ${addprefix ${DIR_HOOK}/, ${SRC_HOOK}}
SRC_DESTROY := ${addprefix ${DIR_DESTROY}/, ${SRC_DESTROY}}

SRCS = ${addprefix ${DIR_SRC}/,	${SRC} ${SRC_PARSE_HELPERS} ${SRC_COORD_OPS} \
		${SRC_ROW_OPS} ${SRC_PARSER} ${SRC_MAP} ${SRC_DRAW} ${SRC_DRAW_HELPERS} \
		${SRC_TRANSFORM} ${SRC_TRANSFORM_HELPERS} ${SRC_MATRICES} \
		${SRC_HOOK} ${SRC_DESTROY}}

DIR_OBJ = obj

OBJ = ${patsubst %.c, %.o, ${SRCS}}
OBJ := ${subst ${DIR_SRC}, ${DIR_OBJ}, ${OBJ}}

LIBFT = libft/libft.a
GNL = get_next_line/libgnl.a
MINILIBX = minilibx-linux/libmlx
LIBFT_RULE = all

all: ${NAME}

${LIBFT}:
	make ${LIBFT_RULE} -C libft

${MINILIBX}:
	make -C minilibx-linux

${GNL}:
	make -C get_next_line

debug: CFLAGS += -g
debug: LIBFT_RULE := debug
debug: fclean all

${NAME}: ${OBJ} | ${LIBFT} ${GNL} ${MINILIBX}
	${CC} ${CFLAGS} $^ ${LINKS} -o $@

${OBJ}: ${DIR_OBJ}/%.o: ${DIR_SRC}/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	make clean -C libft
	make clean -C get_next_line
	rm -f ${OBJ}

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re debug sanitize
