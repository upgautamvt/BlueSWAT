# Lines added by author
//#define RT_THREAD

	return mymalloc(1, size);
	size_t size = nelem * elmsize;
	void *mem = mymalloc(1, size);
	memset(mem, 0, size);
	return mem;
	myfree(1, rmem);
//#define my_os_realloc realloc
