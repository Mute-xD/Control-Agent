#include "stdafx.h"
#include "Network.h"
#include "Status.h"
#include "Threading.h"

int main()
{
    Status status;
    pthread_t threads[2];
    int rc;

    NetThreadData netA{50201, &status, 0};
    NetThreadData netB{50203, &status, 1};
    rc = pthread_create(&threads[0], nullptr, networkThread, (void *) &netA);
    if (rc)
    {
        std::cout << "Threading Failed" << std::endl;
        exit(-1);
    }
    rc = pthread_create(&threads[0], nullptr, networkThread, (void *) &netB);
    if (rc)
    {
        std::cout << "Threading Failed" << std::endl;
        exit(-1);
    }

    std::cout << "Done!" << std::endl;
    pthread_exit(nullptr);
}
