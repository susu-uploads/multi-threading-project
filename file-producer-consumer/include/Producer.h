//
// Created by mick on 2/17/24.
//

#ifndef FILE_PRODUCER_CONSUMER_PRODUCER_H
#define FILE_PRODUCER_CONSUMER_PRODUCER_H

class Producer {
private:
    const char *sh_s;
    const char *sh_m;
public:
    explicit Producer(const char *s, const char *p);

    void produce();
};


#endif //FILE_PRODUCER_CONSUMER_PRODUCER_H
