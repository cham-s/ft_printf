
# insert ifndef

# for dir in `ls -ld */ | awk '{print $9}' | tr -d  '/'  | grep ft | head -n 4`; do
# 	touch $dir/$dir.h
# 	printf "Current directory: %s\n" $dir
# 	printf "#ifndef " >> $dir/$dir.h;
# 	printf "%s" $dir | tr '[:lower:]' '[:upper:]' >> $dir/$dir.h;
# 	printf "_H\n" >> $dir/$dir.h;
# 	printf "# define " >> $dir/$dir.h;
# 	printf "%s" $dir | tr '[:lower:]' '[:upper:]' >> $dir/$dir.h;
# 	printf "_H\n" >> $dir/$dir.h

# 	for f in  `ls -l $dir/ | awk '{if ($9 ~ /\.c/) print $9}'`; do
#     	awk -f proto.awk $dir/$f >> $dir/$dir.h
#     	#printf "%s\n" $dir/$f
# 	done

# 	printf "\n#endif" >> $dir/$dir.h

# 	printf "\n"
# done


# for each dir replace include libft with dir
for dir in `ls -ld */ | awk '{print $9}' | tr -d  '/'  | grep ft | head -n 4`; do
	for f in `ls $dir/ | grep "\.c"`; do
		sed "s/libft/$dir/" $dir/$f
	done
done	

# chang name from libft to current dir
# for f in `ls | grep "\.c"`; do
# 	awk 's/libft/$dir.h/' $f
# done


# remove header files fromd directories

# for dir in `ls -ld */ | awk '{print $9}' | tr -d  '/'  | grep ft | head -n 4`; do
# 	rm $dir/$dir.h
# done


# insert prototypes
# for f in  `ls -l | awk '{if ($9 ~ /\.c/) print $9}'`; do
#     awk -f proto.awk $f
# done


