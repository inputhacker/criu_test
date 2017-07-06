#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <unistd.h>

int main(void) {
        
        /* Our process ID and Session ID */
        pid_t pid, sid;
	int tfd;
	int i;
        
        /* Fork off the parent process */
        pid = fork();
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
           we can exit the parent process. */
        if (pid > 0) {
                exit(EXIT_SUCCESS);
        }

        /* Change the file mode mask */
        umask(0);
                
        /* Open any logs here */        
                
        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        

        
        /* Change the current working directory */
        if ((chdir("/")) < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        
        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        tfd = open("/tmp/simple-daemon.output", O_CREAT | O_RDWR);

        if (tfd < 0)
                return 0;

        /* Daemon-specific initialization goes here */
 
	i = 0;
	while (1)
	{
                dprintf(tfd, "[simple-loop] i=%d\n", i++);
                sleep(1);
        }

        close(tfd);

	exit(EXIT_SUCCESS);
}

