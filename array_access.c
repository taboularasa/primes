int last_index(int* result, int size)
{
    for(int i = 0; i < size; i++){
        if(result[i] == '\0') {
            return i;
        }
    }
    return -1;
}
