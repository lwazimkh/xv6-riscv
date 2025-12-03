#include "kernel/pstat.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
    struct pstat ps;
    if (getpinfo(&ps) < 0){
        printf("getpinfo failed \n");
        exit(1);
    }
    printf("PID\tINUSE\tRUN\tPASS\n");
    for (int i = 0; i < NPROC; i++) {
        if (ps.inuse[i]) {
            printf("%d\t%d\t%d\t%d\n",
                ps.pid[i],
                ps.inuse[i],
                ps.runtime[i],
                ps.pass[i]);
        }
    }

    printf("Global passTotal = %d\n", ps.passTotal);
}
