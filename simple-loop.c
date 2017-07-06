#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <fcntl.h>

int main()
{
	unsigned int i;
	int fd;

	close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

	fd = open("/tmp/simple-loop.output", O_CREAT | O_RDWR);

	if (fd < 0)
		return 0;

	for(i=0;i<2000000000;i++)
	{
		dprintf(fd, "[simple-loop] i=%d\n", i);
		sleep(1);
	}

	close(fd);

	return 0;
}
