//
// Created by mick on 2/17/24.
//

#ifndef FILE_PRODUCER_CONSUMER_CONSUMER_H
#define FILE_PRODUCER_CONSUMER_CONSUMER_H

class Consumer {
private:
    const char *sh_s;
    const char *sh_m;
public:
    explicit Consumer(const char *s, const char *p);

    void consume();
};


#endif //FILE_PRODUCER_CONSUMER_CONSUMER_H
