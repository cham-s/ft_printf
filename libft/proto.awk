# extract prototype from function

# Each line is a field

{
    if ($0 ~ /^(void|int|char|long|unsigned).*\(/)
    {
        printf "%s\t\t\t" , $1
    for (i=2; i <=NF; i++)
       {
            printf "%s" , $i;
            if (i != NF)
                printf " "
       }
        printf ";\n";
    }
}
