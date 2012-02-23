#ifndef REDFLYSERVER_h
#define REDFLYSERVER_h


#ifdef __cplusplus
extern "C" {
#endif
  #include <inttypes.h>
  #include <avr/pgmspace.h>
#ifdef __cplusplus
}
#endif
#include "Print.h"
#include "Server.h"


class RedFlyServer : public Server
{
  public:
    RedFlyServer();
    RedFlyServer(uint16_t port);

    virtual void begin(void); //same as connect()
    virtual int connect(void);
    virtual uint8_t connected(void);
    virtual void stop(void);
    uint8_t status(void);
    uint8_t getSocket(void);

    virtual int available(void);
    virtual int read(void);
    virtual int read(uint8_t *s, size_t size);
    //virtual int peek(void); //not available
    virtual void flush(void);
    virtual size_t write(uint8_t b);
    virtual size_t write(const char *s);
    virtual size_t write(const uint8_t *s, size_t size);
    size_t print_P(PGM_P s);
    size_t println_P(PGM_P s);

    virtual operator bool();

    using Print::write;

  private:
    uint16_t s_port;
    uint8_t s_socket;
    uint8_t error;
};


#endif //REDFLYSERVER_h
