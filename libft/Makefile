
.PHONY: build clean fclean re
build:
	make -C ftctype/
	make -C ftstring/
	make -C ftstdio/
	make -C ftlist/
	make -C ftstdlib/

clean:
	@for f in `ls | grep "ft"`; do \
		make clean -C $$f; \
	done

fclean:
	@for f in `ls | grep "ft"`; do \
		make fclean -C $$f; \
	done

re:
	@for f in `ls | grep "ft"`; do \
		make re -C $$f; \
	done
